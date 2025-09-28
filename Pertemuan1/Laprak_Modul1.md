# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++. [1]
### A. Materi Pertemuan Pertama
Dalam pertemuan pertama ini (minggu pertama ini), mahasiswa diberikan pelajaran tentang c++, cara menginstalnya dan juga melakukan praktek codingan c++ dengan program program seperti berikut:
#### 1. Aritmatika
Operator Aritmatika yang didasarkan oleh operasi-operasi dari perhitungan Aritmatika yang berupa code operator berupa (+,−, ∗, ∕) sebagai code dari perhitungan tersebut. [2]
#### 2. Percabangan
Pernyataan seleksi kondisi (percabangan) yaitu melakukan pengujian untuk memilih satu dari beberapa
alternatif yang tersedia. Seleksi kondisi, haruslah dapat menghasilkan nilai benar (true) atau
nilai salah (false). Jika hasil seleksi kondisi bernilai benar, maka suatu pernyataan baru akan
dikerjakan.[1]
#### 3. Perulangan
Perulangan yaitu Melakukan suatu instruksi,bahkan aksi, secara berulang-ulang. Jenis perulangan ada 3 yaitu while, while-do,dan for.[3]
#### 4. Struct
Struct dalam C++ memungkinkan pengelompokan variabel dengan tipe data yang berbeda dalam satu deklarasi user-defined data type yang disebut structure, yang berguna untuk mendirikan object.[4]


## Guided 

### 1. Aritmatika

```C++
#include <iostream>

using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;


    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian : " << angka1 * angka2 << endl;
    cout << "Pembagian : " << angka1 / angka2 << endl;
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}
```
penjelasan singkat guided 1 
Program ini berfungsi untuk menampilkan hasil penjumlahan, pengurangan,perkalian,pembagian,dan juga modulus (sisa pembagian). Kodingan ini berfungsi ketika user menginput 2 bilangan.

### 2. Percabangan

```C++
#include <iostream>

using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << " Lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 < angka2) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    } 
    
    if (angka1 != angka2) {
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }

    return 0;
}
```
penjelasan singkat guided 2
Program ini berfungsi untuk mengecek suatu kondisi apakah inputan masuk ke kondisi lebih besar, sama dengan,atau lebih kecil. jika 2 inputan adalah angka yang berbeda, maka outputnya terdiri dari 2 kondisi yaitu kondisi lebih besar atau lebih kecil dan kondisi tidak sama dengan.

### 3. Perulangan For

```C++
#include <iostream>

using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    for(int i = 0; i < angka1; i++){ //increment
        cout << i << " - ";
    }

    cout << endl;

    for(int i = 20; i > angka2; i--){ //decrement
        cout << i << " - ";
    }

    return 0;
}

// catatan : kalau menggunakan <= perulangan sampai ke angka itu misal input 10 maka perulangannya akan sampai 10 sedangkan kalau hanya menggunakan < maka perulangan akan kurang dari 1 angka tersebut misal 10 maka perulangan hanya sampai 9
```
penjelasan singkat guided 3
Program ini berfungsi untuk menampilkan perulangan increment (naik) dari angka 0 sampai sebelum inputan dan juga dapat menampilkan perulangan decrement (menurun) dari 20 sampai sebelum inputan.

### 4. Perulangan While

```C++
#include <iostream>

using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    int i = 0;
    int j = 11;

    //perulangan while
    while (i < angka1) {
        cout << i << " - ";
        i++; //increment
    }

    cout << endl;

    //perulangan do-while
    do {
        cout << j << " - ";
        j++; //increment
    } while(j < angka1);

    return 0;
}
```
penjelasan singkat guided 4
Program ini berfungsi untuk menampilkan 2 fungsi,yaitu while dan while do. jika perulangan while maka output terdiri dari 0 hingga ke sebelum angka inputan sedangkan while do ia hanya menampilkan dari angka 11 hingga sebelum n.  

### 5. Struct

```C++
#include <iostream>

using namespace std;

int main(){
    const int jumlah = 5;

    struct rapot{
        char nama[5];
        int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int i = 0;
    while (i < jumlah){
        cout << "nama : " << siswa[i].nama << " nilai : " << siswa[i].nilai << endl;
        i++;
    }

    return 0;
}
```
penjelasan singkat guided 3
Program ini berfungsi untuk menyimpan / menggabungkan beberapa data siswa yaitu berupa nama dan nilai ke dalam array berisi struct.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan,pengurangan,perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main(){
    float angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian : " << angka1 * angka2 << endl;
    cout << "Pembagian : " << angka1 / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan1/output/Output_Soal1.png)

penjelasan unguided 1 
Program ini berfungsi untuk menampilkan hasil dari 2 inputan bertipe float dengan outputnya yaitu hasil penjumlahan,pengurangan,perkalian,dan pembagian dari 2 inputan float.

### 2. Buatlah sebuah program yang menerima masukkan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input kan adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>

using namespace std;

int main(){
    string satuan[9] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",};
    string belasan[9] = {"sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[9] = {"sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    int angka;
    cout << "Masukkan Angka: ";
    cin >> angka;

    if (angka < 10) {
        cout << satuan[angka - 1] << endl;
    } else if (angka < 20) {
        cout << belasan[angka - 11] << endl;
    } else if (angka %10 == 0) {
        cout << puluhan[angka / 10 - 1] << endl;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka > 20 && angka < 100) {
        cout << puluhan[ (angka/10)-1 ] << " " << satuan[ (angka%10)-1 ] << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan1/output/Output_Soal2.png)

penjelasan unguided 2
Program ini berfungsi untuk membuat inputan yang semula adalah angka menjadi bentuk tulisan seperti 79 menjadi tujuh puluh sembilan.
### 3. Buatlah program yang dapat memberikan input dan output sbb.
    321 * 123
     21 * 12
      1 * 1
        *

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan1/output/Output_Soal3.png)

penjelasan unguided 3
Program ini berfungsi untuk membuat segitiga sama kaki ke bawah dengan inputan.

## Kesimpulan
Di pertemuan pertama ini kita dapat memahami perulangan,struct,dan juga input output dalam bahasa pemograman c++

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2] Analisis Studi Literatur Penyelesaian Operator Aritmatika Serta Bilangan Bulat Dengan Code Sederhana Pada Bahasa Pemrograman C++. Diakses pada 28 September 2025 melalui https://jurnal.stikes-ibnusina.ac.id/index.php/SABER/article/download/604/577/2178
[3] Perulangan/Looping (dalam Bahasa C++) - informatika. Diakses pada 28 September 2025 melalui https://informatika.stei.itb.ac.id/~rinaldi.munir/PTI/2013-2014/KU1072_Pengulangan_CPP_140913.pdf
[4] Materi C++ Struct | PDF. Diakses pada 28 September 2025 melalui https://id.scribd.com/document/684330006/Materi-C-Struct.