/**
  @author:mihhail sidorin
  */

#include "qtcalc.h"

qtCalc::qtCalc(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *wrapper = new QVBoxLayout();
    QHBoxLayout *buttons_pane = new QHBoxLayout();
    QGridLayout *leftpane = new QGridLayout();
    QVBoxLayout *rightpanewrapper = new QVBoxLayout();
    QGridLayout *rightpane = new QGridLayout();


    calc_display = new QLineEdit();
    QDoubleValidator *validator = new QDoubleValidator();
    calc_display->setValidator(validator);
    calc_display->setMaximumWidth(200);
    calc_display->setStyleSheet("font-weight: bold; font-size: 24px;");

    wrapper->addWidget(calc_display);
    wrapper->addLayout(buttons_pane);
    buttons_pane->addLayout(leftpane);
    buttons_pane->addLayout(rightpanewrapper);
    rightpanewrapper->addLayout(rightpane);

    QString numberpad[] = {"1","2","3","4","5","6","7","8","9","+/-","0","C"};
    int numberpadcols = 3;
    int numberpadlines = 4;
    for(int i=0;i<numberpadlines;i++){
        for(int k=0;k<numberpadcols;k++){
            leftpane->addWidget(initbutton(numberpad[i*numberpadcols+k]),i,k);
        }
    }

    QString funpad[] = {"*","/","+","-"};
    int funpadcols = 2;
    int funpadlines = 2;
    for(int i=0;i<funpadlines;i++){
        for(int k=0;k<funpadcols;k++){
            rightpane->addWidget(initbutton(funpad[i*funpadcols+k]),i,k);
        }
    }
    rightpanewrapper->addWidget(initbutton("="),3,0);

    resetCalc();

    this->setLayout(wrapper);

}


MyButton *qtCalc::initbutton(QString text){
    MyButton *temp = new MyButton();
    temp->setText(text);
    temp->setMaximumWidth(30);
    temp->setMinimumWidth(30);
    if(text=="="){temp->setMaximumWidth(70);
    temp->setMinimumWidth(70);}
    temp->setMaximumHeight(30);
    temp->setMinimumHeight(30);

    connect(temp,SIGNAL(clicked(QString)),this,SLOT(calc_button_processor(QString)));
    return temp;
}

void qtCalc::calc_button_processor(QString text){
    calc_display->setFocus();
    qDebug()<<"processing "<<text;
    bool isnum;
    int value = text.toInt(&isnum);
    if (isnum){
        addDigitOnScreen(value);
    }
    else {
        if(text=="="){
            processEquals();
        }
        if(text=="+" || text=="-" ||text=="*" ||text=="/"){
            processOperator(text);
        }
        if(text=="C"){
            resetCalc();
        }
        if(text=="+/-"){
            calc_display->setText(QString::number(calc_display->text().toFloat()*-1,'g'));
            calc_state ="input";
        }
    }
}

void qtCalc::processEquals(){
    processPreviousOperator();
    calc_display->setText(QString::number(memory));
    previousOp = "=";
    calc_state ="display";
}

void qtCalc::processOperator(QString text){
    processPreviousOperator();
    previousOp = text;
    calc_state ="display";
    qDebug()<<"memory after action "<< memory;
}

void qtCalc::processPreviousOperator(){
    float displayValue = calc_display->text().toFloat();
    qDebug()<<"memory = "<< memory <<" op "<<displayValue;
    if(previousOp == "+"){ memory = memory + displayValue; }
    if(previousOp == "-"){ memory = memory - displayValue; }
    if(previousOp == "*"){ memory = memory * displayValue; }
    if(previousOp == "/"){ if(displayValue==0){
            resetCalc();
        }else{
            memory = memory / displayValue;
        }
    }
    qDebug()<<"memory = "<<memory<<" ; ";
}

void qtCalc::resetCalc(){
    previousOp  = "+";
    calc_state ="input";
    calc_display->setText("");
    memory = 0;
}

void qtCalc::addDigitOnScreen(int value){
    qDebug()<<calc_state<<" "<<value;
    if(calc_state =="input"){
        calc_display->setText(calc_display->text().append(QString::number(value)));
    } else if(calc_state == "display"){
        calc_display->setText(QString::number(value));
        calc_state ="input";
    }
}

qtCalc::~qtCalc()
{

}
