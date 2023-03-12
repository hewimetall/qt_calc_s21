#ifndef QT_CALC_CORE_H
#define QT_CALC_CORE_H
enum {
    Aut,
    Diff
};

typedef struct {
    int manth;
    double summ;
    double procent;
    short check;
}data_form;

typedef struct {
    double pay_math;
    double over_cred;
    double summ_all;
    char* err;
}data_result;

data_result get_credit(data_form data);
data_result get_debit(data_form data);


#endif //QT_CALC_CORE_H
