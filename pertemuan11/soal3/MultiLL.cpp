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
