//
// Created by xx on 3/12/23.
//

#include "FormCreadit.hpp"

QGroupBox * init_box(QButtonGroup* radio) {
    auto groupBox = new QGroupBox("Тип");
    auto *radio1 = new QRadioButton("аннуитетный",groupBox);
    auto *radio2 = new QRadioButton("дифференцированный",groupBox);
    radio->addButton(radio1,Aut);
    radio->addButton(radio2,Diff);
    radio1->setChecked(true);
    auto lay = new QVBoxLayout;
    lay->addWidget(radio1);
    lay->addWidget(radio2);
    groupBox->setAlignment(4);
    groupBox->setLayout(lay);
    return groupBox;
}

FormCreadit::FormCreadit() {

    radio = new QButtonGroup;
    check = init_box(radio);

    date = new QLineEdit();
    date->setValidator(new QDoubleValidator);
    all_summ = new QLineEdit();
    all_summ->setValidator(new QDoubleValidator);
    procent = new QLineEdit();
    procent->setValidator(new QDoubleValidator);
    init_form();
}
void FormCreadit::init_form() {
    addRow("Общая сумма кредита:", this->all_summ);
    addRow("Процентная ставка:", procent);
    addRow("Срок(в месяцах):", this->date);
    addRow(check);
}

data_form_part2 FormCreadit::clean_data() {
    data_form_part2 data = {0};
    data.check = radio->checkedId();// 0 or 1
    data.procent = procent->text().toDouble();
    data.summ = all_summ->text().toDouble();
    data.manth = date->text().toDouble();
    return data;
}
FormResult::FormResult() {
    pay_math = new  QLabel;
    over_cred= new QLabel;
   summ_all= new QLabel;
   err = new QLabel;
    addRow(err);
    addRow("Eжемесячный платеж:", pay_math);
    addRow("Переплата по кредиту:", over_cred);
    addRow("Общая выплата:", summ_all);
}

TabsViewCreadit::TabsViewCreadit() {
    root = new QVBoxLayout(this);
    c_api = new CreditApi;
    fp = new FormCreadit;
    result = new FormResult;
    root->addLayout(fp);
    auto but = new QPushButton("=");
    root->addWidget(but);
    root->addLayout(result);
    connect(but, SIGNAL(clicked()), this, SLOT(show_result()));
}
void TabsViewCreadit::show_result() {
//    ежемесячный платеж, переплата по кредиту, общая выплата
    auto data = fp->clean_data();
        auto val = this->c_api->process_credit(data);
        if(val.err)
            result->err->setText(QString("ERR REPL:: ").append(QString::fromStdString(val.err)));
        else {
            result->summ_all->setNum(val.summ_all);
            result->over_cred->setNum(val.over_cred);
            result->pay_math->setNum(val.pay_math);
            result->err->setText("Успешный расчет");
        }
    }
