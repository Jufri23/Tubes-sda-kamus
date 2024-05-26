#include "kamus.h" 

int main() {
    string fileName = "kamus.txt";
    Node* root = buildTreeFromFile(fileName);
    
    int pilihan;

    while (true) {
        cout << "\nSelamat datang di Aplikasi Kamus Bahasa Sunda!\n";
        cout << "Pilih jenis login:\n";
        cout << "1. Admin\n";
        cout << "2. Pengguna Umum\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (adminLogin()) {
                    menuAdmin(root);
                }
                break;
            case 2:
                if (userLogin()) {
                    menuPengguna(root);
                }
                break;
            case 3:
                cout << "Terima kasih telah menggunakan aplikasi ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        if (pilihan == 3) {
            break;
        }
    }

    return 0;
}
