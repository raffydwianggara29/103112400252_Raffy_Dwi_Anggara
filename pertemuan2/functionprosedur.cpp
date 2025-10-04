#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){  //function
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){  //procedure
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totaljumlah += arr[i];
    }
    cout << "total penjumlahan : " << totaljumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl; //pemanggilan function
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;  //pemanggilan procedure

    operasiAritmatika(arr, ukuran);
    return 0;
}