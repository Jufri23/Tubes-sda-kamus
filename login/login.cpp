#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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


    cout << "Login pengguna berhasil!" << endl;
    return true;
}

int main() {
    int choice;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "Selamat datang!" << endl;
        cout << "Pilih jenis login:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pengguna Umum" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loggedIn = adminLogin();
                break;
            case 2:
                loggedIn = userLogin();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    // Di sini dapat dilanjutkan dengan menu aplikasi kamus bahasa Sunda

    return 0;
}
