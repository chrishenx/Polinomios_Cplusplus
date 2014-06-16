#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include <initializer_list>
#include "Monomio.h"

class Polinomio
{
    std::vector <Monomio> elementos;
    std::string representacion;
    int cantElementos;

    static void sumar (std::vector <Monomio> & elementos);  // *
public:
    Polinomio (std::vector <Monomio> & elementos);
    Polinomio (std::initializer_list <Monomio> elementos);
    Polinomio (std::initializer_list <double> elementos);
    Polinomio (const Polinomio & polinomioFuente);
    ~Polinomio();

    void sumar(const Polinomio & polinomioFuente); // **
    static Polinomio sumar(const Polinomio & p1, const Polinomio & p2); // ***

    void operator = (const Polinomio & polinomioFuente); // ****
    bool operator != (const Polinomio & polinomioFuente); // *****

    std::string getRepresentacion() const;
};

std::ostream & operator << (std::ostream &, Polinomio &);


#endif // POLINOMIO_H
