#include <iostream>
#include "../include/LetBuffer.hpp"
#include "../include/cfg.hpp"

int main()
{
    LetBuffer<6> buff;

    const char CAPS_OFFSET = 32;

    const char* words[] = {
        "qwert",
        "yuiop",
        "asdfg",
        "hjklz",
        "tea",
        "fox",
        "star"
    };

    for (auto &word : words)
    {
        buff << word;
        std::cout << buff << std::endl;
    }
    

    system("pause");

    return 0x00;
}