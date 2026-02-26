#include "lineChart.h"

LineChart::LineChart(QWidget * parent ) : GraphCustomPlot(parent)
{
    try {
        initUiAndInsertIntoLayout();
        connectSignalSlots();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::setSeprationLineAccToYAxis(double lowerBoundryVal, double upperBoundryVal){
    try {
        lowerBoundry=lowerBoundryVal;
        upperBoundry=upperBoundryVal;
        QCPItemStraightLine *_currentValueAtUpper = new QCPItemStraightLine(this);
        _currentValueAtUpper->setPen(QPen(Qt::gray));
        _currentValueAtUpper->point1->setCoords(xAxis->range().lower, upperBoundry);
        _currentValueAtUpper->point2->setCoords(xAxis->range().upper, upperBoundry);

        QCPItemStraightLine *_currentValueAtLower = new QCPItemStraightLine(this);
        _currentValueAtLower->setPen(QPen(Qt::gray));
        _currentValueAtLower->point1->setCoords(xAxis->range().lower, lowerBoundry);
        _currentValueAtLower->point2->setCoords(xAxis->range().upper, lowerBoundry);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::initUiAndInsertIntoLayout(){
    try {
        setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
        axisRect()->setRangeZoom(Qt::Horizontal);
        setBackground(QBrush(Qt::transparent));
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

}

void LineChart::connectSignalSlots(){
    try {
        connect(this, &QCustomPlot::mouseMove, this, &LineChart::showToolTip);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::clearGraph()
{
    try {
        xCoordinates.clear();
        yCoordinates.clear();
        // Clear existing data from customplot
        clearItems();
        clearGraphs();
        clearPlottables();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

LineChart::~LineChart()
{
    try {
        qDebug()<<"line chart destructor [enterd]"<<endl;

        dateTicker.reset(nullptr);

        qDebug()<<"line chart destructor [finished]"<<endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::updateData(const QList<QPair<QDateTime, double>> &data, GraphStyle graphType){
    try {

        setUpGraph();

        for (const auto& pair : data) {
            xCoordinates.append(pair.first);
            yCoordinates.append(pair.second);
        }

        if(graphType == GraphStyle::default_){
            addGraph();

            if (xCoordinates.isEmpty() || yCoordinates.isEmpty()) {
            } else {
                for (int i = 0; i < xCoordinates.size(); ++i) {
                    graph(0)->addData(xCoordinates[i].toSecsSinceEpoch(), yCoordinates[i]);
                    graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 4));
                }
            }

            if (!xCoordinates.isEmpty()) {
                xAxis->rescale();
                // Set the x-axis range
                xAxis->setRange(xCoordinates.first().toSecsSinceEpoch(), xCoordinates.last().toSecsSinceEpoch());
                // Set the tick label font size
                onXAxisRangeChangedFun();
                xAxis->setTickLabelFont(QFont(QFont().family(), 9));
                xAxis->setTickLabelRotation(0);
                double minX = xAxis->range().lower;
                double maxX = xAxis->range().upper;
                initialXAxisRange = QCPRange(minX, maxX);
            }

            // Replot the graph
        } else if (graphType == GraphStyle::ColorGraph_RedGreen){
            colorGraphLogic(); // 875 microseconds [execution time for 500 datapoints]
        }
        replot();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::setUpGraph(){
    try {
        setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
        axisRect()->setRangeZoom(Qt::Horizontal);
        handleZoomEvent();

        // Clear existing data
        xCoordinates.clear();
        yCoordinates.clear();

        // Enable mouse tracking to show tooltips
        setMouseTracking(true);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}


// -- set ui for live data in line chart

void LineChart::setUpUIForLiveData()
{
    try {
        // in live graph disable graph zoom in and drag mousewheel events
        setInteraction(QCP::iRangeDrag, false);
        setInteraction(QCP::iRangeZoom, false);
        disconnect(this, &QCustomPlot::mouseWheel, this, nullptr);

        // Set up the x-axis ticker
        dateTicker.reset(new QCPAxisTickerDateTime);
        dateTicker->setDateTimeFormat("hh:mm:ss");

        // Calculate the range to cover the next 60 seconds starting from the current time
        QDateTime currentTime = QDateTime::currentDateTime();
        QDateTime startTime = currentTime;
        QDateTime endTime = startTime.addSecs(60); // Add 60 seconds to cover 1 minute interval
        xAxis->setRange(startTime.toMSecsSinceEpoch() / 1000.0, endTime.toMSecsSinceEpoch() / 1000.0);
        xAxis->setTickLabelRotation(-80);
        xAxis->setTicker(dateTicker);

        dateTicker->setTickCount(30); // Set tick count to 30 for one label every 2 seconds
        dateTicker->setTickStepStrategy(QCPAxisTicker::tssReadability);
        xAxis->setTickLabelFont(QFont(QFont().family(), 9));

        // clear all the data of vectors
        xCoordinates.clear();
        yCoordinates.clear();

        // Enable mouse tracking to show tooltips
        setMouseTracking(true);

        // set x axis initial range
        double minX = xAxis->range().lower;
        double maxX = xAxis->range().upper;
        initialXAxisRange = QCPRange(minX, maxX);

        restrictXAxisEntriesLiveGraph = 0; // variable restrict only 60 entries to show in live graph

    }  catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::updateLiveData(QDateTime currentTime, double value, GraphStyle graphType){
    try {
        if(graphType == GraphStyle::default_){

            // Check if the graph exists, otherwise create it
            if (graphCount() == 0) {
                addGraph();
            }

            if (restrictXAxisEntriesLiveGraph < 60) {
                xCoordinates.push_back(currentTime);
                yCoordinates.push_back(value);
                // Do nothing if less than 60 data points
                restrictXAxisEntriesLiveGraph++;
            } else {
                // Shift x-axis range
                QCPRange range = xAxis->range();
                xAxis->setRange(range.lower+1, range.upper + 1);
                qDebug() << range.upper << " " << value << endl;

                if(liveDataLimit>59){
                    liveDataLimit=0;
                }

                // Remove the first data point from the graph if it exceeds the limit
                if (graph(0)->data()->size() >= 60) {
                    // Get the key of the first data point
                    double firstKey = graph(0)->data()->begin()->key;

                    // Remove the first data point from the graph
                    graph(0)->data()->remove(firstKey);

                    // If there are scatter points, remove the first one
                    if (!graph()->data()->isEmpty()) {
                        graph()->data()->remove(firstKey);
                    }
                }

                xCoordinates[liveDataLimit]=currentTime;
                yCoordinates[liveDataLimit]=value;
            }

            liveDataLimit++;

            graph(0)->addData(currentTime.toMSecsSinceEpoch() / 1000.0 , value);
            graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 8));

            replot(); // Replot the graph

        } else if(graphType == GraphStyle::ColorGraph_RedGreen){
            // Update y-axis range -- according to button wise requirement
            // setYAxisRange(); -- check where to put

            //fetch previous value of coordinates from json
            if(prevx==""&& prevy==-1){
                prevx = currentTime.toString().toStdString();
                prevy = value;
                return;
            }

            // Check if the graph exists, otherwise create it
            if (graphCount() == 0) {
                addGraph();
            }

            if (restrictXAxisEntriesLiveGraph < 60) {
                xCoordinates.push_back(currentTime);
                yCoordinates.push_back(value);
                // Do nothing if less than 60 data points
                restrictXAxisEntriesLiveGraph++;
            } else {
                // Shift x-axis range
                QCPRange range = xAxis->range();
                xAxis->setRange(range.lower+1, range.upper + 1);
                qDebug() << range.upper << " " << value << endl;

                if(liveDataLimit>59){
                    liveDataLimit=0;
                    dataPointIndex=0;
                }

                for(int i=0;i<liveGraphDataPointLimit[dataPointIndex];i++){
                    removeItem(0);
                }

                if(liveDataLimit==0)
                {
                    setSeprationLineAccToYAxis(lowerBoundry,upperBoundry);
                }

                xCoordinates[liveDataLimit]=currentTime;
                yCoordinates[liveDataLimit]=value;
            }

            liveDataLimit++;

            std::cout<<currentTime.toString("dd-MM-yyyy hh:mm:ss").toStdString()<<prevy<<" "<<value<<std::endl;
            colorGraphLogicLiveData(QDateTime::fromString(QString::fromStdString(prevx), "dd-MM-yyyy hh:mm:ss"),prevy,currentTime,value);

            replot(); // Replot the graph

            prevx = currentTime.toString().toStdString();
            prevy = value;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::colorGraphLogicLiveData(QDateTime prevx, double prevy, QDateTime currentTime, double currentValue) {
    try {

        // logic to set color in live graph
        double midX = 0.0;
        if (prevy >= upperBoundry && currentValue >= upperBoundry) {
            drawLine(Qt::red, prevx, prevy, currentTime, currentValue,true, true);
            liveGraphDataPointLimit[dataPointIndex]=3;
        }
        else if (prevy >= upperBoundry && currentValue >= lowerBoundry && currentValue < upperBoundry) {
            midX = prevx.toMSecsSinceEpoch() / 1000.0 + (upperBoundry - prevy) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::red, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX * 1000), upperBoundry, true);
            drawLine(Qt::green, QDateTime::fromMSecsSinceEpoch(midX * 1000), upperBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=4;
        }
        else if (prevy >= upperBoundry && currentValue < lowerBoundry) {
            double midX1 = prevx.toMSecsSinceEpoch() / 1000.0 + (upperBoundry - prevy) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            double midX2 = currentTime.toMSecsSinceEpoch() / 1000.0 - (currentValue - lowerBoundry) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::red, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX1 * 1000), upperBoundry, true);
            drawLine(Qt::green, QDateTime::fromMSecsSinceEpoch(midX1 * 1000), upperBoundry, QDateTime::fromMSecsSinceEpoch(midX2 * 1000), lowerBoundry);
            drawLine(Qt::red, QDateTime::fromMSecsSinceEpoch(midX2 * 1000), lowerBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=5;
        }
        else if (prevy >= lowerBoundry && prevy < upperBoundry && currentValue >= upperBoundry) {
            midX = prevx.toMSecsSinceEpoch() / 1000.0 + (upperBoundry - prevy) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::green, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX * 1000), upperBoundry, true);
            drawLine(Qt::red, QDateTime::fromMSecsSinceEpoch(midX * 1000), upperBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=4;
        }
        else if (prevy >= lowerBoundry && prevy < upperBoundry && currentValue < lowerBoundry) {
            midX = prevx.toMSecsSinceEpoch() / 1000.0 + (lowerBoundry - prevy) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::green, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, true);
            drawLine(Qt::red, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=4;
        } else if (prevy >= lowerBoundry && prevy < upperBoundry && currentValue >= lowerBoundry && currentValue < upperBoundry) {
            drawLine(Qt::green, prevx, prevy, currentTime, currentValue, true, true);
            liveGraphDataPointLimit[dataPointIndex]=3;
        }
        else if (prevy < lowerBoundry && currentValue < lowerBoundry) {
            drawLine(Qt::red, prevx, prevy, currentTime, currentValue, true, true);
            liveGraphDataPointLimit[dataPointIndex]=3;
        }
        else if (prevy < lowerBoundry && currentValue >= lowerBoundry && currentValue < upperBoundry) {
            midX = currentTime.toMSecsSinceEpoch() / 1000.0 - (currentValue - lowerBoundry) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::red, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, true);
            drawLine(Qt::green, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=4;
        }
        else if (prevy < lowerBoundry && currentValue >= upperBoundry) {
            midX = prevx.toMSecsSinceEpoch() / 1000.0 + (lowerBoundry - prevy) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            double midX2 = currentTime.toMSecsSinceEpoch() / 1000.0 - (currentValue - upperBoundry) / ((currentValue - prevy) / (currentTime.toMSecsSinceEpoch() / 1000.0 - prevx.toMSecsSinceEpoch() / 1000.0));
            drawLine(Qt::red, prevx, prevy, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, true);
            drawLine(Qt::green, QDateTime::fromMSecsSinceEpoch(midX * 1000), lowerBoundry, QDateTime::fromMSecsSinceEpoch(midX2 * 1000), upperBoundry);
            drawLine(Qt::red, QDateTime::fromMSecsSinceEpoch(midX2 * 1000), upperBoundry, currentTime, currentValue, false, true);
            liveGraphDataPointLimit[dataPointIndex]=5;
        }
        replot();
        dataPointIndex++;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::drawLine(const QColor &color, const QDateTime &startX, double startY, const QDateTime &endX, double endY,  bool startCount , bool endCount ) {
    try {
        double startXSecs = startX.toMSecsSinceEpoch() / 1000.0;
        double startYCoord = startY;
        double endXSecs = endX.toMSecsSinceEpoch() / 1000.0;
        double endYCoord = endY;

        QCPItemLine *line = new QCPItemLine(this);
        line->start->setCoords(startXSecs, startYCoord);
        line->end->setCoords(endXSecs, endYCoord);
        line->setPen(QPen(color));

        // to make circle at data point coordinate
        double circleRadius = 0.01; // Adjust the radius of the circle here
        if (startCount == true) {
            QCPItemLine *startCircle = new QCPItemLine(this);
            startCircle->setPen(QPen(Qt::black)); // Set circle color
            startCircle->start->setCoords(startXSecs - circleRadius / 2, startYCoord);
            startCircle->end->setCoords(startXSecs + circleRadius / 2, startYCoord); // End point adjusted to form a circle
            startCircle->setHead(QCPLineEnding::esDisc); // Set line ending to a disc to form a circle
        }
        if (endCount == true) {
            QCPItemLine *endCircle = new QCPItemLine(this);
            endCircle->setPen(QPen(Qt::black)); // Set circle color
            endCircle->start->setCoords(endXSecs - circleRadius / 2, endYCoord);
            endCircle->end->setCoords(endXSecs + circleRadius / 2, endYCoord); // End point adjusted to form a circle
            endCircle->setHead(QCPLineEnding::esDisc); // Set line ending to a disc to form a circle
        }

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::colorGraphLogic(){
    try {
        // add colored whole graph in static line chart
        if (xCoordinates.isEmpty() || yCoordinates.isEmpty()) {
        } else {
            int i = 0;

            while (i < xCoordinates.size()) {
                if (yCoordinates[i] > upperBoundry) {

                    QCPGraph *subGraph1 = addGraph();

                    while (i < xCoordinates.size() && yCoordinates[i] > upperBoundry) {
                        subGraph1->setPen(QPen(Qt::red));
                        subGraph1->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        subGraph1->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        i++;
                    }
                    if (i < xCoordinates.size() && i != 0 && yCoordinates[i - 1] > upperBoundry && yCoordinates[i] < upperBoundry) {
                        QCPGraph *subGraph5 = addGraph();

                        subGraph5->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        double m = (yCoordinates[i] - yCoordinates[i - 1]) / ((xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0));
                        double midX = (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0) + ((upperBoundry - yCoordinates[i - 1]) / m);
                        subGraph5->setPen(QPen(Qt::red));
                        subGraph5->addData(xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0, yCoordinates[i - 1]);
                        subGraph5->addData(midX, upperBoundry);
                        if (yCoordinates[i] < lowerBoundry) {
                            QCPGraph *subGraph3 = addGraph();

                            subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                            subGraph3->setPen(QPen(Qt::green));
                            subGraph3->addData(midX, upperBoundry);
                            double midY = (xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - ((yCoordinates[i] - lowerBoundry) / m);
                            subGraph3->addData(midY, lowerBoundry);
                            QCPGraph *subGraph4 = addGraph();

                            subGraph4->setPen(QPen(Qt::red));
                            subGraph4->addData(midY, lowerBoundry);
                            subGraph4->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        } else {
                            QCPGraph *subGraph3 = addGraph();

                            subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                            subGraph3->setPen(QPen(Qt::green));
                            subGraph3->addData(midX, upperBoundry);
                            subGraph3->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        }
                    }
                    subGraph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 4));
                } else if (yCoordinates[i] < upperBoundry && yCoordinates[i] > lowerBoundry) {
                    QCPGraph *subGraph2 = addGraph();

                    subGraph2->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                    while (i < xCoordinates.size() && yCoordinates[i] < upperBoundry && yCoordinates[i] > lowerBoundry) {
                        subGraph2->setPen(QPen(Qt::green));
                        subGraph2->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        i++;
                    }
                    if (i < xCoordinates.size() && i != 0 && yCoordinates[i - 1] < upperBoundry && yCoordinates[i - 1] > lowerBoundry && yCoordinates[i] > upperBoundry) {
                        QCPGraph *subGraph5 = addGraph();

                        subGraph5->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        double m = (yCoordinates[i] - yCoordinates[i - 1]) / ((xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0));
                        double midX = (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0) + ((upperBoundry - yCoordinates[i - 1]) / m);
                        subGraph5->setPen(QPen(Qt::green));
                        subGraph5->addData(xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0, yCoordinates[i - 1]);
                        subGraph5->addData(midX, upperBoundry);
                        QCPGraph *subGraph3 = addGraph();

                        subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        subGraph3->setPen(QPen(Qt::red));
                        subGraph3->addData(midX, upperBoundry);
                        subGraph3->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                    } else if (i < xCoordinates.size() && i != 0 && yCoordinates[i - 1] < upperBoundry && yCoordinates[i - 1] > lowerBoundry && yCoordinates[i] < lowerBoundry) {
                        QCPGraph *subGraph5 = addGraph();

                        double m = (yCoordinates[i] - yCoordinates[i - 1]) / ((xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0));
                        double midX = (xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - ((yCoordinates[i] - lowerBoundry) / m);
                        subGraph5->setPen(QPen(Qt::green));
                        subGraph5->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        subGraph5->addData(xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0, yCoordinates[i - 1]);
                        subGraph5->addData(midX, lowerBoundry);
                        QCPGraph *subGraph3 = addGraph();

                        subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        subGraph3->setPen(QPen(Qt::red));
                        subGraph3->addData(midX, lowerBoundry);
                        subGraph3->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                    }
                    subGraph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 4));
                } else {
                    QCPGraph *subGraph1 = addGraph();

                    subGraph1->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                    while (i < xCoordinates.size() && yCoordinates[i] < lowerBoundry) {
                        subGraph1->setPen(QPen(Qt::red));
                        subGraph1->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        i++;
                    }
                    if (i < xCoordinates.size() && i != 0 && yCoordinates[i - 1] < lowerBoundry && yCoordinates[i] > lowerBoundry) {
                        QCPGraph *subGraph5 = addGraph();

                        subGraph5->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                        double m = (yCoordinates[i] - yCoordinates[i - 1]) / ((xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - (xCoordinates[i- 1].toMSecsSinceEpoch() / 1000.0));
                        double midX = (xCoordinates[i].toMSecsSinceEpoch() / 1000.0) - ((yCoordinates[i] - lowerBoundry) / m);
                        subGraph5->setPen(QPen(Qt::red));
                        subGraph5->addData(xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0, yCoordinates[i - 1]);
                        subGraph5->addData(midX, lowerBoundry);
                        if (yCoordinates[i] > upperBoundry) {
                            QCPGraph *subGraph3 = addGraph();

                            subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                            subGraph3->setPen(QPen(Qt::green));
                            subGraph3->addData(midX, lowerBoundry);
                            double midY = (xCoordinates[i - 1].toMSecsSinceEpoch() / 1000.0) + ((upperBoundry - yCoordinates[i - 1]) / m);
                            subGraph3->addData(midY, upperBoundry);
                            QCPGraph *subGraph4 = addGraph();

                            subGraph4->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                            subGraph4->setPen(QPen(Qt::red));
                            subGraph4->addData(midY, upperBoundry);
                            subGraph4->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        } else {
                            QCPGraph *subGraph3 = addGraph();

                            subGraph3->setPen(QPen(Qt::green));
                            subGraph3->setSelectable(QCP::SelectionType::stNone); // Make the graph not selectable

                            subGraph3->addData(midX, lowerBoundry);
                            subGraph3->addData(xCoordinates[i].toMSecsSinceEpoch() / 1000.0, yCoordinates[i]);
                        }
                    }
                    subGraph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::black, Qt::black, 4));
                }
            }
        }
        if (!xCoordinates.isEmpty()) {
            xAxis->rescale();
            QDateTime minX = *std::min_element(xCoordinates.constBegin(), xCoordinates.constEnd());
            QDateTime maxX = *std::max_element(xCoordinates.constBegin(), xCoordinates.constEnd());
            xAxis->setRange(minX.toMSecsSinceEpoch() / 1000.0, maxX.toMSecsSinceEpoch() / 1000.0);
            onXAxisRangeChangedFun();
            xAxis->setTickLabelFont(QFont(QFont().family(), 9));
            xAxis->setTickLabelRotation(0);

            setSeprationLineAccToYAxis(lowerBoundry,upperBoundry);

            double minValX = xAxis->range().lower;
            double maxValX = xAxis->range().upper;
            initialXAxisRange = QCPRange(minValX, maxValX);
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::handleZoomEvent(){
    try {
        double minX = xAxis->range().lower;
        double maxX = xAxis->range().upper;
        initialXAxisRange = QCPRange(minX, maxX);

        //parentWidget()->setAttribute(Qt::WA_AcceptTouchEvents);
        //is it work ????? in touch screen

        connect(this, &QCustomPlot::mouseWheel, this, [=](QWheelEvent *event) {
            // Check if Ctrl key is pressed for more precise zooming
            bool ctrlPressed = event->modifiers() & Qt::ControlModifier;
            // Check if the wheel event leads to zooming in or out
            double factor = event->angleDelta().y() > 0 ? 1.02 : 0.98;
            // Ensure the X-axis cannot be zoomed out beyond the initial range *2
            if (xAxis->range().size() >= initialXAxisRange.size()*2) {
                xAxis->setRange(initialXAxisRange);
            }

            if (xAxis->range().size() <5) {
                xAxis->setRange(initialXAxisRange);
            }
            // Zoom in or out
            xAxis->scaleRange(factor, xAxis->pixelToCoord(event->pos().x()));
            onXAxisRangeChangedFun();
        });

    }  catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::onXAxisRangeChangedFun()
{
    try {
        // Get the current range size in seconds
        double rangeSeconds = xAxis->range().size();
        QString tickerFormat;
        if (rangeSeconds > 2 * 365 * 24 * 60 * 60) { // More than 10 years
            tickerFormat = "yyyy"; // Show only year
        } else if (rangeSeconds > 60 * 24 * 60 * 60) { // More than 2 months
            tickerFormat = "yyyy-MM"; // Show year and month
        } else if (rangeSeconds > 1 * 24 * 60 * 60) { // More than 1 days
            tickerFormat = "yyyy-MM-dd"; // Show year, month, and day
        } else { // Less than 1 days
            tickerFormat = "hh:mm:ss"; // Show time
        }
        // Update the date ticker format
        dateTicker.reset(new QCPAxisTickerDateTime);
        dateTicker->setDateTimeFormat(tickerFormat);
        dateTicker->setTickCount(4); // Set the number of ticks for the initial view
        xAxis->setTicker(dateTicker);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

void LineChart::showToolTip(QMouseEvent *event) {
    try {
//        // Get the position of the mouse cursor
//        QPoint pos = event->pos();
//        // Convert the pixel coordinates to coordinates on the plot
//        double xPixel = pos.x();
//        double yPixel = pos.y();
//        // Find the nearest data point to the mouse cursor
//        double minDistanceSquared = std::numeric_limits<double>::max();
//        int closestIndex = -1;
//        for (int i = 0; i < xCoordinates.size(); ++i) {

//            double xData = xCoordinates[i].toSecsSinceEpoch();
//            double yData = yCoordinates[i];

//            // Convert data point coordinates to pixel coordinates
//            double xPixelData = xAxis->coordToPixel(xData);
//            double yPixelData = yAxis->coordToPixel(yData);
//            // Calculate squared Euclidean distance between mouse cursor and data point
//            double distanceSquared = pow(xPixel - xPixelData, 2) + pow(yPixel - yPixelData, 2);
//            // Update closest data point if it's within a threshold distance
//            if (distanceSquared < minDistanceSquared) {
//                minDistanceSquared = distanceSquared;
//                closestIndex = i;
//            }
//        }
//        // Check if the closest data point is within a certain threshold distance (e.g., 10 pixels)
//        if (closestIndex != -1 && minDistanceSquared < 100) {
//            // Get information about the closest data point
//            QDateTime dateTime = xCoordinates[closestIndex];
//            double yAxisData = yCoordinates[closestIndex];
//            // Format tooltip text
//            QString tooltipText = QString("Date-Time: %1\n"+QString::fromStdString("value")+": %2").arg(dateTime.toString("yyyy-MM-dd hh:mm:ss")).arg(yAxisData);
//            double offset = 2; // Adjust this value as needed
//            double tooltipX = xAxis->coordToPixel(xCoordinates[closestIndex].toSecsSinceEpoch()) + offset;
//            double tooltipY = yAxis->coordToPixel(yCoordinates[closestIndex]) + offset;
//            // Display tooltip at the mouse cursor position
//            QToolTip::showText(mapToGlobal(QPoint(tooltipX, tooltipY)), tooltipText, this);
//        } else {
//            // Hide tooltip if not hovering over any data point
//            QToolTip::hideText();
//        }
//        replot();
        if (graphCount() == 0)
                return;

            QCPGraph *g = graph(0);
            if (!g || g->data()->isEmpty())
                return;

            double x = xAxis->pixelToCoord(event->pos().x());

            auto it = g->data()->findBegin(x);
            if (it == g->data()->end())
                return;

            double xValue = it->key;
            double yValue = it->value;

            QString tooltipText;

            // If using DateTime axis
            if (xAxis->ticker().data() &&
                dynamic_cast<QCPAxisTickerDateTime*>(xAxis->ticker().data()))
            {
                QDateTime dt = QDateTime::fromMSecsSinceEpoch(xValue * 1000);
                tooltipText = QString("Date-Time: %1 | Value: %2")
                                .arg(dt.toString("yyyy-MM-dd hh:mm:ss"))
                                .arg(yValue);
            }
            else
            {
                tooltipText = QString("X: %1 | Y: %2")
                                .arg(xValue)
                                .arg(yValue);
            }

            QToolTip::showText(event->globalPos(), tooltipText, this);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

}

void LineChart::updateData(const QList<QPair<double, double>> &data){
    this->clearGraphs();
        this->addGraph();

        QVector<double> x, y;
        for (const auto& p : data) {
            x.append(p.first);
            y.append(p.second);
        }
        this->graph(0)->setData(x, y);

        this->xAxis->rescale();
        this->yAxis->rescale();
        this->replot();
}

void LineChart::updateData(const QList<QPair<QString, double>> &data){
    this->clearGraphs();
        this->addGraph();

        QVector<double> x;
        QVector<double> y;

        for (int i = 0; i < data.size(); ++i) {
            x.append(i);
            y.append(data[i].second);
        }

        this->graph(0)->setData(x, y);

        // Create a text ticker for string labels
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < data.size(); ++i) {
            textTicker->addTick(i, data[i].first);
        }

        this->xAxis->setTicker(textTicker); // assign ticker
        this->xAxis->setTickLabelRotation(45);

        // Rescale axes
        this->xAxis->setRange(-0.5, x.size() - 0.5);
        this->yAxis->rescale();

        this->replot();
}

void LineChart::updateData(const QList<QPair<int, int>> &data){

}

void LineChart::updateData(const QList<QPair<QString, int>> &data){

}
