#include <iostream>
#include "../include/LetBuffer.hpp"
#include "../include/cfg.hpp"

using namespace std;

int main()
{
    LetBuffer<6> buff = cout;
    buff << "IiIiI" << 'i';
    buff.print();
}