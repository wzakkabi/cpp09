#pragma once
#include <iterator>
#include <list>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iterator>
#include <iomanip>

struct data
{
    int date[3];
    float value;
};


class btc
{
    private:
    std::list<data> dv;

    public:
    btc();
    btc(std::list<data> &tmp);
    btc(const btc &tmp);
    btc &operator=(const btc &tmp);
    void    Add(data &tmp);
    void    print();
    ~btc();
};