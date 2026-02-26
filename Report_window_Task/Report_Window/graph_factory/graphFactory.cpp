#include "graphFactory.h"

GraphChartView* GraphFactory::getQChartView(const graphType &graph)
{
    try {
        switch (graph)
        {
            case PieGraph: return new PieChart();
        }
    } catch (const exception &e) {
        cout << "[ERROR] " << e.what() << ", in => " << __PRETTY_FUNCTION__ << endl;
    }
    return nullptr;
}

GraphCustomPlot* GraphFactory::getQCustomPlot(const graphType &graph)
{
    try {
        switch (graph)
        {
            case BarGraph:
                return new BarChart();

            case LineGraph:
                return new LineChart();

        }
    } catch (const exception &e) {
        cout << "[ERROR] " << e.what() << ", in => " << __PRETTY_FUNCTION__ << endl;
    }
    return nullptr;
}

