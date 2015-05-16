#include "counter.h"
#include <iostream>

Counter::Counter(QObject *parent) :
    QObject(parent)
{
}

void Counter::setValue(int value)
{

   if (value != m_value) {

       m_value = value;

       std::cout<<value<<std::endl;
       emit valueChanged(value);
   }

}
