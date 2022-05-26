#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Matrix.h"

template <typename T>
class Array
{
private:
    T *array;
    int len;

public:
    // Constructors / Destructors
    Array(const Array<T> &other);
    Array();
    Array(const int l);
    ~Array();

    // static methods
    static Array<T> create();

    // methods
    const int length() const;
    void set(T temp, int i) const;
    const T get(int i) const;
    void compile() const;
    void show() const;
    T *ptr() const;

    // only work on Non-Const objects
    void free();

    void reAllocate(int l);

    // IMPORTANT, OPERATOR TAKES A REFERENCE (or pointer) NOT AN INSTANCE

    Array<T> operator+(const Array<T> &other) const;
    Array<T> operator*(const Array<T> &other) const;
    // Matrix operator*(const Matrix &other); matrix * array
    Array<T> &operator++();
    Array<T> &operator++(int);
    Array<T> &operator--();
    Array<T> &operator--(int);
};
