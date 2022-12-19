#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    setlocale(0, "Russian");
    string x;//вводимые буквы
    cout << " Введите буквы: " << endl;
    vector <string> str;

    for (; ;) {
        cin >> x;
        string h = x;
        if (h == "end") {
            break;
        }
        else {
            str.insert(str.end(), x); 
        }
    }

    sort(str.begin(), str.end());

  
        for (size_t m = 0; m < str.size(); m++) {
            cout << str[m] << " ";
        }
   
    

	return 0;
}