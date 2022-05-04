#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Array.h"


class Matrix{
    private:
        float** matrix;
        int cols, rows;
        bool exists = false;
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
        void zero() const;
        void eye() const;
        int row() const;
        int col() const;
        void set(float temp, int i, int j) const;
        void add(float temp, int i, int j) const;
        float get(int i, int j) const;
        void show() const;
        void compile() const;
        void random() const;

        //Only work on Non-Const objects
        void free();
        void reAllocate(int c, int r);
        

        Matrix operator+(const Matrix &other) const;  //matrix + matrix
        Matrix operator*(const Matrix &other) const;  //matrix * matrix
        //Matrix operator*(const Array &other); //matrix * vector
};