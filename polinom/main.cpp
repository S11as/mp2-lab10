#include <iostream>
#include "TMonom.h"

int main()
{
    TMonom a(new double[3]{1,2,3}, 3, 1);
    std::cout<<a<<std::endl;
    return 0;
}
