#ifndef BARCHART_H
#define BARCHART_H

#include "abstractGraph.h"

/**
 * @brief The BarChart class - bar chart tamplate uses QCustomplot to plot bar graph
 * using various user define function
 */
class BarChart : public GraphCustomPlot
{
    Q_OBJECT

public:
    /**
     * @brief BarChart - bar chart constructor to initialize variables and signal slot
     * @param parent
     */
    explicit BarChart(QWidget * parent = nullptr);

    /**
     * deallocate resources
     */
    ~BarChart();

protected:

    void updateData(const QList<QPair<double, double>> &data) override;

    void updateData(const QList<QPair<QString, double>> &data) override;

    void setUpUIForLiveData() override;

    void updateData(const QList<QPair<QDateTime, double>> &data, GraphStyle graph = GraphStyle::default_) override;

    void updateLiveData(QDateTime dateTime, double value, GraphStyle graph = GraphStyle::default_) override;

    void setSeprationLineAccToYAxis(double lowerBoundryVal, double upperBoundryVal) override;

    void updateData(const QList<QPair<int, int>> &data) override;

    void updateData(const QList<QPair<QString, int>> &data) override;

    void clearGraph() override;

private slots:
    /**
     * @brief showToolTip - to hover at data points
     * @param event
     */
    void showToolTip(QMouseEvent *event);

private:

    void initUiAndInsertIntoLayout() override;

    void connectSignalSlots() override;

    /**
     * @brief toolTipText - give text of data point when it hover
     * @param xAxisLblVal - x axis label value
     * @param yAxisLblVal - y axis label value
     * @return - QString the formate of text to show in UI when its hover
     */
    QString toolTipText(double xAxisLblVal, double yAxisLblVal);

    /**
     * @brief toolTipText - give text of data point when it hover
     * @param xAxisLblVal - x axis label value
     * @param yAxisLblVal - y axis label value
     * @return - QString the formate of text to show in UI when its hover
     */
    QString toolTipText(QString xAxisLblVal, double yAxisLblVal);

    QVector<double> xAxisLbl; /*! @brief xAxisLbl - x axis labels vector */
    QVector<QString> xAxisLabels; /*! @brief xAxisLabels - x axis labels vector */
    QVector<double> yAxisLbl; /*! @brief yAxisLbl - y axis labels vector */

    /**
     * @brief The identifier enum - enum to identify which formate the data is in
     */
    enum identifier{
        QStringDouble,
        DoubleDouble
    };

    /**
     * @brief identifierType - selected identifier
     */
    identifier identifierType;
};

#endif // BARCHART_H
