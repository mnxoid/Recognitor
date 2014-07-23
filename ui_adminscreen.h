/********************************************************************************
** Form generated from reading UI file 'adminscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSCREEN_H
#define UI_ADMINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminScreen
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QMainWindow *AdminScreen)
    {
        if (AdminScreen->objectName().isEmpty())
            AdminScreen->setObjectName(QStringLiteral("AdminScreen"));
        AdminScreen->resize(519, 332);
        centralwidget = new QWidget(AdminScreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 256, 311));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(290, 10, 221, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        AdminScreen->setCentralWidget(centralwidget);

        retranslateUi(AdminScreen);

        QMetaObject::connectSlotsByName(AdminScreen);
    } // setupUi

    void retranslateUi(QMainWindow *AdminScreen)
    {
        AdminScreen->setWindowTitle(QApplication::translate("AdminScreen", "Administration Mode", 0));
        pushButton_2->setText(QApplication::translate("AdminScreen", "Add User", 0));
        pushButton_3->setText(QApplication::translate("AdminScreen", "Edit User", 0));
        pushButton_4->setText(QApplication::translate("AdminScreen", "Delete User", 0));
        pushButton->setText(QApplication::translate("AdminScreen", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminScreen: public Ui_AdminScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSCREEN_H
