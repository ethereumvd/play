#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        // Code here
        vector<bool> vis(n, false);
        vector<int> tin(n), low(n);
        int timer = 0;
        vector<bool> isap(n, false);
        
        auto dfs = [&] (int nd, int p, auto&& dfs) -> void {
            vis[nd] = true;
            tin[nd] = low[nd] = timer++;
            int c = 0;
            
            for(int ng:adj[nd]) {
                if(ng == p) continue;
                if(!vis[ng]) {
                    ++c;
                    dfs(ng, nd, dfs);
                    low[nd]  = min(low[ng], low[nd]);
                    if(low[ng] >= tin[nd]  && p != -1) {
                        isap[nd] = true;
                    }
                } else low[nd] = min(low[nd], tin[ng]);
            }
            if(p == -1 && c > 1) isap[nd] = true; 
        };
        for(int i=0; i<n; i++) if(!vis[i]) dfs(i, -1, dfs);
        vector<int> pts;
        for(int i =0; i<n; i++) if(isap[i]) pts.push_back(i);
        if(pts.empty()) pts.push_back(-1);
        sort(pts.begin(), pts.end());
        return pts;
    }
};
