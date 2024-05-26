#include "kamus.h"
#include <fstream>

const string FILE_NAME = "kamus.txt";


Node* buildTreeFromFile(const string& fileName) {
    Node* root = nullptr;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string kata = line.substr(0, pos);
                string arti = line.substr(pos + 1);
                root = sisipkan(root, kata, arti);
            }
        }
        file.close();
    } else {
        cout << "File " << fileName << " tidak dapat dibuka." << endl;
    }
    return root;
}

void loadFromFile(Node*& root) {
    ifstream file(FILE_NAME);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string kata = line.substr(0, pos);
                string arti = line.substr(pos + 1);
                root = sisipkan(root, kata, arti);
            }
        }
        file.close();
    }
}

void saveToFile(Node* root) {
    ofstream file(FILE_NAME);
    if (file.is_open()) {
        saveToFileHelper(root, file);
        file.close();
    }
}

void saveToFileHelper(Node* root, ofstream& file) {
    if (root != nullptr) {
        saveToFileHelper(root->kiri, file);
        file << root->kata << "," << root->arti << endl;
        saveToFileHelper(root->kanan, file);
    }
}

Node* sisipkan(Node* root, string kata, string arti) {
    if (root == nullptr) {
        root = new Node{kata, arti, nullptr, nullptr};
    } else if (kata < root->kata) {
        root->kiri = sisipkan(root->kiri, kata, arti);
    } else if (kata > root->kata) {
        root->kanan = sisipkan(root->kanan, kata, arti);
    }
    return root;
}

Node* hapusNode(Node* root, string kata) {
    if (root == nullptr) {
        return root;
    }

    if (kata < root->kata) {
        root->kiri = hapusNode(root->kiri, kata);
    } else if (kata > root->kata) {
        root->kanan = hapusNode(root->kanan, kata);
    } else {
        // Kasus 1: Node daun
        if (root->kiri == nullptr && root->kanan == nullptr) {
            delete root;
            root = nullptr;
        }
        // Kasus 2: Node hanya memiliki satu anak
        else if (root->kiri == nullptr) {
            Node* temp = root;
            root = root->kanan;
            delete temp;
        } else if (root->kanan == nullptr) {
            Node* temp = root;
            root = root->kiri;
            delete temp;
        }
        // Kasus 3: Node memiliki dua anak
        else {
            Node* temp = root->kiri;
            while (temp->kanan != nullptr) {
                temp = temp->kanan;
            }
            root->kata = temp->kata;
            root->arti = temp->arti;
            root->kiri = hapusNode(root->kiri, temp->kata);
        }
    }

    return root;
}

void tampilkanSemuaKata(Node* root) {
    if (root != nullptr) {
        tampilkanSemuaKata(root->kiri);
        cout << "Kata: " << root->kata << "  Arti: " << root->arti << endl;
        tampilkanSemuaKata(root->kanan);
    }
}

Node* cari(Node* root, string kata) {
    if (root == nullptr || root->kata == kata) {
        return root;
    } else if (kata < root->kata) {
        return cari(root->kiri, kata);
    } else {
        return cari(root->kanan, kata);
    }
}

void tampilkanArti(Node* root, string kata) {
    Node* node = cari(root, kata);
    if (node != nullptr) {
        cout << "Arti dari kata '" << kata << "' adalah: " << node->arti << endl;
    } else {
        cout << "Kata '" << kata << "' tidak ditemukan dalam kamus." << endl;
    }
}

// Fungsi untuk melakukan login admin
bool adminLogin() {
    string username, password;
    cout << "Masukkan username admin: ";
    cin >> username;
    cout << "Masukkan password admin: ";
    cin >> password;

    // Membuka file untuk membaca data admin
    ifstream file("admin.txt");
    if (!file) {
        cerr << "File admin.txt tidak dapat dibuka." << endl;
        return false;
    }

    string storedUsername, storedPassword;
    bool found = false;

    // Membaca setiap baris dalam file
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Login admin berhasil!" << endl;
        return true;
    } else {
        cout << "Login admin gagal. Username atau password salah." << endl;
        return false;
    }
}

// Fungsi untuk melakukan login pengguna umum
bool userLogin() {
    string username;
    cout << "Masukkan username pengguna: ";
    cin >> username;

    // Di sini bisa ditambahkan pengecekan terhadap file pengguna umum (jika diperlukan)

    cout << "Login pengguna berhasil!" << endl;
    return true;
}

// Fungsi untuk menampilkan menu admin
void menuAdmin(Node*& root) {
    int pilihan;
    string kata, arti;

    do {
        cout << "\n===== Kamus Bahasa Sunda (Admin) =====\n";
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
                root = sisipkan(root, kata, arti);
                saveToFile(root);
                break;
            case 2:
                cout << "Daftar Kata dalam Kamus:\n";
                tampilkanSemuaKata(root);
                break;
            case 3:
                cout << "Masukkan kata yang ingin dihapus: ";
                cin >> kata;
                root = hapusNode(root, kata);
                saveToFile(root);
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
}

// Fungsi untuk menampilkan menu pengguna umum
void menuPengguna(Node* root) {
    int pilihan;
    string kata;

    do {
        cout << "\n===== Kamus Bahasa Sunda (Pengguna Umum) =====\n";
        cout << "1. Tampilkan Semua Kata\n";
        cout << "2. Cari Kata\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Daftar Kata dalam Kamus:\n";
                tampilkanSemuaKata(root);
                break;
            case 2:
                cout << "Masukkan kata yang ingin dicari: ";
                cin >> kata;
                tampilkanArti(root, kata);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan aplikasi ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);
}