#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left ;
    node* right;

    node(int data) {
        val = data;
        left = right = nullptr;
    }
};

int main() {

    vector<int> ord;
    stack<node*> st;
    node* root = new node(5);

    while(!st.empty()) {
        node* nd = st.top();
        st.pop();
        ord.push_back(nd->val);

        if(nd->left != nullptr) st.push(nd->left);
        if(nd->right != nullptr) st.push(nd->right);
    }
    delete(root);
}
