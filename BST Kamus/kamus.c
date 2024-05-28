#include "kamus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *FILE_NAME = "kamus.txt";

Node *buildTreeFromFile(const char *fileName)
{
    Node *root = NULL;
    FILE *file = fopen(fileName, "r");
    if (file != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            char *pos = strchr(line, ',');
            if (pos != NULL)
            {
                *pos = '\0';
                char *kata = line;
                char *arti = pos + 1;
                // Remove newline character from arti
                arti[strcspn(arti, "\n")] = '\0';
                root = sisipkan(root, kata, arti);
            }
        }
        fclose(file);
    }
    else
    {
        printf("File %s tidak dapat dibuka.\n", fileName);
    }
    return root;
}

void loadFromFile(Node **root)
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            char *pos = strchr(line, ',');
            if (pos != NULL)
            {
                *pos = '\0';
                char *kata = line;
                char *arti = pos + 1;
                // Remove newline character from arti
                arti[strcspn(arti, "\n")] = '\0';
                *root = sisipkan(*root, kata, arti);
            }
        }
        fclose(file);
    }
}

void saveToFile(Node *root)
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL)
    {
        saveToFileHelper(root, file);
        fclose(file);
    }
}

void saveToFileHelper(Node *root, FILE *file)
{
    if (root != NULL)
    {
        saveToFileHelper(root->kiri, file);
        fprintf(file, "%s,%s\n", root->kata, root->arti);
        saveToFileHelper(root->kanan, file);
    }
}

Node *sisipkan(Node *root, const char *kata, const char *arti)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->kata = strdup(kata);
        root->arti = strdup(arti);
        root->kiri = NULL;
        root->kanan = NULL;
    }
    else if (strcmp(kata, root->kata) < 0)
    {
        root->kiri = sisipkan(root->kiri, kata, arti);
    }
    else if (strcmp(kata, root->kata) > 0)
    {
        root->kanan = sisipkan(root->kanan, kata, arti);
    }
    return root;
}

Node *hapusNode(Node *root, const char *kata)
{
    if (root == NULL)
    {
        return root;
    }

    if (strcmp(kata, root->kata) < 0)
    {
        root->kiri = hapusNode(root->kiri, kata);
    }
    else if (strcmp(kata, root->kata) > 0)
    {
        root->kanan = hapusNode(root->kanan, kata);
    }
    else
    {
        // Kasus 1: Node daun
        if (root->kiri == NULL && root->kanan == NULL)
        {
            free(root->kata);
            free(root->arti);
            free(root);
            root = NULL;
        }
        // Kasus 2: Node hanya memiliki satu anak
        else if (root->kiri == NULL)
        {
            Node *temp = root;
            root = root->kanan;
            free(temp->kata);
            free(temp->arti);
            free(temp);
        }
        else if (root->kanan == NULL)
        {
            Node *temp = root;
            root = root->kiri;
            free(temp->kata);
            free(temp->arti);
            free(temp);
        }
        // Kasus 3: Node memiliki dua anak
        else
        {
            Node *temp = root->kiri;
            while (temp->kanan != NULL)
            {
                temp = temp->kanan;
            }
            free(root->kata);
            free(root->arti);
            root->kata = strdup(temp->kata);
            root->arti = strdup(temp->arti);
            root->kiri = hapusNode(root->kiri, temp->kata);
        }
    }

    return root;
}

void tampilkanSemuaKata(Node *root)
{
    if (root != NULL)
    {
        // Menampilkan header tabel
        printf("%-20s%-20s\n", "Kata", "Arti");
        printf("%-40s\n", "----------------------------------------");

        // Menampilkan setiap kata dan artinya dalam bentuk tabel
        tampilkanSemuaKataHelper(root);

        printf("\n");
    }
}

void tampilkanSemuaKataHelper(Node *root)
{
    if (root != NULL)
    {
        tampilkanSemuaKataHelper(root->kiri);
        // Menampilkan setiap kata dan artinya dalam bentuk tabel
        printf("%-20s%-20s\n", root->kata, root->arti);
        tampilkanSemuaKataHelper(root->kanan);
    }
}

Node *cari(Node *root, const char *kata)
{
    if (root == NULL || strcmp(root->kata, kata) == 0)
    {
        return root;
    }
    else if (strcmp(kata, root->kata) < 0)
    {
        return cari(root->kiri, kata);
    }
    else
    {
        return cari(root->kanan, kata);
    }
}

void tampilkanArti(Node *root, const char *kata)
{
    Node *node = cari(root, kata);
    if (node != NULL)
    {
        printf("Arti dari kata '%s' adalah: %s\n", kata, node->arti);
    }
    else
    {
        printf("Kata '%s' tidak ditemukan dalam kamus.\n", kata);
    }
}

// Fungsi untuk melakukan login admin
bool adminLogin()
{
    char username[50], password[50];
    printf("Masukkan username admin: ");
    scanf("%s", username);
    printf("Masukkan password admin: ");
    scanf("%s", password);

    // Membuka file untuk membaca data admin
    FILE *file = fopen("admin.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "File admin.txt tidak dapat dibuka.\n");
        return false;
    }

    char storedUsername[50], storedPassword[50];
    bool found = false;

    // Membaca setiap baris dalam file
    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF)
    {
        if (strcmp(storedUsername, username) == 0 && strcmp(storedPassword, password) == 0)
        {
            found = true;
            break;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Selamat datang %s di Kamus Bahasa Sunda!\n", username);
        return true;
    }
    else
    {
        printf("Login admin gagal. Username atau password salah.\n");
        return false;
    }
}

// Fungsi untuk melakukan registrasi admin
bool adminRegister()
{
    char username[50], password[50];
    printf("Masukkan username admin baru: ");
    scanf("%s", username);
    printf("Masukkan password admin baru: ");
    scanf("%s", password);

    // Membuka file untuk menulis data admin baru
    FILE *file = fopen("admin.txt", "a");
    if (file == NULL)
    {
        fprintf(stderr, "File admin.txt tidak dapat dibuka.\n");
        return false;
    }

    // Menulis username dan password admin baru ke file
    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Registrasi admin berhasil!\n");
    return true;
}

// Fungsi untuk melakukan login pengguna umum
bool userLogin()
{
    char username[50];
    printf("Masukkan username pengguna: ");
    scanf("%s", username);

    // Di sini bisa ditambahkan pengecekan terhadap file pengguna umum (jika diperlukan)

    printf("Selamat datang %s di Kamus Bahasa Sunda!\n", username);
    return true;
}

// Fungsi untuk menampilkan menu admin
void menuAdmin(Node **root)
{
    int pilihan;
    char kata[100], arti[256];

    do
    {
        printf("\n===== Kamus Bahasa Sunda (Admin) =====\n");
        printf("1. Tambah Kata\n");
        printf("2. Tampilkan Semua Kata\n");
        printf("3. Hapus Kata\n");
        printf("4. Cari Kata\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan kata: ");
            scanf("%s", kata);
            printf("Masukkan arti: ");
            scanf("%s", arti);
            *root = sisipkan(*root, kata, arti);
            saveToFile(*root);
            break;
        case 2:
            printf("Daftar Kata dalam Kamus:\n");
            tampilkanSemuaKata(*root);
            break;
        case 3:
            printf("Masukkan kata yang ingin dihapus: ");
            scanf("%s", kata);
            *root = hapusNode(*root, kata);
            saveToFile(*root);
            break;
        case 4:
            printf("Masukkan kata yang ingin dicari: ");
            scanf("%s", kata);
            tampilkanArti(*root, kata);
            break;
        case 5:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
}

// Fungsi untuk menampilkan menu pengguna umum
void menuPengguna(Node *root)
{
    int pilihan;
    char kata[100];

    do
    {
        printf("\n===== Kamus Bahasa Sunda (Pengguna Umum) =====\n");
        printf("1. Tampilkan Semua Kata\n");
        printf("2. Cari Kata\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Daftar Kata dalam Kamus:\n");
            tampilkanSemuaKata(root);
            break;
        case 2:
            printf("Masukkan kata yang ingin dicari: ");
            scanf("%s", kata);
            tampilkanArti(root, kata);
            break;
        case 3:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);
}
