# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
Stack adalah struktur data linier yang mengikuti aturan tertentu untuk melakukan operasi. Menambah dan menghapus elemen dari tumpukan hanya dapat terjadi di satu lokasi, yaitu ujung tumpukan. Stack bersifat LIFO (Last in First Out) dan objek yang terakhir masuk ke dalam Stack akan menjadi benda pertama yang dikeluarkan dari Stack itu.[1]

### A. Materi Minggu pertemuan 7
Pada pertemuan 7,mahasiswa diperintah untuk membuat sebuah fungsi yaitu stack dengan beberapa fungsi pada operasi nya yaitu pop dan push
#### 1. Push
Fungsi ini menambahkan sebuah elemen ke dalam stack dan tidak bisa dilakukan lagi jika stack sudah penuh dengan cara menambahkan item pada tumpukan paling atas[2]
#### 2. Pop
Fungsi ini mengambil elemen teratas dari stack dengan syarat stack tidak boleh kosong.[2]

## Guided 

### 1. Stack dengan menggunakan linked list 

```C++
//stack.h
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

//main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
penjelasan singkat guided 1
Program ini berfungsi untuk membuat stack dengan menggunakan single linked list agar penyimpanan data dapat dilakukan secara dinamis dengan menggunakan beberapa fungsi yaitu pop sebagai menghapus node yang paling atas dan push sebagai membuat node baru dan menaruhnya di paling atas. Program ini juga dapat mengupdate/mengubah nilai di posisi tertentu dan menampilkan isi stack dari atas ke bawah serta mencari apakah data tersebut ada di dalam stack atau tidak.

### 2. Stack dengan menggunakan fungsi array

```C++
//stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

//main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
penjelasan singkat guided 2
Program ini berfungsi untuk membuat stack dengan menggunakan fungsi array dengan menginisiasi nilai max yaitu sebanyak 10 data pada array dan posisi atas pada stack diperiksa oleh top dan jika top == -1 maka stack tersebut kosong. Berbeda dengan stack linked list, pada pengecekan kondisi stack pada array dilakukan dengan menngunakan 2 fungsi yaitu isEmpty dan isFull. fungsi selanjutnya yaitu pop untuk menambah data di paling atas dan pop untuk menghapus data yang berada di posisi paling atas. Lalu program ini juga dapat mengubah data pada posisi tertentu dan mencari data tertentu pada stack dan menampilkan isi stack dari atas ke bawah.

## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/soal1.png)

```C++
//stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}

//main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/output/output1.png)

penjelasan unguided 1
Program ini berfungsi untuk membuat stack dengan menggunakan array pada fungsinya. Program akan menerima inputan dari fungsi push dan array akan diisi dengan fungsi ini. setelah itu,fungsi pop akan menghapus elemen yang berada di paling atas, disini pop menghapus push 8 dan push 3 sehingga output hanya menampilkan 4 angka dari 6 fungsi push. Program ini juga akan menampilkan output yang terbalik dari hasil pop dan push tadi dengan fungsi balikstack dan akan menampilkan outputnya dengan menggunakan fungsi printInfo. 

### 2. ![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/soal2.png)

```C++
//stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);

#endif

//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

//main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/output/output2.png)

penjelasan unguided 2
Program ini berfungsi untuk membuat stack dengan menggunakan array pada fungsinya. Berbeda dengan sebelumnya, disini kita menggunakan fungsi yang bernama pushAscending yang berfungsi untuk memasukkan data dan mengurutkannya dari nilai terkecil hingga terbesar, sehingga data dapat terurut secara ascending. Lalu fungsi akan menampilkan hasil outputnya pada fungsi printInfo. Program ini juga menampilkan hasil output tadi secara terbalik dengan menggunakan fungsi balikStack dan menampilkannya di printInfo.

### 3. ![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/soal3.png)

```C++
//stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);
void getInputStream(Stack &S);

#endif

//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    createStack(S);

    char n;
    while(true){
        n = cin.get();
        if(n == '\n') {
            break;
        }
        if(n >= '0' && n <= '9' ) {
            int val = n - '0';
            push(S, val);
        }
    }
}

//main.cpp

```#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan7/output/output3.png)

penjelasan unguided 3
Program ini berfungsi untuk membuat stack dengan menggunakan array. Pada fungsi kali ini,user dapat menginput isi array dengan beberapa nilai data dan akan berhenti jika user menginput 'enter'. Bedanya, di program ini kita tidak menggunakan fungsi push dan menggunakan fungsi getInputStream sebagai inputannya, sehingga user dapat menambahkan inputan hingga nilai array max. Program ini juga menampilkan hasil urutan membalik isi stack dengan fungsi balikStack dan menampilkannya dengan fungsi printInfo.

## Kesimpulan
Pada pembelajaran kali ini, kita diberikan beberapa fungsi tambahan pada stack yaitu pushAscending yaitu bukan hanya sekedar menginput dan menaruh data di dalam stack, tetapi juga mengurutkannya dengan secara ascending yaitu dari terbesar [top] hingga terkecil. Setelah itu kita juga dapat menginput data secara manual dengan menggunakan fungsi getStreamInput selama data masih dibawah nilai MAX (pada fungsi ini nilai MAX yaitu 20). Program ini juga dapat membalik isi pada stack dengan fungsi balikStack. Output pada program ini akan ditampilkan dengan fungsi printInfo.
## Referensi
[1] SETIYAWAN, Risky Dwi, et al. PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST. JUTECH: Journal Education and Technology, 2024, 5.2: 484-498. diakses pada tanggal 9 November 2025 melalui https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
[2] Pemrograman C++ ALGORITMA & STRUKTUR DATA. Diakses pada tanggal 9 November 2025 melalui https://abdulkadir.blog.uma.ac.id/wp-content/uploads/sites/365/2019/02/Modul-Praktikum-Algoritma-Struktur-Data-Merge.pdf.