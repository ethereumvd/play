#include<bits/stdc++.h>
using namespace std;
//2SAT implementation

struct TwoSAT {
    int num_vars;
    int n_vertices;
    vector<vector<int>> adj, rev_adj;
    vector<bool> vis;
    vector<int> comp;
    vector<int> topo;
    vector<bool> vals;

    TwoSAT(int n) : num_vars(n), n_vertices(2 * n), adj(n_vertices, vector<int>()),
    rev_adj(n_vertices, vector<int>())
    {
        comp.assign(n_vertices, -1);
        vis.assign(n_vertices, false);
        vals.assign(n, false);
    }

    void dfs1(int nd) {
        vis[nd] = true;

        for(auto& ch : adj[nd]) {
            if(!vis[ch]) dfs1(ch);
        }

        topo.emplace_back(nd);
    }

    void dfs2(int nd, int idx) {
        comp[nd] = idx;
        vis[nd] = true;

        for(auto& ch : rev_adj[nd]) {
            if(!vis[ch]) dfs2(ch, idx);
        }
    }

    bool Possible() {
        vis.assign(n_vertices, false);
        comp.assign(n_vertices, -1);

        for(int i = 0; i < n_vertices; i++) {
            if(!vis[i]) {
                dfs1(i);
            }
        }

        reverse(topo.begin(), topo.end());
        vis.assign(n_vertices, false);
        int id = 0;

        for(auto& i : topo) {
            if(comp[i] == -1) {
                dfs2(i, id);
                id++;
            }
        }

        for(int i = 0; i < n_vertices; i += 2) {
            //i is normal i + 1 will be negation
            int val = (i / 2);
            if(comp[i] == comp[i + 1]) return false;

            vals[val] = comp[i] > comp[i + 1];
        }

        return true;
    }

    void AddExpr(int u, bool sgnu, int v, bool sgnv) {
        //sgn false means 1 should not be added
        //that is do NOT negate u if sgnu is false
        u = (2 * u) + sgnu;
        v = (2 * v) + sgnv;
        int neg_u = u ^ 1;
        int neg_v = v ^ 1;

        adj[neg_u].emplace_back(v);
        adj[neg_v].emplace_back(u);

        rev_adj[v].emplace_back(neg_u);
        rev_adj[u].emplace_back(neg_v);
    }

    void PrintAns() {
        if(!Possible()) cout << "IMPOSSIBLE";
        else {
            for(auto i : vals) cout << (i ? "+" : "-") << " ";
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    TwoSAT solver(m);
    for(int i = 0; i < n; i++) {
        char sgnu, sgnv; int u, v;
        cin >> sgnu >> u >> sgnv >> v;
        --u; --v;
        bool nu, nv;
        nu = sgnu == '+' ? false : true;
        nv = sgnv == '+' ? false : true;
        solver.AddExpr(u, nu, v, nv);
    }

    solver.PrintAns();
}