#pragma once

#include "cfg.hpp"
#include "Letter.hpp"
#include <ostream>
#include <fstream>
#include <string.h>

template <uint8_t H>
class LetBuffer
{
private:
    std::ostream &_os;
    Let_t _buff;

public:
    LetBuffer(std::ostream &os) : _os(os)
    {
    }

    LetBuffer &operator<<(char let)
    {
        std::string path = "..\\res\\";
        path += (let <= 'Z' ? "capital\\" : "lower\\");
        path += let;
        path += ".txt";

        //_os << path << std::endl;

        std::ifstream f_let(path);
        if (!f_let)
        {
            _os << "file is not opened!" << std::endl;
        }
        else
        {
            std::string fl;
            for (auto &l : _buff)
            {
                std::getline(f_let, fl);
                l += fl + ' ';
            }
        }

        return *this;
    }

    LetBuffer &operator<<(const char *str)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            this->operator<<(str[i]);
        }

        return *this;
    }

    void print()
    {
        for (auto &l : _buff)
        {
            _os << l << std::endl;
        }
    }

    void clear()
    {
    }
};