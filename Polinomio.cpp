#include "Polinomio.h"
#include <algorithm>
#include <iostream>

using namespace std;

static ostream & info = cout;

Polinomio::Polinomio(vector <Monomio> & elementos)
{
    info << "Constructor \"vector<monomio> &\"" << endl;
    this->elementos = elementos;
    sumar(this->elementos);
    cantElementos = elementos.size();
    for (const Monomio & monomio : this->elementos) {
        representacion += monomio.getRepresentacion() + "  ";
    }
}

Polinomio::Polinomio(initializer_list <Monomio> elementos)
{
    info << "Constructor \"initializer_list <Monomio>\"" << endl;
    this->elementos = elementos;
    sumar(this->elementos);
    cantElementos = elementos.size();
    for (const Monomio & monomio : this->elementos) {
        representacion += monomio.getRepresentacion() + "  ";
    }
}

Polinomio::Polinomio(initializer_list <double> elementos)
{
    info << "Constructor \"initializer_list <double>\"" << endl;
    cantElementos = elementos.size();
    int grado = cantElementos - 1;
    for (const double coef : elementos) {
        Monomio monomio(coef, grado);
        this->elementos.push_back(monomio);
        representacion += monomio.getRepresentacion() + "  ";
        grado--;
    }
}

Polinomio::Polinomio(const Polinomio& polinomioFuente)
{
    info << "Constructor \"copia\"" << endl;
    elementos = polinomioFuente.elementos;
    cantElementos = polinomioFuente.cantElementos;
    representacion = polinomioFuente.representacion;
}

void Polinomio::operator=(const Polinomio& polinomioFuente)
{
    info << "Asignacion \"operator=\"" << endl;
    if (*this != polinomioFuente)
    {
        info << "\tAsignacion exitosa" << endl;
        elementos = polinomioFuente.elementos;
        cantElementos = polinomioFuente.cantElementos;
        representacion = polinomioFuente.representacion;
    }
    else
    {
        info << "\tAsignacion fallida" << endl;
    }
}

bool Polinomio::operator!=(const Polinomio & polinomioFuente)
{
    info << "Relacion \"operator!=\"" << endl;
    if (elementos != polinomioFuente.elementos)
    {
        if (representacion != polinomioFuente.representacion)
        {
            if (cantElementos != polinomioFuente.cantElementos)
            {
                info << "\ttrue" << endl;
                return true;
            }
        }
    }
    info << "\tfalse" << endl;
    return false;
}

Polinomio::~Polinomio()
{
    info << "Destructor" << endl;
    elementos.clear();
    representacion.clear();
}

string Polinomio::getRepresentacion() const
{
    return representacion;
}

ostream & operator << (ostream & out, Polinomio & polinomio)
{
    out << polinomio.getRepresentacion() << endl;
    return out;
}

    /// Este es el mas importante de los tres
    /// Antes de entrar a este metodo el vector debe estar ordenado
void Polinomio::sumar(vector <Monomio> & elementos)
{
    if (!elementos.empty())
    {
        sort(elementos.begin(), elementos.end());
        vector <Monomio> resultante;
        int gradoActual = elementos.front().getGrado();
        for (unsigned int j = 0; j < elementos.size(); gradoActual--)
        {
            double sumaCoeficientes = 0;
            while (elementos[j].getGrado() == gradoActual) {
                sumaCoeficientes += elementos[j].getCoef();
                j++;
            }
            if (sumaCoeficientes != 0)
            {
                resultante.push_back(Monomio(sumaCoeficientes, gradoActual));
            }
        }
        elementos = resultante;
    }
}

Polinomio Polinomio::sumar(const Polinomio& p1, const Polinomio& p2)
{
    vector <Monomio> resultante = p1.elementos;
    resultante.insert(resultante.end(), p2.elementos.begin(), p2.elementos.end());
    return Polinomio(resultante);
}

void Polinomio::sumar(const Polinomio & polinomioFuente)
{
    elementos.insert(elementos.end(), polinomioFuente.elementos.begin(), polinomioFuente.elementos.end());
    sumar(elementos);
    cantElementos = elementos.size();
    representacion.clear();

    for (const Monomio & monomio : elementos) {
        representacion += monomio.getRepresentacion() + "  ";
    }
}





