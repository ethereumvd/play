#include<bits/stdc++.h>
using namespace std;

struct node {

    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = nullptr;
    }

};

vector<int> ord;

void preorder(node* nd) {

    if(nd == nullptr) return;

    ord.push_back(nd->data);
    preorder(nd->left);
    preorder(nd->right);

}

int main() {

    node* root = new node(5);
    preorder(root);

}
