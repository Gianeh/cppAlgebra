#include <iostream>
#include "Array.h"
#include "Matrix.h"

int main(){
        
        Matrix M(3,3);
        Array A(3);

        M.compile();
        A.compile();
        M.show();
        A.show();
        Matrix L = M * A;
        L.show();

        
        
        //Array A(3);
        //Array B(3);
        //A.compile();
        //B.compile();
        //Array C = A;
        

        //std::cout << std::endl << std::endl;
        //C.show();
        //++A;
        //A.show();
        //Array B(A.length());
        //B.compile();
        //Array C = A + B;
        //C++;
        //C.show();
        //B.show();
    return 0;
}