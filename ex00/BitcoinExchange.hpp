#pragma once
#include <iterator>
#include <list>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>


struct data
{
    int date[3];
    float value;
};

class btc
{
    private:
    std::list<data> dv;
    float Return_last_update(data date);

    public:
    btc();
    btc(std::list<data> &tmp);
    btc(const btc &tmp);
    btc &operator=(const btc &tmp);
    void    Add(data &tmp);
    void    print_data();
    void    check_File_input(std::ifstream &F_N);
    ~btc();
};