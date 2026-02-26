#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // ---------------- PAGE 3 ----------------
    void on_rbCurrent_clicked();  // Pie chart
    void on_rbDate_clicked();     // Table view

    // ---------------- PAGE 4 ----------------
    void on_rbCurrent_2_clicked(); // Current session
    void on_rbDateRange_clicked(); // Date range selection

    // ---------------- COMMON ----------------
    void on_calendarButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    void loadPieChart();
    void loadJsonToTableView(const QString &fileName);
};

#endif // MAINWINDOW_H
