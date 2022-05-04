#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Array.h"


class Matrix{
    private:
        float** matrix;
        int cols, rows;
        bool exists;
        //static
        static const int Max = 1000;
    public:
        //static
        static int counter;

        //Constructors / Destructor
        Matrix(const Matrix &other);
        Matrix();
        Matrix(int c, int r);
        ~Matrix();

        //static methods
        static Matrix create();

        //methods
        void zero();
        void eye();
        int row();
        int col();
        void set(float temp, int i, int j);
        void add(float temp, int i, int j);
        float get(int i, int j);
        void free();
        void reAllocate(int c, int r);
        void compile();
        void show();
        void random();

        Matrix operator+(const Matrix &other);  //matrix + matrix
        Matrix operator*(const Matrix &other);  //matrix * matrix
        //Matrix operator*(const Array &other); //matrix * vector
};