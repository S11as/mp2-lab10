//
// Created by Kirill on 12/9/2020.
//

#include "TMonom.h"

ostream &operator<<(ostream &ostr, const TMonom &monom) {
    ostr << monom.data.k << " "<< monom.data.dim;
    for (int i = 0; i < monom.data.dim; ++i) {
        ostr << " " << monom.data.data[i];
    }
    ostr << " ";
    return ostr;
}

istream &operator>>(istream &istr, TMonom &monom) {
    int dim = 0;
    if (monom.data.dim != 0) {
        dim = monom.data.dim;
    } else {
        istr >> dim;
        monom.set_dim(dim);
    }
    istr >> monom.data.k;
    for (int i = 0; i < dim; ++i) {
        double number;
        istr >> number;
//        monom[i] = number;
    }
    return istr;
}

TMonom::TMonom(TMonomData data) : TListElem<TMonomData>(data) {}

TMonom::TMonom(double *data, int dim, double k) : TListElem<TMonomData>() {
    if (dim < 0) {
        throw std::invalid_argument("wrong dim");
    }
    this->data.dim = dim;
    this->data.k = k;
    if (dim > 0) {
        this->data.data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            this->data.data[i] = data[i];
        }
    }
}

TMonom::TMonom(TMonom &monom) : TListElem<TMonomData>(monom) {
    this->prev = 0;
    this->next = 0;
}

bool TMonom::operator==(const TMonom &monom) {
    if (this->data.dim != monom.data.dim)
        throw std::invalid_argument("Monoms have different dimensions");
    if (this->data.dim > 0) {
        for (int i = 0; i < this->data.dim; ++i) {
            if (this->data.data[i] != monom.data.data[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool TMonom::operator!=(const TMonom &monom) {
    return !this->operator==(monom);
}

TMonomData &TMonom::operator*() {
    return this->data;
}

double TMonom::get_k() {
    return this->data.k;
}

void TMonom::set_k(double k) {
    this->data.k = k;
}

int TMonom::get_dim() const {
    return this->data.dim;
}

void TMonom::set_dim(int dim) {
    if (dim < 0)
        throw std::invalid_argument("invalid dim");
    if (dim == 0) {
        if(this->data.dim > 0){
            delete[] this->data.data;
        }
        this->data.dim = 0;
        this->data.data = 0;
    } else if (this->data.dim == dim) {
        return;
    } else {
        if(this->data.dim > 0){
            delete[] this->data.data;
        }
        this->data.dim = dim;
        this->data.data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            this->data.data[i] = 0;
        }
    }
}

TMonom &TMonom::operator=(const TMonom &monom) {
    if(this == &monom){
        return *this;
    }
    this->next = 0;
    this->prev = 0;
    this->data.k = monom.data.k;

    if(monom.data.dim == 0){
        if(this->data.dim > 0){
            delete[] this->data.data;
        }
        this->data.dim = 0;
        this->data.data = 0;
        return *this;
    }

    if (this->data.dim != monom.data.dim) {
        if(this->data.dim > 0){
            delete[] this->data.data;
        }
        this->data.data = new double[monom.data.dim];
        this->data.dim = monom.data.dim;
    }
    for (int i = 0; i < this->data.dim; ++i) {
        this->data.data[i] = monom.data.data[i];
    }
    return *this;
}

double TMonom::operator[](int i) {
    return this->data.data[i];
}

TMonom TMonom::operator*(const TMonom &monom) {
    if(this->data.dim != monom.get_dim()){
        throw std::invalid_argument("wrong monom dimension");
    }
    TMonom tmp(*this);
    tmp.data.k = this->data.k * monom.data.k;
    for (int i = 0; i < this->data.dim; ++i) {
        tmp.data.data[i] = this->data.data[i] + monom.data.data[i];
    }
    return tmp;
}

TMonom TMonom::operator/(const TMonom &monom) {
    if(this->data.dim != monom.get_dim()){
        throw std::invalid_argument("wrong monom dimension");
    }
    TMonom tmp(*this);
    tmp.data.k = this->data.k / monom.data.k;
    for (int i = 0; i < this->data.dim; ++i) {
        tmp.data.data[i] = this->data.data[i] - monom.data.data[i];
    }
    return tmp;
}

TMonom *TMonom::operator+(const TMonom &monom) {
    TMonom* tmp = nullptr;
    if(*this == monom){
        tmp = new TMonom(*this);
        tmp->data.k = this->data.k + monom.data.k;
    }else{
        tmp = new TMonom[2];
        if(*this>monom){
            tmp[0] = *this;
            tmp[1] = monom;
        }else{
            tmp[1] = *this;
            tmp[0] = monom;
        }
    }
    return tmp;
}


TMonom *TMonom::operator-(const TMonom &monom) {
    TMonom* tmp = nullptr;
    if(*this == monom){
        tmp = new TMonom(*this);
        tmp->data.k = this->data.k - monom.data.k;
    }else{
        tmp = new TMonom[2];
        if(*this>monom){
            tmp[0] = *this;
            tmp[1] = monom;
        }else{
            tmp[1] = *this;
            tmp[0] = monom;
        }
    }
    return tmp;
}

bool TMonom::operator>(const TMonom &monom) {
    if (this->data.dim != monom.data.dim)
        throw std::invalid_argument("Monoms have different dimensions");
    if (this->data.dim > 0) {
        for (int i = 0; i < this->data.dim; ++i) {
            if (this->data.data[i] > monom.data.data[i]) {
                return true;
            }else if(this->data.data[i] < monom.data.data[i]){
                return false;
            }
        }
        return false;
    }else{
        return this->data.k > monom.data.k;
    }
}

bool TMonom::operator<(const TMonom &monom) {
    if (this->data.dim != monom.data.dim)
        throw std::invalid_argument("Monoms have different dimensions");
    if (this->data.dim > 0) {
        for (int i = 0; i < this->data.dim; ++i) {
            if (this->data.data[i] < monom.data.data[i]) {
                return true;
            }else if(this->data.data[i] > monom.data.data[i]){
                return false;
            }
        }
        return false;
    }else{
        return this->data.k > monom.data.k;
    }
}

TMonom* TMonom::Clone() {
    auto* res = new TMonom(*this);
    return res;
}

void TMonom::change_sign() {
    this->data.k = this->data.k*(-1.0);
}


TMonomData::TMonomData(int t) {
    if (t < 0)
        throw std::invalid_argument("wrong data");
    else if (t == 0) {
        this->dim = 0;
        this->data = 0;
    } else {
        this->data = new double[this->dim];
        for (int i = 0; i < this->dim; ++i) {
            this->data[i] = 0;
        }
    }

}

TMonomData::TMonomData(double *data, int dim, double k) {
    if (dim < 0) {
        throw std::invalid_argument("wrong dim");
    }
    this->dim = dim;
    this->k = k;
    if (dim > 0) {
        this->data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            this->data[i] = data[i];
        }
    }
}

TMonomData::TMonomData(TMonomData &monomData) {
    this->dim = monomData.dim;
    this->k = monomData.k;
    if (this->dim > 0) {
        this->data = new double[this->dim];
        for (int i = 0; i < this->dim; ++i) {
            this->data[i] = monomData.data[i];
        }
    }
}

TMonomData::~TMonomData() {
    if (this->data != nullptr) {
        delete[] data;
        this->data = nullptr;
        this->dim = 0;
        this->k = 0;
    }
}

ostream &operator<<(ostream &ostr, const TMonomData &monom) {
    ostr << monom.dim << " "<< monom.k;
    for (int i = 0; i < monom.dim; ++i) {
        ostr << " " << monom.data[i];
    }
    ostr << " ";
    return ostr;
}

istream &operator>>(istream &istr, TMonomData &monom) {
    int dim = 0;
    if (monom.dim != 0) {
        dim = monom.dim;
    } else {
        istr >> dim;
        monom.set_dim(dim);
    }
    istr >> monom.k;
    for (int i = 0; i < dim; ++i) {
        double number;
        istr >> number;
        monom.data[i] = number;
    }
    return istr;
}

void TMonomData::set_dim(int dim) {
    if (dim < 0)
        throw std::invalid_argument("invalid dim");
    if (dim == 0) {
        if(this->dim > 0){
            delete[] this->data;
        }
        this->dim = 0;
        this->data = 0;
    } else if (this->dim == dim) {
        return;
    } else {
        if(this->dim > 0){
            delete[] this->data;
        }
        this->dim = dim;
        this->data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            this->data[i] = 0;
        }
    }
}
