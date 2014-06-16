#include "to_string.h"

using namespace std;

string to_string(double valor)
{
    ostringstream oss;
    oss << fixed << showpos;
    oss << valor;
    return oss.str();
}

string to_string(int valor)
{
    ostringstream oss;
    oss << valor;
    return oss.str();
}
