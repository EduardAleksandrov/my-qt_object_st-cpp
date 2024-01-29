#include "mainwindow.h"
#include "second.h"

#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <ui_mainwindow.h>


void onclick();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // для консоли, для окна нужно писать в конструкторе mainwindow
    QPushButton pushButton{"Click", &w};
    QObject::connect(&pushButton, &QPushButton::clicked,onclick);

    // для консоли, для окна нужно писать в конструкторе mainwindow
    Second na(22,&w), nb(33,&w);
    Second::connect(&na, SIGNAL(valueChanged(int)), &nb, SLOT(setValue(int)));
    na.emitValue(10);
    qDebug() << nb.get_m();
    //#include <ui_mainwindow.h> и видим результат в виджете
    w.returnUi()->label->setNum(nb.get_m());

    w.show();
    return a.exec();
}
void onclick()
{
    qDebug() << "hello to terminal";
}
