// Lab-8_Shevel_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int** generateMatrix(int);
void printMatrix(int**, int);
int sumInRow(int**, int, int);
int sumInColumn(int**, int, int);
int sumInDiagonal(int**, int, string);
bool sumOfElementsInRows(int**, int);
bool sumOfElementsInColumns(int**, int);
bool sumOfElementsOnDiagonals(int**, int);
void isAMagicSquare(int**, int);


int main()
{
    int n;
    cout << "Enter the number of rows and columns: "; cin >> n;
    if (n < 2) {
        cout << "Matrix should contain at least 2 rows and columns";
    }
    else {
        int** matrix = generateMatrix(n);
        printMatrix(matrix, n); cout << endl;

        isAMagicSquare(matrix, n);
    }
}


int** generateMatrix(int n) {

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        matrix[i][j] = 1;/* rand() % 9;*/
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) 
            cout << matrix[i][j] <<" ";
            ;
        }
   
}

int sumInColumn(int** matrix, int n, int number) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][number];
    }
    return sum;
}

bool sumOfElementsInColumns(int** matrix, int n) {
    bool result = false;

    int check = sumInRow(matrix, n, 0);
    for (int counter = 1; counter < n; counter++) {
        if (check == sumInRow(matrix, n, counter)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}

bool sumOfElementsInRows(int** matrix, int n) {
    bool result = false;

    int check = sumInColumn(matrix, n, 0);
    for (int counter = 1; counter < n; counter++) {
        if (check == sumInColumn(matrix, n, counter)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}

int sumInRow(int** matrix, int n, int number) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[number][i];
    }

    return sum;
}

int sumInDiagonal(int** matrix, int n, string type) {
    int sum = 0;
    if (type == "main") {
        for (int i = 0; i < n; i++) {
            sum += matrix[i][i];
        }
    }
    else {
        int j = n-1;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
            j--;
        }
    }
    return sum;
}

bool sumOfElementsOnDiagonals(int** matrix, int n) {
    if (sumInDiagonal(matrix, n, "main") == sumInDiagonal(matrix, n, " ")) {
        return true;
    }
    return false;
};

void isAMagicSquare(int ** matrix, int n) {
    if (sumOfElementsInColumns(matrix, n) && sumOfElementsInRows(matrix, n) && sumOfElementsOnDiagonals(matrix, n)) {
        cout << "Is a magic square!!!";
    }
    else {
        cout << "Not a magic square :-(";
    }
}
 






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
