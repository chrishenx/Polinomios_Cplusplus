#ifndef MONOMIO_H
#define MONOMIO_H

#include "to_string.h"
#include <ostream>

/// ax^n

class Monomio
{
    double coef;
    int grado;
    std::string representacion;
public:
    Monomio(double coef, int grado);
    double getCoef() const;
    int getGrado() const;
    std::string getRepresentacion() const;
};

std::ostream & operator << (std::ostream &, Monomio &);
bool operator < (const Monomio &, const Monomio &);
bool operator == (const Monomio &, const Monomio &); //*

#endif // MONOMIO_H
