#ifndef KAMUS_H
#define kAMUS_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string kata;
    string arti;
    Node* kiri;
    Node* kanan;
};

Node* buildTreeFromFile(const string& fileName);
void loadFromFile(Node*& root);
void saveToFile(Node* root);
void saveToFileHelper(Node* root, ofstream& file);
Node* sisipkan(Node* root, string kata, string arti);
Node* hapusNode(Node* root, string kata);
void tampilkanSemuaKata(Node* root);
Node* cari(Node* root, string kata);
void tampilkanArti(Node* root, string kata);

#endif