#ifndef SECOND_H
#define SECOND_H

#include <QObject>

class Second: public QObject
{
    Q_OBJECT
public:
    explicit Second(int m = 1, QObject* parent = nullptr);
    virtual ~Second() {}
    void emitValue(int);
    int get_m()
    {return m_value;}
signals:
   void valueChanged(int newValue);
public slots:
   void setValue(int value);
private:
    int m_value;
};




#endif

