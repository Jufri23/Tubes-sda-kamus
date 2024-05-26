/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    
    Pembuat Modul : Achmadya Ridwan I	(211511001)
------------------------------------------------------------- */
#include "avl.h"
#include "tampilanUI.h"


int max(int data1, int data2)
{
    /* Algoritma */

    if(data1 > data2)
    {
        return data1;
    }
    
    return data2;
}

int getHeight(address *root)
{
    /* Algoritma */

    /* Jika belum terbentuk root */
    if(root == NULL)
    {
        return 0;
    }
    
    /* Me-return nilai height dalam node */
    return root->height;
}

int getBalanceFactor(address *root)
{
    /* Algoritma */

    /* Jika belum terbentuk root */
    if(root ==NULL)
	{
        return 0;
    }

    /* Me-return selisih tinggi anak kiri dan anak kanan */
    return (getHeight(root->LeftSon) - getHeight(root->RightSon));
}

address *alokasi(char *dataKata, char *dataPenjelasanKata, char *dataKelasKata)
{
    /* Kamus Data Lokal*/
    address *node;              // variable penampung untuk mengalokasi node
    
    /* Algoritma */

    /* Memesan memori */
    node = (address *) malloc(sizeof(address));
    if(node == NULL)
	{
        return 0;
    }
    
    /* Mengisi memori yang sudah dipesan sebelumya dengan data */
    strcpy(node->KataIndonesia, dataKata);
    strcpy(node->PenjelasanKata, dataPenjelasanKata); 
    strcpy(node->KelasKata, dataKelasKata); 
    
    /* Inisialisasi penunjuk dan tinggi node */
    node->LeftSon = NULL;
    node->RightSon = NULL;
    node->height = 1;

    return node;
}

address *leftRotate(address *root)
{
    /* Kamus Data Lokal */
    address *newRoot;
    address *temp;

    /* Algoritma */

    newRoot = root->RightSon;
    temp = newRoot->LeftSon;
    newRoot->LeftSon = root;
    root->RightSon = temp;

    /* Memperbaharui nilai height */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rightRotate(address *root)
{
    /* Kamus Data Lokal */
    address *newRoot;
    address *temp;

    /* Algoritma */
    newRoot = root->LeftSon;
    temp = newRoot->RightSon;     
    newRoot->RightSon = root;
    root->LeftSon = temp;

    /* Memperbaharui nilai height */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rotate(address *root)
{
    /* Kamus Data Lokal */
    int balanceFactorRoot;                     // balance factor

    /* Algoritma */

    /* Mengambil tinggi tree yang baru dan mengidentifikasi anak yang tidak balance */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon))+1;
    balanceFactorRoot = getBalanceFactor(root);

    /* Jika anak kiri menyebabkan tidak balance dan anak kiri memiliki child di kiri */
    if(balanceFactorRoot>1 && getBalanceFactor(root->LeftSon)>0)
	{
        root = rightRotate(root);
    }

    /* Jika anak kiri menyebabkan tidak balance dan anak kiri memiliki child di kanan */
    else if(balanceFactorRoot > 1 && getBalanceFactor(root->LeftSon) <= 0)
	{
        root->LeftSon = leftRotate(root->LeftSon);
        root = rightRotate(root);
    }

    /* Jika anak kanan menyebabkan tidak balance dan anak kanan memiliki child di kanan */
    else if(balanceFactorRoot < -1 && getBalanceFactor(root->RightSon)<=0)
	{
        root = leftRotate(root);
    }

    /* Jika anak kanan menyebabkan tidak balance dan anak kanan memiliki child di kiri */
    else if(balanceFactorRoot < -1 && getBalanceFactor(root->RightSon)>0)
	{
        root->RightSon = rightRotate(root->RightSon);
        root = leftRotate(root);
    }

    return root;
}

address *InsertAVL(address *root, char *dataKata, char *dataPenjelasanKata,  char *dataKelasKata)
{
    /* Algoritma */

    /* Insertion jika belum terbentuk */
    if(root == NULL)
	{
        /* Alokasi awal (root) */
        root = alokasi(dataKata, dataPenjelasanKata, dataKelasKata);
        return root;
    }
 
    /* INSERTION (setelah tersebentuk root) */
    /* Jika nilai dataKata lebih kecil disambungkan di anak kiri*/
    if(strcmp(dataKata, root->KataIndonesia) < 0)
	{
        root->LeftSon = InsertAVL(root->LeftSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }

    /* Jika nilai dataKata lebih besar disambungkan di anak kanan */
    else if(strcmp(dataKata, root->KataIndonesia) > 0)
	{
        root->RightSon = InsertAVL(root->RightSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }

    /* Jika nilai dataKata sama penyambungan di batalkan */
    else
    {
    	gotoxy(45,23); printf("                                          ");
		gotoxy(38,23); printf("Ehh Ternyata data kata sudah tersedia, Gagal dehh..."); 
        Sleep(2000); 
        return root;
    }

    /* Melakukan rotasi agar setelah ditambah node baru tetap balance */
    root = rotate(root);
    return root;
}


address *Predecessor(address *root)
{
    /* Kamus Data Lokal*/
    address *current;
    
    /* Algoritma */

    current = root;
    while (current->RightSon != NULL)
	{
        current = current->RightSon;
    }
    
    return current;
}

address *Successor(address *root)
{
    /* Kamus Data Lokal*/
    address *current;
    
    /* Algortima */

    current = root;
    while (current->LeftSon != NULL)
	{
        current = current->LeftSon;
    }
    
    return current;
}

address *remove(address *root,  char *dataKata)
{
    /* Kamus Data Lokal */
    address *temp;

    /* Jika belum terbentuk */
    if(root == NULL)
	{
        return root;
    }
	
    /* Deteltion */
    /* Jika dataKata lebih kecil dari node, maka rekursif remove ke anak kiri */
    else if(strcmp(dataKata, root->KataIndonesia) < 0)
	{
        root->LeftSon = remove(root->LeftSon, dataKata);
    }

    /* Jika dataKata lebih besar dari node, maka rekursif remove ke anak kanan */
    else if(strcmp(dataKata, root->KataIndonesia) > 0)
	{
        root->RightSon = remove(root->RightSon, dataKata);
    }

    /* Jika dataKata sama, maka remove node tersebut dengan ketentuan */
    else
	{
        if(root->LeftSon == NULL || root->RightSon==NULL)
		{
            temp = NULL;
            /* Jika memiliki anak di kanan saja */ 
            if(root->LeftSon==NULL)
			{
                temp = root->RightSon;
            }

            /* Jika memiliki anak di kiri saja */
            else
			{
                temp = root->LeftSon;
            }
            
            /* Jika tidak memiliki anak */
            if(temp == NULL)
			{
                temp = root;
                root = NULL;
            }
			
            else
			{
                *root = *temp;
            }
            free(temp);
        }
		
        /* Jika memiliki anak di kanan dan di kiri */
        else
		{
            /* Me-replace root dengan Predecessor dan dealokasi Predecessor tersebut */
            temp = Predecessor(root->LeftSon);
            strcpy(root->KataIndonesia, temp->KataIndonesia);
            root->LeftSon = remove(root->LeftSon, temp->KataIndonesia);
        }
    }
    if (root == NULL)
	{
        return root;
    }

    /* Melakukan rotasi agar tetap balance setelah proses deletion */
    return rotate(root);
}

void InPrint(address *root)
{
    /* Algortima */

    /* Jika belum terbentuk tree */
    if(root != NULL)
	{
        InPrint(root->LeftSon);
        printf("%s ", root->KataIndonesia); 
        InPrint(root->RightSon);
    }
}

void deleteBinaryTree(address *root)
{
    /* Algortima */

    /* Jika belum terbentuk tree */
    if (root == NULL) 
	{
        return;
    }
    deleteBinaryTree(root->LeftSon);
    deleteBinaryTree(root->RightSon);
    
    /* Dealokasi */
    delete root;
    root = NULL;
}

char *inputKata(char karakter[25])
{
    /* Kamus Data Lokal*/
    char ch;                        // variable penampung input karakter
    int array = 0;                  // variable menampung data input
    
    /* Algoritma agar insert tidak melebihi batas (25 karakter )*/
    memset(karakter, 0, 1);
    
    while(1)
	{
		
        /* Pengaturan agar karakter seragam (huruf kecil) */
        ch = tolower(getch());

        /* Jika menekan enter selesai */
        if(ch == 13 || ch == 10)
		{
            break;
        }

        /* Jika menekan backspace mengahapus karakter */
        else if(ch == 8 || ch == 127)
		{
            /* Jika line berada di line awal pengahpusan tidak bekerja */
            if(array <= 0)
			{
                continue;
            }
			
            else
			{
                printf("\b \b");
                karakter[array-1] = '\0';
                array--;
            }
        }
		
        else
		{
            /* Jika batas karakter yang dinput sama dengan 25 tidak dapat menginput lagi */
        	if(strlen(karakter)>=24)
			{
            	continue;
			}

            /* Mengimput */
            karakter[array] = ch;
            karakter[array+1] = '\0';
            printf("%c", karakter[array]);
            array = array + 1;
        }
    }
    
    /* return NULL di ujung array */
    karakter[array] = '\0';
    return karakter;
}

char *inputPenjelasan(char karakter[100])
{
    /* Kamus Data Lokal*/
    char ch;                        // variable penampung input karakter
    int array = 0;                  // variable menampung data input
    
    /* Algoritma agar insert tidak melebihi batas (25 karakter )*/
    memset(karakter, 0, 1);
    while(1)
	{
        /* Pengaturan agar karakter seragam (huruf kecil) */
        ch = tolower(getch());

        /* Jika menekan enter selesai */
        if(ch == 13 || ch == 10)
		{
            break;
        }

        /* Jika menekan backspace mengahapus karakter */
        else if(ch == 8 || ch == 127)
		{
            /* Jika line berada di line awal pengahpusan tidak bekerja */
            if(array <= 0)
			{
                continue;
            }
			else if(array == 54)
			{
				gotoxy(106,11);
                printf("\b \b");
				array--; 
			}
            else
			{
                printf("\b \b");
                karakter[array-1] = '\0';
                array--;
            }
        }
		
        else
		{
            /* Jika batas karakter yang dinput sama dengan 100 tidak dapat menginput lagi */
        	if(strlen(karakter)>=99)
			{
            	continue;
			}

            /* Mengimput */
            karakter[array] = ch;
            karakter[array+1] = '\0';
            printf("%c", karakter[array]);
            array = array + 1;
            
            if(array == 54)
            {
            	gotoxy(51,12);
                printf("%c", karakter[array]);
			}
        }
    }
    
    /* return NULL di ujung array */
    karakter[array] = '\0';
    return karakter;
}



