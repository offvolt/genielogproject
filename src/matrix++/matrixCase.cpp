#include "matrixCase.h"


MatrixCase::MatrixCase()
{
    i=0;
    j=0;
    value=0;
}

MatrixCase::MatrixCase(unsigned int const& i, unsigned int const& j, int const& value)
{
    setI(i);
    setJ(j);
    setValue(value);
}
MatrixCase::~MatrixCase()
{
}

void MatrixCase::setI(unsigned int const& i)
{
    this->i = i;
}
void MatrixCase::setJ(unsigned int const& j)
{
    this->j = j;
}
void MatrixCase::setValue(int const& value)
{
    this->value = value;
}
unsigned int MatrixCase::getI()
{
    return i;
}
unsigned int MatrixCase::getJ()
{
    return j;
}
int MatrixCase::getValue()
{
    return value;
}
