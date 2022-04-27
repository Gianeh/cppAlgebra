#define Max 1000
#include "Matrix.h"


Matrix Matrix::operator+(const Matrix &other){
    Matrix temp;
    if(rows == other.rows && cols == other.cols){
        temp.reAllocate(rows,cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp.set(matrix[i][j] + other.matrix[i][j], i, j);
            }
            
            
        }return temp;

        
    }
    ///complete with other two cases rows = cols && cols = rows 
        return temp;
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix temp;
    if (cols != other.rows) return temp;
    temp.reAllocate(rows, other.cols);
    temp.zero();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < other.rows; k++) {
                temp.add(matrix[i][k] * other.matrix[k][j], i, j);
            }
        }
    }return temp;

}


Matrix::Matrix(const Matrix &other) {
    cols = other.cols;
    rows = other.rows;
    exists = true;
    matrix = new float*[rows];
    for (int k = 0; k < rows; k++) {
        matrix[k] = new float[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
Matrix::Matrix(){
    matrix = nullptr;
};
Matrix::Matrix(int r, int c){
        exists = true;
        cols = c, rows = r;
        matrix = new float*[rows];
        for(int k = 0; k < rows; k++){
            matrix[k] = new float[cols];
        }
}

Matrix::~Matrix(){
        //std::cout << "\n\nEnd of scope" << std::endl;
        if(exists) {
            //std::cout << "Cleaning memory ./." << std::endl;
            for(int k = 0; k < rows; k++){
                delete[] matrix[k];
            } delete[] matrix;
            std::cout << "Done..." << std::endl;

       }//else std::cout << "Already cleaned at RunTime!" << std::endl;
}

void Matrix::zero(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }return;
}
void Matrix::eye() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            i == j ? matrix[i][j] = 1 : matrix[i][j] = 0;
        }
    }return;
}
int Matrix::row(){
        return rows;
}
int Matrix::col(){
        return cols;
}
void Matrix::set(float temp, int i, int j){
        if(i < rows && j < cols && i >= 0 && j >= 0 && exists){
            matrix[i][j] = temp;
        }else if(!exists){
            std::cout << "Matrix deleted..." << std::endl;
            return;
        }else{
            std::cout << "Out of range" << std::endl;
            return;
        }
}
void Matrix::add(float temp, int i, int j) {
    matrix[i][j] += temp;
}
float Matrix::get(int i, int j){
        if(i < rows && j < cols && i >= 0 && j >= 0 && exists){
            return matrix[i][j];
        }else if(!exists){
            std::cout << "Matrix deleted..." << std::endl;
            return 0;
        }else{
            std::cout << "Out of range" << std::endl;
            return 0;
        }
}
void Matrix::free(){
        if(exists){
            for(int k = 0; k < rows; k++){
                delete[] matrix[k];
            }delete[] matrix;
            exists = false;
            std::cout << "Memory area cleaned!" << std::endl;
        }else return;
}
void Matrix::reAllocate(int r, int c){
        if(exists){
            free();
        }
        rows = r;
        cols = c;
        
        matrix = new float*[rows]();
        for(int k = 0; k < rows; k++){
            matrix[k] = new float[cols];
        }
        exists = true;
}
void Matrix::compile(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                float temp;
                std::cout << "Add new element[" << i << "][" << j << "]: ";
                std::cin >> temp;
                set(temp,i,j);
                std::cout << std::endl;
            }
        }
}
void Matrix::show(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                std::cout << "Matrix[" << i << "][" << j << "]: " << matrix[i][j] << "\t";
            }std::cout << std::endl << std::endl;     
        }
}
void Matrix::random(){
        srand(int(time(0)));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                set(float(rand()%Max),i,j);
            }
        }
}