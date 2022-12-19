#include <iostream>
#include <vector>
#include<cmath>
using namespace std;


    //Возвращает матрицу matrix без row-ой строки и col-того столбца, результат в newMatrix
    void Minor(int** matrix, int size, int row, int col, int** newMatrix) {
        int Row = 0; //Смещение индекса строки в матрице
        int Col = 0; //Смещение индекса столбца в матрице
        for (int i = 0; i < size - 1; i++) {
            //Пропустить row-ую строку
            if (i == row) {
                Row = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
            }

            Col = 0; //Обнулить смещение столбца
            for (int j = 0; j < size - 1; j++) {
                //Пропустить col-ый столбец
                if (j == col) {
                    Col = 1; //Встретили нужный столбец, проускаем его смещением
                }

                newMatrix[i][j] = matrix[i + Row][j + Col];
            }
        }
    }

    int matrixDet(int** matrix, int size) {
        int det = 0;
        int degree = 1; // (-1)^(1+j)

        if (size == 1) {
            return matrix[0][0];
        }
        else if (size == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        else {
            //Матрица без строки и столбца
            int** newMatrix = new int* [size - 1];
            for (int i = 0; i < size - 1; i++) {
                newMatrix[i] = new int[size - 1];
            }

            //Раскладываем по 0-ой строке, цикл бежит по столбцам
            for (int j = 0; j < size; j++) {
                
                Minor(matrix, size, 0, j, newMatrix);

                det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
                
                degree = -degree;
            }

            for (int i = 0; i < size - 1; i++) {
                delete[] newMatrix[i];
            }
            delete[] newMatrix;
        }
        
        return det;
    }
    int main(){
        setlocale(0, "Russian");
        int n;
 
        cout << "Введите размер квадратной матрицы:" << endl;
        cin >> n;
        int** num = new int* [n];   // создаем двумерный массив
        for (int i = 0; i < n; i++) { 
            num[i] = new int[n]; 
        } 
    
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> num[i][j];
            }
        }

      
        cout << "Вычисляем определитель данной матрицы:" << endl;
        for (int k = 0; k < n; k++) {
            for (int m = 0; m < n; m++) {
                cout << num[k][m] << " ";
            }
            cout << endl;
        }
 
        int det = matrixDet(num, n);

        cout << "Определитель равен: "<< det << endl;

        for (int i = 0; i < n; i++) {
            delete[] num[i];  // удаляем массив
        }
}
