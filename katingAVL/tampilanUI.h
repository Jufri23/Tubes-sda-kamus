/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Wildan Setya Nugraha	(211511032)
------------------------------------------------------------- */
#ifndef tampilanUI_H
#define tampilanUI_H

#include "fiturKamus.h"

address *mainMenu(address *root, bool *run);
void gotoxy(int x, int y);
void pilihanAwal(bool *run);
void boxTampilanAwal();
void boxFileTidakTersedia(); 
void boxTampilanMenu();
void boxTampilanKelasKata();  
int pilihanMainMenu(); 
void printWrapPenjelasan(char karakter[100]); 
void color(int color);

#endif
