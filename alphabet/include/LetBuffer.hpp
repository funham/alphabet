#pragma once

#include "cfg.hpp"
#include "Letter.hpp"
#include <ostream>

using namespace std;

template <uint8_t H>
class LetBuffer
{
private:
    ostream &_os;
    Let_t _buff;
public:
    LetBuffer(ostream& os) : _os(os)
    {
        
    }

    LetBuffer& operator << (char let)
    {

        return *this;   
    }

    LetBuffer& operator << (const char* str)
    {

        return *this;
    }

    void print()
    {

    }
};