#include "magic/template_traits.h"
#include "magic/visualize.h"

#include <iostream>


int main()
{
    using T = I<J<K>>; // hard to understand
    std::cout << magic::visualize<T>() << std::endl;
    
}
