#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int data) :val(data), left(nullptr), right(nullptr) {}
};

vector<int> pre, post, in;
void pre_post_in(node* root) {
    stack<pair<node*,int>> st;
    st.push({root,1});
    while(!st.empty()) {
        node* nd = st.top().first;
        int ord = st.top().second;
        st.pop();
        if(ord == 1) {
            pre.push_back(nd->val);
            st.push({nd,2});
            if(nd->left) st.push({nd->left,1});
        } else if(ord == 2) {
            in.push_back(nd->val);
            st.push({nd,3});
            if(nd->right) st.push({nd->right,1});
        } else if(ord == 3) {
            post.push_back(nd->val);
        }
    }
}

int main() {

}
