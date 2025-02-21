#include<bits/stdc++.h>
using namespace std;
class dsu {

private:
    vector<int> parent;

public:
    dsu(int n) {
        parent.resize(n);
    }

    void make_set(int v) {
        parent[v] = v ;
    }

    int find_set(int v) {
        if(parent[v]==v) return v ;
        return find_set(parent[v]);
    }

    void unite(int v , int w) {
        int rt_v = find_set(v);
        int rt_w = find_set(w);

        if(rt_v!=rt_w) parent[w] = rt_v;
    }
};

int main() {
    return 0 ;
}
