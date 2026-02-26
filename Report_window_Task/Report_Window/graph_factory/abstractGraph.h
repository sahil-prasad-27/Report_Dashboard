#ifndef GRAPH_H
#define GRAPH_H

#include "../qcustomplot/qcustomplot.h"
#include <QtCharts/QChartView>
#include <iostream>

/**
 * @brief The GraphCustomPlot class - wrapper for QCustomPlot functionalities.
 * using QCustomPlot draw cartesian graph like bar chart, line chart etc.
 */
class GraphCustomPlot : public QCustomPlot
{
public:
    /**
     * @brief GraphCustomPlot - constructor to initialize parameters
     * @param parent
     */
    explicit GraphCustomPlot(QWidget *parent);

    /**
     * deallocate resources
     */
    virtual ~GraphCustomPlot();

    /**
     * @brief The GraphStyle enum - to select style for a graph [here default_ for plain graph
     * and ColorGraph_RedGreen to draw graph of two type of color which seperate boundries.]
     */
    enum GraphStyle {
        default_,
        ColorGraph_RedGreen,
    };

    /**
     * @brief deleteXAndYAxisTitle - to delete x and y axis label
     */
    virtual void deleteXAndYAxisTitle();

    /**
     * @brief setXAxisTitle - to set x axis title in a customplot graph
     * @param xAxisLbl - x axis label
     */
    virtual void setXAxisTitle(const QString &xAxisLbl);

    /**
     * @brief setYAxisTitle - to set y axis title in a customplot graph
     * @param yAxisLbl - y axis label
     */
    virtual void setYAxisTitle(const QString &yAxisLbl);

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<double, double>>
     */
    virtual void updateData(const QList<QPair<double, double>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<int, int>>
     */
    virtual void updateData(const QList<QPair<int, int>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<QString, int>>
     */
    virtual void updateData(const QList<QPair<QString, int>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<QString, double>>
     */
    virtual void updateData(const QList<QPair<QString, double>> &data)=0;

    /**
     * @brief setGraphTitle - set graph title
     * @param graphTitle - graph title name
     */
    virtual void setGraphTitle(const QString graphTitle);

    /**
     * @brief deleteGraphTitle - to delete graph title
     */
    virtual void deleteGraphTitle();

    /**
     * @brief setYAxisRanges - set y axis range
     * @param lowerValue - lower value
     * @param upperValue - upper value
     */
    virtual void setYAxisRanges(double lowerValue, double upperValue);

    /**
     * @brief clearGraph - clear all the data from a graph
     */
    virtual void clearGraph()=0;

    /**
     * @brief title - to set a title for a customplot graph
     */
    QCPTextElement *title = nullptr;

    //********* color graph Feature *******//
    /**
     * @brief setSeprationLineAccToYAxis - to draw two sepration line according to y axis
     * [which will safe the region between the boudries]
     * @param lowerBoundryVal - lower boundry value on y axis
     * @param upperBoundryVal - upper boundry value on y axis
     */
    virtual void setSeprationLineAccToYAxis(double lowerBoundryVal, double upperBoundryVal) = 0;

    /**
     * @brief updateData - update color graph in line chart [feature zoom in for date range]
     * @param data - data in a form of QList<QPair<QDateTime, double>>
     * @param graph - user want color graph then select ColorGraph_RedGreen
     */
    virtual void updateData(const QList<QPair<QDateTime, double>> &data, GraphStyle graph = GraphStyle::default_) =0;

    //********* Live Data Feature ******//
    /**
     * @brief setUpUIForLiveData - to set UI for live data [uses time on x axis]
     */
    virtual void setUpUIForLiveData() = 0;

    /**
     * @brief updateLiveData - to update live data point in a graph [uses time on x axis and to show only 1 minute data]
     * @param dateTime - give x axis value datetime
     * @param value - set y axis value on that time
     * @param graph - user want color graph then select ColorGraph_RedGreen
     */
    virtual void updateLiveData(QDateTime dateTime, double value, GraphStyle graph = GraphStyle::default_)=0;

protected:
    /**
     * @brief initUiAndInsertIntoLayout - initialize UI and set into layout
     */
    virtual void initUiAndInsertIntoLayout() = 0;

    /**
     * @brief connectSignalSlots - connect signal slots
     */
    virtual void connectSignalSlots() = 0;

};


/**
 * @brief The GraphChartView class - wrapper for QChartView functionalities.
 * using QChartView draw graph like pie chart etc.
 */
class GraphChartView : public virtual QtCharts::QChartView
{
public:
    /**
     * @brief GraphChartView - to initialize the parameter
     * @param parent
     */
    explicit GraphChartView(QWidget *parent);

    /**
     * @brief ~GraphChartView - to deallocate memory
     */
    virtual ~GraphChartView();

    /**
     * @brief setXAxisTitle - to set x axis title in a customplot graph
     * @param xAxisLbl - x axis label
     */
    virtual void setXAxisTitle(const QString &xAxisLbl) =0;

    /**
     * @brief setYAxisTitle - to set y axis title in a customplot graph
     * @param yAxisLbl - y axis label
     */
    virtual void setYAxisTitle(const QString &yAxisLbl) =0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<double, double>>
     */
    virtual void updateData(const QList<QPair<double, double>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<int, int>>
     */
    virtual void updateData(const QList<QPair<int, int>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<QString, int>>
     */
    virtual void updateData(const QList<QPair<QString, int>> &data)=0;

    /**
     * @brief updateData - update graph according to given data
     * @param data - data in a form of QList<QPair<QString, double>>
     */
    virtual void updateData(const QList<QPair<QString, double>> &data)=0;

    /**
     * @brief setGraphTitle - set graph title
     * @param graphTitle - graph title name
     */
    virtual void setGraphTitle(const QString graphTitle) = 0;

    /**
     * @brief deleteGraphTitle - to delete graph title
     */
    virtual void deleteGraphTitle() = 0;

    /**
     * @brief clearGraph - to clear all the content from a graph
     */
    virtual void clearGraph() = 0 ;

    /**
     * @brief deleteXAndYAxisTitle - to delete x and y axis title
     */
    virtual void deleteXAndYAxisTitle() = 0;

protected:
    /**
     * @brief initUiAndInsertIntoLayout - initialize UI and set into layout
     */
    virtual void initUiAndInsertIntoLayout() = 0;

    /**
     * @brief connectSignalSlots - connect signal slots
     */
    virtual void connectSignalSlots() = 0;

};

#endif // GRAPH_H
