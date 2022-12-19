#include <iostream>
using namespace std;

pair<int*, int>input() {
    setlocale(0, "Russian");
    cout << " Введите числа: " << endl;
    int* num = new int[100000];
    int i = 0;
    int x;
    while (i < 100000) {
        cin >> x;
        if (x == 0) break;
        num[i] = x;
        i++;
    }
    return { num, i };
}

pair<int*, int> more_than_5(int* num, int i) {
    int k = 0;
    int* num5 = new int;
    for (int j = 0; j < i; j++) {
        if (num[j] > 5) {
            num5[k] = num[j];
            k++;
        }
    }
    return { num5, k };
}

int main() {
    setlocale(0, "Russian");
    auto mass = input();
    cout << " Введенный массив: " << endl;
    for (int l = 0; l < mass.second; l++) {
        cout << mass.first[l] << " ";
    }
    cout << endl;
    auto mass2 = more_than_5(mass.first, mass.second);
    cout <<"Массив со значениями больше 5:" << endl;
    for (int i = 0; i < mass2.second; i++) {
        cout << mass2.first[i] << " ";
    }

    return 0;
}