#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include "abstractGraph.h"

using namespace std;

namespace Ui {
class PieChart;
}

/**
 * @brief The PieChart class - to plot pie chart using QChartView
 */
class PieChart :  public GraphChartView
{

public:
    /**
     * @brief PieChart - pie chart constructor to initialize variables, pointers, database object
     * @param state - sorting is running or not
     * @param parent
     */
    explicit PieChart(QWidget * parent = nullptr);

    ~PieChart(); /*! @brief deallocate resources */

    void setGraphTitle(const QString graphTitle) override;
    void deleteGraphTitle() override;
    void setXAxisTitle(const QString &xAxisLbl) override;
    void setYAxisTitle(const QString &yAxisLbl) override;
    void updateData(const QList<QPair<double, double>> &data) override;
    void updateData(const QList<QPair<QString, double>> &data) override;
    void updateData(const QList<QPair<int, int>> &data) override;
    void updateData(const QList<QPair<QString, int>> &data) override;
    void clearGraph() override;
    void deleteXAndYAxisTitle() override;

private:

    QList<QColor> colorList; /*! @brief colorList - to store color in list use in pie chart */

    /**
     * @brief pieSeries - A pointer to a QtCharts::QPieSeries for managing data series for a pie chart.
     */
    QtCharts::QPieSeries* pieSeries=nullptr;

    QtCharts::QChart* chart=nullptr; /*! @brief chart - A pointer to a QtCharts::QChart for managing and displaying a chart. */

    void initUiAndInsertIntoLayout() override;

    void connectSignalSlots() override;

    void initializeColorList(); /*! @brief initializeColorList - select color in color list for pie chart slices */

};

#endif // PIECHART_H
