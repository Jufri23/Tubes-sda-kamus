#include "kamus.h"
#include <fstream>
#include <iomanip>

const string FILE_NAME = "kamus.txt";

int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

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
                root = sisipkanAVL(root, kata, arti);
            }
        }
        file.close();
    } else {
        cout << "File " << fileName << " tidak dapat dibuka." << endl;
    }
    return root;
}

int getBalanceFactor(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return getHeight(root->kiri) - getHeight(root->kanan);
}

Node* rotateKiri(Node* root) {
    Node* newRoot = root->kanan;
    root->kanan = newRoot->kiri;
    newRoot->kiri = root;

    root->height = max(getHeight(root->kiri), getHeight(root->kanan)) + 1;
    newRoot->height = max(getHeight(newRoot->kiri), getHeight(newRoot->kanan)) + 1;

    return newRoot;
}

Node* rotateKanan(Node* root) {
    Node* newRoot = root->kiri;
    root->kiri = newRoot->kanan;
    newRoot->kanan = root;

    root->height = max(getHeight(root->kiri), getHeight(root->kanan)) + 1;
    newRoot->height = max(getHeight(newRoot->kiri), getHeight(newRoot->kanan)) + 1;

    return newRoot;
}

Node* rotate(Node* root) {
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) {
        if (getBalanceFactor(root->kiri) >= 0) {
            return rotateKanan(root);
        } else {
            root->kiri = rotateKiri(root->kiri);
            return rotateKanan(root);
        }
    } else if (balanceFactor < -1) {
        if (getBalanceFactor(root->kanan) <= 0) {
            return rotateKiri(root);
        } else {
            root->kanan = rotateKanan(root->kanan);
            return rotateKiri(root);
        }
    }

    return root;
}

Node* sisipkanAVL(Node* root, string kata, string arti) {
    if (root == nullptr) {
        root = new Node{kata, arti, nullptr, nullptr, 1};
    } else if (kata < root->kata) {
        root->kiri = sisipkanAVL(root->kiri, kata, arti);
    } else if (kata > root->kata) {
        root->kanan = sisipkanAVL(root->kanan, kata, arti);
    } else {
        return root;
    }

    root->height = 1 + max(getHeight(root->kiri), getHeight(root->kanan));
    root = rotate(root);

    return root;
}

Node* successor(Node* root) {
    if (root == nullptr || root->kanan == nullptr) {
        return nullptr;
    }

    root = root->kanan;
    while (root->kiri != nullptr) {
        root = root->kiri;
    }

    return root;
}

Node* predecessor(Node* root) {
    if (root == nullptr || root->kiri == nullptr) {
        return nullptr;
    }

    root = root->kiri;
    while (root->kanan != nullptr) {
        root = root->kanan;
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
        if (root->kiri == nullptr || root->kanan == nullptr) {
            Node* temp = root->kiri ? root->kiri : root->kanan;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = predecessor(root->kanan);
            root->kata = temp->kata;
            root->arti = temp->arti;
            root->kanan = hapusNode(root->kanan, temp->kata);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(getHeight(root->kiri), getHeight(root->kanan));
    root = rotate(root);

    return root;
}

void tampilkanSemuaKata(Node* root) {
    if (root != nullptr) {
        // Menampilkan header tabel
        cout << setw(20) << left << "Kata" << setw(20) << "Arti" << endl;
        cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

        // Menampilkan setiap kata dan artinya dalam bentuk tabel
        tampilkanSemuaKataHelper(root);

        cout << endl;
    }
}

void tampilkanSemuaKataHelper(Node* root) {
    if (root != nullptr) {
        tampilkanSemuaKataHelper(root->kiri);
        // Menampilkan setiap kata dan artinya dalam bentuk tabel
        cout << setw(20) << left << root->kata << setw(20) << root->arti << endl;
        tampilkanSemuaKataHelper(root->kanan);
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

void saveToFile(Node* root, const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        tampilkanSemuaKata(root);
        file.close();
    } else {
        cout << "File " << fileName << " tidak dapat dibuka." << endl;
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

// Fungsi untuk melakukan registrasi admin
bool adminRegister() {
    string username, password;
    cout << "Masukkan username admin baru: ";
    cin >> username;
    cout << "Masukkan password admin baru: ";
    cin >> password;

    // Membuka file untuk menulis data admin baru
    ofstream file("admin.txt", ios::app);
    if (!file) {
        cerr << "File admin.txt tidak dapat dibuka." << endl;
        return false;
    }

    // Menulis username dan password admin baru ke file
    file << username << " " << password << endl;
    file.close();

    cout << "Registrasi admin berhasil!" << endl;
    return true;
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
void menuAdmin(Node* root) {
    int pilihan;
    string kata, arti;
    do {
        cout << "\n===== Menu Admin =====\n";
        cout << "1. Tambah Kata\n";
        cout << "2. Tampilkan Semua Kata\n";
        cout << "3. Hapus Kata\n";
        cout << "4. Logout\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan kata: ";
                cin >> kata;
                cout << "Masukkan arti: ";
                cin >> arti;
                root = sisipkanAVL(root, kata, arti);
                saveToFile(root, FILE_NAME);
                break;
            case 2:
                cout << "Daftar Kata dalam Kamus:\n";
                tampilkanSemuaKata(root);
                break;
            case 3:
                cout << "Masukkan kata yang ingin dihapus: ";
                cin >> kata;
                root = hapusNode(root, kata);
                saveToFile(root, FILE_NAME);
                break;
            case 4:
                cout << "Logout berhasil.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);
}

// Fungsi untuk menampilkan menu pengguna
void menuPengguna(Node* root) {
    int pilihan;
    string kata;
    do {
        cout << "\n===== Menu Pengguna =====\n";
        cout << "1. Cari Kata\n";
        cout << "2. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan kata yang ingin dicari: ";
                cin >> kata;
                tampilkanArti(root, kata);
                break;
            case 2:
                cout << "Terima kasih telah menggunakan aplikasi ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 2);
}
