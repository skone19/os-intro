#include "matrix.h"

Matrix::Matrix()
{
    std::cout << "Default constructor is called\n";
    width = 0;
    height = 0;
    other = 0;
    data = nullptr;
}

Matrix::Matrix(unsigned int w, unsigned int h)
{
    std::cout << "Constructor is called\n";
    height = h;
    width = w;
    createMatrix();
}

Matrix::Matrix(const Matrix& other)
{
    std::cout << "Copy constructor is called\n";
    width = other.width;
    height = other.height;
    createMatrix();
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix()
{
    deleteMatrix();
}

void Matrix::createMatrix()
{
    data = new double* [height];
    for (unsigned int i = 0; i < height; i++)
    {
        data[i] = new double[width];
        for (unsigned int j = 0; j < width; j++)
            data[i][j] = 0;
    }
}


void Matrix::deleteMatrix()
{
    for (unsigned int i = 0; i < height; i++)
        delete[] data[i];
    delete[] data;
}

void Matrix::print() const
{
    if (height != 0 && width != 0)
        for (unsigned int i = 0; i < height; i++)
        {
            for (unsigned int j = 0; j < width; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
}

void Matrix::setWidth(unsigned int w)
{
    if (height != 0 && width != 0)
        deleteMatrix();
    width = w;
    if (height != 0 && width != 0)
        createMatrix();
}

void Matrix::setHeight(unsigned int h)
{
    if (height != 0 && width != 0)
        deleteMatrix();
    height = h;
    if (height != 0 && width != 0)
        createMatrix();
}

void Matrix::setWidthHeight(unsigned int w, unsigned int h)
{
    if (height != 0 && width != 0)
        deleteMatrix();
    width = w;
    height = h;
    if (height != 0 && width != 0)
        createMatrix();
}




void Matrix::setElement(unsigned int i, unsigned int j, double value)
{
    data[i][j] = value;
}

void Matrix::getMatrixFromFile(std::string dama)
{
    std::ifstream input;
    input.open(dama);
    if (input.is_open())
    {
        input >> height;
        input >> width;
        createMatrix();
        for (unsigned int i = 0; i < height; i++)
            for (unsigned int j = 0; j < width; j++)
            {
                if (input.eof())
                {
                    std::cout << "Error! Reached EOF!\n";
                    input.close();
                    return;
                }
                input >> data[i][j];
            }
        if (!input.eof())
            std::cout << "Error! All data was loaded, but EOF has not been reached!\n";

    }
    else
    {
        std::cout << "Error! File is not open!\n";
        return;
    }
    input.close();
}

void Matrix::getMatrixFrom_File(std::string damo)
{
    std::ifstream inpu;
    inpu.open(damo);
    if (inpu.is_open())
    {
        inpu >> height;
        inpu >> width;
        createMatrix();
        for (unsigned int i = 0; i < height; i++)
            for (unsigned int j = 0; j < width; j++)
            {
                if (inpu.eof())
                {
                    std::cout << "Error! Reached EOF!\n";
                    inpu.close();
                    return;
                }
                inpu >> data[i][j];
            }
        if (!inpu.eof())
            std::cout << "Error! All data was loaded, but EOF has not been reached!\n";

    }
    else
    {
        std::cout << "Error! File is not open!\n";
        return;
    }
    inpu.close();
}

/*void Matrix::getMatrixfactorFrom_File(std::string dam)
{
    std::ifstream inpa;
    inpa.open(dam);
    if (inpa.is_open())
    {
        inpa >> other;
       for (unsigned int i = 0; i < other; i++)
          for (unsigned int j = 0; j < other; j++)
            {
                if (inpa.eof())
                {
                    std::cout << "Error! Reached EOF!\n";
                    inpa.close();
                    return;
                }
                inpa >> other;
            }
        if (!inpa.eof())
            std::cout << "Error! All data was loaded, but EOF has not been reached!\n";

    }
    else
    {
        std::cout << "Error! File is not open!\n";
        return;
    }
    inpa.close();
}*/
Matrix Matrix::operator +(const Matrix& other)
{
    std::cout << "Operator + is called\n";
    Matrix result(width, height);
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            result.setElement(i, j, data[i][j] + other.data[i][j]);
    return result;
}

Matrix Matrix :: operator-(const Matrix& other)
{
    std::cout << "Operator - is called\n";
    Matrix result(width, height);
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            result.setElement(i, j, data[i][j] - other.data[i][j]);
    return result;
}

Matrix  Matrix:: operator*(const Matrix& other)
{
    std::cout << "Operator * is called\n";
    if (width == other.height) {
        Matrix result(other.width, height);
        double** restant = new double* [height];
        for (int i = 0; i < height; i++) {
            restant[i] = new double[other.width];
            for (int j = 0; j < other.width; j++) {
                restant[i][j] = 0;
                for (int k = 0; k < width; k++) {
                    restant[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        for (int i = 0; i < height; i++)
            for (int j = 0; j < other.width; j++)
                result.setElement(i, j, restant[i][j]);
        return result;

    }
    else {
        Matrix result;
        std::cout << "Error!!!";
        return result;
    }
}

Matrix Matrix::operator*(const double value)
{
    std::cout << "Operator * is called\n";
    Matrix result(width, height);
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            result.setElement(i, j, data[i][j] * value);
    return result;
}

Matrix& Matrix::operator =(const Matrix& other)
{
    std::cout << "Operator = is called\n";
    width = other.width;
    height = other.height;
    createMatrix();
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            data[i][j] = other.data[i][j];
    return *this;
}
