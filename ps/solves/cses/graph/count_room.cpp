#include<bits/stdc++.h>
using namespace std;

int n, m;

bool valid(int i, int j) {
    if(j>=0 && j<m && i>=0 && i<n) return true;
    return false;
}

void jogo() {

    cin >> n >> m;
    vector<vector<char>> gr(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m)) ;

    vector<int> dx = {0, 1, 0,-1};
    vector<int> dy = {1, 0,-1, 0};
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> gr[i][j];
            vis[i][j]=false;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(gr[i][j]=='#' || vis[i][j]) continue;

            queue<pair<int,int>> q;
            q.push({i,j}); vis[i][j] = 1;
            ans++;

            while(!q.empty()) {
                int ndi = q.front().first;
                int ndj = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nxi = ndi + dx[k];
                    int nxj = ndj + dy[k];
                    if(valid(nxi, nxj) && !vis[nxi][nxj] && gr[nxi][nxj]=='.'){
                        vis[nxi][nxj]=true;
                        q.push({nxi,nxj});
                    }
                }
            }
        }
    }

    cout << ans ;
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
