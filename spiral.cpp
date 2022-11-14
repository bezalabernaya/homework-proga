
#include <iostream>
#include <string>
#include <vector>
using  namespace std;

int main()
{
    int n;    
    cin >> n;  

    vector < vector <int> > matr(n, vector <int>(n)); // Объявление вектора на n строк по m элементов 
    int x = 1;

    for (int i = 0; i < n-2; i++){
        for (int j = i; j < n - i; j++) {
            matr[i][j] = x;
            x++;
        }
        x--;
        for (int j = i; j < n - i; j++) {
            matr[j][n - 1 - i] = x;
            x++;
        }
        x--;
        for (int j = n - 1 - i; j >= i; j--) {
            matr[n - 1 - i][j] = x;
            x++;
        }
        x--;
        for (int j = n - 1 - i; j >= 1 + i; j--) {
            matr[j][i] = x;
            x++;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int m = 0; m < n; m++) {
            cout << matr[k][m] << " ";
        }
        cout << endl;
    }
    string M;
    for (int d = 0; d < 3; d++) {
        M = d + 1;
    }
    setlocale(0, "Russian");
    cout <<"Поставьте зачетик плиз " << M;
    return 0;
}
