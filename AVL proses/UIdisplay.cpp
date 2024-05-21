#include <iostream>
#include <conio.h> // Untuk _getch() pada Windows
#ifdef _WIN32
#include <windows.h> // Untuk fungsi-fungsi Windows API
#endif
#include "UIdisplay.h"
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> adminAccounts;

void clearScreen()
{
    // Fungsi ini akan membersihkan layar dengan perintah sistem
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void setColor(int color)
{
#ifdef _WIN32
    // Hanya bekerja pada Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#else
    // ANSI escape codes for other systems (e.g., Linux, Mac)
    cout << "\033[" << color << "m";
#endif
}

void resetColor()
{
#ifdef _WIN32
    // Kembali ke warna standar
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#else
    // ANSI escape code untuk mengatur ulang warna
    cout << "\033[0m";
#endif
}

void welcomePage()
{
    clearScreen();
    cout << "Selamat datang di kamus bahasa sunda" << endl;
    _getch();
}

bool registerAdmin()
{
    string username, password;

    clearScreen();
    cout << "=== Registrasi Admin ===" << endl;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    if (adminAccounts.find(username) == adminAccounts.end())
    {
        adminAccounts[username] = password;
        cout << "Registrasi berhasil!" << endl;
        _getch();
        welcomePage();
        return true;
    }
    else
    {
        cout << "Username sudah terdaftar. Silakan coba lagi." << endl;
        _getch();
        return false;
    }
}

bool adminLogin()
{
    string username, password;

    clearScreen();
    cout << "=== Admin Login ===" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (adminAccounts.find(username) != adminAccounts.end() && adminAccounts[username] == password)
    {
        cout << "Login sebagai Admin berhasil!" << endl;
        _getch();
        welcomePage();
        return true;
    }
    else
    {
        cout << "Login sebagai Admin gagal. Username atau Password salah." << endl;
        _getch();
        return false;
    }
}

void adminOptions()
{
    int highlight = 0;
    const char *choices[] = {
        "Login",
        "Registrasi",
        "Keluar"};

    while (true)
    {
        clearScreen();
        cout << "Pilih opsi:" << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                setColor(32); // Set warna hijau untuk pilihan yang disorot
                cout << "> " << choices[i] << endl;
                resetColor();
            }
            else
            {
                cout << "  " << choices[i] << endl;
            }
        }

        int c = _getch();
        switch (c)
        {
        case 72: // Tombol panah atas
            highlight = (highlight - 1 + 3) % 3;
            break;
        case 80: // Tombol panah bawah
            highlight = (highlight + 1) % 3;
            break;
        case 13: // Tombol Enter
            switch (highlight)
            {
            case 0:
                if (adminLogin())
                    return;
                break;
            case 1:
                if (registerAdmin())
                    return;
                break;
            case 2:
                return;
            }
            break;
        default:
            break;
        }
    }
}
