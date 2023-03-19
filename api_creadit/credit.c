//
// Created by xx on 3/12/23.
//

#include "headers/api_credit_core.h"
#include <math.h>

double annuity(double k, double p) {
    double t = pow(p + 1, k);
    return p * t / (t - 1);
}

data_result __annuity(data_form_part2 data) {
    data_result res = {0};
    data.procent /=  12. * 100.;
    data.period *=12.;

    double a = data.summ * annuity(data.period, data.procent);
    double s = data.summ;
    double over = 0;
    while (s >0) {
        double ds =  a - s*data.procent;
        over += a-ds;
        s -= ds;

        printf("%.2f-ds:%.2lf\n", s,ds);
    }
    res.pay_math = a;
    res.over_cred =over;
    res.summ_all = over + data.summ;
    return res;
}
data_result __debit(data_form_part2 data) {
    data_result res = {0};
    double mp_cnt = data.period * 12.;
    double rest = data.summ;
    double mp_real = rest / mp_cnt;
    while (mp_cnt > 0) {
        double mp = mp_real + (rest * data.procent / 1200);
        res.summ_all += mp;
        rest -= mp_real;
        mp_cnt -= 1;
    }
    res.pay_math = 0;
    res.over_cred = res.summ_all - data.summ;
    return res;
}
data_result get_credit(data_form_part2 data){
    data_result  res = {0};
    if(data.check) res = __debit(data);
    else res = __annuity(data);
    return res;
}