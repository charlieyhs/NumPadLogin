#ifndef DUNUMERICKEYPUSHBUTTON_H
#define DUNUMERICKEYPUSHBUTTON_H

#include <QPushButton>

class DuNumericKeyPushButton : public QPushButton
{
public:
    DuNumericKeyPushButton(QWidget *parent = nullptr);
signals:
    void keyWasClicked(QString);
};

#endif // DUNUMERICKEYPUSHBUTTON_H
