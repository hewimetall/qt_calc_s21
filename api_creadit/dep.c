//
// Created by xx on 3/12/23.
//


#include "headers/api_credit_core.h"

data_result get_debit(data_form_part3 data) {
    data_result res = {0};
    return res;
}

//int deposit_calc(data_form_part3 *data) {
//    // S=(P*I*j:K):100
//    int bug = 0;
//    double inter;
//    data->interest = 0;
//    data->output = 0;
//    data->total_tax = 0;
//    data->input += (data->add_list[0]+data->add_list[1]+data->add_list[3]);
//    data->input -= (data->subtract_list[0]+data->subtract_list[1]+data->subtract_list[3]);
//    if (data->input < 0) {
//        bug = 1;
//    } else {
//        if (!data->capitalization) {
//            for (int k = 0; k < data->period; k++) {
//                inter = data->input*data->perc*30.417/365/100;
//                data->total_tax += inter*data->tax/100;
//                data->interest += inter;
//            }
//            data->output = data->input;
//        } else {
//            int cap;
//            if (data->frequency == 0)
//                cap = 1;    // ежемесячная капитализация
//            else if (data->frequency == 1)
//                cap = 3;    // ежеквартальная капитализация
//            else if (data->frequency == 2)
//                cap = 12;   // ежегодная капитализация
//            double p = 0;
//            for (int k = 0; k < data->period; k++) {
//                if (!(k%cap))
//                    p = data->interest;
//                inter = ((data->input + p)*data->perc*30.417/365/100);
//                data->total_tax += inter*data->tax/100;
//                inter -= inter * data->tax/100;
//                data->interest += inter;
//            }
//            data->output = data->input + data->interest;
//            data->interest += data->total_tax;
//        }
//    }
//    return bug;
//}

