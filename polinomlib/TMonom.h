//
// Created by Kirill on 12/9/2020.
//

#ifndef POLINOMLIB_TMONOM_H
#define POLINOMLIB_TMONOM_H
#include "TList.h"

struct TMonomData{
    double* data = nullptr;
    double k = 0;
    int dim = 0;
    explicit TMonomData(int t);
    TMonomData(double* data=0, int dim=0, double k=0);
    void set_dim(int dim);

    TMonomData(TMonomData& monomData);
    ~TMonomData();
    friend ostream&operator<<(ostream& ostr, const TMonomData& monom);
    friend istream&operator>>(istream& istr, TMonomData& monom);
};

class TMonom : public TListElem<TMonomData> {
public:
    TMonom(TMonomData data);
    TMonom(double* data=0, int dim=0, double k=0);
    TMonom(TMonom& monom);
    ~TMonom() = default;

    bool operator==(const TMonom& monom);
    bool operator!=(const TMonom& monom);

    TMonomData& operator*();
    double get_k();
    void set_k(double k);
    int get_dim() const;
    void set_dim(int dim);

    TMonom& operator++();

    TMonom& operator=(const TMonom& monom);

    double operator[](int i);
    TMonom operator* (const TMonom& monom);
    TMonom operator/ (const TMonom& monom);

    TMonom* operator+ (const TMonom& monom);
    TMonom* operator- (const TMonom& monom);

    bool operator> (const TMonom& monom);
    bool operator< (const TMonom& monom);

    TMonom* Clone();
    void change_sign();

    friend ostream&operator<<(ostream& ostr, const TMonom& monom);
    friend istream&operator>>(istream& istr, TMonom& monom);
};


#endif //POLINOMLIB_TMONOM_H
