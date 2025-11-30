# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type(ADT)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.[1]

### A. Materi pertemuan ketiga
Dalam pertemuan ketiga ini,mahasiswa akan diajarkan tentang bagaimana cara membuat ADT dalam C++ dan pembuatan struct.
#### 1. ADT
ADT merupakan sebuah konsep yang memisahkan antara bagian yang terlihat (interface) dengan yang tidak terlihat (implementasi). Interface sendiri merupakan bagian yang berisi nama nama atau fungsi operasi yang digunakan oleh pemogram. Sedangkan implementasi merupakan bagaimana operasi operasi tersebut dijalankan di dalam program.[2]
#### 2. Struct
Struct merupakan pengelompokan beberapa nilai yang berelasi walaupun berbeda tipe datanya[3]

## Guided 

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama Mahasiswa : ";
    cin >> m.nama;
    cout << "masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan prosedur
    cout << "Rata rata : " << rata2(mhs); //pemanggilan function
    return 0;
}
```
Program ini berfungsi untuk memanggil struct dari mahasiswa dan menghitung nilai rata rata yang didapat dari 2 inputan nilai tersebut.

### 2. ADT (pelajaran.h)

```C++
//header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

```
Program ini dibuat untuk mendeklarasikan awal suatu file ADT dan membuat tipe data bernama pelajaran dengan struct.

### 3. ADT (pelajaran.cpp)

```C++
#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Program ini berfungsi untuk mengisi variabel data pelajaran dan menampilkan data pelajaran yang dibuat di program sebelumnya.


### 4. ADT (main.cpp)

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
Program ini berfungsi untuk menjalankan semua fungsi yang sudah dibuat di 2 file sebelumnya dan menampilkan hasilnya.


## Unguided 

### Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama,nim,uts, uas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    string nama, nim;
    float uts, uas, tugas;
};

void inputMahasiswa(mahasiswa &m) {
    cout << "Masukkan nama Mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan NIM mahasiswa : ";
    cin >> m.nim;
    cout << "Masukkan UTS : ";
    cin >> m.uts;
    cout << "Masukkan UAS : ";
    cin >> m.uas;
    cout << "Masukkan Tugas : ";
    cin >> m.tugas;
}
float nilaiakhir(mahasiswa m) {
    return (0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas);
}

int main(){
    mahasiswa mhs[10];
    int n;
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    if (n > 10) {
        cout << "Maksimal hanya 10 mahasiswa : " << endl;
        return 0;
    }

    int i = 0;
    while (i < n) {
        inputMahasiswa(mhs[i]);
        i++;
    }

    for (int i = 0; i < n; i++){
        cout << mhs[i].nama << " dengan NIM " << mhs[i].nim << "," << " Nilai Akhirnya adalah " << nilaiakhir(mhs[i]) << endl;
    }

    return 0;
     
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan3/output/Output3_Soal1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan3/output/Output3_Soal1(1).png)

penjelasan unguided 1 
Program ini berfungsi untuk menyimpan data nama,nim,nilai uts,uas,dan tugas di struct mahasiswa lalu menjumlahkan nilai rata ratanya di function bernama nilaiakhir.

### 2. ![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan3/Soal2.png)

```C++

//pelajarann.H
#ifndef PELAJARANN_H
#define PELAJARANN_H

#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};
pelajaran create_Pelajarann(string namapel, string kodepel);

void tampil_Pelajarann(pelajaran pel);

#endif

//pelajarann.cpp
#include "pelajarann.h"

pelajaran create_Pelajarann(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_Pelajarann(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//mainn.cpp
#include <iostream>
#include "pelajarann.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_Pelajarann(namapel, kodepel);
    tampil_Pelajarann(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan3/output/Output3_Soal2.png)


penjelasan unguided 
Program ini berfungsi untuk membuat ADT dalam sebuah pemograman c++ yang berisi 3 file lalu dijalankan di folder main.

### 3.  Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer.

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan3/output/Soal3_Output3.png)

penjelasan unguided 3
Program ini berfungsi untuk menukar 2 kolom matriks berukuran 3x3 dengan matriks lainnya dan menukar pointer X dan Y secara bersamaan

## Kesimpulan
Dalam pembelajaran kali ini,kita belajar cara menggunakan struct dan membuat ADT dengan cara membuat beberapa program yang berbeda yang nantinya akan dijalankan di satu file penting yaitu file main.cpp.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2] Adding performance information to ADT interfaces. Diakses pada 12 Oktober 2025 melalui https://dl.acm.org/doi/abs/10.1145/185087.185108.
[3] Pemrograman C++ Untuk SMA/SMK dan Mahasiswa Oleh Vivian Siahaan, Rismon Hasiholan Sianipar. Diakses pads 12 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=LYdeDwAAQBAJ&oi=fnd&pg=PP2&dq=c%2B%2B+struct+adalah&ots=1Qryyj9cNy&sig=_nBNM0rxPI_5k0syA7LKn31I00E&redir_esc=y#v=onepage&q=c%2B%2B%20struct%20adalah&f=false.
