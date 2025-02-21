#include<bits/stdc++.h>
using namespace std;
class dsu {

private:
    vector<int> parent ;
    vector<int> size;
public:

    dsu(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find_rt(int v){
        if(parent[v]==v) return v;
        return parent[v] = find_rt(parent[v]);
    }

    void union_size(int v, int w) {

        int rt_v = find_rt(v);
        int rt_w = find_rt(w);

        if(rt_w!=rt_v) {
            if(size[rt_w]>size[rt_v]){
                swap(rt_w,rt_v);
            }
            parent[rt_w] = rt_v ;
            size[rt_v] += size[rt_w];
        }
    }


}

void jogo() {

    int n; cin >> n;
    dsu gr(n);
    vector<pair<int,int>> rem , add ;

    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;

        if(gr.find_rt(u)==gr.find_rt(v)) {
            rem.push_back({u,v});
        } else {
            gr.union_size(u,v);
        }
    }

    int rt_1 = gr.find_rt(1);
    for(int i=2; i<=n; i++){
        if(gr.find_rt(i)!=rt_1) {
            add.push_back({gr.find_rt(i),rt_1});
            gr.union_size(1,i);
        }
    }

    if(add.empty()) cout << 0 ;
    else {
        cout << add.size() << "\n" ;
        for(int i=0; i<add.size(); i++){
            cout << rem[i].first << " " << rem[i].second << " " ;
            cout << add[i].first << " " << add[i].second << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1; 
    while(tc--) jogo();
    return 0;
}
