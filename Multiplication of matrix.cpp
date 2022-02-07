#include <iostream>
#include <cmath>
#include <new>

using namespace std;
#define VALUE 10

int main() {

    double** matrix1;
    double** matrix2;
    double** multi ;
    int i, j, row1, col1,row2,col2 ;
  
    srand(time(0));
   // cout << "How many rows & col of matrixa: ";
   // cin >> row1>>col1;
    row1 = rand() % VALUE;
    col1 = rand() % VALUE;
    //cout << "How many rows & col of matrixb: ";
    //cin >> row2>>col2;
    
    row2 = col1;
    col2 = rand() % VALUE;

    try {
        //Here we reserve an array of pointers of type double.
        matrix1 = new double* [row1];
        

    }
    catch (bad_alloc& xa) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }


    for (i = 0; i < row1; i++) {
        try {

            //Here we reserve row arrays of type integer.
            matrix1[i] = new double[col1];

        }
        catch (bad_alloc& xa) {
            cout << "Memory allocation failed!" << endl;
            return 1;
        }
    }

    
    //Here we initialise the matrix.
    for (i = 0; i < row1; i++)
        for (j = 0; j < col1; j++) {
            matrix1[i][j] = rand() % 10;
            
        }

    //Here we print the content of the matrix.
    cout << "The matrixa is:\n";
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

   
    try {
        //Here we reserve an array of pointers of type double.
        matrix2 = new double* [row2];


    }
    catch (bad_alloc& xa) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    for (i = 0; i < row2; i++) {
        try {

            //Here we reserve row arrays of type integer.
            matrix2[i] = new double[col2];

        }
        catch (bad_alloc& xa) {
            cout << "Memory allocation failed!" << endl;
            return 1;
        }
    }
    //Here we initialise the matrix.
    for (i = 0; i < row2; i++)
        for (j = 0; j < col2; j++) {
            matrix2[i][j] = rand() % 10;
            
        }

    //Here we print the content of the matrix.
    cout << "The matrixb is:\n";
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            cout << matrix2[i][j] << "\t";
        }
        cout << endl;
    }

    try {
        //Here we reserve an array of pointers of type double.
       multi = new double* [row1];


    }
    catch (bad_alloc& xa) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    for (i = 0; i < row1; i++) {
        try {

            //Here we reserve row arrays of type integer.
            multi[i] = new double[col2];

        }
       catch (bad_alloc& xa) {
            cout << "Memory allocation failed!" << endl;
            return 1;
        }
    }


    cout << endl;
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            multi[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                multi[i][j] += matrix1[i][k] * matrix2[k][j];

            }
        }
    }


        cout << "Multiplication result" << endl;
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            cout << multi[i][j] << "\t";
        }
        cout << endl;
    }
   

    //Here we free locations of the array of pointers.
    //Remember that each location of the array of poniters refers to an array
    //of integer numbers.
    for (i = 0; i < row1; i++)
      delete[] matrix1[i];

    //////Here we free the array of pointers
    delete[] matrix1;
    for (i = 0; i < row2; i++)
        delete[] matrix2[i];

    //////Here we free the array of pointers
    delete[] matrix2;
    for (i = 0; i < row1; i++)
        delete[] multi[i];

    //////Here we free the array of pointers
    delete[] multi;

    return 0;

}

