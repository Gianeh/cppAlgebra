#include <iostream>
#include "Array.h"
#include "Array.cpp"
#include "Matrix.h"

int main()
{
    Array<std::string> list(100);
    list.set("Hello world!", 5);
    std::cout << list.get(5) << std::endl;
    list.reAllocate(2);
    list.set("Hello",1);
    Array<std::string> A = Array<std::string>::create();
    std::cout << A.get(2) << std::endl;
    // const operators tests
    /*
    const Array A(5);
    A.compile();
    Array B = A + A;
    B.show();
    Array C = B + B;
    C.show();
    */

    // const tests
    /*
    const Matrix A = Matrix::create();
    A.compile();
    A.eye();
    A.add(1,0,0);
    A.set(1,0,0);
    A.zero();
    std::cout << A.col() << std::endl;
    Matrix B(10,10);
    B.eye();
    B.set(1,0,0);
    B.zero();
    std::cout << B.col() << std::endl;
    A.show();
    B.show();

    B.free();
    */

    // tests on global counter
    /*
    Matrix A(3,3);
    Matrix B(1,2);
    std::cout << Matrix::counter << std::endl;
    B.free();
    std::cout << Matrix::counter << std::endl;
    Matrix C = A;
    std::cout << Matrix::counter << std::endl;
    */

    /*
    Matrix M(3,3);
    Array A(3);
    M.compile();
    A.compile();
    M.show();
    A.show();
    Matrix L = M * A;
    L.show();
    */

    // asks user to cin size and prints the temporaneus array.length()
    // std::cout << Array::create().length() << std::endl;

    // Matrix M = Matrix::create();

    // Array A(3);
    // Array B(3);
    // A.compile();
    // B.compile();
    // Array C = A;

    // std::cout << std::endl << std::endl;
    // C.show();
    //++A;
    // A.show();
    // Array B(A.length());
    // B.compile();
    // Array C = A + B;
    // C++;
    // C.show();
    // B.show();
    return 0;
}
//