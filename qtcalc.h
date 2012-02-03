/**
  @author:mihhail sidorin
  */

#ifndef QTCALC_H
#define QTCALC_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QtGui/QWidget>
#include <mybutton.h>
#include <QDebug>
 #include <QDoubleValidator>

class qtCalc : public QWidget
{
    Q_OBJECT

    QLineEdit *calc_display; //object that displays information
    QString calc_state; //shows caclulator state "display" or "input"
    QString    previousOp;
    float memory;

public:
    qtCalc(QWidget *parent = 0);
    ~qtCalc();
    MyButton *initbutton(QString text);
    void addDigitOnScreen(int value);
    void resetCalc();
    void processOperator(QString text);
    void processPreviousOperator();
    void processEquals();

public slots:
   void calc_button_processor(QString text);

};

#endif // QTCALC_H
