#include <iostream>
#include "TMonom.h"
#include "TPolinomial.h"

int main()
{
//    TMonom a(new double[3]{1.1,2.2,3.3}, 3, 1);
//    TMonom b(new double[3]{3,2,1}, 3, 1);
//
//    TMonom c(new double[3]{1,1,1}, 4, 1);
//    TMonom d(new double[3]{2,2,2}, 4, 1);
//
//
//    TPolinomial aa;
//    aa+=a;
//    aa+=b;
//    TPolinomial bb(aa);
//    bb+=c;
//    bb+=d;
//    std::cout<<aa*bb<<std::endl;
//    std::cout<<aa-bb<<std::endl;
//
//    TMonom k(new double[3]{ 1, 2, 3 }, 3, 1);
//    a.set_dim(10);
//    aa.save("hello.txt");
    TMonom a(new double[5]{1, 2, 3, 4, 5}, 5, 1);
    TMonom b(new double[6]{1, 2, 3, 4, 5, 6}, 10, 1);
    TPolinomial P1;
    P1 += a;
    P1 += b;
    return 0;
}
