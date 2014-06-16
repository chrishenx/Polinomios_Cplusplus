#include "Monomio.h"

using namespace std;

Monomio::Monomio(double coef, int grado)
{
    this->coef = coef;
    this->grado = grado;
    representacion = to_string(coef) + "x^" + to_string(grado);
}

double Monomio::getCoef() const
{
    return coef;
}

int Monomio::getGrado() const
{
    return grado;
}

string Monomio::getRepresentacion() const
{
    return representacion;
}

ostream & operator << (ostream & out, Monomio & monomio)
{
    out << monomio.getRepresentacion() << endl;
    return out;
}

bool operator < (const Monomio & m1, const Monomio & m2)
{
    return m2.getGrado() < m1.getGrado();
}

bool operator == (const Monomio & m1, const Monomio & m2)
{
    return m1.getGrado() == m2.getGrado() && m1.getCoef() == m2.getCoef();
}




