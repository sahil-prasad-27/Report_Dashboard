#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItem>
#include <QHeaderView>
#include <QDialog>
#include <QCalendarWidget>
#include <QPushButton>
#include <QDebug>
#include "graphFactory.h"
#include <QButtonGroup>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    // ---------------- GLOBAL BUTTON GROUP ----------------
    QButtonGroup* globalGroup = new QButtonGroup(this);
    globalGroup->addButton(ui->rbCurrent);
    globalGroup->addButton(ui->rbDate);
    globalGroup->addButton(ui->rbCurrent_2);
    globalGroup->addButton(ui->rbDateRange);
    globalGroup->setExclusive(true);

    // ---------------- DEFAULT PAGE ----------------
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->rbCurrent->setChecked(true);

    ui->dateRangeEdit->setEnabled(false);
    ui->calendarButton->setEnabled(false);

    // ---------------- LOAD PIE AND TABLE ----------------
    loadPieChart();
    loadJsonToTableView(":/sessions.json");

    // ---------------- CONNECT RADIO BUTTONS ----------------
    connect(ui->rbCurrent, &QRadioButton::clicked, this, &MainWindow::on_rbCurrent_clicked);
    connect(ui->rbDate, &QRadioButton::clicked, this, &MainWindow::on_rbDate_clicked);
    connect(ui->rbCurrent_2, &QRadioButton::clicked, this, &MainWindow::on_rbCurrent_2_clicked);
    connect(ui->rbDateRange, &QRadioButton::clicked, this, &MainWindow::on_rbDateRange_clicked);

    // ---------------- DEFAULT COMBOBOX ----------------
    ui->comboBox->setCurrentIndex(1);
}

bool MainWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/Irsdb_Suka.sqlite");
    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected!";
    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////////////////////////////////////////////////////////
/// PAGE 3 RADIO BUTTONS
////////////////////////////////////////////////////////////
void MainWindow::on_rbCurrent_clicked()
{
    // Show Page 3 (Pie Chart)
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->rbCurrent->setChecked(true);

    ui->dateRangeEdit->setEnabled(false);
    ui->calendarButton->setEnabled(false);

    loadPieChart();
}

void MainWindow::on_rbDate_clicked()
{
    // Show Page 4 (Table)
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->rbDate->setChecked(true);

    ui->rbCurrent_2->setChecked(false);
    ui->rbDateRange->setChecked(true);

    ui->dateRangeEdit->setEnabled(true);
    ui->calendarButton->setEnabled(true);

    loadJsonToTableView(":/sessions.json");
}

////////////////////////////////////////////////////////////
/// PAGE 4 RADIO BUTTONS
////////////////////////////////////////////////////////////
void MainWindow::on_rbCurrent_2_clicked()
{
    // Return to main "Current" view
    ui->stackedWidget->setCurrentWidget(ui->page_3);

    ui->rbCurrent->setChecked(true);    // Main page
    ui->rbCurrent_2->setChecked(true);  // Page4 current
    ui->rbDateRange->setChecked(false);

    ui->dateRangeEdit->clear();
    ui->dateRangeEdit->setEnabled(false);
    ui->calendarButton->setEnabled(false);

    loadPieChart(); // restore pie chart
}

void MainWindow::on_rbDateRange_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);

    ui->rbDateRange->setChecked(true);
    ui->rbCurrent_2->setChecked(false);

    ui->dateRangeEdit->clear();
    ui->dateRangeEdit->setEnabled(true);
    ui->calendarButton->setEnabled(true);

    loadJsonToTableView(":/sessions.json");
}

////////////////////////////////////////////////////////////
/// PIE CHART
////////////////////////////////////////////////////////////
void MainWindow::loadPieChart()
{
    GraphChartView* pieGraph = GraphFactory::getQChartView(GraphFactory::PieGraph);
    if (!pieGraph) return;

    QLayout* layout = ui->frame_7->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->frame_7);
        ui->frame_7->setLayout(layout);
    }

    while (QLayoutItem* item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }

    layout->addWidget(pieGraph);

    QList<QPair<QString, double>> graphData;
    QFile file(":/data.json");
    QJsonObject liveObj;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        liveObj = doc.object()["PieChart"].toObject()["Live"].toObject();
    }

    if (liveObj.isEmpty()) {
        liveObj["Fired Objects"] = QJsonObject{{"count", 1}};
        liveObj["Non Fired Objects"] = QJsonObject{{"count", 1}};
    }

    for (auto it = liveObj.begin(); it != liveObj.end(); ++it) {
        QString key = it.key();
        QJsonObject obj = it.value().toObject();
        double sliceValue = 0;
        QStringList details;

        for (auto inner = obj.begin(); inner != obj.end(); ++inner) {
            sliceValue += inner.value().toDouble();
            details << inner.key() + ": " + QString::number(inner.value().toDouble());
        }

        graphData.append(qMakePair(key + "\n" + details.join("\n"), sliceValue));
    }

    pieGraph->updateData(graphData);
    pieGraph->setGraphTitle("Live Fired Objects Pie Chart");
}

////////////////////////////////////////////////////////////
/// TABLE VIEW
////////////////////////////////////////////////////////////
void MainWindow::loadJsonToTableView(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isArray()) return;

    QJsonArray array = doc.array();
    QStandardItemModel* model = new QStandardItemModel(array.size(), 10, this);
    model->setHorizontalHeaderLabels({
        "Session Count", "Start Date", "End Date",
        "Start Time", "Stop Time", "Working Time",
        "Status", "Sorting Type", "View Detail", "Download"
    });

    for (int row = 0; row < array.size(); ++row) {
        QJsonObject obj = array[row].toObject();
        model->setItem(row, 0, new QStandardItem(QString::number(obj["session_count"].toInt())));
        model->setItem(row, 1, new QStandardItem(obj["session_start_date"].toString()));
        model->setItem(row, 2, new QStandardItem(obj["session_end_date"].toString()));
        model->setItem(row, 3, new QStandardItem(obj["session_start_time"].toString()));
        model->setItem(row, 4, new QStandardItem(obj["session_stop_time"].toString()));
        model->setItem(row, 5, new QStandardItem(obj["session_working_time"].toString()));
        model->setItem(row, 6, new QStandardItem(obj["status"].toString()));
        model->setItem(row, 7, new QStandardItem(obj["sorting_type"].toString()));
        model->setItem(row, 8, new QStandardItem(""));
        model->setItem(row, 9, new QStandardItem(""));

        QPushButton *viewBtn = new QPushButton("View Detail");
        connect(viewBtn, &QPushButton::clicked, this, [row]() { qDebug() << "View clicked row:" << row; });
        ui->tableView_3->setIndexWidget(model->index(row, 8), viewBtn);

        QPushButton *downloadBtn = new QPushButton("Download");
        connect(downloadBtn, &QPushButton::clicked, this, [row]() { qDebug() << "Download clicked row:" << row; });
        ui->tableView_3->setIndexWidget(model->index(row, 9), downloadBtn);
    }

    ui->tableView_3->setModel(model);
    ui->tableView_3->verticalHeader()->setVisible(false);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_3->setAlternatingRowColors(true);
}

////////////////////////////////////////////////////////////
/// CALENDAR BUTTON
////////////////////////////////////////////////////////////
void MainWindow::on_calendarButton_clicked()
{
    QDialog dialog(this);
    dialog.setWindowModality(Qt::ApplicationModal);
    dialog.resize(350, 300);

    QVBoxLayout layout(&dialog);
    QCalendarWidget calendar(&dialog);
    layout.addWidget(&calendar);

    static QDate startDate, endDate;
    static bool firstClick = true;

    connect(&calendar, &QCalendarWidget::clicked, this, [&](const QDate &date){
        if(firstClick) {
            startDate = date;
            endDate = date;
            firstClick = false;
            ui->dateRangeEdit->setText(startDate.toString("yyyy-MM-dd") + " to ...");
        } else {
            endDate = date;
            if(endDate < startDate) std::swap(startDate, endDate);
            ui->dateRangeEdit->setText(startDate.toString("yyyy-MM-dd") + " to " + endDate.toString("yyyy-MM-dd"));
            firstClick = true;
            dialog.accept();
        }
    });

    dialog.exec();
}

////////////////////////////////////////////////////////////
/// COMBOBOX CHANGE
////////////////////////////////////////////////////////////
void MainWindow::on_comboBox_currentIndexChanged(int)
{
    if(ui->stackedWidget->currentWidget() != ui->page_4) return;

    QString selected = ui->comboBox->currentText();

    // reuse existing handlers
    if(selected == "Session Wise") {
        on_rbCurrent_2_clicked();
    } else {
        on_rbDateRange_clicked();
    }
}
