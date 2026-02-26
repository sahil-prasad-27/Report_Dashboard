#include "abstractGraph.h"

GraphCustomPlot::GraphCustomPlot(QWidget *parent)
    : QCustomPlot(parent)
{
}

GraphCustomPlot::~GraphCustomPlot()
{
    qDebug()<<"GraphCustomPlot destructor [enterd]"<<endl;

    deleteGraphTitle();

    qDebug()<<"GraphCustomPlot destructor [enterd]"<<endl;

}

void GraphCustomPlot::setXAxisTitle(const QString &xAxisLbl)
{
    try {
        if(xAxis != nullptr){
            xAxis->setLabel(xAxisLbl);
            xAxis->setLabelFont(QFont("Ubuntu", 14));
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void GraphCustomPlot::setYAxisTitle(const QString &yAxisLbl)
{
    try {
        if(yAxis != nullptr){
            yAxis->setLabel(yAxisLbl);
            yAxis->setLabelFont(QFont("Ubuntu", 14));
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void GraphCustomPlot::setYAxisRanges(double lowerValue, double upperValue){
    try {
        if(yAxis != nullptr){
            yAxis->setRange(lowerValue, upperValue);
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void GraphCustomPlot::deleteXAndYAxisTitle()
{
    try {
        if(xAxis != nullptr){
            xAxis->setLabel("");
        }
        if(yAxis != nullptr){
            yAxis->setLabel("");
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void GraphCustomPlot::setGraphTitle(const QString graphTitle) {
    try {
        // Set title of the QCustomPlot widget
        if(title == nullptr){
            title = new QCPTextElement(this);
            QFont titleFont = title->font(); // Get current font
            titleFont.setPointSize(30); // Set font size (adjust as needed)
            title->setFont(titleFont); // Apply the new font

            plotLayout()->insertRow(0); // Ensure there is a row at the top for the title
            plotLayout()->addElement(0, 0, title);
        }
        title->setText(graphTitle);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void GraphCustomPlot::deleteGraphTitle()
{
    try {
        if(title !=nullptr){
            delete title;
            title = nullptr;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

GraphChartView::GraphChartView(QWidget *parent)
    : QtCharts::QChartView(parent)
{
}

GraphChartView::~GraphChartView()
{
}
