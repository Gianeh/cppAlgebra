#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Matrix.h"

class Array{
    private:
        
        float* array;
        int len;
        bool exists;
    public:
        //Constructors / Destructors
        Array(const Array &other);
        Array();
        Array(const int l);
        ~Array();

        //static variables
        static int counter;

        //static methods
        static Array create();

        //methods
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
        //Matrix operator*(const Matrix &other); matrix * array
        Array& operator++();
        Array& operator++(int);
        Array& operator--();
        Array& operator--(int);

};