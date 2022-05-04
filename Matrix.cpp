
#include "Matrix.h"
#include "Array.h"

int Matrix::counter = 0;

Matrix Matrix::operator+(const Matrix &other) const{
    Matrix temp;
    if(rows == other.rows && cols == other.cols){
        temp.reAllocate(rows,cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp.set(matrix[i][j] + other.matrix[i][j], i, j);
            }
            
            
        }return temp;
    }
    //if some kind of sum is still possible (same number of elements) returns a sum matrix shaped as the first
    if(rows == other.cols && cols == other.rows){
        temp.reAllocate(rows,cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp.set(matrix[i][j] + other.matrix[j][i], i, j);
            }
        }
        
    }//no possible sum formula (unless you "decide" one)
        return temp;
}

/*
//Assumes a column array
Matrix Matrix::operator*(Array &other){
    Matrix temp;
    if(cols != other.length()) return temp;
    temp.reAllocate(rows, 1);
    temp.zero();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp.add(matrix[i][j] * other.ptr()[j], i, j);
        }
    }
    return temp;
}
*/

Matrix Matrix::operator*(const Matrix& other) const{
    Matrix temp;
    if (cols != other.rows) return temp;
    std::cout << "Matrix crime! check your matrices" << std::endl;
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

//copy constructor
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
    Matrix::counter++;
}
//void constructor
Matrix::Matrix(){
    matrix = nullptr;
    Matrix::counter++;
};
//default constructor
Matrix::Matrix(int r, int c){
        exists = true;
        cols = c, rows = r;
        matrix = new float*[rows];
        for(int k = 0; k < rows; k++){
            matrix[k] = new float[cols];
        }
        Matrix::counter++;
}
//destructor
Matrix::~Matrix(){
        //std::cout << "\n\nEnd of scope" << std::endl;
        if(exists) {
            //std::cout << "Cleaning memory ./." << std::endl;
            for(int k = 0; k < rows; k++){
                delete[] matrix[k];
            } delete[] matrix;
            std::cout << "Done..." << std::endl;
            Matrix::counter--;

       }//else std::cout << "Already cleaned at RunTime!" << std::endl;
}

//static
Matrix Matrix::create(){
    int temp_rows, temp_cols;
    std::cout << "Matrix rows: ";
    std::cin >> temp_rows;
    std::cout << "Matrix cols: ";
    std::cin >> temp_cols;
    std::cout << std::endl;
    Matrix temp(temp_rows, temp_cols);
    float tempval;
    for(int i = 0; i < temp.col(); i ++){
        for(int j = 0; j < temp.row(); j++){
            std::cout << "M[" << i << "][" << j << "]: ";
            std::cin >> tempval;
            temp.set(tempval, i,j);
        }
    }
    return temp;
}

void Matrix::zero() const{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }return;
}
void Matrix::eye() const{
    if(cols != rows){ return; }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            i == j ? matrix[i][j] = 1 : matrix[i][j] = 0;
        }
    }return;
}
int Matrix::row() const{
        return rows;
}
int Matrix::col() const{
        return cols;
}
void Matrix::set(float temp, int i, int j) const{
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
void Matrix::add(float temp, int i, int j) const{
    matrix[i][j] += temp;
}
float Matrix::get(int i, int j) const{
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
void Matrix::compile() const{
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
void Matrix::show() const{
        std::cout << std::endl;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                std::cout << "Matrix[" << i << "][" << j << "]: " << matrix[i][j] << "\t";
            }std::cout << std::endl << std::endl;     
        }
}
void Matrix::random() const{
        srand(int(time(0)));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                set(float(rand()%Max),i,j);
            }
        }
}

//non-const object methods
void Matrix::free(){
        if(exists){
            for(int k = 0; k < rows; k++){
                delete[] matrix[k];
            }delete[] matrix;
            exists = false;
            std::cout << "Memory area cleaned!" << std::endl;
            Matrix::counter--;
        }else{
            return;
        }
}
void Matrix::reAllocate(int r, int c){
        if(exists){
            free();
            Matrix::counter++;
        }
        rows = r;
        cols = c;
        
        matrix = new float*[rows]();
        for(int k = 0; k < rows; k++){
            matrix[k] = new float[cols];
        }
        exists = true;
}
