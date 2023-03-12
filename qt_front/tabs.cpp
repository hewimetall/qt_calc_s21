//
// Created by xx on 3/12/23.
//

#include "tabs.hpp"

Tabs::Tabs() {
    view_calc = new FormCalc;
    view_creadit = new TabsViewCreadit;
    view_debit = new TabsViewDebit;
    addTab(view_calc, "Calc");
    addTab(view_creadit, "Credit");
    addTab(view_debit, "deb");
}