#ifndef KAMUS_H
#define KAMUS_H

#include <iostream>
#include <string>
#include <fstream> // tambahkan ini untuk ofstream
using namespace std;

struct Node {
    string kata;
    string arti;
    Node* kiri;
    Node* kanan;
    int height;
};

Node* buildTreeFromFile(const string& fileName);
Node* sisipkanAVL(Node* root, string kata, string arti);
Node* hapusNode(Node* root, string kata);
void tampilkanSemuaKata(Node* root, ofstream& file);
Node* cari(Node* root, string kata);
void tampilkanArti(Node* root, string kata);
int getHeight(Node* root);
int getBalanceFactor(Node* root);
Node* rotateKiri(Node* root);
Node* rotateKanan(Node* root);
Node* rotate(Node* root);
Node* successor(Node* root);
Node* predecessor(Node* root);
void saveToFile(Node* root, const string& fileName);

#endif
