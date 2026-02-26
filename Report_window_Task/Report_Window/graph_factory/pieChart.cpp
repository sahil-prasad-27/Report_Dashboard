#include "pieChart.h"

PieChart::PieChart(QWidget * parent) :GraphChartView(parent)
{
    try {
        initializeColorList();
        initUiAndInsertIntoLayout();
        connectSignalSlots();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::initializeColorList()
{
    try {
        colorList.clear();
        colorList << QColor("#91cc75")
                  << QColor("#5470c6")
                  << QColor("#00b4d8")
                  << QColor("#48cae4")
                  << QColor("#ADE8F4");
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::setGraphTitle(const QString graphTitle)
{
    try {
        if(chart){
            chart->setTitle(graphTitle);
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::deleteGraphTitle()
{
    try {
        if(chart){
            chart->setTitle("");
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::initUiAndInsertIntoLayout()
{
    try {
        pieSeries = new QtCharts::QPieSeries();
        chart = new QtCharts::QChart();
        chart->addSeries(pieSeries);
        chart->legend()->setVisible(false);
        chart->setMargins(QMargins(0, 0, 0, 0));
        chart->setContentsMargins(0,0,0,0);
        chart->setBackgroundBrush(QBrush(Qt::white));
        setChart(chart);
        setRenderHint(QPainter::Antialiasing);
        setBackgroundBrush(QBrush(Qt::white));
        chart->setContentsMargins(-20, -20, -20, -20);
        chart->layout()->setContentsMargins(0, 0, 0, 0);
        chart->legend()->hide();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

PieChart::~PieChart()
{
    try {
        qDebug() << 12.0 << endl;
        // Check if the series is not nullptr
        if (pieSeries != nullptr) {
            // Remove the series from the chart
            if (chart != nullptr) {
                chart->removeSeries(pieSeries);
            }
            qDebug() << 12.1 << endl;
            // Delete the series
            if(pieSeries!=nullptr){
                delete pieSeries;
                pieSeries=nullptr;
            }
            qDebug() << 10 << endl;
        }
        if(chart!=nullptr){
            delete chart;
            chart=nullptr;
        }
        qDebug()<<19<<endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::updateData(const QList<QPair<QString, int>> &data)
{
    try {
        int i = 0;
        pieSeries->clear(); // Clear existing slices before updating with new data
        int total = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            total=total+it->second;
        }
        // Iterate over the data list and add slices to the pie series
        for (auto it = data.begin(); it != data.end(); ++it) {
            const QString &category = it->first;
            double value = it->second;
            // Append a new slice to the pie series with category as label and value as size
            QtCharts::QPieSlice *slice = pieSeries->append(category, value);
            slice->setLabelVisible(true);
            // Set slice brush color using modulo indexing with colorList
            slice->setBrush(QBrush(colorList.at(i % colorList.size())));
            i++;
            // Connect hover event to show tooltip with slice data
            connect(slice, &QtCharts::QPieSlice::hovered, this, [category, value]() {
                QString tooltip = QString("%1: %2").arg(category).arg(value);
                QToolTip::showText(QCursor::pos(), tooltip);
            });
            // Update label for the slice
            QString label = QString("%1 (%2%)")
                .arg(slice->label())
                .arg(100 * slice->value()/total, 0, 'f', 1);
            slice->setLabel(label);
            // Set font size for the label
            QFont font = slice->labelFont();
            font.setPointSize(12);
            slice->setLabelFont(font);
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::clearGraph()
{
    try {
        if(pieSeries){
            pieSeries->clear(); // Clear existing slices before updating with new data
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void PieChart::updateData(const QList<QPair<int, int> > &data)
{
}

//void PieChart::updateData(const QList<QPair<QString, double>> &data)
//{
//    try {
//        if (!pieSeries) return;
//        pieSeries->clear();
//        double total = 0;
//        for (const auto &p : data) total += p.second;
//        int i = 0;
//        for (const auto &p : data) {
//            QtCharts::QPieSlice *slice = pieSeries->append(p.first, p.second);
//            slice->setLabelVisible(true);
//            slice->setBrush(QBrush(colorList.at(i % colorList.size())));
//            i++;
//            // Format label as "Category (xx.x%)"
//            QString label = QString("%1 (%2%)").arg(slice->label()).arg(100*slice->value()/total,0,'f',1);
//            slice->setLabel(label);
//            QFont font = slice->labelFont();
//            font.setPointSize(12);
//            slice->setLabelFont(font);
//        }
//        if(chart) chart->update();
//    } catch (const std::exception &e) {
//        std::cerr << "An error occurred: " << e.what() << std::endl;
//    }
//}

void PieChart::deleteXAndYAxisTitle()
{
}

void PieChart::updateData(const QList<QPair<double, double>> &data)
{
}

void PieChart::connectSignalSlots()
{

}

void PieChart::setXAxisTitle(const QString &xAxisLbl)
{
}

void PieChart::setYAxisTitle(const QString &yAxisLbl)
{
}
void PieChart::updateData(const QList<QPair<QString, double>> &data)
{
    try {
        if (!pieSeries) return;
        pieSeries->clear();

        double total = 0;
        for (const auto &p : data) total += p.second;

        int i = 0;
        for (const auto &p : data) {
            const QString &category = p.first; // e.g., "Fired\ncount:1\nother:2"
            double value = p.second;

            QtCharts::QPieSlice *slice = pieSeries->append(category, value);
            slice->setBrush(QBrush(colorList.at(i % colorList.size())));
            slice->setLabelVisible(true);
            i++;

            // Split category into first line = label, rest = hover
            QStringList parts = category.split('\n');
            QString baseLabel = parts.first(); // "Fired" or "Non Fired"

            // Calculate percentage
            double percentage = (value / total) * 100.0;
            QString sliceLabel = QString("%1 %2%").arg(baseLabel).arg(percentage, 0, 'f', 1);
            slice->setLabel(sliceLabel);

            // Font
            QFont font = slice->labelFont();
            font.setPointSize(12);
            slice->setLabelFont(font);

            // Hover = all remaining details (exclude the label/percentage)
            QString hoverText = parts.mid(1).join("\n");
            connect(slice, &QtCharts::QPieSlice::hovered, this,
                    [hoverText](bool state) {
                        if (state)
                            QToolTip::showText(QCursor::pos(), hoverText);
                        else
                            QToolTip::hideText();
                    });
        }

        if(chart) chart->update();

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}
