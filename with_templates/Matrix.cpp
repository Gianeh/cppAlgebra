//BOOLEAN VERSION OF MY MATRIX CLASS
#include "Matrix.h"


template <typename T>
T Matrix<T>::operator()(int i, int j) const{
    return matrix[i][j];
}
template <typename T>
T& Matrix<T>::operator()(int i, int j){
    return matrix[i][j];
}
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const{
    Matrix<T> temp;
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
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const{
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
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other){
    if(this == &other) return *this;
    cols = other.cols;
    rows = other.rows;
    free();
    matrix = new T*[rows];
    for (int k = 0; k < rows; k++){
        matrix[k] = new T[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;

}
template <typename T>
//copy constructor
Matrix<T>::Matrix(const Matrix<T> &other) {
    
    cols = other.cols;
    rows = other.rows;
    free();
    matrix = new bool*[rows];
    for (int k = 0; k < rows; k++) {
        matrix[k] = new bool[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
//void constructor
template <typename T>
Matrix<T>::Matrix(){
    matrix = nullptr;
};
//default constructor
template <typename T>
Matrix<T>::Matrix(int r, int c){
        cols = c, rows = r;
        matrix = new T*[rows];
        for(int k = 0; k < rows; k++){
            matrix[k] = new T[cols];
        }
}
//destructor
template <typename T>
Matrix<T>::~Matrix(){
        if(matrix != nullptr) {
            //std::cout << "destructor" << std::endl;
            for(int k = 0; k < rows; k++){
                //std::cout << "destroyed " << k << std::endl;
                if (matrix[k] != nullptr){
                    delete[] matrix[k];
                    matrix[k] = nullptr;
                }
            } delete[] matrix;
            matrix = nullptr;
            //std::cout << "Done..." << std::endl;
       }//else std::cout << "Already cleaned at RunTime!" << std::endl;
}

//static
template <typename T>
Matrix<T> Matrix<T>::create(){
    int temp_rows, temp_cols;
    std::cout << "Matrix rows: ";
    std::cin >> temp_rows;
    std::cout << "Matrix cols: ";
    std::cin >> temp_cols;
    std::cout << std::endl;
    Matrix<T> temp(temp_rows, temp_cols);
    bool tempval;
    for(int i = 0; i < temp.col(); i ++){
        for(int j = 0; j < temp.row(); j++){
            std::cout << "M[" << i << "][" << j << "]: ";
            std::cin >> tempval;
            temp.set(tempval, i,j);
        }
    }
    return temp;
}
template <typename T>
void Matrix<T>::zero() const{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }return;
}
template <typename T>
void Matrix<T>::eye() const{
    if(cols != rows){ return; }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            i == j ? matrix[i][j] = true : matrix[i][j] = false;
        }
    }return;
}
template <typename T>
int Matrix<T>::row() const{
        return rows;
}
template <typename T>
int Matrix<T>::col() const{
        return cols;
}
template <typename T>
void Matrix<T>::set(T temp, int i, int j) const{
        if(i < rows && j < cols && i >= 0 && j >= 0 && matrix != nullptr){
            matrix[i][j] = temp;
        }else if(matrix == nullptr){
            std::cout << "Matrix deleted..." << std::endl;
            return;
        }else{
            std::cout << "Out of range" << std::endl;
            return;
        }
}
template <typename T>
void Matrix<T>::add(T temp, int i, int j) const{
    matrix[i][j] += temp;
}
template <typename T>
T Matrix<T>::get(int i, int j) const{
        if(i < rows && j < cols && i >= 0 && j >= 0 && matrix != nullptr){
            return matrix[i][j];
        }else if(matrix == nullptr){
            std::cout << "Matrix deleted..." << std::endl;
            return 0;
        }else{
            std::cout << "Out of range" << std::endl;
            return 0;
        }
}
template <typename T>
void Matrix<T>::compile() const{
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bool temp;
                std::cout << "Add new element[" << i << "][" << j << "]: ";
                std::cin >> temp;
                set(temp,i,j);
                std::cout << std::endl;
            }
        }
}
template <typename T>
void Matrix<T>::show() const{
        if(matrix == nullptr) return;
        std::cout << std::endl;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                std::cout << "Matrix[" << i << "][" << j << "]: " << matrix[i][j] << "\t";
            }std::cout << std::endl << std::endl;     
        }
}
template <typename T>
void Matrix<T>::random() const{
        srand(int(time(0)));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                set(bool(rand()%2),i,j);
            }
        }
}
//non-const object methods
template <typename T>
void Matrix<T>::free(){
        if(matrix != nullptr){
            //std::cout << "free" << std::endl;
            for(int k = 0; k < rows; k++){
                //std::cout << "freed " << k << std::endl;
                if (matrix[k] != nullptr){
                    delete[] matrix[k];
                    matrix[k] = nullptr;
                }
            }delete[] matrix;
            matrix = nullptr;
            //std::cout << "Memory area cleaned!" << std::endl;
        }else{
            return;
        }
}
template <typename T>
void Matrix<T>::reAllocate(int r, int c){
        free();
        rows = r;
        cols = c;
        
        matrix = new T*[rows]();
        for(int k = 0; k < rows; k++){
            matrix[k] = new T[cols];
        }
}
