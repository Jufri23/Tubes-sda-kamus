/*TUGAS BESAR MK STRUKTUR DATA DAN ALGORITMA*/
/*
=========================KELOMPOK 10===============================
NAMA : FAKHRIE RIZDAN MUZAKKI (075)  MUHAMMAD HAIKAL AL JUFRI (085)
KELAS : 1C
PRODI : D3 - TEKNIK INFORMATIKA
JURUSAN : TEKNIK KOMPUTER DAN INFORMATIKA
*/
/*KAMUS BAHASA SUNDA (AVL TREE)*/


#ifndef SUNDA_H
#define SUNDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_STRING_LENGTH 256

// Struktur NODE
typedef struct Node
{
    char kata[MAX_STRING_LENGTH];
    char arti[MAX_STRING_LENGTH];
    struct Node *kiri;
    struct Node *kanan;
    int height;
} Node;

/*---------------------------------------------------PENERAPAN AVL------------------------------------------------*/

//Tinggi Node
int getHeight(Node *root);
//Menghitung Keseimbangan
int getBalanceFactor(Node *root);
//Rotasi kiri
Node *rotateKiri(Node *root);
//Rotasi kanan
Node *rotateKanan(Node *root);
//Rotasi
Node *rotate(Node *root);
//insert
Node *sisipkanAVL(Node *root, const char *kata, const char *arti);
//Pengganti
Node *successor(Node *root);
//Pendahulu
Node *predecessor(Node *root);
//hapus
Node *hapusNode(Node *root, const char *kata);

/*--------------------------------------------Display------------------------------------------------------------*/

// Cari
Node *cari(Node *root, const char *kata);
// Tampilkan semua kata
void tampilkanSemuaKata(Node *root);
void tampilkanSemuaKataHelper(Node *root);
// Tampilkan arti kata
void tampilkanArti(Node *root, const char *kata);

/*--------------------------------------------FILE------------------------------------------------------------*/

//Membuat Tree
Node *buildTreeFromFile(const char *fileName);
// Save Ke File
void saveToFile(Node *root, const char *fileName);
void saveToFileHelper(Node *root, FILE *file);

/*----------------------------------------Halaman Utama dan Tampilan--------------------------------------------*/

//Selamat Datang
void tampilkanSelamatDatang();
//login user umum
int userLogin();
// Menu untuk user umum
void menuPengguna(Node *root);
// Login Admin
int adminLogin();
// Menu untuk admin
void menuAdmin(Node *root);

/*-------------------------------------------Fitur Pendukung-----------------------------------------------------*/

// To Lowwer Case
char *toLowercase(char *str);

#endif