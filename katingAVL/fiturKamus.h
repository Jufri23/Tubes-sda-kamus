/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Wildan Setya Nugraha	(211511032)
------------------------------------------------------------- */

#ifndef fiturKamus_H
#define fiturKamus_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string>
#include <unistd.h>
#define namaFileData "fileDataKamus.txt"

#include "avl.h"
#include "tampilanUI.h"

address *bukaFile(address *root);
address *tambahDataKata(address *root);
void temukanDataKata(address *root);
bool isKataTersedia(address *root, char *dataKata); 
address *hapusDataKata(address *root); 
void printBerdasarkanKelasKata(address *root);
void cariBerdasarkanKelasKata(address *root, char *dataKelasKata, bool *cek, int *kata, int *baris, int *kolom); 
void tulisKeFile(address *root); 
void simpanKeFile(address *root); 

#endif 
