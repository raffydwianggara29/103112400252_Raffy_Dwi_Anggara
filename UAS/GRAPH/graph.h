#ifndef GRAPH_H
#define GRAPH_H 

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namakota;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrKota Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrKota kotaTujuan;  //Pointer yang menunjuk ke lokasi node tujuan
    int jarak;
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrKota First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrKota AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrKota nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrKota FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, string namaKota1, string namaKota2, int jarak); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrKota node1, adrKota node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)
#endif