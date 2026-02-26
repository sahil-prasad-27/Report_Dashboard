/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainVerticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout;
    QWidget *radioWidget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbCurrent;
    QRadioButton *rbDate;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_6;
    QVBoxLayout *vl_sc;
    QLabel *labelSessionCount;
    QHBoxLayout *hl_sc;
    QLabel *iconSessionCount;
    QLabel *valSessionCount;
    QFrame *frame_2;
    QVBoxLayout *vl_se;
    QLabel *labelSessionEff;
    QHBoxLayout *hl_se;
    QLabel *iconSortingEff;
    QLabel *valSortingEff;
    QFrame *frame_3;
    QVBoxLayout *vl_sr;
    QLabel *lableSelectedRecepie;
    QHBoxLayout *hl_sr;
    QLabel *iconSelectedRecepie;
    QLabel *valSelectedRecepie;
    QFrame *frame_4;
    QVBoxLayout *vl_oo;
    QLabel *lableObjectOverlap;
    QHBoxLayout *hl_oo;
    QLabel *iconObjectOveLap;
    QLabel *label;
    QFrame *frame_5;
    QVBoxLayout *vl_fd;
    QLabel *lableSessionCount_6;
    QHBoxLayout *hl_fd;
    QLabel *labelSessionValue_11;
    QLabel *valFiringDirection;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_7;
    QFrame *frame_8;
    QVBoxLayout *timingVLayout;
    QFrame *frame_11;
    QVBoxLayout *vl_start;
    QFrame *frame_9;
    QHBoxLayout *hl_timing_header;
    QLabel *labelSessionTiming;
    QLabel *labelStart;
    QHBoxLayout *hl_start;
    QLabel *iconStart;
    QLabel *valStart;
    QFrame *frame_10;
    QVBoxLayout *vl_end;
    QLabel *labelEnd;
    QHBoxLayout *hl_end;
    QLabel *iconEnd;
    QLabel *valEnd;
    QFrame *frame_12;
    QVBoxLayout *vl_total;
    QLabel *labelTotalTime;
    QHBoxLayout *hl_total;
    QLabel *iconTotalTime;
    QLabel *valTotalTIme;
    QFrame *frame_13;
    QVBoxLayout *vl_actual;
    QLabel *labelActualTime;
    QHBoxLayout *hl_actual;
    QLabel *iconActualTime;
    QLabel *valActualTime;
    QHBoxLayout *tablesLayout;
    QFrame *frame_15;
    QVBoxLayout *vl_fired;
    QLabel *label_2;
    QTableView *tableView;
    QFrame *frame_16;
    QVBoxLayout *vl_nonfired;
    QLabel *label_3;
    QTableView *tableView_2;
    QWidget *page_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbCurrent_2;
    QRadioButton *rbDateRange;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QLineEdit *dateRangeEdit;
    QToolButton *calendarButton;
    QPushButton *pushButton;
    QTableView *tableView_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1217, 802);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainVerticalLayout = new QVBoxLayout(centralwidget);
        mainVerticalLayout->setSpacing(6);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(10, 10, 10, 10);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout = new QVBoxLayout(page_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioWidget = new QWidget(page_3);
        radioWidget->setObjectName(QString::fromUtf8("radioWidget"));
        horizontalLayout_3 = new QHBoxLayout(radioWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rbCurrent = new QRadioButton(radioWidget);
        rbCurrent->setObjectName(QString::fromUtf8("rbCurrent"));
        QFont font;
        font.setPointSize(16);
        rbCurrent->setFont(font);

        horizontalLayout_3->addWidget(rbCurrent);

        rbDate = new QRadioButton(radioWidget);
        rbDate->setObjectName(QString::fromUtf8("rbDate"));
        rbDate->setFont(font);

        horizontalLayout_3->addWidget(rbDate);


        verticalLayout->addWidget(radioWidget);

        frame = new QFrame(page_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {\n"
"    background-color: #e9eaec;\n"
"    border-radius: 6px;\n"
"}"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 8, 8, 8);
        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy1);
        frame_6->setMinimumSize(QSize(0, 70));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame#frame_6 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_6->setFrameShape(QFrame::NoFrame);
        vl_sc = new QVBoxLayout(frame_6);
        vl_sc->setSpacing(4);
        vl_sc->setObjectName(QString::fromUtf8("vl_sc"));
        vl_sc->setContentsMargins(10, 6, 10, 6);
        labelSessionCount = new QLabel(frame_6);
        labelSessionCount->setObjectName(QString::fromUtf8("labelSessionCount"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelSessionCount->setFont(font1);

        vl_sc->addWidget(labelSessionCount);

        hl_sc = new QHBoxLayout();
        hl_sc->setObjectName(QString::fromUtf8("hl_sc"));
        iconSessionCount = new QLabel(frame_6);
        iconSessionCount->setObjectName(QString::fromUtf8("iconSessionCount"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(iconSessionCount->sizePolicy().hasHeightForWidth());
        iconSessionCount->setSizePolicy(sizePolicy2);
        iconSessionCount->setMinimumSize(QSize(40, 40));
        iconSessionCount->setMaximumSize(QSize(40, 40));
        iconSessionCount->setPixmap(QPixmap(QString::fromUtf8("icons8-report-50(1).png")));
        iconSessionCount->setScaledContents(true);

        hl_sc->addWidget(iconSessionCount);

        valSessionCount = new QLabel(frame_6);
        valSessionCount->setObjectName(QString::fromUtf8("valSessionCount"));

        hl_sc->addWidget(valSessionCount);


        vl_sc->addLayout(hl_sc);


        horizontalLayout->addWidget(frame_6);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_2->setFrameShape(QFrame::NoFrame);
        vl_se = new QVBoxLayout(frame_2);
        vl_se->setSpacing(4);
        vl_se->setObjectName(QString::fromUtf8("vl_se"));
        vl_se->setContentsMargins(10, 6, 10, 6);
        labelSessionEff = new QLabel(frame_2);
        labelSessionEff->setObjectName(QString::fromUtf8("labelSessionEff"));
        labelSessionEff->setFont(font1);

        vl_se->addWidget(labelSessionEff);

        hl_se = new QHBoxLayout();
        hl_se->setObjectName(QString::fromUtf8("hl_se"));
        iconSortingEff = new QLabel(frame_2);
        iconSortingEff->setObjectName(QString::fromUtf8("iconSortingEff"));
        sizePolicy2.setHeightForWidth(iconSortingEff->sizePolicy().hasHeightForWidth());
        iconSortingEff->setSizePolicy(sizePolicy2);
        iconSortingEff->setMinimumSize(QSize(40, 40));
        iconSortingEff->setMaximumSize(QSize(40, 40));
        iconSortingEff->setPixmap(QPixmap(QString::fromUtf8("icons8-graph-24(1).png")));
        iconSortingEff->setScaledContents(true);

        hl_se->addWidget(iconSortingEff);

        valSortingEff = new QLabel(frame_2);
        valSortingEff->setObjectName(QString::fromUtf8("valSortingEff"));

        hl_se->addWidget(valSortingEff);


        vl_se->addLayout(hl_se);


        horizontalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setStyleSheet(QString::fromUtf8("QFrame#frame_3 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_3->setFrameShape(QFrame::NoFrame);
        vl_sr = new QVBoxLayout(frame_3);
        vl_sr->setSpacing(4);
        vl_sr->setObjectName(QString::fromUtf8("vl_sr"));
        vl_sr->setContentsMargins(10, 6, 10, 6);
        lableSelectedRecepie = new QLabel(frame_3);
        lableSelectedRecepie->setObjectName(QString::fromUtf8("lableSelectedRecepie"));
        lableSelectedRecepie->setFont(font1);

        vl_sr->addWidget(lableSelectedRecepie);

        hl_sr = new QHBoxLayout();
        hl_sr->setObjectName(QString::fromUtf8("hl_sr"));
        iconSelectedRecepie = new QLabel(frame_3);
        iconSelectedRecepie->setObjectName(QString::fromUtf8("iconSelectedRecepie"));
        sizePolicy2.setHeightForWidth(iconSelectedRecepie->sizePolicy().hasHeightForWidth());
        iconSelectedRecepie->setSizePolicy(sizePolicy2);
        iconSelectedRecepie->setMinimumSize(QSize(40, 40));
        iconSelectedRecepie->setMaximumSize(QSize(40, 40));
        iconSelectedRecepie->setPixmap(QPixmap(QString::fromUtf8("icons8-tick-50(1).png")));
        iconSelectedRecepie->setScaledContents(true);

        hl_sr->addWidget(iconSelectedRecepie);

        valSelectedRecepie = new QLabel(frame_3);
        valSelectedRecepie->setObjectName(QString::fromUtf8("valSelectedRecepie"));

        hl_sr->addWidget(valSelectedRecepie);


        vl_sr->addLayout(hl_sr);


        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setStyleSheet(QString::fromUtf8("QFrame#frame_4 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_4->setFrameShape(QFrame::NoFrame);
        vl_oo = new QVBoxLayout(frame_4);
        vl_oo->setSpacing(4);
        vl_oo->setObjectName(QString::fromUtf8("vl_oo"));
        vl_oo->setContentsMargins(10, 6, 10, 6);
        lableObjectOverlap = new QLabel(frame_4);
        lableObjectOverlap->setObjectName(QString::fromUtf8("lableObjectOverlap"));
        lableObjectOverlap->setFont(font1);

        vl_oo->addWidget(lableObjectOverlap);

        hl_oo = new QHBoxLayout();
        hl_oo->setObjectName(QString::fromUtf8("hl_oo"));
        iconObjectOveLap = new QLabel(frame_4);
        iconObjectOveLap->setObjectName(QString::fromUtf8("iconObjectOveLap"));
        sizePolicy2.setHeightForWidth(iconObjectOveLap->sizePolicy().hasHeightForWidth());
        iconObjectOveLap->setSizePolicy(sizePolicy2);
        iconObjectOveLap->setMinimumSize(QSize(40, 40));
        iconObjectOveLap->setMaximumSize(QSize(40, 40));
        iconObjectOveLap->setPixmap(QPixmap(QString::fromUtf8("overlap(2).png")));
        iconObjectOveLap->setScaledContents(true);

        hl_oo->addWidget(iconObjectOveLap);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));

        hl_oo->addWidget(label);


        vl_oo->addLayout(hl_oo);


        horizontalLayout->addWidget(frame_4);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setStyleSheet(QString::fromUtf8("QFrame#frame_5 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_5->setFrameShape(QFrame::NoFrame);
        vl_fd = new QVBoxLayout(frame_5);
        vl_fd->setSpacing(4);
        vl_fd->setObjectName(QString::fromUtf8("vl_fd"));
        vl_fd->setContentsMargins(10, 6, 10, 6);
        lableSessionCount_6 = new QLabel(frame_5);
        lableSessionCount_6->setObjectName(QString::fromUtf8("lableSessionCount_6"));
        lableSessionCount_6->setFont(font1);

        vl_fd->addWidget(lableSessionCount_6);

        hl_fd = new QHBoxLayout();
        hl_fd->setObjectName(QString::fromUtf8("hl_fd"));
        labelSessionValue_11 = new QLabel(frame_5);
        labelSessionValue_11->setObjectName(QString::fromUtf8("labelSessionValue_11"));
        sizePolicy2.setHeightForWidth(labelSessionValue_11->sizePolicy().hasHeightForWidth());
        labelSessionValue_11->setSizePolicy(sizePolicy2);
        labelSessionValue_11->setMinimumSize(QSize(40, 40));
        labelSessionValue_11->setMaximumSize(QSize(40, 40));
        labelSessionValue_11->setPixmap(QPixmap(QString::fromUtf8("overlap(2).png")));
        labelSessionValue_11->setScaledContents(true);

        hl_fd->addWidget(labelSessionValue_11);

        valFiringDirection = new QLabel(frame_5);
        valFiringDirection->setObjectName(QString::fromUtf8("valFiringDirection"));

        hl_fd->addWidget(valFiringDirection);


        vl_fd->addLayout(hl_fd);


        horizontalLayout->addWidget(frame_5);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_7 = new QFrame(page_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy1.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy1);
        frame_7->setStyleSheet(QString::fromUtf8("QFrame#frame_7 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #ddd;\n"
"}"));
        frame_7->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(frame_7);

        frame_8 = new QFrame(page_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy1.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy1);
        frame_8->setFrameShape(QFrame::NoFrame);
        timingVLayout = new QVBoxLayout(frame_8);
        timingVLayout->setSpacing(8);
        timingVLayout->setObjectName(QString::fromUtf8("timingVLayout"));
        timingVLayout->setContentsMargins(10, 8, 10, 8);
        frame_11 = new QFrame(frame_8);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy3);
        frame_11->setStyleSheet(QString::fromUtf8("QFrame#frame_11 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_11->setFrameShape(QFrame::NoFrame);
        vl_start = new QVBoxLayout(frame_11);
        vl_start->setSpacing(4);
        vl_start->setObjectName(QString::fromUtf8("vl_start"));
        vl_start->setContentsMargins(12, 6, 12, 6);
        frame_9 = new QFrame(frame_11);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame#frame_9 {\n"
"    background-color: #e5f0f8;\n"
"    border-radius: 8px;\n"
"}"));
        frame_9->setFrameShape(QFrame::NoFrame);
        hl_timing_header = new QHBoxLayout(frame_9);
        hl_timing_header->setObjectName(QString::fromUtf8("hl_timing_header"));
        hl_timing_header->setContentsMargins(10, 4, 10, 4);
        labelSessionTiming = new QLabel(frame_9);
        labelSessionTiming->setObjectName(QString::fromUtf8("labelSessionTiming"));
        labelSessionTiming->setFont(font1);
        labelSessionTiming->setStyleSheet(QString::fromUtf8("QLabel { background-color: transparent; }"));

        hl_timing_header->addWidget(labelSessionTiming);


        vl_start->addWidget(frame_9);

        labelStart = new QLabel(frame_11);
        labelStart->setObjectName(QString::fromUtf8("labelStart"));
        labelStart->setFont(font1);

        vl_start->addWidget(labelStart);

        hl_start = new QHBoxLayout();
        hl_start->setObjectName(QString::fromUtf8("hl_start"));
        iconStart = new QLabel(frame_11);
        iconStart->setObjectName(QString::fromUtf8("iconStart"));
        sizePolicy2.setHeightForWidth(iconStart->sizePolicy().hasHeightForWidth());
        iconStart->setSizePolicy(sizePolicy2);
        iconStart->setMinimumSize(QSize(30, 30));
        iconStart->setMaximumSize(QSize(30, 30));
        iconStart->setPixmap(QPixmap(QString::fromUtf8("icons8-time-30.png")));
        iconStart->setScaledContents(true);

        hl_start->addWidget(iconStart);

        valStart = new QLabel(frame_11);
        valStart->setObjectName(QString::fromUtf8("valStart"));

        hl_start->addWidget(valStart);


        vl_start->addLayout(hl_start);


        timingVLayout->addWidget(frame_11);

        frame_10 = new QFrame(frame_8);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        sizePolicy3.setHeightForWidth(frame_10->sizePolicy().hasHeightForWidth());
        frame_10->setSizePolicy(sizePolicy3);
        frame_10->setStyleSheet(QString::fromUtf8("QFrame#frame_10 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_10->setFrameShape(QFrame::NoFrame);
        vl_end = new QVBoxLayout(frame_10);
        vl_end->setSpacing(4);
        vl_end->setObjectName(QString::fromUtf8("vl_end"));
        vl_end->setContentsMargins(12, 6, 12, 6);
        labelEnd = new QLabel(frame_10);
        labelEnd->setObjectName(QString::fromUtf8("labelEnd"));
        labelEnd->setFont(font1);

        vl_end->addWidget(labelEnd);

        hl_end = new QHBoxLayout();
        hl_end->setObjectName(QString::fromUtf8("hl_end"));
        iconEnd = new QLabel(frame_10);
        iconEnd->setObjectName(QString::fromUtf8("iconEnd"));
        sizePolicy2.setHeightForWidth(iconEnd->sizePolicy().hasHeightForWidth());
        iconEnd->setSizePolicy(sizePolicy2);
        iconEnd->setMinimumSize(QSize(30, 30));
        iconEnd->setMaximumSize(QSize(30, 30));
        iconEnd->setPixmap(QPixmap(QString::fromUtf8("icons8-time-30.png")));
        iconEnd->setScaledContents(true);

        hl_end->addWidget(iconEnd);

        valEnd = new QLabel(frame_10);
        valEnd->setObjectName(QString::fromUtf8("valEnd"));

        hl_end->addWidget(valEnd);


        vl_end->addLayout(hl_end);


        timingVLayout->addWidget(frame_10);

        frame_12 = new QFrame(frame_8);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        sizePolicy3.setHeightForWidth(frame_12->sizePolicy().hasHeightForWidth());
        frame_12->setSizePolicy(sizePolicy3);
        frame_12->setStyleSheet(QString::fromUtf8("QFrame#frame_12 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_12->setFrameShape(QFrame::NoFrame);
        vl_total = new QVBoxLayout(frame_12);
        vl_total->setSpacing(4);
        vl_total->setObjectName(QString::fromUtf8("vl_total"));
        vl_total->setContentsMargins(12, 6, 12, 6);
        labelTotalTime = new QLabel(frame_12);
        labelTotalTime->setObjectName(QString::fromUtf8("labelTotalTime"));
        labelTotalTime->setFont(font1);

        vl_total->addWidget(labelTotalTime);

        hl_total = new QHBoxLayout();
        hl_total->setObjectName(QString::fromUtf8("hl_total"));
        iconTotalTime = new QLabel(frame_12);
        iconTotalTime->setObjectName(QString::fromUtf8("iconTotalTime"));
        sizePolicy2.setHeightForWidth(iconTotalTime->sizePolicy().hasHeightForWidth());
        iconTotalTime->setSizePolicy(sizePolicy2);
        iconTotalTime->setMinimumSize(QSize(30, 30));
        iconTotalTime->setMaximumSize(QSize(30, 30));
        iconTotalTime->setPixmap(QPixmap(QString::fromUtf8("icons8-hourglass-30.png")));
        iconTotalTime->setScaledContents(true);

        hl_total->addWidget(iconTotalTime);

        valTotalTIme = new QLabel(frame_12);
        valTotalTIme->setObjectName(QString::fromUtf8("valTotalTIme"));

        hl_total->addWidget(valTotalTIme);


        vl_total->addLayout(hl_total);


        timingVLayout->addWidget(frame_12);

        frame_13 = new QFrame(frame_8);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        sizePolicy3.setHeightForWidth(frame_13->sizePolicy().hasHeightForWidth());
        frame_13->setSizePolicy(sizePolicy3);
        frame_13->setStyleSheet(QString::fromUtf8("QFrame#frame_13 {\n"
"    background-color: white;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}"));
        frame_13->setFrameShape(QFrame::NoFrame);
        vl_actual = new QVBoxLayout(frame_13);
        vl_actual->setSpacing(4);
        vl_actual->setObjectName(QString::fromUtf8("vl_actual"));
        vl_actual->setContentsMargins(12, 6, 12, 6);
        labelActualTime = new QLabel(frame_13);
        labelActualTime->setObjectName(QString::fromUtf8("labelActualTime"));
        labelActualTime->setFont(font1);

        vl_actual->addWidget(labelActualTime);

        hl_actual = new QHBoxLayout();
        hl_actual->setObjectName(QString::fromUtf8("hl_actual"));
        iconActualTime = new QLabel(frame_13);
        iconActualTime->setObjectName(QString::fromUtf8("iconActualTime"));
        sizePolicy2.setHeightForWidth(iconActualTime->sizePolicy().hasHeightForWidth());
        iconActualTime->setSizePolicy(sizePolicy2);
        iconActualTime->setMinimumSize(QSize(30, 30));
        iconActualTime->setMaximumSize(QSize(30, 30));
        iconActualTime->setPixmap(QPixmap(QString::fromUtf8("icons8-stopwatch-30.png")));
        iconActualTime->setScaledContents(true);

        hl_actual->addWidget(iconActualTime);

        valActualTime = new QLabel(frame_13);
        valActualTime->setObjectName(QString::fromUtf8("valActualTime"));

        hl_actual->addWidget(valActualTime);


        vl_actual->addLayout(hl_actual);


        timingVLayout->addWidget(frame_13);


        horizontalLayout_2->addWidget(frame_8);


        verticalLayout->addLayout(horizontalLayout_2);

        tablesLayout = new QHBoxLayout();
        tablesLayout->setSpacing(10);
        tablesLayout->setObjectName(QString::fromUtf8("tablesLayout"));
        frame_15 = new QFrame(page_3);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        sizePolicy1.setHeightForWidth(frame_15->sizePolicy().hasHeightForWidth());
        frame_15->setSizePolicy(sizePolicy1);
        frame_15->setFrameShape(QFrame::NoFrame);
        vl_fired = new QVBoxLayout(frame_15);
        vl_fired->setSpacing(6);
        vl_fired->setObjectName(QString::fromUtf8("vl_fired"));
        vl_fired->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame_15);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        vl_fired->addWidget(label_2);

        tableView = new QTableView(frame_15);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        vl_fired->addWidget(tableView);


        tablesLayout->addWidget(frame_15);

        frame_16 = new QFrame(page_3);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        sizePolicy1.setHeightForWidth(frame_16->sizePolicy().hasHeightForWidth());
        frame_16->setSizePolicy(sizePolicy1);
        frame_16->setFrameShape(QFrame::NoFrame);
        vl_nonfired = new QVBoxLayout(frame_16);
        vl_nonfired->setSpacing(6);
        vl_nonfired->setObjectName(QString::fromUtf8("vl_nonfired"));
        vl_nonfired->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_16);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        vl_nonfired->addWidget(label_3);

        tableView_2 = new QTableView(frame_16);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        vl_nonfired->addWidget(tableView_2);


        tablesLayout->addWidget(frame_16);


        verticalLayout->addLayout(tablesLayout);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout = new QGridLayout(page_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbCurrent_2 = new QRadioButton(page_4);
        rbCurrent_2->setObjectName(QString::fromUtf8("rbCurrent_2"));
        sizePolicy.setHeightForWidth(rbCurrent_2->sizePolicy().hasHeightForWidth());
        rbCurrent_2->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(rbCurrent_2);

        rbDateRange = new QRadioButton(page_4);
        rbDateRange->setObjectName(QString::fromUtf8("rbDateRange"));
        sizePolicy.setHeightForWidth(rbDateRange->sizePolicy().hasHeightForWidth());
        rbDateRange->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(rbDateRange);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox = new QComboBox(page_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMaxVisibleItems(10);

        horizontalLayout_5->addWidget(comboBox);

        dateRangeEdit = new QLineEdit(page_4);
        dateRangeEdit->setObjectName(QString::fromUtf8("dateRangeEdit"));
        dateRangeEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(dateRangeEdit);

        calendarButton = new QToolButton(page_4);
        calendarButton->setObjectName(QString::fromUtf8("calendarButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(calendarButton->sizePolicy().hasHeightForWidth());
        calendarButton->setSizePolicy(sizePolicy4);

        horizontalLayout_5->addWidget(calendarButton);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        pushButton = new QPushButton(page_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        tableView_3 = new QTableView(page_4);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tableView_3->sizePolicy().hasHeightForWidth());
        tableView_3->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(tableView_3, 3, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        mainVerticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        rbCurrent->setText(QApplication::translate("MainWindow", "Current Session", nullptr));
        rbDate->setText(QApplication::translate("MainWindow", "Date Range", nullptr));
        labelSessionCount->setText(QApplication::translate("MainWindow", "Session Count", nullptr));
        iconSessionCount->setText(QString());
        valSessionCount->setText(QString());
        labelSessionEff->setText(QApplication::translate("MainWindow", "Sorting Efficiency", nullptr));
        iconSortingEff->setText(QString());
        valSortingEff->setText(QString());
        lableSelectedRecepie->setText(QApplication::translate("MainWindow", "Selected Recipe", nullptr));
        iconSelectedRecepie->setText(QString());
        valSelectedRecepie->setText(QString());
        lableObjectOverlap->setText(QApplication::translate("MainWindow", "Object Overlap", nullptr));
        iconObjectOveLap->setText(QString());
        label->setText(QString());
        lableSessionCount_6->setText(QApplication::translate("MainWindow", "Firing Direction", nullptr));
        labelSessionValue_11->setText(QString());
        valFiringDirection->setText(QString());
        labelSessionTiming->setText(QApplication::translate("MainWindow", "Session Timing Details", nullptr));
        labelStart->setText(QApplication::translate("MainWindow", "Start time", nullptr));
        iconStart->setText(QString());
        valStart->setText(QString());
        labelEnd->setText(QApplication::translate("MainWindow", "End time", nullptr));
        iconEnd->setText(QString());
        valEnd->setText(QString());
        labelTotalTime->setText(QApplication::translate("MainWindow", "Total Time", nullptr));
        iconTotalTime->setText(QString());
        valTotalTIme->setText(QString());
        labelActualTime->setText(QApplication::translate("MainWindow", "Actual Time", nullptr));
        iconActualTime->setText(QString());
        valActualTime->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Fired Objects", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Non Fired Objects", nullptr));
        rbCurrent_2->setText(QApplication::translate("MainWindow", "Current Session", nullptr));
        rbDateRange->setText(QApplication::translate("MainWindow", "Date Range", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Session wise", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Date wise", nullptr));

        calendarButton->setText(QApplication::translate("MainWindow", "\360\237\223\205", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
