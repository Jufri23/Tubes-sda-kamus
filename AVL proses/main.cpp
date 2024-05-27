#include "kamus.h"


int main() {
    string fileName = "kamus.txt";
    Node* root = buildTreeFromFile(fileName);
    int pilihan;
    string kata, arti;

    do {
        cout << "\n===== Kamus Bahasa Sunda =====\n";
        cout << "1. Tambah Kata\n";
        cout << "2. Tampilkan Semua Kata\n";
        cout << "3. Hapus Kata\n";
        cout << "4. Cari Kata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan kata: ";
                cin >> kata;
                cout << "Masukkan arti: ";
                cin >> arti;
                root = sisipkanAVL(root, kata, arti);
                saveToFile(root, fileName);
                break;
            case 2:
                cout << "Daftar Kata dalam Kamus:\n";
                {
                    ifstream file(fileName);
                    if (file.is_open()) {
                        string line;
                        while (getline(file, line)) {
                            cout << line << endl;
                        }
                        file.close();
                    } else {
                        cout << "File " << fileName << " tidak dapat dibuka." << endl;
                    }
                }
                break;
            case 3:
                cout << "Masukkan kata yang ingin dihapus: ";
                cin >> kata;
                root = hapusNode(root, kata);
                saveToFile(root, fileName);
                break;
            case 4:
                cout << "Masukkan kata yang ingin dicari: ";
                cin >> kata;
                tampilkanArti(root, kata);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan aplikasi ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
