#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = right = nullptr;
    }
};

vector<int> ord;

void inorder(node* nd) {
    if(nd == nullptr) return;
    inorder(nd->left);
    ord.push_back(nd->val);
    inorder(nd->right);
}

int main() {

}
