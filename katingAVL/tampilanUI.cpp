/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Wildan Setya Nugraha	(211511032)
------------------------------------------------------------- */

#include "tampilanUI.h"
#include <cstdio>
#include <cstdlib>

address *mainMenu(address *root, bool *run)
{
	/* kamus Data Lokal */
	char kata[25];          // variable untuk menampung kata 
	gotoxy(45,23); printf("Tekan (ESC: Tampilan Awal)");
	
	switch(pilihanMainMenu()){
		case 1:
			root = tambahDataKata(root); 
			break;
		case 2:
			root = hapusDataKata(root); 
			break;
		case 3:
			printBerdasarkanKelasKata(root); 
			break;
		case 27:
			pilihanAwal(&(*run));
			break; 
		case 59:
			temukanDataKata(root);  
			break;
		default:
			break;
	}
	return root; 
}

void boxTampilanAwal()
{
	system("cls");
	gotoxy(10,3);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	gotoxy(10,4);  printf("\xB3"); gotoxy(55,4); printf("K B B I"); gotoxy(110,4);  printf("\xB3");
	gotoxy(10,5);  printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
		
	gotoxy(10,6);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,7);  printf("\xB3"); gotoxy(11,7);   printf(" OOO     OOO        OO                                                               *");                 gotoxy(110,7);  printf("\xB3");
	gotoxy(10,8);  printf("\xB3"); gotoxy(11,8);   printf("  O       O   OOO    O    OOOO   OOO   OOO O     OOO                               ****");                gotoxy(110,8);  printf("\xB3");
	gotoxy(10,9);  printf("\xB3"); gotoxy(11,9);   printf("  O       O  O   O   O   O   O  O   O   O O O   O   O                           * ********");             gotoxy(110,9);  printf("\xB3");
	gotoxy(10,10); printf("\xB3"); gotoxy(11,10);  printf("  O   O   O  OOOOO   O   O      O   O   O O O   OOOOO                      *** ***************");         gotoxy(110,10);  printf("\xB3");
	gotoxy(10,11); printf("\xB3"); gotoxy(11,11);  printf("  O   O   O  O       O   O      O   O   O O O   O          * *****     ****************************");    gotoxy(110,11);  printf("\xB3");
	gotoxy(10,12); printf("\xB3"); gotoxy(11,12);  printf("    O   O     OOOO  OOO   OOOO   OOO   OOOOOOO   OOOO     ***********  ****************************");    gotoxy(110,12);  printf("\xB3");
	gotoxy(10,13); printf("\xB3"); gotoxy(11,13);  printf("                                                        ** ************** ***********************");      gotoxy(110,13); printf("\xB3");
	gotoxy(10,14); printf("\xB3"); gotoxy(11,14);  printf("***********************************************************************************************");        gotoxy(110,14); printf("\xB3");
	gotoxy(10,15); printf("\xB3"); gotoxy(11,15);  printf("                                                        ** ************** ***********************");      gotoxy(110,15); printf("\xB3");
	gotoxy(10,16); printf("\xB3"); gotoxy(11,16);  printf("                O  O   OOOO   OOOO   OOO                  ***********  ****************************");    gotoxy(110,16); printf("\xB3");
	gotoxy(10,17); printf("\xB3"); gotoxy(11,17);  printf("                O O    O   O  O   O   O                    * *****     ****************************");    gotoxy(110,17); printf("\xB3");
	gotoxy(10,18); printf("\xB3"); gotoxy(11,18);  printf("                OO     OOOO   OOOO    O                                    *** ***************");         gotoxy(110,18); printf("\xB3");
	gotoxy(10,19); printf("\xB3"); gotoxy(11,19);  printf("                O O    O   O  O   O   O                                         * ********");             gotoxy(110,19); printf("\xB3");
	gotoxy(10,20); printf("\xB3"); gotoxy(11,20);  printf("                O  O   OOOO   OOOO   OOO                                           ****");                gotoxy(110,20); printf("\xB3");
	gotoxy(10,21); printf("\xB3"); gotoxy(11,21);  printf(" 	                                                                                *");                 gotoxy(110,21); printf("\xB3");
	gotoxy(10,22); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(10,23); printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,24); printf("\xB3"); gotoxy(110,24); printf("\xB3");
	gotoxy(10,25); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
	gotoxy(50,26); printf("<--LEFT | RIGHT-->");
}


void pilihanAwal(bool *run)
{
	/* Kamus Data Global */
	int counter = 2;
	int SetColor[] = {7,7}; //7 Warna default (putih)
	char keyCursor;
	
	boxTampilanAwal();
	/* Algoritma */
	while(1){
		
		gotoxy(51,24); 
		color(SetColor[0]); 
		printf("MULAI"); 
	
		gotoxy(61,24); 
		color(SetColor[1]); 
		printf("KELUAR");
	
		keyCursor = getch();
		
		if(keyCursor == 75 && counter >= 2) //Cursor Left
		{
			counter--;
		}
		if(keyCursor == 77 && counter >= 1 && counter <2) //Cursor Right
		{
			counter++;
		}
		if(keyCursor == '\r') //Enter
		{
			if(counter == 1)
			{
				break;
				
			} else {
				*run = false;
				break;
			}	
		}
		
		SetColor[0] = 7;
		SetColor[1] = 7;
		
 		if(counter == 1){
			SetColor[0] = 12;
		}
		if(counter == 2){
			SetColor[1] = 12;
		}
	}
}


void boxFileTidakTersedia()
{
	system("cls");
	gotoxy(10,2);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,3);  printf("\xB3"); 																																																																							gotoxy(110,3);  printf("\xB3");
	gotoxy(10,4);  printf("\xB3"); 																																																																							gotoxy(110,4);  printf("\xB3");
	gotoxy(10,5);  printf("\xB3"); 																																																																							gotoxy(110,5);  printf("\xB3");
	gotoxy(10,6);  printf("\xB3"); 																																																																							gotoxy(110,6);  printf("\xB3");
	gotoxy(10,7);  printf("\xB3"); 																																																																							gotoxy(110,7);  printf("\xB3");
	gotoxy(10,8);  printf("\xB3"); 																																																																							gotoxy(110,8);  printf("\xB3");
	gotoxy(10,9);  printf("\xB3"); gotoxy(30,9);	printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF"); 	gotoxy(110,9);  printf("\xB3");
	gotoxy(10,10); printf("\xB3"); gotoxy(30,10);	printf("\xB3");																										gotoxy(91,10);	printf("\xB3");																														gotoxy(110,10); printf("\xB3");
	gotoxy(10,11); printf("\xB3"); gotoxy(30,11);	printf("\xB3");		gotoxy(51,11); printf("Maaf file tidak ada,");													gotoxy(91,11);	printf("\xB3");																														gotoxy(110,11); printf("\xB3");
	gotoxy(10,12); printf("\xB3"); gotoxy(30,12);	printf("\xB3");		gotoxy(31,12); printf("Tetapi tenang file data kamus akan dibuatkan secara otomatis");			gotoxy(91,12);	printf("\xB3");																														gotoxy(110,12); printf("\xB3");
	gotoxy(10,13); printf("\xB3"); gotoxy(30,13);	printf("\xB3");																										gotoxy(91,13);	printf("\xB3");																														gotoxy(110,13); printf("\xB3");
	gotoxy(10,14); printf("\xB3"); gotoxy(30,14);	printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");		gotoxy(110,14); printf("\xB3");
	gotoxy(10,15); printf("\xB3"); 																																																																							gotoxy(110,15); printf("\xB3");
	gotoxy(10,16); printf("\xB3"); 																																																																							gotoxy(110,16); printf("\xB3");
	gotoxy(10,17); printf("\xB3"); 																																																																							gotoxy(110,17); printf("\xB3");
	gotoxy(10,18); printf("\xB3"); 																																																																							gotoxy(110,18); printf("\xB3");
	gotoxy(10,19); printf("\xB3"); 																																																																							gotoxy(110,19); printf("\xB3");
	gotoxy(10,20); printf("\xB3"); 																																																																							gotoxy(110,20); printf("\xB3");
	gotoxy(10,21); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(10,22); printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,23); printf("\xB3");	  																																																																						gotoxy(110,23); printf("\xB3");
	gotoxy(10,24); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(45,23); system("pause");
}


void boxTampilanMenu()
{
	gotoxy(10,2);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");	gotoxy(38,2);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,3);  printf("\xB3"); 	gotoxy(20,3);  printf(" K B B I");								gotoxy(37,3);  printf("\xB3"); 				gotoxy(38,3);  printf("\xB3"); 																																				                            gotoxy(110,3);  printf("\xB3");
	gotoxy(10,4);  printf("\xB3"); 	gotoxy(20,4);  printf("---------");						        gotoxy(37,4);  printf("\xB3");				gotoxy(38,4);  printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
	gotoxy(10,5);  printf("\xB3"); 	gotoxy(11,5);  printf("---------------------------");			gotoxy(37,5);  printf("\xB3");				gotoxy(38,5);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,6);  printf("\xB3"); 	gotoxy(11,6);  printf("   1. Adjektiva    (adj)");				gotoxy(37,6);  printf("\xB3");				gotoxy(38,6);  printf("\xB3");																																											gotoxy(110,6);  printf("\xB3");
	gotoxy(10,7);  printf("\xB3"); 	gotoxy(11,7);  printf("   2. Adverbia     (adv)");  			gotoxy(37,7);  printf("\xB3");				gotoxy(38,7);  printf("\xB3");																																											gotoxy(110,7);  printf("\xB3");
	gotoxy(10,8);  printf("\xB3"); 	gotoxy(11,8);  printf("   3. Nomina       (n)"); 				gotoxy(37,8);  printf("\xB3");				gotoxy(38,8);  printf("\xB3");																																											gotoxy(110,8);  printf("\xB3");
	gotoxy(10,9);  printf("\xB3"); 	gotoxy(11,9);  printf("   4. Verb         (v)");				gotoxy(37,9);  printf("\xB3");				gotoxy(38,9);  printf("\xB3");																																											gotoxy(110,9);  printf("\xB3");
	gotoxy(10,10); printf("\xB3"); 	gotoxy(11,10); printf("---------------------------");			gotoxy(37,10); printf("\xB3");				gotoxy(38,10); printf("\xB3");																																											gotoxy(110,10); printf("\xB3");
	gotoxy(10,11); printf("\xB3"); 	gotoxy(11,11); printf("---------------------------");			gotoxy(37,11); printf("\xB3");				gotoxy(38,11); printf("\xB3");																																											gotoxy(110,11); printf("\xB3");
	gotoxy(10,12); printf("\xB3"); 																	gotoxy(37,12); printf("\xB3");				gotoxy(38,12); printf("\xB3");																																											gotoxy(110,12); printf("\xB3");
	gotoxy(10,13); printf("\xB3"); 																	gotoxy(37,13); printf("\xB3");				gotoxy(38,13); printf("\xB3");																																											gotoxy(110,13); printf("\xB3");
	gotoxy(10,14); printf("\xB3"); 	gotoxy(11,15); printf("---------------------------");			gotoxy(37,14); printf("\xB3");				gotoxy(38,14); printf("\xB3");																																											gotoxy(110,14); printf("\xB3");
	gotoxy(10,15); printf("\xB3"); 																	gotoxy(37,15); printf("\xB3");				gotoxy(38,15); printf("\xB3");																																											gotoxy(110,15); printf("\xB3");
	gotoxy(10,16); printf("\xB3"); 																	gotoxy(37,16); printf("\xB3");				gotoxy(38,16); printf("\xB3");																																											gotoxy(110,16); printf("\xB3");
	gotoxy(10,17); printf("\xB3"); 																	gotoxy(37,17); printf("\xB3");				gotoxy(38,17); printf("\xB3");																																											gotoxy(110,17); printf("\xB3");
	gotoxy(10,18); printf("\xB3"); 																	gotoxy(37,18); printf("\xB3");				gotoxy(38,18); printf("\xB3");																																											gotoxy(110,18); printf("\xB3");
	gotoxy(10,19); printf("\xB3"); 	gotoxy(11,19); printf("---------------------------");			gotoxy(37,19); printf("\xB3");				gotoxy(38,19); printf("\xB3");																																											gotoxy(110,19); printf("\xB3");
	gotoxy(10,20); printf("\xB3"); 	gotoxy(20,20);  printf("---------");							gotoxy(37,20); printf("\xB3");				gotoxy(38,20); printf("\xB3");																																											gotoxy(110,20); printf("\xB3");
	gotoxy(10,21); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9"); 	gotoxy(38,21); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(10,22); printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,23); printf("\xB3");	  																																																																						gotoxy(110,23); printf("\xB3");
	gotoxy(10,24); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
}


int pilihanMainMenu(){
	/* Kamus Data Lokal */
	int counter = 2;
	int Set[] = {7,7,7};
	char key;
	
	/* Tampilan Nav */
	gotoxy(13,16); printf("F1   : Pencarian kata ");
	gotoxy(13,17); printf("UP   : Selection Menu ");
	gotoxy(13,18); printf("DOWN : Selection Menu "); 
	gotoxy(39,3);  printf("Pencarian kata : ");
	
	/* Tampilan Main Menu*/
	gotoxy(65,6);  printf("  M A I N   M E N U");
	gotoxy(65,7);  printf("=====================");
	gotoxy(40,8);  printf("=====================================================================");
	
	while(1){
		gotoxy(69,11); color(Set[0]); printf("Tambah  Data"); 
		gotoxy(69,13); color(Set[1]); printf(" Hapus Data");
		gotoxy(62,15); color(Set[2]); printf("Print Berdasarkan Kelas Kata");
	
		key = getch();
		
		if(key == 72 && counter >= 2 && counter <= 3) 		//Up Kursor
		{
			counter--;
		}
		
		if(key == 80 && counter >= 1 && counter <= 2)		//Down Kursor
		{
			counter++;
		}
		
		if(key == 59)										//Tombol F1
		{			
			counter = 59; 
			break;  
		}
		
		if(key == 27)										// Tombol ESC
		{
			counter = 27; 
			break; 
		}
		
		if(key == '\r')
		{
			switch(counter){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				default:
					break;	
			}
			break; 
		}
		
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7; 
		
 		if(counter == 1 || counter == 2 || counter == 3){
			Set[counter-1] = 12;
		}
	}
	return counter; 
}


void boxTampilanKelasKata()
{
	system("cls");
	gotoxy(10,2);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,3);  printf("\xB3"); 																																																																							gotoxy(110,3);  printf("\xB3");
	gotoxy(10,4);  printf("\xB3"); 																																																																							gotoxy(110,4);  printf("\xB3");
	gotoxy(10,5);  printf("\xB3"); 																																																																							gotoxy(110,5);  printf("\xB3");
	gotoxy(10,6);  printf("\xB3"); 																																																																							gotoxy(110,6);  printf("\xB3");
	gotoxy(10,7);  printf("\xB3"); 																																																																							gotoxy(110,7);  printf("\xB3");
	gotoxy(10,8);  printf("\xB3"); 																																																																							gotoxy(110,8);  printf("\xB3");
	gotoxy(10,9);  printf("\xB3"); 																																																																							gotoxy(110,9);  printf("\xB3");
	gotoxy(10,10); printf("\xB3"); 																																																																							gotoxy(110,10); printf("\xB3");
	gotoxy(10,11); printf("\xB3"); 																																																																							gotoxy(110,11); printf("\xB3");
	gotoxy(10,12); printf("\xB3"); 																																																																							gotoxy(110,12); printf("\xB3");
	gotoxy(10,13); printf("\xB3"); 																																																																							gotoxy(110,13); printf("\xB3");
	gotoxy(10,14); printf("\xB3"); 																																																																							gotoxy(110,14); printf("\xB3");
	gotoxy(10,15); printf("\xB3"); 																																																																							gotoxy(110,15); printf("\xB3");
	gotoxy(10,16); printf("\xB3"); 																																																																							gotoxy(110,16); printf("\xB3");
	gotoxy(10,17); printf("\xB3"); 																																																																							gotoxy(110,17); printf("\xB3");
	gotoxy(10,18); printf("\xB3"); 																																																																							gotoxy(110,18); printf("\xB3");
	gotoxy(10,19); printf("\xB3"); 																																																																							gotoxy(110,19); printf("\xB3");
	gotoxy(10,20); printf("\xB3"); 																																																																							gotoxy(110,20); printf("\xB3");
	gotoxy(10,21); printf("\xB3"); 																																																																							gotoxy(110,21); printf("\xB3");
	gotoxy(10,22); printf("\xB3"); 																																																																							gotoxy(110,22); printf("\xB3");
	gotoxy(10,23); printf("\xB3"); 																																																																							gotoxy(110,23); printf("\xB3");
	gotoxy(10,24); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(10,25); printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,26); printf("\xB3");	  																																																																						gotoxy(110,26); printf("\xB3");
	gotoxy(10,27); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
}


void printWrapPenjelasan(char karakter[100])
{
	/* Kamus Data Lokal*/
    int array = 0;                  // variable menampung data input
    
    /* Algoritma */
    gotoxy(40,13); printf("Penjelasan   : ");
    while(1)
	{
        /* Proses Tampil ke layar */	
        printf("%c", karakter[array]);
        array = array + 1;
        
        if(array >= 99 || karakter[array] == '\0')
        {
        	break;
		}
		
        if(array == 54)
        {
           	gotoxy(55,14);
		}
    }
}


void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int x, int y)
{
	/* Kamus Data Lokal */
	COORD coord;            // Tipe data komposit koordinat
	
	/* Proses mengisi untuk menentukan posisi baru kursor */
	coord.X = x;
	coord.Y = y;
	
	/* Proses mengatur posisi kursor */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
