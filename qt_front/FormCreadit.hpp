//
// Created by xx on 3/12/23.
//

#ifndef QT_CALC_FORMCREADIT_H
#define QT_CALC_FORMCREADIT_H

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


class FormCreadit: public QFormLayout {
Q_OBJECT
public:
    FormCreadit();
    data_form_part2 clean_data();
private:
    QLineEdit* date;
    QLineEdit* all_summ;
    QLineEdit* procent;
    QGroupBox* check;
    QButtonGroup* radio;
protected:
    void init_form();
};

class FormResult: public QFormLayout {
Q_OBJECT
public:
    FormResult();
    QLabel* err;
    QLabel* pay_math;
    QLabel* over_cred;
    QLabel* summ_all;
};

class TabsViewCreadit: public QWidget {
Q_OBJECT
public:
    TabsViewCreadit();
public slots:
    void show_result();
private:
    FormCreadit *fp;
    QVBoxLayout* root;
    FormResult* result;
    CreditApi* c_api;
};

#endif //QT_CALC_FORMCREADIT_H
