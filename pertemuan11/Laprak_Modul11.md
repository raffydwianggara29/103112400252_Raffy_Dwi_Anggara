# <h1 align="center">Laporan Praktikum Modul 11 - Multi Linked List</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
Multi-Linked List adalah jenis linked list di mana setiap node dapat memiliki lebih dari satu pointer (link) ke node lain. Artinya, bukan hanya satu urutan (seperti "next" pada singly linked list) atau dua arah (seperti prev/next pada doubly linked list), tapi bisa banyak pointer, sesuai kebutuhan.[1]
### A. Materi Modul 11
Pada pertemuan ke 11 ini, kita akan membahas fungsi fungsi pada struktur MLL (Multi Linked List)
#### 1. Update
Update merupakan sebuah fungsi yang berfungsi sebagai mengubah elemen yang ditunjuk dengan pointer dan diisi dari sesuatu.[2]
#### 2. Searching
Searching adalah tindakan mengambil data dari kumpulan data berdasarkan kunci (key) atau referensi data. Misalnya, jika ingin menghapus atau mengubah data tertentu pada suatu file, maka harus terlebih dahulu menentukan apakah data tersebut ada dalam file. Jika ada, maka data tersebut dapat diubah / dihapus.[3]
#### 3. Delete
Pada Doubly linked list, ada beberapa cara fungsi delete, yaitu deleteFirts, deleteLast, dan deleteAfter. DeleteFirts adalah operasi untuk menghapus data pada posisi pertama, deleteLast merupakan menghapus data pada posisi terakhir, sedangkan deleteAfter adalah penghapusan data di tengah linked list.[3]
#### 4. Parent Node
Parent Node (Predecessor): Simpul induk (Parent Node) merupakan simpul yang memiliki satu atau lebih simpul anak. Setiap simpul kecuali akar, memiliki tepat satu simpul induk.[4]
#### 5. Child Node
Children Node: Simpul Anak merupakan simpul yang menjadi turunan dari simpul induk. Simpul anak terhubung ke simpul induk melalui percabangan ke kiri dan ke kanan.[4]

## Guided 

### 1. Multi Linked List dengan beberapa fungsi

```C++
//MLL.h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
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
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif

//MLL.cpp
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

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
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
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
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
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
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
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
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

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
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

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
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

//main.cpp
    #include "mll.h"
    #include <iostream>

    using namespace std;

    int main() {
        // 1. Inisialisasi List
        listInduk L;
        createListInduk(L);
        cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

        // 2. Membuat Data Parent (Kategori Makanan)
        // Kita simpan pointer-nya agar mudah memasukkan anak nanti
        NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
        insertFirstParent(L, Kat1);

        NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
        insertAfterParent(L, Kat2, Kat1);

        NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
        insertLastParent(L, Kat3);
        
        cout << endl;

        // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
        
        // --> Isi Kategori Makanan Berat (K01)
        NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
        insertFirstChild(Kat1->L_Anak, Mkn1);

        NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
        insertLastChild(Kat1->L_Anak, Mkn2);

        // --> Isi Kategori Minuman (K02)
        NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
        insertLastChild(Kat2->L_Anak, Min1);
        
        NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
        insertFirstChild(Kat2->L_Anak, Min2);

        // --> Isi Kategori Dessert (K03)
        NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
        insertLastChild(Kat3->L_Anak, Des1);
        cout << endl;

        cout << "=== TAMPILAN AWAL MENU ===" << endl;
        printStrukturMLL(L);
        cout << endl;

        // 4. Test Pencarian (Find)
        cout << "=== TEST PENCARIAN ===" << endl;
        findParentByID(L, "K02"); // Cari Kategori Minuman
        cout << "---------------------------" << endl;
        findChildByID(L, "M01");  // Cari Nasi Goreng
        cout << "---------------------------" << endl;
        findChildByID(L, "X99");  // Cari data ngawur (harus not found)
        cout << "---------------------------" << endl;
        cout << endl;

        // 5. Test Update Data
        cout << "=== TEST UPDATE ===" << endl;
        // Update Nama Kategori (Parent)
        // Mengubah "Dessert" menjadi "Makanan Penutup"
        updateDataParentByID(L, "K03", "Makanan Penutup");
        cout << "---------------------------" << endl;
        
        // Update Data Makanan (Child)
        // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
        updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
        cout << "---------------------------" << endl;
        
        cout << "\n=== SETELAH UPDATE ===" << endl;
        // Kita cek apakah data berubah
        printListInduk(L); // Cek nama kategori saja
        cout << endl;
        printListAnak(L, Kat1); // Cek list anak di kategori 1
        cout << endl;

        // 6. Test Penghapusan (Delete)
        cout << "=== TEST DELETE ===" << endl;
        
        // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
        cout << "> Menghapus Child D02..." << endl;
        deleteFirstChild(Kat2->L_Anak); 
        
        // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
        // DeleteLastParent akan menghapus elemen terakhir (K03)
        cout << "> Menghapus Parent Terakhir (K03)..." << endl;
        deleteLastParent(L); 

        cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
        printStrukturMLL(L);

        return 0;
    }
```
penjelasan singkat guided 1
Program ini berfungsi untuk membuat Multi Linked List dengan beberapa fungsi yaitu update, searching, delete, serta mencari parent dan child. Program ini juga dapat menambahkan / insert parent dengan child.
## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal1_1.png)
![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal1_2.png)
![Screenshot Output Unguided 1_3](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal1_3.png)
![Screenshot Output Unguided 1_4](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/soall/soal1_4.png)
```C++
//MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocateNodeParent(string idGol, string namagol);
NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &Nchild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirtsParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertlastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteLastChild(listChild &LChild);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif
//MultiLL.cpp
#include "MultiLL.h"
#include <iostream>
#include <string>

using namespace std;

bool isEmptyParent(listParent &LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyChild(listChild &LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

NodeParent allocateNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev =  NULL;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = height;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void deallocNodeParent(NodeParent &NParent){
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first =LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirtsParent(listParent &LParent){
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL) {
            deleteListChild(nodeHapus->L_Child);
        }
        deallocNodeParent(nodeHapus);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL) {
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL) {
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Child.first != NULL) {
                deleteListChild(nodeHapus->L_Child);
            }
            deallocNodeParent(nodeHapus);
            cout << "delete berhasil" << endl;
        } else {
            cout << "delete tidak berhasil" << endl;
        }
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertlastChild(listChild &LChild, NodeChild NewNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = NewNChild;
    } else {
        NewNChild->prev = LChild.last;
        LChild.last->next = NewNChild;
        LChild.last = NewNChild;
    }
}

void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void deleteLastChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.last;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.last = LChild.last->prev;
            nodeHapus->prev = NULL;
            LChild.last->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void printMLLStructure(listParent &LParent){
    if(isEmptyParent(LParent)){
        cout << "List kosong " << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan : " << nodeBantuParent->isidata.namaGolongan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "(tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << " - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "      Bobot : " << nodeBantuChild->isidata.bobot << endl;
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

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

//main.cpp
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent K1 = allocateNodeParent("G001", "Aves");
    insertFirstParent(L, K1);

    NodeParent K2 = allocateNodeParent("G002", "Mamalia");
    insertLastParent(L, K2);

    NodeParent K3 = allocateNodeParent("G003", "Pisces");
    insertLastParent(L, K3);

    NodeParent K4 = allocateNodeParent("G004", "Amfibi");
    insertLastParent(L, K4);

    NodeParent K5 = allocateNodeParent("G005", "Reptil");
    insertLastParent(L, K5);

    cout << endl;

    NodeChild AV1 = allocateNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(K1->L_Child, AV1);
    NodeChild AV2 = allocateNodeChild("AV002", "Bebek", "Air", true, 2);
    insertlastChild(K1->L_Child, AV2);

    NodeChild MML1 = allocateNodeChild("M01", "Harimau", "Hutan", true, 200);
    insertFirstChild(K2->L_Child, MML1);
    NodeChild MML2 = allocateNodeChild("M02", "Gorila", "Hutan", false, 160);
    insertlastChild(K2->L_Child, MML2);
    NodeChild MML3 = allocateNodeChild("M03", "Kucing", "Darat", true, 4);
    insertlastChild(K2->L_Child, MML3);

    NodeChild AMF1 = allocateNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertlastChild(K4->L_Child, AMF1);

    printMLLStructure(L);
    cout << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_5](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/output/Output1.png)

penjelasan unguided 1 
Program ini berfungsi untuk membuat Multi Linked List dengan beberapa fungsi seperti insert, dealokasi pada parent dan child, delete parent dan child, serta menampilkan output dengan fungsi printMLLStructure. Pada program ini, kita menginisiasi parent dengan data golongan hewan dan nama golongan hewan dan menginisiasi child node dengan data id hewan, nama hewan, habitat, ekor, serta bobot dari hewan.
### 2. ![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal2.png)

```C++
//MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocateNodeParent(string idGol, string namagol);
NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &Nchild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirtsParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertlastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteLastChild(listChild &LChild);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
//MultiLL.cpp
#include "MultiLL.h"
#include <iostream>
#include <string>

using namespace std;

bool isEmptyParent(listParent &LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyChild(listChild &LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

NodeParent allocateNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev =  NULL;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = height;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void deallocNodeParent(NodeParent &NParent){
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first =LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirtsParent(listParent &LParent){
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL) {
            deleteListChild(nodeHapus->L_Child);
        }
        deallocNodeParent(nodeHapus);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL) {
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL) {
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Child.first != NULL) {
                deleteListChild(nodeHapus->L_Child);
            }
            deallocNodeParent(nodeHapus);
            cout << "delete berhasil" << endl;
        } else {
            cout << "delete tidak berhasil" << endl;
        }
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertlastChild(listChild &LChild, NodeChild NewNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = NewNChild;
    } else {
        NewNChild->prev = LChild.last;
        LChild.last->next = NewNChild;
        LChild.last = NewNChild;
    }
}

void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void deleteLastChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.last;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.last = LChild.last->prev;
            nodeHapus->prev = NULL;
            LChild.last->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void printMLLStructure(listParent &LParent){
    if(isEmptyParent(LParent)){
        cout << "List kosong " << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan : " << nodeBantuParent->isidata.namaGolongan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "(tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << " - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "      Bobot : " << nodeBantuChild->isidata.bobot << endl;
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

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchHewanByEkor(listParent &LParent, bool tail){
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        bool ketemu = false;
        while(nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL) {
                if(nodeBantuChild->isidata.ekor == tail) {
                    cout << "----------------------------------------" << endl;
                    cout << "Data ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGolongan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "Ekor : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "Bobot : " << nodeBantuChild->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama golongan : " << nodeBantuParent->isidata.namaGolongan << endl;
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
//main.cpp
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent K1 = allocateNodeParent("G001", "Aves");
    insertFirstParent(L, K1);

    NodeParent K2 = allocateNodeParent("G002", "Mamalia");
    insertLastParent(L, K2);

    NodeParent K3 = allocateNodeParent("G003", "Pisces");
    insertLastParent(L, K3);

    NodeParent K4 = allocateNodeParent("G004", "Amfibi");
    insertLastParent(L, K4);

    NodeParent K5 = allocateNodeParent("G005", "Reptil");
    insertLastParent(L, K5);

    cout << endl;

    NodeChild AV1 = allocateNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(K1->L_Child, AV1);
    NodeChild AV2 = allocateNodeChild("AV002", "Bebek", "Air", true, 2);
    insertlastChild(K1->L_Child, AV2);

    NodeChild MML1 = allocateNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(K2->L_Child, MML1);
    NodeChild MML3 = allocateNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertlastChild(K2->L_Child, MML3);
    NodeChild MML2 = allocateNodeChild("M002", "Kucing", "Darat", true, 4);
    insertlastChild(K2->L_Child, MML2);

    NodeChild AMF1 = allocateNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertlastChild(K4->L_Child, AMF1);

    printMLLStructure(L);
    cout << endl;

    cout << "=== TEST PENCARIAN ===" << endl;
        searchHewanByEkor(L, false);
        cout << "---------------------------" << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/output/output2.png)

penjelasan unguided 2
Program ini berfungsi untuk membuat Multi Linked List dengan beberapa fungsi yaitu insert node parent dan child, delete node parent dan child, serta searching. Pada program ini, kita menambahkan fungsi searching untuk mencari hewan yang tidak memiliki ekor/ ekor hewan tersebut bernilai false. Pada main kita menambahkan fungsi search tersebut lalu menambahkan false dalam kondisinya. Pada operasi perbandingan kita akan membandingkan data ekor dengan tail.

### 3. ![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal3_1.png)
![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/soall/soal3_2.png)
```C++
//MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocateNodeParent(string idGol, string namagol);
NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &Nchild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirtsParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertlastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteLastChild(listChild &LChild);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif

//MultiLL.cpp
#include "MultiLL.h"
#include <iostream>
#include <string>

using namespace std;

bool isEmptyParent(listParent &LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyChild(listChild &LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

NodeParent allocateNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev =  NULL;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocateNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float height){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = height;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void deallocNodeParent(NodeParent &NParent){
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first =LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirtsParent(listParent &LParent){
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL) {
            deleteListChild(nodeHapus->L_Child);
        }
        deallocNodeParent(nodeHapus);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL) {
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL) {
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Child.first != NULL) {
                deleteListChild(nodeHapus->L_Child);
            }
            deallocNodeParent(nodeHapus);
            cout << "delete berhasil" << endl;
        } else {
            cout << "delete tidak berhasil" << endl;
        }
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertlastChild(listChild &LChild, NodeChild NewNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = NewNChild;
    } else {
        NewNChild->prev = LChild.last;
        LChild.last->next = NewNChild;
        LChild.last = NewNChild;
    }
}

void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void deleteLastChild(listChild &LChild){
    if(isEmptyChild(LChild) == true) {
        cout << "List anak kosong" << endl;
    } else {
        NodeChild nodeHapus = LChild.last;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.last = LChild.last->prev;
            nodeHapus->prev = NULL;
            LChild.last->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void printMLLStructure(listParent &LParent){
    if(isEmptyParent(LParent)){
        cout << "List kosong " << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan : " << nodeBantuParent->isidata.namaGolongan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "(tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << " - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "      Bobot : " << nodeBantuChild->isidata.bobot << endl;
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

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchHewanByEkor(listParent &LParent, bool tail){
    if(isEmptyParent(LParent) == true) {
        cout << "List kosong" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        bool ketemu = false;
        while(nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL) {
                if(nodeBantuChild->isidata.ekor == tail) {
                    cout << "Data ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGolongan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Hewan : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "Habitat : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "Ekor : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "Bobot : " << nodeBantuChild->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama golongan : " << nodeBantuParent->isidata.namaGolongan << endl;
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


//main.cpp
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent K1 = allocateNodeParent("G001", "Aves");
    insertFirstParent(L, K1);

    NodeParent K2 = allocateNodeParent("G002", "Mamalia");
    insertLastParent(L, K2);

    NodeParent K3 = allocateNodeParent("G003", "Pisces");
    insertLastParent(L, K3);

    NodeParent K4 = allocateNodeParent("G004", "Amfibi");
    insertLastParent(L, K4);

    NodeParent K5 = allocateNodeParent("G005", "Reptil");
    insertLastParent(L, K5);

    cout << endl;

    NodeChild AV1 = allocateNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(K1->L_Child, AV1);
    NodeChild AV2 = allocateNodeChild("AV002", "Bebek", "Air", true, 2);
    insertlastChild(K1->L_Child, AV2);

    NodeChild MML1 = allocateNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(K2->L_Child, MML1);
    NodeChild MML3 = allocateNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertlastChild(K2->L_Child, MML3);
    NodeChild MML2 = allocateNodeChild("M002", "Kucing", "Darat", true, 4);
    insertlastChild(K2->L_Child, MML2);

    NodeChild AMF1 = allocateNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertlastChild(K4->L_Child, AMF1);

    printMLLStructure(L);
    cout << endl;

    cout << "=== TEST PENCARIAN ===" << endl;
    cout << "---------------------------" << endl;
    searchHewanByEkor(L, false);
    cout << "---------------------------" << endl;

    deleteFirstChild(K4->L_Child);
    deleteAfterParent(L, K3);

    printMLLStructure(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan11/output/output3.png)

penjelasan unguided 3
Program ini berfungsi untuk membuat Multi Linked List dengan beberapa fungsi yaitu fungsi insert node parent dan child, fungsi delete parent dan child, dan fungsi searching. Pada program ini, kita akan menghapus parent dengan node id parent "G004" serta menghapus child nya dari parent tersebut. kita menggunakan fungsi delete first child untuk menghapus child dari parent "G004" ini, lalu menghapus parent dengan menggunakan fungsi delete after parent karena letak node parent berada di tengah tengah (tidak di paling awal dan tidak di paling akhir). Pada pemanggilannya di fungsi ini, kita menggunakan prec (nilai sebelum) data yang akan dihapus, sehingga kita menginisiasi K3 karena nilai/parent K3 terletak sebelum nilai K4.Setelah itu program akan menampilkan ouput dengan fungsi printMLLStructure.

## Kesimpulan
Pada materi Multi Linked List kali ini, kita dapat memahami bahwa Multi Linked List ini seperti linked list pada umumnya, yaitu ada fungsi insert,delete,searching, serta fungsi print. Yang membedakan MLL ini dengan linked list lainnya yaitu adanya node parent dan juga child seperti tree sehingga kita perlu menginisiasi parent serta child dari data yang akan dibuat. Oleh karena itu,secara garis besar fungsi MLL ini seperti tree tetapi dengan inisiasi beberapa fungsi yang terdapat pada linked list pada umumnya.

## Referensi
[1] Introduction to Multi Linked List https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/ 
[2] MODUL PRAKTIKUM "STRUKTUR DATA". Diakses pada 26 Oktober 2025 melalui https://www.ocw.upj.ac.id/files/Handout-TIF104-Modul-Praltikum-Struktur-Data.pdf?
[3] Setiyawan, Risky Dwi, et al. "PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST." JUTECH: Journal Education and Technology 5.2 (2024): 484-498. Diakses pada 26 Oktober 2025 melalui http://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.
[4] Pengantar Struktur Data http://repo.stimata.ac.id/705/1/Pengantar%20Struktur%20Data%20Full.pdf