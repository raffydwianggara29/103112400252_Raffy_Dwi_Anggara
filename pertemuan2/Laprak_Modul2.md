# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.[1]

### A. Materi Pertemuan Kedua
Dalam pertemuan kedua ini,setelah mahasiswa sudah melakukan membuat perulangan, struct, dan lainnya pada minggu pertama kali ini mahasiswa akan diajarkan tentang membuat array,function,dan penukaran variabel.
#### 1. Array
Array merupakan suatu struktur data yang terdiri dari sekumpulan data dengan tipe data yang sama dan setiap data yang disimpan kedalam alamat memori disebun elemen array[2]. Ada juga yang disebut array 2 dimensi yaitu perluasan dari konsep array satu dimensi dan array 2 dimensi ini berbentuk matriks dan elemen nya dibentuk dari baris dan kolom sehingga dapat mempresentasikan data yang lebih kompleks lagi.[3]
#### 2. Function
Function merupakan sebuah blok kode yang dapat menerima input dari pemanggilnya,melakukan serangkaian operasi,dan dapat secara opsional mengembalikan nilai sebagai output.[4]
#### 3. Procedure
Prosedur adalah sederetan intruksi algoritma yang diberi nama,dan akan menghasilkan efek neto yang terdefinisi.[5]
#### 4. Pointer
Pointer dalam C++ merupakan sebuah variabel yang menunjuk alamat memori variabel lain. Pointer memungkinkan kita unutuk melakukan manipulasi secara langsung terhadap variabel lain di dalam memori.[6]
#### 5. Reference
Reference adalah sebuah variabel yang berfungsi sebagai pemberi alias untuk variabel yang ada / menyediakan nama alternatif untuk variabel dan memungkinkan bekerja dengan data asli secara langsung.[7]


## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
penjelasan singkat guided 1
Program ini berfungsi untuk membuat array sebanyak [n] (di soal ini [5] jadi membuat sebanyak 5 elemen array) lalu mengisi array dan juga menampilkan isi elemen dari array yang telah dibuat tadi.

### 2. Array 2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2 x 2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2 x 2
    for (int i = 0; i < 2; i++) {            //perulangan Baris
        for (int j = 0; j < 2; j++) {       //perulangan Kolom
            for (int k = 0; k < 2; k++) {  //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
penjelasan singkat guided 2
Program ini berfungsi untuk menampilkan hasil penjumlahan dan perkalian pada matriks 2x2 dengan cara melakukukan perulangan for pada baris dan kolomnya.

### 3. Function dan Procedur

```C++
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
```
penjelasan singkat guided 3
Program ini berfungsi untuk menampilkan hasil dari nilai maksimum yang terdapat di array dan dapat menampilkan aritmatika penjumlahan dan perkalian pada array yang diinput oleh pengguna.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    tukar (&a, &b);
    cout << "After swapping, value of a="  << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 4
Kodingan ini berfungsi untuk mengubah nilai a menjadi nilai b begitupun sebaliknya dengan mengggunakan pointer.

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai Ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;
    
    //mengubah nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar (a, b);
    cout << "After swapping, value of a="  << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 3
program ini berfungsi untuk mengubah nilai a dengan menggunakan referensi (atau inisial) menjadi 50, lalu menukarnya dengan nilai b sehingga nilai a adalah nilai b dan nilai b adalah nilai a yang sudah ditukar oleh referensi.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
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

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan2/output/Output2_Soal1.png)

penjelasan unguided 1 
Program ini berfungsi untuk menampilkan hasil dari penjumlahan, pengurangan, dan perkalian dari matriks 3x3 dengan menggunakan array 3 dimensi.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
//Pointer
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

//reference
#include <iostream>
using namespace std;

void tukar(int &a, int &b, int &c) {
    int temp; 
    temp = a;
    a = b;
    b = c;
    c = temp;
}
int main(){
    int a = 10, b = 25, c = 17;
    int& ref = a;

    cout << "nilai dari a : " << a << endl;
    cout << "nilai dari b : " << b << endl;
    cout << "nilai dari c : " << c << endl;

    tukar (a, b, c);
    cout << "setelah ditukar nilainya, nilai a : " << a << " nilai b :" << b << " nilai c : " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan2/output/Output2_Soal2_Pointer.png)

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan2/output/Output2_Soal2_Reference.png)

penjelasan unguided 2
Program ini berfungsi untuk menukar nilai 3 variabel dengan menggunakan pointer dan juga menggunakan reference (dengan menggunakan inisial).

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array --- 1. Tampilkan isi array 2. cari nilai maksimum 3. cari nilai minimum 4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[], int n){
    cout << "Isi array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

int cariMIN(int arr[], int ukuran){
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

float NilaiRataRata(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return (float)total / n;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int inputan;

    do {
        cout << "\n-- Menu Program Array --\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Inputan: ";
        cin >> inputan;

        switch (inputan){
            case 1:
                tampilArray(arrA, 10); break;
            case 2:
                cout << "Nilai Maksimumnya adalah: " << cariMAX(arrA, 10) << endl; break;
            case 3:
                cout << "Nilai Minimumnya adalah: " << cariMIN(arrA, 10) << endl; break;
            case 4:
                cout << "Nilai rata ratanya adalah: " << NilaiRataRata(arrA, 10) << endl; break;
            case 5:
                cout << "Program selesai\n"; break;
        }
    } while (inputan != 5);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan2/output/Output2_Soal3(1).png)

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan2/output/Output2_Soal3(2).png)


penjelasan unguided 3
Kodingan ini berfungsi untuk menampilkan menu dengan terdiri dari menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung nilai rata - rata dengan menggunakan function pada bagian mencari nilai maksimum dan minimum serta menggunakan prosedur untuk bagian menghitung rata-rata.

## Kesimpulan
Dalam pertemuan ini,mahasiswa diajarkan bagaimana cara membuat menu sederhana dengan beberapa fungsi dan prosedur serta mahasiswa bisa mengubah nilai variabel dengan menggunakan 2 cara yaitu pointer serta reference.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2] Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++ Oleh Shofwan Hanief, S.Kom., M.T., I Wayan Jepriana, S.Kom., M.Cs. Diakses pada 4 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=BRQQEAAAQBAJ&oi=fnd&pg=PP1&dq=bahasa+pemrograman+c%2B%2B+array+&ots=0DeP7JvQiX&sig=ljOtCM5nabUNTAs6uY8T44eGlmU&redir_esc=y#v=onepage&q=array&f=false.
[3] Algoritma dan Pemrograman: Konsep Dasar, Logika, dan Implementasi dengan C++ & Phyton Oleh Rozzi Kesuma Dinata, Novia Hasdyna. Diakses pada 4 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=6kBlEQAAQBAJ&oi=fnd&pg=PA1&dq=bahasa+pemrograman+c%2B%2B+array+2+dimensi&ots=bk_HFcsTHF&sig=Mu99cJIpT_eMiFE9BXV2aFZko5E&redir_esc=y#v=onepage&q&f=false.
[4] Funtion C++: Panduan Lengkap. Diakses pada 4 Oktober 2025 melalui https://www.kodingakademi.id/function-c-panduan-lengkap/.
[5] PROGRAM STUDI KOMPUTERISASI AKUNTANSI AMIK BSI PONTIANAK 2016. Diakses pada 4 Oktober 2025 melalui https://repository.bsi.ac.id/repo/files/237654/download/20161---Algoritma-dan-Pemrograman.pdf.
[6] ALGORITMA DAN PEMROGRAMAN DASAR: Menggunakan Bahasa Pemrograman C++ dengan Menggunakan Bahasa Pemograman C++ Dengan Contoh Kasus Aplikasi Untuk Bisnis Dan Manajemen Oleh Rangga Gelar Guntara. Diakses pada tanggal 4 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=NO_LEAAAQBAJ&oi=fnd&pg=PP1&dq=bahasa+pemrograman+c%2B%2B+pointer&ots=2Fy9qe7r66&sig=r7nXwe9x7bufh2J_QmoGV101yDg&redir_esc=y#v=onepage&q&f=false.
[7] Reference in C++. Diakses 4 Oktober 2025 melalui https://www.geeksforgeeks.org/cpp/references-in-cpp/.