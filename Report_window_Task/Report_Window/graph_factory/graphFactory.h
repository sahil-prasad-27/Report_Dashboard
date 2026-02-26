#ifndef FACTORY_H
#define FACTORY_H

#include "pieChart.h"
#include "lineChart.h"
#include "barChart.h"

/**
 * @brief The GraphFactory class - to get graph instance
 */
class GraphFactory
{
public:

    /**
     * @brief The graphType enum - graph types
     */
    enum graphType{
        BarGraph,
        PieGraph,
        LineGraph
    };

    /**
     * @brief getChartWidget - get graph instance which return type is QChartView
     * @param graph - graph type
     * @return - object of graph [pie]
     */
    static GraphChartView* getQChartView(const graphType &graph);

    /**
     * @brief getQCustomPlot - get graph instance which return type is QCustomPlot
     * @param graph - graph type
     * @return - object of graph [bar, line]
     */
    static GraphCustomPlot* getQCustomPlot(const graphType &graph);


};

#endif // FACTORY_H
