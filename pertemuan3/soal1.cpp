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
