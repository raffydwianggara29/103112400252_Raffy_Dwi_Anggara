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