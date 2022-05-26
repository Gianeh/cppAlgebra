#include "Array.h"
#include "Matrix.h"

// devo capire perchè passando una reference sono in grado di leggere il private ma funziona cosi
template <typename T>
Array<T> Array<T>::operator+(const Array<T> &other) const
{
    Array temp;
    if (len != other.len)
        return temp;
    temp.reAllocate(len);
    for (int i = 0; i < len; i++)
    {
        temp.set(array[i] + other.array[i], i);
    }
    return temp;
}
template <typename T>
Array<T> Array<T>::operator*(const Array<T> &other) const
{
    Array temp;
    if (len != other.len)
        return temp;
    temp.reAllocate(len);
    for (int i = 0; i < len; i++)
    {
        temp.set(array[i] * other.array[i], i);
    }
    return temp;
}
// increment operators, only work on Non-Const objects
template <typename T>
Array<T> &Array<T>::operator++()
{
    for (int i = 0; i < len; i++)
    {
        array[i]++;
    }
    return *this;
}
template <typename T>
Array<T> &Array<T>::operator++(int)
{
    for (int i = 0; i < len; i++)
    {
        array[i]++;
    }
    return *this;
}
template <typename T>
Array<T> &Array<T>::operator--()
{
    for (int i = 0; i < len; i++)
    {
        array[i]--;
    }
    return *this;
}
template <typename T>
Array<T> &Array<T>::operator--(int)
{
    for (int i = 0; i < len; i++)
    {
        array[i]--;
    }
    return *this;
}
// Copy constructor
template <typename T>
Array<T>::Array(const Array<T> &other)
{
    len = other.len;
    array = new T[len];
    for (int k = 0; k < len; k++)
    {
        array[k] = other.array[k];
    }
}
// Void constructor
template <typename T>
Array<T>::Array()
{
    array = nullptr;
}
// Default constructor
template <typename T>
Array<T>::Array(const int l)
{
    array = new T[l]();
    len = l;
}
// Destructor (cleans the array* pointer (float))
template <typename T>
Array<T>::~Array()
{

    // std::cout << "\n\nEnd of scope" << std::endl;
    if (array != nullptr)
    {
        delete[] array;
        // std::cout << "Cleaning memory ./." << std::endl << "Done..." << std::endl;

    } // else std::cout << "Already cleaned at RunTime!" << std::endl;
}

// static
template <typename T>
Array<T> Array<T>::create()
{
    int temp_len;
    std::cout << "Array length: ";
    std::cin >> temp_len;
    std::cout << std::endl;
    Array<T> temp(temp_len);
    temp.compile();
    return temp;
}
template <typename T>
const int Array<T>::length() const
{
    if (array == nullptr)
        return 0;
    return len;
}
template <typename T>
void Array<T>::set(T temp, int i) const
{
    if (!(i >= len) && !(i < 0) && array != nullptr)
    {
        array[i] = temp;
        return;
    }
    else if (array == nullptr)
    {
        std::cout << "Array deleted..." << std::endl;
        return;
    }
    else
    {
        std::cout << "Out of range" << std::endl;
        return;
    }
}
template <typename T>
const T Array<T>::get(int i) const
{
    if (!(i >= len) && !(i < 0) && array != nullptr)
    {
        return array[i];
    }
    else if (array == nullptr)
    {
        std::cout << "Array deleted..." << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Out of range" << std::endl;
        return 0;
    }
}
template <typename T>
void Array<T>::compile() const
{
    for (int i = 0; i < len; i++)
    {
        T temp;
        std::cout << "Add new element[" << i << "]: ";
        std::cin >> temp;
        set(temp, i);
        std::cout << std::endl;
    }
}
template <typename T>
void Array<T>::show() const
{
    if (array == nullptr)
        return;
    for (int i = 0; i < len; i++)
    {
        std::cout << "Array[" << i << "]: " << array[i] << std::endl;
    }
}
template <typename T>
T *Array<T>::ptr() const
{
    return array;
}

// handles new dynamic allocation (change in size)
template <typename T>
void Array<T>::reAllocate(int l)
{
    if (array != nullptr)
    {
        free();
    }
    len = l;
    array = new T[len]();
}
template <typename T>
void Array<T>::free()
{
    if (array != nullptr)
    {
        delete[] array;
        std::cout << "Memory area cleaned!" << std::endl;
    }
    return;
}