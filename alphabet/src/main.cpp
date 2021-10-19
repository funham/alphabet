#include <iostream>
#include "../include/LetBuffer.hpp"
#include "../include/cfg.hpp"

int main()
{
    LetBuffer<6> buff;

    const char CAPS_OFFSET = 32;

    for (char ch = 'A'; ch <= 'Z'; ++ch)
    {
        // AaBb...YyZz
        buff << ch << (ch + CAPS_OFFSET);
    }

    std::cout << std::endl
              << buff << std::endl;

    system("pause");

    return 0x00;
}