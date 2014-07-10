/**
 * @file	mainwindow.h
 * @brief	Authorization window header (auto generated)
 * @author  mnxoid
 *
 * Copyright 2014 by mnxoid,
 *
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief       Main window class
 **/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief       MainWindow constructor
     * @param       [in]    parent - Window parent
     **/
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief       MainWindow destructor
     **/
    ~MainWindow();
    
private slots:
    /**
     * @brief       Exit button click handler
     **/
    void on_pushButton_2_clicked();
    /**
     * @brief       Login button click handler
     **/
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui; //!< User interface reference
};

#endif // MAINWINDOW_H
