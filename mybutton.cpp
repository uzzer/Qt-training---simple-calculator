/**
  @author:mihhail sidorin
  */
#include "mybutton.h"

MyButton::MyButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(emitter()));
}

void MyButton::emitter() {
    emit(clicked(this->text()));
}
