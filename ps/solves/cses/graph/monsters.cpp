#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<char> path;

void pathtrace() {}

bool valid(int i, int j) {
    if(i<n-1 && i>=0 && j<m-1 && j>=0) return true;
    return false;
}

void jogo() {
    cin >> n >> m;
    vector<vector<char>> gr(n,vector<char>(m)); 
    vector<vector<bool>> vis(n,vector<bool>(m));
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
    vector<pair<int,int>> exits;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    bool flag = false;


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> gr[i][j];
            if(gr[i][j]=='.' && (j==n-1 || i==n-1 || i==0 || j==0)) {
                exits.push_back({i,j});
            }
        }
    }
    for(auto exit:exits) {
        int exi = exit.first;
        int exj = exit.second;

        int lev = 0;
        int mlev = -1;
        int alev = -1;

        vector<pair<int,int>> q;
        q.push_back({exi,exj});
        vis[exi][exj]=true;

        while(true) {
            lev++;
            vector<pair<int,int>> temp;

            for(auto nd:q) {
                int ndi = nd.first;
                int ndj = nd.second;
                vis[ndi][ndj]=true;
                for(int k=0; k<4; k++) {
                    int nxi = ndi + dx[k];
                    int nxj = ndj + dy[k];
                    if(valid(nxi,nxj) && gr[nxi][nxj]=='.' && !vis[nxi][nxj]) {
                        temp.push_back({nxi,nxj});
                        par[nxi][nxj] = {ndi,ndj};
                    }
                    if(gr[nxi][nxj]=='A') {
                        alev = lev;
                        pair<int,int> A = {nxi,nxj};
                        par[nxi][nxj] = {ndj,nxj};
                        break;
                    }
                    if(gr[nxi][nxj]=='M') {
                        mlev = lev;
                        break;
                    }
                }
            }

            if(alev > mlev) {
                flag = true;
                break;
            }

            if(temp.empty()) break;
            q = temp ;
            temp.clear();
        }



    } 


}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
