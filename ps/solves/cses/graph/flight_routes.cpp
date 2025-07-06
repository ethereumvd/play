#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5;
priority_queue<ll> vpq[MAXN];
// vector<priority_queue<ll>> vpq(MAXN, priority_queue<int>());
// vector<vector<tuple<int, int>>>  adj(1e5, vector<tuple<int, int>>());
vector<tuple<int, int>> adj[MAXN];
priority_queue<tuple<ll, int>, vector<tuple<ll, int>>, greater<tuple<ll, int>>> pq;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        adj[u].push_back({v, c});
    }

    pq.push({0, 0});
    vpq[0].push(0);

    while(!pq.empty()) {
        auto [cstnd, nd] = pq.top(); pq.pop();

        if (cstnd > vpq[nd].top()) continue;
        //one fucking line makes the differece b/w tle and accepted

        for(auto& [ch, cost] :  adj[nd]) {
            ll newcst = cstnd + cost;
            if((int)vpq[ch].size() < k) {
                pq.push({newcst, ch});
                vpq[ch].push(newcst);
            } else if(vpq[ch].top() > newcst) {
                vpq[ch].pop();
                vpq[ch].push(newcst);
                pq.push({newcst, ch});
            }
        }
    }

    vector<ll> res;
    while(!vpq[n-1].empty()) {
        res.push_back(vpq[n-1].top());
        vpq[n-1].pop();
    }
    reverse(res.begin(), res.end());

    for(auto& i : res) cout << i << " ";
    cout << "\n";
}