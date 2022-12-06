#include "../include/Vector.h"
#include <sstream>
#include <iostream>
#include <string_view>
#include "../include/Zi.h"

int main()
{

    auto z0 = Zi(14, 3);
    auto z1 = Zi(4, 5);
    auto z2 = Zi(27, -23);
    auto z3 = Zi(8, 1);
    z0 = z0 % z1;

    std::cout << z0;

    z0.dividedBy(z1);



    return 0;
}