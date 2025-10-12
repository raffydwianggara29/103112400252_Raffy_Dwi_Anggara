#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarposisiarray(int A[3][3],int B[3][3], int i, int j) {
    int temp = A[i][j];
    A[i][j] = B[i][j];
    B[i][j] = temp;
}

void tukarPointer(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int arrA[3][3] = {
        {1, 2, 4},
        {3, 4, 6},
        {2, 1, 8}
    };
    int arrB[3][3] = {
        {2, 3, 5},
        {4, 5, 2},
        {8, 1, 9}
    };

    int i = 1, j = 2;

    cout << "Array A sebelum ditukar: " << endl;
    tampilkanArray(arrA);
    cout << "Array B sebelum ditukar: " << endl;
    tampilkanArray(arrB);

    tukarposisiarray(arrA, arrB, 1, 2);

    cout << "Setelah tukar posisi\n" << endl;
    
    cout << "Array A: " << endl;
    tampilkanArray(arrA);
    cout << "Array B: " << endl;
    tampilkanArray(arrB);

    int x = 15, y = 25;
    int *p1 = &x;
    int *p2 = &y;
    cout << "Pointer sebelum ditukar adalah: ";
    cout << "X = " << x << " Y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "setelah ditukar pointernya adalah: ";
    cout << "x = " << x << " Y = " << y << endl;

    return 0;
}