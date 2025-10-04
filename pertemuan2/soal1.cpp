#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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
    int arrC[3][3] = {0}; 
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan : " << endl;
    tampilkanHasil(arrD);

    cout << endl;


    for (int i = 0; i < 3; i++) {            
        for (int j = 0; j < 3; j++) {       
            for (int k = 0; k < 3; k++) {  
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrE);

    return 0;
}
