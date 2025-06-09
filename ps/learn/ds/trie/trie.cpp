#include<bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node*> links;
    bool isend ;
    bool presentch(char ch) {
        return links[ch - 'a'] == nullptr;
    }

    Node() : links(26, nullptr), isend(false) {}
};

struct Trie {

    Trie() {
        Node* root = new Node;
    }

    void insert(string word) {

    }

    bool startswith(string pref) {
        return false;
    }

    bool present (string word) {
        return false;
    }



};

int main() {
    
}
