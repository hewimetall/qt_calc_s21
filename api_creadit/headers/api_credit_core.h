#ifndef QT_CALC_CORE_H
#define QT_CALC_CORE_H
enum {
    Aut,
    Diff
};

typedef struct {
    double period;
    double summ;
    double procent;
    short check;
}data_form_part2;

typedef struct {
    double summ;
    double manth;
    double procent;
    double nalog;
    double period;
    double cap_procent;
    double* list_add;
    double* list_add_simple;
    short check;
}data_form_part3;

typedef struct {
    double pay_math;
    double over_cred;
    double summ_all;
    char* err;
}data_result;

data_result get_credit(data_form_part2 data);
data_result get_debit(data_form_part3 data);

#endif //QT_CALC_CORE_H
