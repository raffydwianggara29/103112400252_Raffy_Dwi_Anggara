#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

struct Mahasiswa{
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    int dataMahasiswa[MAX];
    int top;
};


bool isEmpty(StackMahasiswa StackMHS);
bool isFull(StackMahasiswa StackMHS);
void createStack(StackMahasiswa StackMHS);

void push(StackMahasiswa &StackMHS);
void pop(StackMahasiswa &StackMHS);
void update(StackMahasiswa &StackMHS, int posisi);
void view(StackMahasiswa &StackMHS);
void searchData(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);

#endif