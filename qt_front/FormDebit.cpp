//
// Created by xx on 3/13/23.
//

#include "FormDebit.hpp"

QGroupBox *FormDebit::init_box(QButtonGroup *radio) {
    auto groupBox = new QGroupBox("Тип");
    auto *radio1 = new QRadioButton("В конце срока", groupBox);
    auto *radio2 = new QRadioButton("раз в месяц", groupBox);
    auto *radio3 = new QRadioButton("раз в год", groupBox);
    radio->addButton(radio1, 0);
    radio->addButton(radio2, 1);
    radio->addButton(radio3, 2);
    radio1->setChecked(true);
    auto lay = new QVBoxLayout;
    lay->addWidget(radio1);
    lay->addWidget(radio2);
    lay->addWidget(radio3);
    groupBox->setAlignment(4);
    groupBox->setLayout(lay);
    return groupBox;
}

FormDebit::FormDebit() {
    summ = new QLineEdit();
    summ->setValidator(new QDoubleValidator);
    manth = new QLineEdit();
    manth->setValidator(new QDoubleValidator);
    procent = new QLineEdit();
    procent->setValidator(new QDoubleValidator);
    nalog = new QLineEdit();
    nalog->setValidator(new QDoubleValidator);
    radio = new QButtonGroup;
    period = init_box(radio);
    cap_procent = new QCheckBox();
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
    data_form_part3 data = {0,0,0,0,0,0,0,0,0};
    data.summ = summ->text().toDouble();
    data.manth = manth->text().toDouble();
    data.procent = procent->text().toDouble();
    data.nalog = nalog->text().toDouble();
    data.period = (double) radio->checkedId();
    data.cap_procent = (double) cap_procent->isChecked();
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
