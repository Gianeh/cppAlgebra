#include "Array.h"

//devo capire perchè passando una reference sono in grado di leggere il private ma funziona cosi

Array Array::operator+(const Array &other){
            Array temp;
            if(len != other.len) return temp;
            temp.reAllocate(len);
            for(int i = 0; i < len; i++){
                temp.set(array[i] + other.array[i], i);
            }
            return temp;
            
            }
Array Array::operator*(const Array& other) {
            Array temp;
            if (len != other.len) return temp;
            temp.reAllocate(len);
            for (int i = 0; i < len; i++) {
                temp.set(array[i] * other.array[i], i);
            }
            return temp;
}
Array& Array::operator++() {
    for (int i = 0; i < len; i++) {
        array[i]++;
    }return *this;
}
Array& Array::operator++(int) {
    for (int i = 0; i < len; i++) {
        array[i]++;
    }return *this;
}
Array& Array::operator--() {
    for (int i = 0; i < len; i++) {
        array[i]--;
    }return *this;
}
Array& Array::operator--(int) {
    for (int i = 0; i < len; i++) {
        array[i]--;
    }return *this;
}

//Copy constructor
Array::Array(const Array &other) {
            len = other.len;
            array = new float[len];
            exists = true;
            for (int k = 0; k < len; k++) {
                array[k] = other.array[k];
            }
}
//Void constructor
Array::Array(){
            array = nullptr;
}
//Default constructor
Array::Array(const int l){
            //array = malloc(l*sizeof(float));      //Doesn't work and is deprecated
            array = new float[l]();
            exists = true;
            len = l;
        }
//Destructor (cleans the array* pointer (float))
Array::~Array(){

            //std::cout << "\n\nEnd of scope" << std::endl;
            if(exists) {
                delete[] array;
                //std::cout << "Cleaning memory ./." << std::endl << "Done..." << std::endl;

            }//else std::cout << "Already cleaned at RunTime!" << std::endl;

        }

//static
Array Array::create(){
    int temp_len;
    std::cout << "Array length: ";
    std::cin >> temp_len;
    std::cout << std::endl;
    Array temp(temp_len);
    return temp;
}

void Array::free(){
            if(exists){
                delete[] array;
                exists = false;
                std::cout << "Memory area cleaned!" << std::endl;
            }
            return;
        }
// handles new dynamic allocation (change in size)
void Array::reAllocate(int l){
            if(exists){
                free();
            }
            len = l;
            array = new float[len]();
            exists = true;
        }
const int Array::length(){
            if(!exists) return 0;
            return len;
        }
void Array::set(float temp, int i){
            if (!(i >= len) && !(i < 0) && exists){
                array[i] = temp;
                return;
            }else if(!exists){
                std::cout << "Array deleted..." << std::endl;
                return;
            }else{
                std::cout << "Out of range" << std::endl;
                return;
            }
        }
const float Array::get(int i){
            if (!(i >= len) && !(i < 0) && exists){
                return array[i];
            }else if(!exists){
                std::cout << "Array deleted..." << std::endl;
                return 0;
            }else{
                std::cout << "Out of range" << std::endl;
                return 0;
            }
        }
void Array::compile(){

            for(int i = 0; i < len; i++){
                float temp;
                std::cout << "Add new element[" << i << "]: ";
                std::cin >> temp;
                set(temp,i);
                std::cout << std::endl;
            }
        }
void Array::show(){
            for(int i = 0; i < len; i++){
                std::cout << "Array[" << i << "]: " << array[i] << std::endl;
            }//std::cout << int(exists) << std::endl; //?
        }

float* Array::ptr(){
    return array;
}