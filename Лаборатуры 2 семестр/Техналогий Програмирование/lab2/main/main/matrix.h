#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <fstream>

class Matrix
{
private:
    unsigned int width;
    unsigned int height;
    double** data;
public:
    double other;
    Matrix();
    Matrix(unsigned int w, unsigned int h);
    Matrix(const Matrix& other);
    void createMatrix();
    void deleteMatrix();
    void setWidth(unsigned int w);
    void setHeight(unsigned int h);
    void setWidthHeight(unsigned int w, unsigned int h);
    void setFactor(unsigned int w, unsigned int h);
    void getMatrixFromFile(std::string file_name);
    void getMatrixFrom_File(std::string file_name);
    void getMatrixfactorFrom_File(std::string file_name);
    void setElement(unsigned int i, unsigned int j, double value);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator*(double value);
    Matrix& operator=(const Matrix& other);
    void print() const;
    ~Matrix();
};

#endif // MATRIX_H
#pragma once
