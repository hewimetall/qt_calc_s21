//
// Created by xx on 3/12/23.
//

#include "simple_calc.hpp"

SimpleCalc::SimpleCalc(QString *input) {
    this->inp = input;
    check = 0;
}

string SimpleCalc::convert_to_string() {
    char *p = inp->toLocal8Bit().data();
    return string{
            .len = (int) strlen(p),
            .str = p
    };
}


int SimpleCalc::valid() {
    string ss = convert_to_string();
    if (ss.len == 0) check = 1;
    else check = !check_validation(ss);
    return check;
}

QString SimpleCalc::process(double x) {
    if (check) { return QString("Err"); }
    return QString::number(process_calc(convert_to_string(), x));
}
