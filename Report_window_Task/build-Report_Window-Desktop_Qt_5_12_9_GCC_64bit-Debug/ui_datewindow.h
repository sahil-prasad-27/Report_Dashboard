/********************************************************************************
** Form generated from reading UI file 'datewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEWINDOW_H
#define UI_DATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QToolButton *calendarButton;
    QTableView *tableView;
    QRadioButton *rbCurrent;
    QLineEdit *dateRangeEdit;
    QRadioButton *rbDateRange;

    void setupUi(QMainWindow *DateWindow)
    {
        if (DateWindow->objectName().isEmpty())
            DateWindow->setObjectName(QString::fromUtf8("DateWindow"));
        DateWindow->resize(1213, 569);
        centralwidget = new QWidget(DateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 2, 0, 1, 4);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMaxVisibleItems(10);

        gridLayout->addWidget(comboBox, 1, 0, 1, 2);

        calendarButton = new QToolButton(centralwidget);
        calendarButton->setObjectName(QString::fromUtf8("calendarButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendarButton->sizePolicy().hasHeightForWidth());
        calendarButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(calendarButton, 1, 3, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(tableView, 3, 0, 1, 4);

        rbCurrent = new QRadioButton(centralwidget);
        rbCurrent->setObjectName(QString::fromUtf8("rbCurrent"));
        sizePolicy.setHeightForWidth(rbCurrent->sizePolicy().hasHeightForWidth());
        rbCurrent->setSizePolicy(sizePolicy);

        gridLayout->addWidget(rbCurrent, 0, 0, 1, 1);

        dateRangeEdit = new QLineEdit(centralwidget);
        dateRangeEdit->setObjectName(QString::fromUtf8("dateRangeEdit"));
        dateRangeEdit->setReadOnly(true);

        gridLayout->addWidget(dateRangeEdit, 1, 2, 1, 1);

        rbDateRange = new QRadioButton(centralwidget);
        rbDateRange->setObjectName(QString::fromUtf8("rbDateRange"));
        sizePolicy.setHeightForWidth(rbDateRange->sizePolicy().hasHeightForWidth());
        rbDateRange->setSizePolicy(sizePolicy);

        gridLayout->addWidget(rbDateRange, 0, 1, 1, 1);

        DateWindow->setCentralWidget(centralwidget);
        tableView->raise();
        comboBox->raise();
        dateRangeEdit->raise();
        calendarButton->raise();
        rbCurrent->raise();
        rbDateRange->raise();
        pushButton->raise();

        retranslateUi(DateWindow);

        QMetaObject::connectSlotsByName(DateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DateWindow)
    {
        DateWindow->setWindowTitle(QApplication::translate("DateWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("DateWindow", "Search", nullptr));
        comboBox->setItemText(0, QApplication::translate("DateWindow", "Session wise", nullptr));
        comboBox->setItemText(1, QApplication::translate("DateWindow", "Date wise", nullptr));

        calendarButton->setText(QApplication::translate("DateWindow", "\360\237\223\205", nullptr));
        rbCurrent->setText(QApplication::translate("DateWindow", "Current Session", nullptr));
        rbDateRange->setText(QApplication::translate("DateWindow", "Date Range", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateWindow: public Ui_DateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEWINDOW_H
