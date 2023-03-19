//
// Created by xx on 3/12/23.
//


#include "headers/api_credit_core.h"
/**
 * @brief: Годовая капитолизация.
 * */
data_result __yerl(data_form_part3 data) {
    double  S = data.summ;
    double preb = 0., preb_nalog = 0.;
    int yerl = (int) data.manth;
    data_result res = {0};
    for (int i = 0; i < yerl; ++i) {
        preb += S*data.procent;
        preb_nalog += preb * data.nalog;
        preb-= preb * data.nalog;
        if(data.cap_procent)
        S+=preb, preb = 0;
    }
    res.summ_all = S + preb;
    res.over_cred = preb_nalog;
    res.pay_math = res.summ_all - data.summ;
    return res;
}

/**
 * @brief: В конце срока.
 * */
data_result __end(data_form_part3 data) {
    double  S = data.summ;
    data_result res = {0};
    double preb = S * data.procent;
    double preb_nalog = preb * data.nalog;
    preb -= preb_nalog;
    S += preb;
    res.summ_all = S;
    res.over_cred = preb_nalog;
    res.pay_math = S - data.summ;
    return res;
}

/**
 * @brief: В конце месяца.
 * */
data_result __month(data_form_part3 data) {
    double  S = data.summ;
    double  S_proc = 0;
    double preb = 0;
    double preb_nalog = 0;
    int yerl = (int) data.manth;
    data_result res = {0};
    for (int i = 0; i < yerl*12; ++i) {
        preb = S * (data.procent/12.);
        preb -= preb * data.nalog;
        preb_nalog +=preb * data.nalog;
        S_proc +=preb;
        if(data.cap_procent)
            S += preb;

    }
    res.summ_all = S + S_proc;
    res.over_cred = preb_nalog;
    res.pay_math = S_proc;
    return res;
}


data_result get_debit(data_form_part3 data) {
    data_result res = {0};
    data.procent = data.procent/100.0;
    data.nalog = data.nalog/100.0;

    switch ((int)data.period) {
        case 1:
            res = __month(data);
            break;
        case 2:
            res = __yerl(data);
            break;
        default:
            res = __end(data);
    }
    return res;
}
