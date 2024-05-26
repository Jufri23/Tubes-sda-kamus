#include "kamus.h"
#include <iostream>
using namespace std;

int main()
{
    Node *root = nullptr;
    loadFromFile(root);

    int pilihan;

    do
    {
        cout << "\n===== Kamus Bahasa Sunda =====\n";
        cout << "1. Admin\n";
        cout << "2. Pengguna Umum\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            int adminPilihan;
            cout << "\n===== Admin =====\n";
            cout << "1. Login\n";
            cout << "2. Registrasi\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> adminPilihan;

            if (adminPilihan == 1)
            {
                if (adminLogin())
                {
                    menuAdmin(root);
                }
            }
            else if (adminPilihan == 2)
            {
                adminRegister();
            }
            else
            {
                cout << "Pilihan tidak valid.\n";
            }
            break;
        }
        case 2:
            if (userLogin())
            {
                menuPengguna(root);
            }
            break;
        case 3:
            cout << "Terima kasih telah menggunakan aplikasi ini!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}
