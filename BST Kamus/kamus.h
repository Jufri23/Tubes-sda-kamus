#ifndef KAMUS_H
#define KAMUS_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    char *kata;
    char *arti;
    struct Node *kiri;
    struct Node *kanan;
} Node;

Node *buildTreeFromFile(const char *fileName);
void loadFromFile(Node **root);
void saveToFile(Node *root);
void saveToFileHelper(Node *root, FILE *file);
Node *sisipkan(Node *root, const char *kata, const char *arti);
Node *hapusNode(Node *root, const char *kata);
void tampilkanSemuaKata(Node *root);
void tampilkanSemuaKataHelper(Node *root);
Node *cari(Node *root, const char *kata);
void tampilkanArti(Node *root, const char *kata);
bool adminLogin();
bool adminRegister();
bool userLogin();
void menuAdmin(Node **root);
void menuPengguna(Node *root);

#endif
