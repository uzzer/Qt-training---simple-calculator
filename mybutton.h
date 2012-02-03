/**
  @author:mihhail sidorin
  */

#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);


signals:
    void clicked(QString);

public slots:
    void emitter();
};

#endif // MYBUTTON_H
