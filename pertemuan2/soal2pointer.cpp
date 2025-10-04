#include <iostream>
using namespace std;

void tukar(int *a, int *b, int *c) {
    int temp;
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
int main(){
    int a = 10, b = 25, c = 17;
    int *ptr;

    ptr = &a;

    cout << "nilai dari a : " << a << endl;
    cout << "nilai dari b : " << b << endl;
    cout << "nilai dari c : " << c << endl;

    tukar (&a, &b, &c);
    cout << "setelah ditukar nilainya, nilai a : " << a << " nilai b : " << b << " nilai c : " << c << endl;

    return 0;
}