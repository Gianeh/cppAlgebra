#pragma once
#include <iostream>
#include <random>
#include <ctime>
template <typename T>
class Matrix{
    private:
        T** matrix;
        int cols, rows;
        //static
        static const int Max = 1000;
    public:
        //Constructors / Destructor
        Matrix(const Matrix<T> &other);
        Matrix();
        Matrix(int r, int c);
        ~Matrix();

        //static methods
        static Matrix<T> create();

        //methods
        void zero() const;
        void eye() const;
        int row() const;
        int col() const;
        void set(T temp, int i, int j) const;
        void add(T temp, int i, int j) const;
        T get(int i, int j) const;
        void show() const;
        void compile() const;
        void random() const;

        //Only work on Non-Const objects
        void free();
        void reAllocate(int c, int r);
        
        T operator()(int i, int j) const;
        T& operator()(int i, int j);
        Matrix<T> operator+(const Matrix<T> &other) const;  //matrix + matrix
        Matrix<T> operator*(const Matrix<T> &other) const;  //matrix * matrix
        Matrix<T>& operator=(const Matrix<T> &other);
        //needs #include "Array.h", of course, mine Array.h lib
        //Matrix operator*(const Array &other); //matrix * vector
};