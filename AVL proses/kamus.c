#include "kamus.h"

void tampilkanSelamatDatang()
{
    printf("\n");
    printf("=================================================\n");
    printf("==     Selamat Datang di Kamus Bahasa Sunda    ==\n");
    printf("=================================================\n");
    printf("\n");
}

char *toLowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

Node *buildTreeFromFile(const char *fileName)
{
    Node *root = NULL;
    FILE *file = fopen(fileName, "r");
    if (file != NULL)
    {
        char line[MAX_STRING_LENGTH];
        while (fgets(line, sizeof(line), file))
        {
            char *pos = strchr(line, ',');
            if (pos != NULL)
            {
                *pos = '\0';
                char *kata = line;
                char *arti = pos + 1;
                arti[strcspn(arti, "\n")] = '\0'; // Remove newline character
                root = sisipkanAVL(root, toLowercase(kata), arti);
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

int getBalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->kiri) - getHeight(root->kanan);
}

Node *rotateKiri(Node *root)
{
    Node *newRoot = root->kanan;
    root->kanan = newRoot->kiri;
    newRoot->kiri = root;

    root->height = 1 + (getHeight(root->kiri) > getHeight(root->kanan) ? getHeight(root->kiri) : getHeight(root->kanan));
    newRoot->height = 1 + (getHeight(newRoot->kiri) > getHeight(newRoot->kanan) ? getHeight(newRoot->kiri) : getHeight(newRoot->kanan));

    return newRoot;
}

Node *rotateKanan(Node *root)
{
    Node *newRoot = root->kiri;
    root->kiri = newRoot->kanan;
    newRoot->kanan = root;

    root->height = 1 + (getHeight(root->kiri) > getHeight(root->kanan) ? getHeight(root->kiri) : getHeight(root->kanan));
    newRoot->height = 1 + (getHeight(newRoot->kiri) > getHeight(newRoot->kanan) ? getHeight(newRoot->kiri) : getHeight(newRoot->kanan));

    return newRoot;
}

Node *rotate(Node *root)
{
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->kiri) >= 0)
        {
            return rotateKanan(root);
        }
        else
        {
            root->kiri = rotateKiri(root->kiri);
            return rotateKanan(root);
        }
    }
    else if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->kanan) <= 0)
        {
            return rotateKiri(root);
        }
        else
        {
            root->kanan = rotateKanan(root->kanan);
            return rotateKiri(root);
        }
    }

    return root;
}

Node *sisipkanAVL(Node *root, const char *kata, const char *arti)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        strcpy(root->kata, kata);
        strcpy(root->arti, arti);
        root->kiri = root->kanan = NULL;
        root->height = 1;
    }
    else if (strcmp(kata, root->kata) < 0)
    {
        root->kiri = sisipkanAVL(root->kiri, kata, arti);
    }
    else if (strcmp(kata, root->kata) > 0)
    {
        root->kanan = sisipkanAVL(root->kanan, kata, arti);
    }
    else
    {
        return root;
    }

    root->height = 1 + (getHeight(root->kiri) > getHeight(root->kanan) ? getHeight(root->kiri) : getHeight(root->kanan));
    root = rotate(root);

    return root;
}

Node *successor(Node *root)
{
    if (root == NULL || root->kanan == NULL)
    {
        return NULL;
    }

    root = root->kanan;
    while (root->kiri != NULL)
    {
        root = root->kiri;
    }

    return root;
}

Node *predecessor(Node *root)
{
    if (root == NULL || root->kiri == NULL)
    {
        return NULL;
    }

    root = root->kiri;
    while (root->kanan != NULL)
    {
        root = root->kanan;
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
        if (root->kiri == NULL || root->kanan == NULL)
        {
            Node *temp = root->kiri ? root->kiri : root->kanan;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }

            free(temp);
        }
        else
        {
            Node *temp = predecessor(root->kanan);
            strcpy(root->kata, temp->kata);
            strcpy(root->arti, temp->arti);
            root->kanan = hapusNode(root->kanan, temp->kata);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + (getHeight(root->kiri) > getHeight(root->kanan) ? getHeight(root->kiri) : getHeight(root->kanan));
    root = rotate(root);

    return root;
}

void tampilkanSemuaKata(Node *root)
{
    if (root != NULL)
    {
        printf("%-20s%-20s\n", "Kata", "Arti");
        for (int i = 0; i < 40; i++)
            printf("-");
        printf("\n");
        tampilkanSemuaKataHelper(root);
        printf("\n");
    }
}

void tampilkanSemuaKataHelper(Node *root)
{
    if (root != NULL)
    {
        tampilkanSemuaKataHelper(root->kiri);
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
    char kataLower[MAX_STRING_LENGTH];
    strcpy(kataLower, kata);
    Node *hasil = cari(root, toLowercase(kataLower));
    if (hasil != NULL)
    {
        printf("Arti kata \"%s\" adalah: %s\n", hasil->kata, hasil->arti);
    }
    else
    {
        printf("Kata \"%s\" tidak ditemukan dalam kamus.\n", kata);
    }
}

void saveToFile(Node *root, const char *fileName)
{
    FILE *file = fopen(fileName, "w");
    if (file != NULL)
    {
        saveToFileHelper(root, file);
        fclose(file);
    }
    else
    {
        printf("File %s tidak dapat dibuka untuk menulis.\n", fileName);
    }
}

void saveToFileHelper(Node *root, FILE *file)
{
    if (root != NULL)
    {
        fprintf(file, "%s,%s\n", root->kata, root->arti);
        saveToFileHelper(root->kiri, file);
        saveToFileHelper(root->kanan, file);
    }
}

int adminLogin()
{
    char username[MAX_STRING_LENGTH], password[MAX_STRING_LENGTH];
    printf("Masukkan username admin: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    FILE *file = fopen("admin.txt", "r");
    if (!file)
    {
        fprintf(stderr, "File admin.txt tidak dapat dibuka.\n");
        return 0;
    }

    char storedUsername[MAX_STRING_LENGTH], storedPassword[MAX_STRING_LENGTH];
    int found = 0;

    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF)
    {
        if (strcmp(storedUsername, username) == 0 && strcmp(storedPassword, password) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Selamat Datang %s di Kamus Bahasa Sunda!\n", username);
        return 1;
    }
    else
    {
        printf("Login admin gagal. Username atau password salah.\n");
        return 0;
    }
}

int userLogin()
{
    char username[MAX_STRING_LENGTH];
    printf("Masukkan username pengguna: ");
    scanf("%s", username);

    printf("Selamat datang %s di Kamus Bahasa Sunda!\n", username);
    return 1;
}

void menuAdmin(Node *root)
{
    int pilihan;
    char kata[MAX_STRING_LENGTH], arti[MAX_STRING_LENGTH];
    do
    {
        printf("\n===== Menu Admin =====\n");
        printf("1. Tambah Kata\n");
        printf("2. Tampilkan Semua Kata\n");
        printf("3. Cari Kata\n");
        printf("4. Hapus Kata\n");
        printf("5. Logout\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            printf("Masukkan kata: ");
            scanf("%s", kata);
            printf("Masukkan arti: ");
            scanf("%s", arti);
            root = sisipkanAVL(root, toLowercase(kata), arti);
            saveToFile(root, "kamus.txt");
            break;
        case 2:
            printf("Daftar Kata dalam Kamus:\n");
            tampilkanSemuaKata(root);
            break;
        case 3:
            printf("Masukkan kata yang ingin dicari: ");
            scanf("%s", kata);
            tampilkanArti(root, kata);
            break;
        case 4:
            printf("Masukkan kata yang ingin dihapus: ");
            scanf("%s", kata);
            root = hapusNode(root, toLowercase(kata));
            saveToFile(root, "kamus.txt");
            break;
        case 5:
            printf("Logout berhasil.\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
}

void menuPengguna(Node *root)
{
    int pilihan;
    char kata[MAX_STRING_LENGTH];
    do
    {
        printf("\n===== Menu Pengguna =====\n");
        printf("1. Cari Kata\n");
        printf("2. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            printf("Masukkan kata yang ingin dicari: ");
            scanf("%s", kata);
            tampilkanArti(root, kata);
            break;
        case 2:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 2);
}