#pragma once
#include <iostream>
#include <random>
#include <ctime>

class Matrix{
    private:
        float** matrix;
        int cols, rows;
        bool exists;
    public:
        Matrix(const Matrix &other);
        Matrix();
        Matrix(int c, int r);
        ~Matrix();
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

        Matrix operator+(const Matrix &other);
        Matrix operator*(const Matrix &other);
};