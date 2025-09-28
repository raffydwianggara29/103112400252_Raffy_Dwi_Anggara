#include <iostream>

using namespace std;

int main(){
    int n, i;
    cout << "Masukkan Inputan : ";
    cin >> n;

    for (int i = n; 0 <  i; i--) {
        cout << i;
    } 
    cout << "*";

    for (int i = 1; i <= n; i++) {
        cout << i;
    }

    cout << endl;
    n = n - 1;

    int spasi = 1;

    while (n >= 0) {

        for (int i = 0; i < spasi; i++) {
            cout << " ";
        }
        for (int i = n; 0 < i; i--) {
            cout << i;
        } 
            cout << "*";

        for (int i = 1; i <= n; i++) {
            cout << i;
        } 
        cout << endl;
        n = n - 1;
        spasi++;
    }
}