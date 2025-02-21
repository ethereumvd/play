#include<bits/stdc++.h>
using namespace std;

class dsu {

private:
    vector<int> parent;
    vector<int> size;

public:

    dsu(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
    }

    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find_rt(int v) {
        if(parent[v]==v) return v;
        return parent[v] = find_rt(parent[v]);
    }

    void unite_size(int v , int w) {
        int rt_v = find_rt(v);
        int rt_w = find_rt(w);

        if(rt_w!=rt_v) {
            if(size[rt_w]>size[rt_v]) {
                swap(rt_w,rt_v);
            }
            parent[rt_v] = rt_w;
            size[rt_v] += size[rt_w] ;
        }
    }

};

int main() {
    return 0;
} 
