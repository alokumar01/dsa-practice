#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (value < root->data) {
        root->left = insert(root->left, val);
    } else if (value > root->data) {
        root->right = insert(root->right, val);
    } 
    return root;
}

bool serch(Node* root, int val) {
    if (!root) return false;

    if (value == root->data) return true;

    if (value < root->left) {
        return serch(root->left, val);
    } else {
        return serch(root->right, val);
    }
}

Node* findMin(Node* root) {
    while(root && root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (!root->left) return nullptr;
        if (!root->right) return nullptr;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
};

void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}