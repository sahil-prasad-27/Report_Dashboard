#include "barChart.h"

BarChart::BarChart(QWidget * parent) : GraphCustomPlot(parent)
{
    initUiAndInsertIntoLayout();
    connectSignalSlots();
}

void BarChart::initUiAndInsertIntoLayout()
{
}

void BarChart::connectSignalSlots()
{
    connect(this, &QCustomPlot::mouseMove, this, &BarChart::showToolTip);
}

void BarChart::updateData(const QList<QPair<double, double> > &data)
{
    try {
        identifierType = identifier::DoubleDouble;

        // Clear existing data
        clearPlottables();

        QCPBars *bars = new QCPBars(xAxis, yAxis);

        addGraph();
        graph(0)->setLineStyle(QCPGraph::lsLine); // No line connecting points
        graph(0)->setBrush(QColor(30, 144, 255, 150)); // Set color and transparency for bars

        for (const auto& pair : data) {
            xAxisLbl.append(pair.first);
            yAxisLbl.append(pair.second);
        }

        bars->setData(xAxisLbl, yAxisLbl);

        rescaleAxes();

        // Adjusted range to center the bars
        replot();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred during data update: " << e.what() << std::endl;
    }
}

void BarChart::updateData(const QList<QPair<QString, double>> &data)
{
    try {
        identifierType = identifier::QStringDouble;

        // Clear existing data
        clearPlottables();

        // Create new bars object
        QCPBars *bars = new QCPBars(xAxis, yAxis);

        // Set up graph properties
        addGraph();
        graph(0)->setLineStyle(QCPGraph::lsLine); // No line connecting points
        graph(0)->setBrush(QColor(30, 144, 255, 150)); // Set color and transparency for bars

        // Populate data vectors
        int i = 0;
        for (auto it = data.constBegin(); it != data.constEnd(); ++it) {
            xAxisLbl.append(i + 1); // Assign numeric index for each label
            yAxisLbl.append(it->second); // Use the value as y-axis data
            xAxisLabels.append(it->first); // Store label for x-axis
            ++i;
        }

        // Set data for bars
        bars->setData(xAxisLbl, yAxisLbl);

        // Set labels on x-axis
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(xAxisLbl, xAxisLabels);
        xAxis->setTickLabelRotation(-80); // Rotate labels by -80 degrees

        xAxis->setTicker(textTicker);

        rescaleAxes();

        replot();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred during data update: " << e.what() << std::endl;
    }
}

QString BarChart::toolTipText(double xAxisLblVal, double yAxisLblVal)
{
    QString tooltipText;
    try {
        tooltipText = QString(xAxis->label()+": %1 "+
                                      yAxis->label()+": %2").arg(xAxisLblVal).arg(yAxisLblVal);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during data update: " << e.what() << std::endl;
    }
    return tooltipText;
}

QString BarChart::toolTipText(QString xAxisLblVal, double yAxisLblVal)
{
    QString tooltipText;
    try {
        tooltipText = QString(xAxis->label()+"%1 | "+
                                      yAxis->label()+" %2").arg(xAxisLblVal).arg(yAxisLblVal);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during data update: " << e.what() << std::endl;
    }
    return tooltipText;
}

void BarChart::showToolTip(QMouseEvent *event)
{
    try {

        // Get the position of the mouse cursor
        QPoint pos = event->pos();

        // Convert the pixel coordinates to coordinates on the plot
        double xPixel = pos.x();
        double yPixel = pos.y();

        // Find the nearest bar to the mouse cursor
        double minDistanceSquared = std::numeric_limits<double>::max();
        int closestIndex = -1;
        for (int i = 0; i < xAxisLbl.size(); ++i) {
            double xData = xAxisLbl[i];
            double yData = yAxisLbl[i];

            // Convert bar coordinates to pixel coordinates
            double xPixelData = xAxis->coordToPixel(xData);
            double yPixelData = yAxis->coordToPixel(yData);

            // Calculate squared Euclidean distance between mouse cursor and bar
            double distanceSquared = pow(xPixel - xPixelData, 2) + pow(yPixel - yPixelData, 2);

            // Update closest bar if it's within a threshold distance
            if (distanceSquared < minDistanceSquared) {
                minDistanceSquared = distanceSquared;
                closestIndex = i;
            }
        }

        // Check if the closest bar is within a certain threshold distance (e.g., 10 pixels)
        if (closestIndex != -1 && minDistanceSquared < 100) {

            QString tooltipText;

            double offset = 2; // Adjust this value as needed
            double tooltipX = pos.x() + offset;
            double tooltipY = pos.y() + offset;

            // Format tooltip text
            if(identifierType == identifier::DoubleDouble){
                tooltipText= toolTipText(xAxisLbl[closestIndex], yAxisLbl[closestIndex]);
                // Display tooltip at the mouse cursor position
                QToolTip::showText(mapToGlobal(QPoint(tooltipX, tooltipY)), tooltipText, this);
            } else if (identifierType == identifier::QStringDouble){
                tooltipText= toolTipText(xAxisLabels[closestIndex], yAxisLbl[closestIndex]);
                // Display tooltip at the mouse cursor position
                QToolTip::showText(mapToGlobal(QPoint(tooltipX, tooltipY)), tooltipText, this);
            } else{
                // Hide tooltip if not hovering over any bar
                QToolTip::hideText();
            }

        } else {
            // Hide tooltip if not hovering over any bar
            QToolTip::hideText();
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void BarChart::clearGraph()
{
    try {
        xAxisLabels.clear();
        yAxisLbl.clear();
        xAxisLbl.clear();
        clearGraphs();
        clearItems();
        clearGraphs();
        clearPlottables();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

BarChart::~BarChart()
{
}

void BarChart::setUpUIForLiveData()
{
}

void BarChart::updateData(const QList<QPair<QDateTime, double>> &data, GraphStyle graph)
{
}

void BarChart::updateLiveData(QDateTime dateTime, double value, GraphStyle graph)
{
}

void BarChart::setSeprationLineAccToYAxis(double lowerBoundryVal, double upperBoundryVal)
{
}

void BarChart::updateData(const QList<QPair<int, int>> &data)
{
}

void BarChart::updateData(const QList<QPair<QString, int>> &data)
{
}
