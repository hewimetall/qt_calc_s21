//
// Created by xx on 3/12/23.
//

#ifndef QT_CALC_TABS_H
#define QT_CALC_TABS_H

#include <QWidget>
#include <QTabWidget>
#include "FormCalc.hpp"
#include "FormCreadit.hpp"
class Tabs : public QTabWidget {
Q_OBJECT

public:
    Tabs();
private:
    FormCalc *view_calc;
    TabsViewCreadit *view_creadit;
};


#endif //QT_CALC_TABS_H
