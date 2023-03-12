#include "FormCalc.hpp"

FormCalc::FormCalc() {
    init_ui();
    bind();
    init_form();
    setup_windows();
}

void FormCalc::init_ui() {
    q = QString();
    sc = new SimpleCalc(&q);

    this->root = new QVBoxLayout;
    this->gridLayoutI = new QVBoxLayout;
    this->gridLayoutT = new QHBoxLayout;

    b1 = new QPushButton("=");
    b2 = new QPushButton("Clean");
    b3 = new QPushButton("Graph");

    inp = new QLineEdit;
    out = new QLabel("Out:");

}
void FormCalc::bind() {
    connect(b1, SIGNAL(clicked()), this, SLOT(text()));
    connect(b2, SIGNAL(clicked()), this, SLOT(clean()));
    connect(b3, SIGNAL(clicked()), this, SLOT(print()));
}
void FormCalc::setup_windows() {
    root->addLayout(gridLayoutI);
    root->addLayout(gridLayoutT);
    setLayout(root);
}

void FormCalc::init_form() {
    this->gridLayoutT->addWidget(b1);
    this->gridLayoutT->addWidget(b2);
    this->gridLayoutT->addWidget(b3);
    this->gridLayoutI->addWidget(inp);
    this->gridLayoutI->addWidget(out);
}

void FormCalc::text() {
    q = inp->text();
    if (!sc->valid()) {
        out->setText(sc->process(0));
    } else out->setText(QString("FAILE"));
}

void FormCalc::clean() {
    auto q = QString("Out:\t");
    out->setText(q);
}
void FormCalc::print() {
    auto qch = new QChart;

    QLineSeries *series = new QLineSeries();
    this->text();
    for (double i = -3.14; i < 3.14; i+=0.25) {
        series->append(i, sc->process(i).toDouble());
    }
    qch->legend()->hide();

    qch->addSeries(series);
    qch->createDefaultAxes();
    auto chartView = new QChartView(qch);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(500,500);
    chartView->showMaximized();

}