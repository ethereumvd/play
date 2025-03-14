#include<bits/stdc++.h>
using namespace std;
//dayumnnn !!!
void jogo() {
    int sti, stj, eni, enj; cin >> sti >> stj >> eni >> enj;
    int dx[] = {1,1,0,-1,-1,-1,0,1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    map<pair<int,int>,int> dist;
    set<pair<int,int>> poss;

    int n; cin >> n;
    while(n--) {
        int r, a, b; cin >> r >> a >> b;
        for(int i=a; i<=b; i++) {
            poss.insert({r,i});
        }
    }

    queue<pair<int,int>> q;
    q.push({sti,stj});
    dist[{sti,stj}] = 0;

    while(!q.empty()) {
        auto [ndi,ndj] = q.front();
        q.pop();

        for(int i=0; i<8; i++) {
            int nxi = ndi + dx[i];
            int nxj = ndj + dy[i];
            if(poss.find({nxi,nxj})!=poss.end()) {
                if(dist.find({nxi,nxj}) == dist.end()) {
                    q.push({nxi,nxj});
                    dist[{nxi,nxj}] = dist[{ndi,ndj}] + 1;
                } else {
                    continue;
                }
            }
        }
    }

    if(dist.find({eni,enj})==dist.end()) cout << "-1" << "\n";
    else cout << dist[{eni,enj}] << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
