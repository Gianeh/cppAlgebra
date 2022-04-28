#pragma once
#include <iostream>
#include <random>
#include <ctime>

class Array{
    private:
        float* array;
        int len;
        bool exists;
    public:
        Array(const Array &other);
        Array();
        Array(int l);
        ~Array();
        const int length();
        void set(float temp, int i);
        const float get(int i);
        void free();
        void reAllocate(int l);
        void compile();
        void show();
        float* ptr();

        //IMPORTANT, OPERATOR TAKES A REFERENCE (or pointer) NOT AN INSTANCE

        Array operator+(const Array &other);
        Array operator*(const Array &other);
        Array& operator++();
        Array& operator++(int);
        Array& operator--();
        Array& operator--(int);

};