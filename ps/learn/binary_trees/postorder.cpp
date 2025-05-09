#include<bits/stdc++.h>
using namespace std;

struct node  {

    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = right = nullptr;
    }
 
};

vector<int> ord;

void postorder(node* nd) {

    if(nd == nullptr) return;
    postorder(nd->left);
    postorder(nd->right);
    ord.push_back(nd->val);
    return;

}

int main() {

}
