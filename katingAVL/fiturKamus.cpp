/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Wildan Setya Nugraha	(211511032)
------------------------------------------------------------- */

#include "avl.h"
#include <cstdio>
#include <cstdlib>
#pragma GCC diagnostic ignored "-Wwrite-strings" //Mengabaikan 
#include "fiturKamus.h"

/*---------------------------------*/
address *bukaFile (address *root)
{
	/* Kamus Data Lokal */
	FILE *bukaFile;             // variable untuk menampung file
	char kata[25];              // variable untuk menampung kata
	char penjelasan[100];       // variable untuk menampung penjelasan
	char kelasKata[4];          // variable untuk menampung kelas kata
	
    /* Algortima */

	/* Proses buka file database kamus bahasa Indonesia */
	bukaFile = (fopen(namaFileData, "r"));
	
	/* Cek Apakah file database tersebut ada atau tidak */
	if(!bukaFile)
	{
		boxFileTidakTersedia(); 
		return NULL; 
	}

	else 
	{  
        /* Jika ada maka baca isinya lalu insert ke dalam AVL Tree */
		while(!feof(bukaFile))
		{   
			fscanf(bukaFile, "%[^;];%[^;];%s\n", kata, penjelasan, kelasKata); 
            root = InsertAVL(root, kata, penjelasan, kelasKata);
        }
	}
	fclose(bukaFile);
	return root;
}

/*---------------------------------*/
address *tambahDataKata(address *root)
{
	/* Kamus Data Lokal */
	char kata[25];                  // variable untuk menampung kata
	char *kelasKata;                // variable untuk menampung kelas kata
    char penjelasan[100];           // variable untuk menampung penjelasan
	char dataOk;                    // variable untuk konfirmasi
	bool kelasKataValid;            // variable untuk memvalidasi kata yang diinput
	int pilihKelasKata;             // variable untuk memilih kelas kata
		
    /* Algortima */

	/* Proses Inputan Data Kata */
	do
	{
		system("cls");
		boxTampilanMenu();
		
		gotoxy(65,6);  printf("  T A M B A H  D A T A");
		gotoxy(65,7);  printf("========================");
		gotoxy(40,8);  printf("=====================================================================");
		
		/* Input Kata Indonesia */
		gotoxy(40,9); printf("Kata       :");
		inputKata(kata);
		fflush(stdin);
		
		/* Input Penjelasan dari katanya */
		gotoxy(40,11); printf("Penjelasan :");
        inputPenjelasan(penjelasan);
		fflush(stdin);
		
		/* Inputan untuk menentukan kata tersebut masuk ke dalam kelas kata apa */
		kelasKataValid = false;
		while(kelasKataValid == false)
		{
			gotoxy(65,14); printf("      1. Adjektiva");
			gotoxy(65,15); printf("      2. Adverbia");
			gotoxy(65,16); printf("      3. Nomina");
			gotoxy(65,17); printf("      4. Verba");
			gotoxy(45,23); printf("                                         ");
			gotoxy(45,23); printf("Pilih dengan angka (1-4)");
			gotoxy(40,18); printf("Kelas Kata : ");
			scanf("%d", &pilihKelasKata);
			fflush(stdin); 
			
			switch(pilihKelasKata)
			{
				case 1 :
                {
                    kelasKata = "adj";
                    kelasKataValid = true;
                    break;
                }

				case 2 :
                {
                    kelasKata = "adv";
                    kelasKataValid = true;
                    break;
                }	

				case 3 :
                {
                    kelasKata = "n";
                    kelasKataValid = true;
                    break;
                }

                case 4 :
                {
                    kelasKata = "v";
                    kelasKataValid = true;
                    break;
                }	

				default :
                {
                	gotoxy(45,23); printf("                        ");
                    gotoxy(45,23); printf("     Inputan salah");
                    Sleep(1500);
                    gotoxy(45,23); system("pause");
                    break;
                }
			}
		}
		
		/* Print Data hasil Inputan sementara apakah sudah ok */
		system("cls");
		boxTampilanMenu();
		gotoxy(65,6);  printf("  T A M B A H  D A T A");
		gotoxy(65,7);  printf("========================");
		gotoxy(40,8);  printf("=====================================================================");
		gotoxy(40,11); printf("kata         : %s", kata);
		printWrapPenjelasan(penjelasan); 
		gotoxy(40,16); printf("Kelas kata   : %s", kelasKata); 
		
		/* Input apakah data sudah benar */
		gotoxy(65,19); printf("      Data Ok?");
		gotoxy(45,23); printf("Tekan (T/t: Revisi, Bebas: Lanjut)");
		dataOk = getch();
		
	}while(dataOk == 'T' || dataOk == 't');
	
	if(dataOk != 'T' || dataOk != 't'){
		gotoxy(45,23); printf("                                          ");
		gotoxy(45,23); printf("Asik data berhasil ditambahkan");
		Sleep(2000); 
	}
	
	/* Proses Insert ke dalam AVL Tree */
	root = InsertAVL(root, kata, penjelasan, kelasKata); 
	simpanKeFile(root);
	return root;
}

void temukanDataKata(address *root)
{
	/* Kamus Data Lokal */
	bool kataKetemu;
	char kata[25]; 
	
    /* Algortima */
    system("cls"); 
    color(7); 
    boxTampilanMenu(); 
	gotoxy(39,3);  printf("Pencarian kata : ");
	inputKata(kata);
	fflush(stdin);
	
	gotoxy(65,6);  printf("   H A S I L  C A R I");
	gotoxy(65,7);  printf("========================");
	gotoxy(40,8);  printf("=====================================================================");
	
	/* Proses pencarian kata */
	kataKetemu = false;
	while(kataKetemu == false)
	{
        /* Jika Tree belum terbentuk */
		if(root == NULL)
		{ 
			break;	
		}

		/* Jika kata yang dicari dan kata yang ada di AVL Tree sama	*/
		else if(strcmp(kata, root->KataIndonesia) == 0)
		{
			gotoxy(40,11); printf("kata         : %s", root->KataIndonesia);
			printWrapPenjelasan(root->PenjelasanKata); 
			gotoxy(40,16); printf("Kelas kata   : %s", root->KelasKata);
			kataKetemu = true;
		} 
		
        /*Jika kata yang dicari dengan kata yang ada di AVL Tree lebih kecil jumlah ASCII-nya */
		else if (strcmp(kata, root->KataIndonesia) < 0)
		{
			root = root->LeftSon;
		
		}
		
        /* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih besar jumlah ASCII-nya */
		else if (strcmp(kata, root->KataIndonesia) > 0)
		{
			root = root->RightSon;
		}
	}
	
	if(kataKetemu == false)
	{
		gotoxy(45,23); printf("Kata %s tidak tersedia nihh :(", kata);
		Sleep(2500);
	}
	gotoxy(45,23); printf("                                         ");
	gotoxy(45,23); system("pause");
}

/*---------------------------------*/
bool isKataTersedia(address *root, char *dataKata)
{
	/* Kamus Data Lokal */
	bool kataKetemu;
	
    /* Algortima */

	/* Proses pencarian kata */
	kataKetemu = false;
	while(kataKetemu == false)
	{
		if(root == NULL)
		{ 
			break;
		}
		
        /* Jika kata yang dicari dan kata yang ada di AVL Tree sama	*/
		else if(strcmp(dataKata, root->KataIndonesia) == 0)
		{
			gotoxy(40,11); printf("kata         : %s", root->KataIndonesia);
			printWrapPenjelasan(root->PenjelasanKata); 
			gotoxy(40,16); printf("Kelas kata   : %s", root->KelasKata);
			kataKetemu = true;
		}

		/* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih kecil jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) < 0)
		{
			root = root->LeftSon;
		}

		/* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih besar jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) > 0)
		{
			root = root->RightSon;
		}
	}
	return kataKetemu; 
}
/*---------------------------------*/


/*---------------------------------*/
address *hapusDataKata(address *root)
{
	/* Kamus Data Lokal */
	char kata[25];
	char yakin;
	
    /* Algortima */
    menuHapus:
		system("cls"); 
	    color(7); 
	    boxTampilanMenu(); 
		gotoxy(39,3);  printf("Hapus kata : ");
		inputKata(kata);
		fflush(stdin);
		
		gotoxy(65,6);  printf("   H A P U S  K A T A");
		gotoxy(65,7);  printf("========================");
		gotoxy(40,8);  printf("=====================================================================");
		gotoxy(45,23); printf("                                                         ");
		
		if(isKataTersedia(root, kata) && root!=NULL)
		{		
			gotoxy(65,19); printf("    Yakin dihapus?");
			gotoxy(45,23); printf("Tekan (Y/y: Yakin, Bebas: Ga yakin) ");
			yakin = getch();
		
			if(yakin == 'Y' || yakin == 'y')
			{
				root = remove(root, kata);
				gotoxy(45,23); printf("                                          ");
				gotoxy(45,23); printf("Data berhasil dihapus yaa");
				Sleep(2000); 
			} 
			else 
			{
				gotoxy(45,23); printf("                                          ");
				gotoxy(45,23); printf("Ga yakin dihapus yasudah...");
				Sleep(2000);
			}
			
		}
		else
		{
			gotoxy(45,23); printf("Kata %s tidak tersedia nihh :(", kata);
			Sleep(2500);
		}
		
	simpanKeFile(root);
	gotoxy(45,23); printf("                                         ");
	gotoxy(45,23); system("pause");
	return root;
}

/*---------------------------------*/
void cariBerdasarkanKelasKata(address *root, char *dataKelasKata, bool *cek, int *kata, int *baris, int *kolom)
{
    /* Algortima */

	if(root!=NULL)
	{
		cariBerdasarkanKelasKata(root->LeftSon, dataKelasKata, &(*cek), &(*kata), &(*baris), &(*kolom));
		if(strcmp(dataKelasKata, root->KelasKata) == 0)
		{
			if(*kata == 21)
			{
				*baris = 3; 
				*kolom += 25;
			}
			gotoxy(*kolom, *baris); printf("%s ", root->KataIndonesia);
            *cek = true;
            *kata += 1; 
            *baris += 1; 
		} 
		cariBerdasarkanKelasKata(root->RightSon, dataKelasKata, &(*cek), &(*kata), &(*baris), &(*kolom));
	}
}

void printBerdasarkanKelasKata(address *root)
{
	/* Kamus Data Lokal */
	int pilihKelasKata;                 // variable untuk menampung pilihan kelas kata
	char *kelasKata;                    
	bool kelasKataValid;
	bool cek = false;
	int kata = 1;
	int kolom = 12; 
	int baris = 3; 
	
    /* Algortima */
	    system("cls");
	    color(7); 
		boxTampilanMenu();
			
		gotoxy(65,6);  printf("   K E L A S  K A T A");
		gotoxy(65,7);  printf("========================");
		gotoxy(40,8);  printf("=====================================================================");
	
		/* Memilih Kelas Kata yang ingin dicari */
		kelasKataValid = false;
		while(kelasKataValid == false)
		{
			gotoxy(65,10); printf("      1. Adjektiva");
			gotoxy(65,11); printf("      2. Adverbia");
			gotoxy(65,12); printf("      3. Nomina");
			gotoxy(65,13); printf("      4. Verba");
			gotoxy(45,23); printf("                                           ");
			gotoxy(45,23); printf("Pilih dengan angka (1-4)");
			gotoxy(45,16); printf("Kelas Kata : ");
			scanf("%d", &pilihKelasKata);
			fflush(stdin); 
			
			switch(pilihKelasKata)
			{
				case 1:
	            {
	                kelasKata = "adj"; 
					kelasKataValid = true;
					break;
	            }
					
				case 2:
	            {
					kelasKata = "adv";
					kelasKataValid = true;
					break;
	            }
	
				case 3:
	            {
					kelasKata = "n";
					kelasKataValid = true;
					break;
	            }
	
				case 4:
	            {
					kelasKata = "v";
					kelasKataValid = true;
					break;
	            }
	
				default:
	            {
	                gotoxy(45,23); printf("                                       ");
	                gotoxy(45,23); printf("     Inputan salah");
	                Sleep(1500);
	                gotoxy(45,23); system("pause");
	                break;
	            }
			}
		}
	
	/* Proses pencarian kata lalu print kata ke layar sesuai dengan kelas katanya */
	boxTampilanKelasKata();
	cariBerdasarkanKelasKata(root, kelasKata, &cek, &kata, &baris, &kolom);
    if(cek == false)
    {
        gotoxy(42,26); printf("Data kelas kata %s tidak tersedia nihh :(", kelasKata);
		Sleep(2500);
    }
    
    gotoxy(42,26); printf("                                                      ");
	gotoxy(45,26); system("pause");
}

/*--------------------------------------------------------------------------------------SAVE DATA KE DALAM FILE-----------------------------------------------------------------------------------*/
void tulisKeFile(FILE *file, address *root)
{
    /* Algortima */

	/* Proses menulis data kata ke dalam File berdasarkan postOrder */
	if(root!=NULL)
	{
		tulisKeFile(file, root->LeftSon);
		fprintf(file, "%s;%s;%s\n", root->KataIndonesia, root->PenjelasanKata, root->KelasKata);
		tulisKeFile(file, root->RightSon);	 
	}
}

void simpanKeFile(address *root)
{
	/* Kamus Data Lokal */
	FILE *filePenyimpanan;
	
    /* Algortima */

	/* Proses membuka dan menulis data ke dalam file penyimpanan */
	filePenyimpanan = fopen(namaFileData, "w");
	tulisKeFile(filePenyimpanan, root); 
	
	/* Menutup file penyimpanan */
	fclose(filePenyimpanan);
}
