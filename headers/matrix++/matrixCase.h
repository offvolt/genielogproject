#ifndef MATRIXCASE_H_INCLUDED
#define MATRIXCASE_H_INCLUDED

class MatrixCase
{
private:
    unsigned int i;
    unsigned int j;
    int value;
public:
    MatrixCase();
    MatrixCase(unsigned int const& i, unsigned int const& j, int const& value);
    ~MatrixCase();

    void setI(unsigned int const& i);
    void setJ(unsigned int const& j);
    void setValue(int const& value);
    unsigned int getI();
    unsigned int getJ();
    int getValue();

};

#endif // MATRIXCASE_H_INCLUDED
