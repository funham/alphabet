#pragma once

#include "cfg.hpp"
#include "Letter.hpp"
#include <ostream>
#include <fstream>
#include <string.h>

template <uint8_t H>
class LetBuffer
{
protected:
    Let_t _buff;

public:
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
            std::cerr << "couldn't find " << path << std::endl;
            return *this;
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

    void print(std::ostream &os)
    {
        for (auto &l : _buff)
        {
            os << l << std::endl;
        }
    }

    void flush()
    {
        for (auto &s : _buff)
        {
            s = "";
        }
    }
};

template <uint8_t H = LET_H>
std::ostream &operator<<(std::ostream &os, LetBuffer<H> &buff)
{
    buff.print(os);
    buff.flush();
    return os;
}