//
// Created by xx on 3/13/23.
//

#include "FormDebit.hpp"

FormDebit::FormDebit() {
    summ = new QLineEdit();
    summ->setValidator(new QDoubleValidator);
    manth = new QLineEdit();
    manth->setValidator(new QDoubleValidator);
    procent = new QLineEdit();
    procent->setValidator(new QDoubleValidator);
    nalog = new QLineEdit();
    nalog->setValidator(new QDoubleValidator);
    period = new QLineEdit();
    period->setValidator(new QDoubleValidator);
    cap_procent = new QLineEdit();
    cap_procent->setValidator(new QDoubleValidator);

    init_form();
}

void FormDebit::init_form() {
    addRow("сумма вклада:", summ);
    addRow("срок размещения:", manth);
    addRow("процентная ставка:", procent);
    addRow("налоговая ставка:", nalog);
    addRow("периодичность выплат:", period);
    addRow("капитализация процентов:", cap_procent);
//    addRow("список пополнений:", list_add);
//    addRow("список частичных снятий:", list_add_simple);
}

data_form_part3 FormDebit::clean_data() {
    data_form_part3 data = {0};
    data.summ = summ->text().toDouble();
    data.manth = manth->text().toDouble();
    data.procent = procent->text().toDouble();
    data.nalog = nalog->text().toDouble();
    data.period = period->text().toDouble();
    data.cap_procent = cap_procent->text().toDouble();
    return data;
}

FormResult2::FormResult2() {
    err = new QLabel;
    procent = new QLabel;
    summ_nalog = new QLabel;
    summ_all = new QLabel;
    addRow(err);
    addRow("начисленные проценты:", procent);
    addRow("сумма налога:", summ_nalog);
    addRow("сумма на вкладе к концу срока:", summ_all);
}

TabsViewDebit::TabsViewDebit() {
    root = new QVBoxLayout(this);
    c_api = new CreditApi;
    fp = new FormDebit;
    result = new FormResult2;
    root->addLayout(fp);
    auto but = new QPushButton("=");
    root->addWidget(but);
    root->addLayout(result);
    connect(but, SIGNAL(clicked()), this, SLOT(show_result()));
}

void TabsViewDebit::show_result() {
    auto data = fp->clean_data();
    auto val = this->c_api->process_debit(data);
    if (val.err)
        result->err->setText(QString("ERR REPL:: ").append(QString::fromStdString(val.err)));
    else {
        result->procent->setNum(val.pay_math);
        result->summ_nalog->setNum(val.over_cred);
        result->summ_all->setNum(val.summ_all);
        result->err->setText("Успешный расчет");
    }
}
