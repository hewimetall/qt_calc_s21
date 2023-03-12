#ifndef QT_CALC_SIMPLE_CALC_H
#define QT_CALC_SIMPLE_CALC_H
#include <QString>
extern "C" {
    #include <api_core.h>
}

/**
 * @bref: Класс адаптер между qt <--> api_calc.
 */
class SimpleCalc {
public:
    SimpleCalc(QString *input);
    int valid();
    QString process(double x);
private:
    int check;
    QString *inp;
    string convert_to_string();
};


#endif //QT_CALC_SIMPLE_CALC_H
