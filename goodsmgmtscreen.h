/**
 * @file	goodsmgmtscreen.h
 * @brief	Goods management window header
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

#ifndef GOODSMGMTSCREEN_H
#define GOODSMGMTSCREEN_H

#include <QMainWindow>

namespace Ui {
class GoodsMgmtScreen;
}
/**
 * @brief       Goods Management window class
 **/
class GoodsMgmtScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief       GoodsMgmtScreen constructor
     * @param       [in]    parent - Window parent
     **/
    explicit GoodsMgmtScreen(QWidget *parent = 0);
    /**
     * @brief       GoodsMgmtScreen destructor
     **/
    ~GoodsMgmtScreen();
    
private slots:
    /**
     * @brief       Add Item button click handler
     **/
    void on_pushButton_clicked();

    /**
     * @brief       Edit Item button click handler
     **/
    void on_pushButton_2_clicked();

    /**
     * @brief       Remove Item button click handler
     **/
    void on_pushButton_3_clicked();

    /**
     * @brief       Exit button click handler
     **/
    void on_pushButton_4_clicked();

private:
    Ui::GoodsMgmtScreen *ui; //!< User interface reference
};

#endif // GOODSMGMTSCREEN_H
