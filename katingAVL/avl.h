/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Achmadya Ridwan I 	(211511001)
------------------------------------------------------------- */

#ifndef AVL_H
#define AVL_H

#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

typedef struct InfoKataIndonesia{
    struct InfoKataIndonesia *LeftSon;
    struct InfoKataIndonesia *RightSon;
    char KataIndonesia[25];
    char PenjelasanKata[100];
    char KelasKata[4];
    int height;
}address;


int max(int a, int b);
int getHeight(address *root);
int getBalanceFactor(address *root);
address *alokasi(char *dataKata, char *dataPenjelasanKata, char *dataKelasKata);
address *leftRotate(address *root);
address *rightRotate(address *root);
address *rotate(address *root);
address *InsertAVL(address *root,  char *dataKata, char *dataPenjelasanKata, char *dataKelasKata);
address *Predecessor(address *root);
address *Successor(address *root);
address *remove(address *root,  char *dataKata);
void InPrint(address *root);
void deleteBinaryTree(address *root);
char *inputKata(char karakter[25]);
char *inputPenjelasan(char karakter[100]);

#endif 
