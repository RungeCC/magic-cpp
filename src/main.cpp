#include "magic/template_traits.h"
#include "magic/visualize.h"

#include <iostream>

int main()
{
    using T = int (*(*(*)(int*))[4])(int*); // hard to understand
    std::cout << magic::visualize<T>() << std::endl;
}
