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
    string  ss = convert_to_string();
    if (ss.len == 0) check = 1;
    else check = !cast_string(ss);
    return check;
}

QString SimpleCalc::process(double x) {
    string ss = {0};
    stack_char sc = to_pn(convert_to_string(), &check);
    ss.len = sc.len;
    ss.str = sc.start;
    return QString::number(calc_polish(ss, x));
}
