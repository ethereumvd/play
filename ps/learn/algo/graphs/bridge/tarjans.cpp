#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
        
        vector<vector<int>> adj(n, vector<int>());
        
        for(auto e:edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        vector<int> tin(n), low(n);
        int timer = 0;
        
        auto dfs = [&] (int nd, int pr, auto&& dfs) -> void  {
            vis[nd] = true;
            tin[nd] = low[nd] = timer++;
            
            for(auto ng:adj[nd]) {
                if(ng == pr) continue;
                if(!vis[ng]) {
                    dfs(ng, nd, dfs);
                }
                low[nd] = min(low[nd], low[ng]);
            }
            
        };
        for(int i=0; i<n; i++) if(!vis[i]) dfs(i, -1, dfs);
        
        if(low[d] > tin[c] || low[c] > tin[d]) return true;
        return false;

    }
  
};
