#ifndef LINECHART_H
#define LINECHART_H

#include "abstractGraph.h"

using namespace std;

namespace Ui {
class LineChart;
}

/**
 * @brief The LineChart class - draw a live graph of time and static graph update in ui using customplot
 */
class LineChart :  public GraphCustomPlot
{
    Q_OBJECT
public:
    /**
     * @brief LineChart - constructor to initialize values, to create database object
     * @param sortingState - sorting is running or not
     * @param buttonName - which button is clicked know (air pressure, air consuption, motor ampere etc)
     * @param parent
     */
    explicit LineChart(QWidget * parent = nullptr);

    /**
      * to deallocate memories
      */
    ~LineChart();


protected:

    void setUpUIForLiveData() override;

    void updateData(const QList<QPair<double, double>> &data) override;

    void updateData(const QList<QPair<QString, double>> &data) override;

    void updateData(const QList<QPair<QDateTime, double>> &data, GraphStyle graph = GraphStyle::default_) override;

    void updateLiveData(QDateTime dateTime, double value, GraphStyle graph = GraphStyle::default_) override;

    void setSeprationLineAccToYAxis(double lowerBoundryVal, double upperBoundryVal) override;

    void updateData(const QList<QPair<int, int>> &data) override;

    void updateData(const QList<QPair<QString, int>> &data) override;

    void clearGraph() override;

private slots:
    /**
     * @brief showToolTip - function use to show data point values of data point when hover on it
     * @param event - mouse click event
     */
    void showToolTip(QMouseEvent *event);

private:

    QCPRange initialXAxisRange; /*! @brief initialXAxisRange - to store x axis range */

    QSharedPointer<QCPAxisTickerDateTime> dateTicker=nullptr; /*! @brief dateTicker - formate of timestamp in x axis */

    int liveGraphDataPointLimit[60]={0}; /*! @brief liveGraphDataPointLimit - to deallocate data of live graph [air pressure and air consuption] */

    int dataPointIndex=0; /*! @brief dataPointIndex - use to track data of live graph */

    /**
     * @brief restrictXAxisEntriesLiveGraph - variable to show only 60 values in live graph on x axis
     */
    int restrictXAxisEntriesLiveGraph=0;

    int liveDataLimit=0; /*! @brief liveDataLimit - variable to limit live chart vector plot */

    QVector<QDateTime> xCoordinates; /*!< @brief xCoordinate - vector to store date value [x coordinate] */

    /**
     * @brief y - vector to store y coordinate [y coordinate]
     */
    QVector<double> yCoordinates;

    double lowerBoundry; /*! @brief lowerGreen - lower boundry - define pressure ranges [boundries] */

    double upperBoundry; /*! @brief upperBoundry - uper boundry - define different regions ranges [boundries] */

    string prevx=""; /*! @brief prevx - to store previous value of time initially it is empty */

    double prevy=-1; /*! @brief prevy - to store initial value of y coordinate , initially it is zero */

    void initUiAndInsertIntoLayout() override;

    void connectSignalSlots() override;

    /**
     * @brief onXAxisRangeChangedFun - on x axis range change in which formate user can see x axis label (eg. date, time, year)
     */
    void onXAxisRangeChangedFun();

    /**
     * @brief handleZoomEvent - signal to show x axis range change
     */
    void handleZoomEvent();

    /**
     * @brief colorGraphLogicLiveData - add color to graph lines according to boundries
     * @param prevx - previous values of time
     * @param prevy - previous value of value [air pressure, consuption etc.]
     * @param currentTime - current value of time
     * @param value - current value of y coordinate
     */
    void colorGraphLogicLiveData(QDateTime prevx, double prevy, QDateTime currentTime, double value) ;

    /**
     * @brief drawLine - draw colored line to the graph
     * @param color - select qt color
     * @param startX - previous values of time
     * @param startY - previous value of value [air pressure, consuption etc.]
     * @param endX - current value of time
     * @param endY - current value of y coordinate
     * @param startCount - add dot to the start coordinate [true or false]
     * @param endCount - add dot to the end coordinate [true or false]
     */
    void drawLine(const QColor &color, const QDateTime &startX, double startY, const QDateTime &endX, double endY,  bool startCount = false, bool endCount = false) ;

    /**
     * @brief colorGraphLogic - color graph logic for static graph values comes from database
     */
    void colorGraphLogic();

    /**
     * @brief setUpGraph - set a graph in date range is there [handle signal slot]
     */
    void setUpGraph();

};

#endif // LINECHART_Hff
