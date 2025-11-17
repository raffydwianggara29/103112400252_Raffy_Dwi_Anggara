#include "StackMahasiswa.h"
#include <iostream>

using namespace std;

bool isEmpty(StackMahasiswa StackMHS) {
    return StackMHS.top == -1;
}

bool isFull(StackMahasiswa StackMHS){
    return StackMHS.top == MAX -1;
}

void createStack(StackMahasiswa StackMHS) {
    StackMHS.top = -1;
}

void push(StackMahasiswa &StackMHS) {
    if(isFull(StackMHS)) {
        cout << "Stack Penuh!" << endl;
    } else {
        StackMHS.top++;
        StackMHS.dataMahasiswa[StackMHS.top] = Nama;
        StackMHS.dataMahasiswa[StackMHS.top] = NIM;
        StackMHS.dataMahasiswa[StackMHS.top] = NilaiTugas;
        StackMHS.dataMahasiswa[StackMHS.top] = NilaiUTS;
        StackMHS.dataMahasiswa[StackMHS.top] = NilaiUAS;
    }
}

void pop(StackMahasiswa &StackMHS){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = StackMHS.dataMahasiswa[StackMHS.top];
        StackMHS.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(StackMahasiswa &StackMHS, int posisi){
    if(isEmpty(StackMHS)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = StackMHS.top - (posisi -1);
    if(idx < 0 || idx > StackMHS.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> StackMHS.dataMahasiswa[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(StackMahasiswa &StackMHS){
    if(isEmpty(StackMHS)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = StackMHS.top; i >= 0; --i){
            cout << StackMHS.dataMahasiswa[i] << " ";
        }
    }
    cout << endl;
}

void searchData(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax){
    if(isEmpty(StackMHS)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << NilaiAkhirMin << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = StackMHS.top; i >= 0; --i){
        if(StackMHS.dataMahasiswa[i] == ni){
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