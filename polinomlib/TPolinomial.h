//
// Created by Kirill on 12/12/2020.
//

#ifndef POLINOMLIB_TPOLINOMIAL_H
#define POLINOMLIB_TPOLINOMIAL_H

#include "TMonom.h"
#include "TList.h"

#include "iostream"
using namespace std;

class TPolinomial : public TList<TMonomData> {
public:
    TPolinomial() = default;
    TPolinomial(TPolinomial& polinomial);
    ~TPolinomial() = default;

    TPolinomial& operator+= (TMonom& _v);

    TPolinomial operator* (TPolinomial& _v);
    TPolinomial operator+ (TPolinomial& _v);
    TPolinomial operator- (TPolinomial& _v);

};


#endif //POLINOMLIB_TPOLINOMIAL_H
