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
