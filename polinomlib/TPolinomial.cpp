//
// Created by Kirill on 12/12/2020.
//

#include "TPolinomial.h"

TPolinomial::TPolinomial(TPolinomial &polinomial) : TList<TMonomData>(polinomial) {

}

TPolinomial &TPolinomial::operator+=(TMonom &_v) {
    TMonom *toAdd = _v.Clone();
    if (this->root == 0) {
        this->root = toAdd;
        return *this;
    }

    TMonom *temp = static_cast<TMonom *>(this->root);
    while (temp != 0) {
        if (*temp == _v) {
            temp->set_k(temp->get_k() + _v.get_k());
            this->count++;
            return *this;
        } else if (*temp < _v) {
            toAdd->SetPrev(temp->GetPrev());
            toAdd->SetNext(temp);
            if (temp->GetPrev()) {
                temp->GetPrev()->SetNext(toAdd);
            }
            temp->SetPrev(toAdd);
            // вставляем перед рутом - надо сменить рут
            if (temp == this->root) {
                this->root = toAdd;
            }
            this->count++;
            return *this;
        } else {
            if (temp->GetNext() == 0) {
                toAdd->SetPrev(temp);
                temp->SetNext(toAdd);
                this->count++;
                return *this;
            } else {
                temp = static_cast<TMonom *>(temp->GetNext());
            }
        }
    }
    this->count++;
    return *this;
}

TPolinomial TPolinomial::operator*(TPolinomial &_v) {
    if (this->root == 0 || _v.root == 0) {
        throw std::invalid_argument("Polinomials are empty");
    }
    TPolinomial result;
    auto *local_monom = static_cast<TMonom *>(this->root);
    while (local_monom != 0) {
        auto *other_monom = static_cast<TMonom *>(_v.root);
        while (other_monom != 0) {
            TMonom result_monom;
            result_monom = (static_cast<TMonom &>(*local_monom)) * (static_cast<TMonom &>(*other_monom));
            result += result_monom;
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        }
        local_monom = static_cast<TMonom *>(local_monom->GetNext());
    }
    return result;
}

TPolinomial TPolinomial::operator+(TPolinomial &_v) {
    if (this->root == 0 || _v.root == 0) {
        throw std::invalid_argument("Polinomials are empty");
    }
    TPolinomial result;
    auto *local_monom = static_cast<TMonom *>(this->root);
    auto *other_monom = static_cast<TMonom *>(_v.root);
    TMonom *root = 0;
    while (local_monom != 0 && other_monom != 0) {
        TMonom temp;
        if (*local_monom == *other_monom) {
            temp = ((*local_monom) + (*other_monom))[0];
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        } else if (*local_monom < *other_monom) {
            temp = *other_monom;
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        } else {
            temp = *local_monom;
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
        }

        if (root == 0) {
            result += temp;
            root = static_cast<TMonom *>(result.root);
        } else {
            root->SetNext(temp.Clone());
            root->GetNext()->SetPrev(static_cast<TMonom *>(root));
            root = static_cast<TMonom *>(root->GetNext());
        }
    }
    if (local_monom != 0) {
        while (local_monom != 0) {
            root->SetNext(local_monom->Clone());
            root->GetNext()->SetPrev(root);
            root = static_cast<TMonom *>(root->GetNext());
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
        }
    } else if (other_monom != 0) {
        while (other_monom != 0) {
            root->SetNext(other_monom->Clone());
            root->GetNext()->SetPrev(root);
            root = static_cast<TMonom *>(root->GetNext());
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        }
    }
    return result;
}

TPolinomial TPolinomial::operator-(TPolinomial &_v) {
    if (this->root == 0 || _v.root == 0) {
        throw std::invalid_argument("Polinomials are empty");
    }
    TPolinomial result;
    auto *local_monom = static_cast<TMonom *>(this->root);
    auto *other_monom = static_cast<TMonom *>(_v.root);
    TMonom *root = 0;
    while (local_monom != 0 && other_monom != 0) {
        TMonom temp;
        if (*local_monom == *other_monom) {
            temp = ((*local_monom) - (*other_monom))[0];
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        } else if (*local_monom < *other_monom) {
            temp = *other_monom;
            temp.change_sign();
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        } else {
            temp = *local_monom;
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
        }

        if (root == 0) {
            result += temp;
            root = static_cast<TMonom *>(result.root);
        } else {
            root->SetNext(temp.Clone());
            root->GetNext()->SetPrev(static_cast<TMonom *>(root));
            root = static_cast<TMonom *>(root->GetNext());
        }
    }
    if (local_monom != 0) {
        while (local_monom != 0) {
            root->SetNext(local_monom->Clone());
            root->GetNext()->SetPrev(root);
            root = static_cast<TMonom *>(root->GetNext());
            local_monom = static_cast<TMonom *>(local_monom->GetNext());
        }
    } else if (other_monom != 0) {
        while (other_monom != 0) {
            TMonom* toInsert = other_monom->Clone();
            toInsert->change_sign();
            root->SetNext(toInsert);
            root->GetNext()->SetPrev(root);
            root = static_cast<TMonom *>(root->GetNext());
            other_monom = static_cast<TMonom *>(other_monom->GetNext());
        }
    }
    return result;
}
