#ifndef WRITER_GRID_H
#define WRITER_GRID_H
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QLineEdit>
#include <QLabel>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include "simple_calc.hpp"

class FormCalc : public QWidget
{
    Q_OBJECT
public:
    FormCalc();
    QHBoxLayout *gridLayoutT;
    QVBoxLayout *gridLayoutI;
public slots:
    void text();
    void clean();
    void print();

private:
    QString q;
    SimpleCalc *sc;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QLineEdit *inp;
    QLabel *out;
    QVBoxLayout *root;
protected:
    void init_form();
    void bind();
    void setup_windows();
    void init_ui();

};


#endif //WRITER_GRID_H
