#ifndef KAMUS_H
#define KAMUS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256

typedef struct Node
{
    char kata[MAX_STRING_LENGTH];
    char arti[MAX_STRING_LENGTH];
    struct Node *kiri;
    struct Node *kanan;
    int height;
} Node;

Node *buildTreeFromFile(const char *fileName);
Node *sisipkanAVL(Node *root, const char *kata, const char *arti);
Node *hapusNode(Node *root, const char *kata);
void tampilkanSemuaKata(Node *root);
void tampilkanSemuaKataHelper(Node *root);
Node *cari(Node *root, const char *kata);
void tampilkanArti(Node *root, const char *kata);
int getHeight(Node *root);
int getBalanceFactor(Node *root);
Node *rotateKiri(Node *root);
Node *rotateKanan(Node *root);
Node *rotate(Node *root);
Node *successor(Node *root);
Node *predecessor(Node *root);
void saveToFile(Node *root, const char *fileName);

int adminLogin();
int userLogin();
void menuAdmin(Node *root);
void menuPengguna(Node *root);
char *toLowercase(char *str);

#endif
