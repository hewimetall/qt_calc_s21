//
// Created by xx on 3/13/23.
//

#ifndef QT_CALC_FORMDEBIT_H
#define QT_CALC_FORMDEBIT_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QList>
#include "simple_creadit.hpp"


class FormDebit: public QFormLayout {
Q_OBJECT
public:
    FormDebit();
    data_form_part3 clean_data();
private:
    QLineEdit* summ;
    QLineEdit* manth;
    QLineEdit* procent;
    QLineEdit* nalog;
    QLineEdit* period;
    QLineEdit* cap_procent;
//    double* list_add;
//    double* list_add_simple;
protected:
    void init_form();
};

class FormResult2: public QFormLayout {
Q_OBJECT
public:
    FormResult2();
    QLabel* err;
    QLabel* procent;
    QLabel* summ_nalog;
    QLabel* summ_all;
};

class TabsViewDebit: public QWidget {
Q_OBJECT
public:
    TabsViewDebit();
public slots:
    void show_result();
private:
    FormDebit *fp;
    QVBoxLayout* root;
    FormResult2* result;
    CreditApi* c_api;
};

#endif //QT_CALC_FORMDEBIT_H
