/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
    File        : main.c 
------------------------------------------------------------- */
#include "tampilanUI.h"
#include "fiturKamus.h"
#include "avl.h"

int main()
{
	/* Kamus data */
	bool run = true;        // variable untuk menjalankan menu
	address *root = NULL;   // root pada tree dan diinisialisasi NULL

	/* Buka dan baca isi file */
	root = bukaFile(root); 
	
	/* Masuk ke tampilan awal */
	boxTampilanAwal();
	pilihanAwal(&run); 
	/* Masuk ke main menu */
	while(run)
	{
		system("cls");
		color(7);
		boxTampilanMenu();
		root = mainMenu(root, &run);
	}
	
	/* Menghapus tree setelah tidak digunakan */
	deleteBinaryTree(root);
	
	color(7);
	return 0;
}
