// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "matrix.h"
using namespace std;

int main()
{
   /* ifstream input("dama.txt");
    if (!input)
    {
        cerr << "dama.txt could not be opened for reading!" << endl;
        exit(1);
    }
    while (input)
    {
        string strInput;
        getline(input, strInput);
        cout << strInput << endl;

    }

    ifstream inpu("damo.txt");
    if (!inpu)
    {
        cerr << "damo.txt could not be opened for reading!" << endl;
        exit(1);
    }
    while (inpu)
    {
        string strInpu;
        getline(inpu, strInpu);
        cout << strInpu << endl;

    }*/
    
    Matrix My_Matrix;
    int other;
    int number;
    Matrix matrixA;
    Matrix matrixB;
    Matrix matrixC;
    bool Exit = true;
    while (Exit) {
        int operation = 0;
cout <<">-----WELCOME TO PROGRAMM OF OPERATION IN MATRIX------<"<<endl;
cout <<"Choose operation:\n\
            1-Addition\n\
            2-Substration\n\
            3-Multiplication\n\
            4-Multiplication of number\n\
            5-exit\n";
        bool go = true;
        while (go) {
            cout << "Input number Operation :\n";
            cin >> operation;
          

            /*ifstream inpa("dam.txt");
            if (!inpa)
            {
                cerr << "damo.txt could not be opened for reading!" << endl;
                exit(1);
            }
            while (inpa)
            {
                string strInpa;
                getline(inpa, strInpa);
                cout << strInpa << endl;

            }*/
            if (operation <= 0 || operation > 5)
            {
                cout << "Error\n";
                continue;
            }
            switch (operation) {
            case 1: {
                My_Matrix.createMatrix();
                break;
            }
            case 2: {
                My_Matrix.createMatrix();
                break;
            }
            case 3: {
                My_Matrix.createMatrix();
                break;
            }
            case 4: {
                My_Matrix.createMatrix();
                break;
            }
            case 5: {
                go = false;
                Exit = false;
                cout << "Programm completed successfully!!!\n\n";
                break;
            }
            default: {
                cout << "Error! Insert from 1 to 4\n";
                break;
            }
            }
            if (operation == 1) {
                matrixA.getMatrixFromFile("dama.txt");
                matrixB.getMatrixFrom_File("damo.txt");
                matrixA.print();
                std::cout << "_________\n";
                matrixB.print();
                std::cout << "_________\n";
                matrixC = matrixA + matrixB;
                std::cout << "_________\n";
                matrixC.print();
            }
            else if (operation == 2) {
                matrixA.getMatrixFromFile("dama.txt");
                matrixB.getMatrixFrom_File("damo.txt");
                matrixA.print();
                std::cout << "_________\n";
                matrixB.print();
                std::cout << "_________\n";
                matrixC = matrixA - matrixB;
                std::cout << "_________\n";
                matrixC.print();
            }
            else if (operation == 3) {
                matrixA.getMatrixFromFile("dama.txt");
                matrixB.getMatrixFrom_File("damo.txt");
                matrixA.print();
                std::cout << "_________\n";
                matrixB.print();
                std::cout << "_________\n";
                matrixC = matrixA * matrixB;
                std::cout << "_________\n";
                matrixC.print();
            }
            else if (operation == 4) {
                cout << "Input number factor :\n";
                cin >> number;
                matrixA.getMatrixFromFile("dama.txt");
                //matrixB.getMatrixFrom_File("damo.txt");
                matrixA.print();
                std::cout << "_________\n";
                matrixB.print();
                std::cout << "_________\n";
                matrixC = matrixA * number;
                std::cout << "_________\n";
                matrixC.print();
            }
        }
    }
    return 0;
}
