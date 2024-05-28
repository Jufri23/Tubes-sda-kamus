#include "kamus.h"
#include <stdio.h>

int main()
{
    Node *root = NULL;
    loadFromFile(&root);

    int pilihan;

    do
    {
        printf("**********************************************\n");
        printf("*                                            *\n");
        printf("*        Selamat Datang di Kamus Sunda       *\n");
        printf("*                                            *\n");
        printf("**********************************************\n\n");
        printf("1. Admin\n");
        printf("2. Pengguna Umum\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
        {
            if (adminLogin())
            {
                menuAdmin(&root);
            }
        }
        case 2:
            if (userLogin())
            {
                menuPengguna(root);
            }
            break;
        case 3:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}
