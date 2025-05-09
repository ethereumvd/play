#include<bits/stdc++.h>
using namespace std;
struct node{

    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void iter_preord(node *root) {

    vector<int> ord;
    stack<node*> st;
    st.push(root);

    while(!st.empty()) {

        node* nd = st.top();
        st.pop();
        ord.push_back(nd->data);

        if(nd->right != nullptr) st.push(nd->right);
        if(nd->left != nullptr) st.push(nd->left);

    }


}

int main() {

}
