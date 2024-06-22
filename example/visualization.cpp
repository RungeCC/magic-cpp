#include "magic/template_traits.h"
#include "magic/visualize.h"

#include <format>
#include <functional>
#include <iostream>
#include <ostream>

template <class... Ts>
void print(std::format_string<Ts...> str, Ts&&... args)
{
    std::cout << std::format(str, std::forward<Ts>(args)...) << std::flush;
}
void print() { std::cout << std::flush; }

template <auto>
struct nttp
{
};

int main()
{
    using T1 = int (*(*(*)(int*))[4])(int*); // hard to understand
    print("type alias T1\n{}", magic::visualize<T1>());

    using T2 = decltype([a = 1](int, char, double, nttp<[]() {}> i) noexcept { return [&]() {}; }); // hard to understand
    print("type alias T2\n{}", magic::visualize<T2>());

    magic::VisualizeOption option1{
        .utf_support = false,   // do not use utf8 characters
        .color_support = false, // turn off color support
        .full_name = true       // use full name instead of custom alias
    };

    print("type alias std::string\n{}", magic::visualize<std::string>(option1));

    magic::VisualizeOption option2{
        .utf_support = true,   // use unicode characters
        .color_support = true, // turn on color support
        .full_name = true      // use full name instead of custom alias
    };
    print("type alias std::string\n{}", magic::visualize<std::string>(option2, magic::Light));
}
