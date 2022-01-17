#include "numpadlogindialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    NumPadLogInDialog numPadLogIn;
    int numPadLoginResult;
    do{
        numPadLoginResult = numPadLogIn.exec();
        if(numPadLoginResult == QDialog::Rejected){
            QMessageBox::warning(&numPadLogIn,"Advertencia","Codigo incorrecto");
        }
    }while(numPadLoginResult == QDialog::Rejected);

    MainWindow window;
    window.show();
    numPadLogIn.show();
    return a.exec();
}
