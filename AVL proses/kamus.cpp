
#include "kamus.h"
#include <fstream>
#include <cstring>

const string FILE_NAME = "kamus.txt";

int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->height;
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

void tampilkanSemuaKata(Node* root, ofstream& file) {
    if (root != nullptr) {
        tampilkanSemuaKata(root->kiri, file);
        file << root->kata << "," << root->arti << endl;
        tampilkanSemuaKata(root->kanan, file);
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
