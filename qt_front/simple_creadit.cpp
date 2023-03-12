//
// Created by xx on 3/12/23.
//

#include "simple_creadit.hpp"

data_result CreditApi::process_credit(data_form data){
    return get_credit(data);
}
data_result CreditApi::process_debit(data_form data){
    return get_debit(data);
}