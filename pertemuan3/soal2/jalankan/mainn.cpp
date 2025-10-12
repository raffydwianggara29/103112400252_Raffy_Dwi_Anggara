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