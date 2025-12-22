#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListChild(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idGenre, string namaGenre) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGenre = idGenre;
    nodeBaruParent->isidata.namaGenre = namaGenre;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListChild(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idFilm = idFilm;
    nodeBaruChild->isidata.judulFilm = judulFilm;
    nodeBaruChild->isidata.durasiFilm = durasiFilm;
    nodeBaruChild->isidata.tahunTayang = tahunTayang;
    nodeBaruChild->isidata.ratingFilm = ratingFilm;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.idGenre << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}


void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaGenre << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idGenre == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idGenre << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaGenre << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void searchFilmByRatingRange (listInduk &LParent, float ratingFilm){
    if(isEmptyInduk(LParent) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.ratingFilm = ratingFilm) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGenre << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Film ---" << endl;
                    cout << "ID Film : " << nodeBantuChild->isidata.idFilm << endl;
                    cout << "Judul Film :  "<< nodeBantuChild->isidata.judulFilm << endl;
                    cout << "Durasi Film : " << nodeBantuChild->isidata.durasiFilm << endl;
                    cout << "Tahun Tayang : " << nodeBantuChild->isidata.tahunTayang << endl;
                    cout << "Rating film : " << nodeBantuChild->isidata.ratingFilm << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Genre ---" << endl;
                    cout << "ID Genre : " << nodeBantuParent->isidata.idGenre << endl;
                    cout << "Nama Genre : " << nodeBantuParent->isidata.namaGenre << endl;
                    ketemu = true;
                }
                nodeBantuChild = nodeBantuChild->next;
                indexChild++;
            }
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Genre : " << nodeBantuParent->isidata.idGenre << endl;
            cout << "Nama Genre : " << nodeBantuParent->isidata.namaGenre << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Film : " << nodeBantuChild->isidata.idFilm << endl;
                    cout << "      Judul Film : " << nodeBantuChild->isidata.judulFilm << endl;
                    cout << "      Durasi film : " << nodeBantuChild->isidata.durasiFilm << endl;
                    cout << "      Tahun tayang : " << nodeBantuChild->isidata.tahunTayang << endl;
                    cout << "      Tahun tayang : " << nodeBantuChild->isidata.ratingFilm << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
