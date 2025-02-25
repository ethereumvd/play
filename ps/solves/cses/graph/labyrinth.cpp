#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<char,pair<int,int>>> moves = {{'U',{-1,0}},{'D',{1,0}},{'R',{0,1}},{'L',{0,-1}}};
vector<char> path;

void pathtrace(vector<vector<pair<int,int>>> &parent, int i, int j, int stri, int strj) {

    if(i==stri && j==strj) return;

    for(auto x:moves) {
        if((i-parent[i][j].first)==x.second.first && j-parent[i][j].second==x.second.second) {
            path.push_back(x.first);
            pathtrace(parent,parent[i][j].first,parent[i][j].second,stri,strj);
            break;
        }
    }

}

bool valid(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

void jogo() {

    cin >> n >> m ;

    vector<vector<char>> gr(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    pair<int,int> start, end;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> gr[i][j];
            vis[i][j] = false;
            if(gr[i][j]=='A') start = make_pair(i,j);
            if(gr[i][j]=='B') end = make_pair(i,j);
        }
    }

    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    vis[start.first][start.second] = true ;

    while(!q.empty()) {
        int ndi = q.front().first ;
        int ndj = q.front().second ;
        q.pop();
        for(int k=0; k<4; k++) {
            int nxi = ndi + dx[k];
            int nxj = ndj + dy[k];
            if(valid(nxi,nxj) && (gr[nxi][nxj]=='.' || gr[nxi][nxj]=='B') && !vis[nxi][nxj]) {
                vis[nxi][nxj] = true ;
                q.push({nxi,nxj});
                parent[nxi][nxj] = {ndi,ndj};
            }
        }
    }

    if(!vis[end.first][end.second]) cout << "NO" ;
    else {
        cout << "YES" << "\n" ;
        pathtrace(parent,end.first,end.second,start.first,start.second) ;
        reverse(path.begin(),path.end());
        cout << path.size() << "\n" ;
        for(int i=0; i<path.size(); i++) cout << path[i] ;
    }
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
