//
// Created by xx on 3/12/23.
//

#ifndef QT_CALC_SIMPLE_CREADIT_H
#define QT_CALC_SIMPLE_CREADIT_H
extern "C" {
    #include <api_credit_core.h>
};

class CreditApi {
public:
    data_result process_credit(data_form data);
    data_result process_debit(data_form data);
};
#endif //QT_CALC_SIMPLE_CREADIT_H
