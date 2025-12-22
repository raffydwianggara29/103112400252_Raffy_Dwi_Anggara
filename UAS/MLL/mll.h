#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataFilm {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

struct KategoriGenre {
    string idGenre;
    string namaGenre;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataFilm isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriGenre isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListParent(listInduk &LInduk);
void createListChild(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idGenre, string namaGenre);
NodeChild alokasiNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void searchFilmByRatingRange(listAnak &LAnak, float ratingFilm);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);

//operasi print
void printStrukturMLL(listInduk &LInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

//operasi find mind and max
bool findMinandMax(listInduk &LInduk, float &minharga, float &maxharga);

#endif