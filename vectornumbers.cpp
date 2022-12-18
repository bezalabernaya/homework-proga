#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using  namespace std;

int main()
{
    setlocale(0, "Russian");
    int x ;//вводимые числа
    cout << " Введите числа: " << endl;
    size_t r = 0;// счетчик уникальных чисел 
    int a = 1;//счетчик повторений чисел
    vector < vector <int> > num(2, vector <int>());
    
    for (; ;) {
        cin >> x;
        int h = x;
        if (h == 0) {
            break;
        }
        else {
            num[0].insert(num[0].end(),x);
            num[1].insert(num[1].end(), 1);
        }
    }

    size_t n = num[0].size();
    sort(num[0].begin(), num[0].end());
  
    for (size_t j = 1; j < n; j++) {
        if (num[0][j-1] != num[0][j]) {
            a = 1;
            num[1][r] = a;
            num[0][r] = num[0][j - 1];
            if (j == n - 1) {
                num[1][r + 1] = a;
                num[0][r + 1] = num[0][j];
            }
        }
        else {
            while (num[0][j - 1] == num[0][j]) {
                a++;
                j++;
                if (j == n) {
                    break;
                }
            }
            num[1][r] = a;
            num[0][r] = num[0][j - 1];
        }
        a = 1;
        r++;
    }
    num[0].resize(r);
    num[1].resize(r);
    
    cout << " Полученный вектор: " << endl;

    for (size_t k = 0; k < 2; k++) {
        for (size_t m = 0; m < r; m++) {
            cout << num[k][m] << " ";
        }
        cout << endl;
    }
    cout << " Я умерла, но сделала... " << endl;
    return 0;
}
