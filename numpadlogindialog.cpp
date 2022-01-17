#include "numpadlogindialog.h"
#include "ui_numpadlogindialog.h"
#if defined(MY_DEBUG)
#include <QDebug>
#include <QResizeEvent>
#endif
#define PASSWORD 12345

NumPadLogInDialog::NumPadLogInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NumPadLogInDialog)
{
    ui->setupUi(this);
    QSize tamanio;
    tamanio.setHeight(100);
    tamanio.setWidth(100);
    resizeKey(ui->enterPushButton, tamanio);
    resizeKey(ui->clearPushButton,tamanio);
    resize(334,618);
    connectKeys();
}

NumPadLogInDialog::~NumPadLogInDialog()
{
    delete ui;
}
#if defined(MY_DEBUG)
void NumPadLogInDialog::resizeEvent(QResizeEvent *e)
{
    qDebug() <<e->size();
    QDialog::resizeEvent(e);
}
#endif
void NumPadLogInDialog::on_clearPushButton_clicked()
{
    ui->lcdNumber->display(0);
}

void NumPadLogInDialog::on_enterPushButton_clicked()
{
    const double password = ui->lcdNumber->value();
    if(password == PASSWORD){
        accept();
        return;
    }
    reject();
}

void NumPadLogInDialog::onKeyWasClicked(const QString &number)
{
    ui->lcdNumber->display(QString::number(ui->lcdNumber->value())+number);
}


void NumPadLogInDialog::resizeKey(QPushButton *key, QSize &size) const
{
    key->setMinimumSize(size);
    key->setMaximumSize(size);
}

void NumPadLogInDialog::connectKeys()
{
    connect(ui->ceroPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->unoPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->dosPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->tresPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->cuatroPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->cincoPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->seisPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->sietePushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->ochoPushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);
    connect(ui->nuevePushButton, &DuNumericKeyPushButton::keyWasClicked,this,&NumPadLogInDialog::onKeyWasClicked);

}
