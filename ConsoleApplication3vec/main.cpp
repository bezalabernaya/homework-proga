// ConsoleApplication2811.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector a(1.0, 2.0);
    Vector b(2.0, 3.0);
    Vector c = a + b;
    cout << c.getLen() << endl;
    cout << c.getPhi() << endl;
    cout << c.getPhiDeg() << endl;
    b -= a;
    cout << b.x << " " << b.y << endl;
    b /= 2;
    cout << b.x << " " << b.y << endl;
    Vector A = a;
    cout << (a == A) << endl;
    cout << (a != b) << endl;
    cout << a.kosoe_product(c) << endl;
    c.norm();
    cout << c.x << " " << c.y<<endl;
    cout << a.getLen() << endl;
    a.change_len(4);
    cout << a.getLen() << endl;
    cout<< A.scalar_product(c) << endl;

   
    return 0;
}