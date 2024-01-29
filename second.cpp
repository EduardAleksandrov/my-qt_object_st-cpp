#include "second.h"

Second::Second(int m, QObject* parent): m_value {m}, QObject(parent){}

void Second::setValue(int value)
{
    if (value != m_value)
    {
        m_value = value;
    }
}

void Second::emitValue(int value)
{
    emit valueChanged(value);
}
