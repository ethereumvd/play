#include<bits/stdc++.h>
using namespace std;

int n;

bool valid(int x, int y) {
    if(x>=0 && x<n && y<n && y>=0) return true;
    return false;
}

void jogo() {

    int stx, sty, edx, edy; 
    cin >> stx >> sty >> edx >> edy ;
    cin >> n;
    vector<vector<bool>> vis(n,vector<bool>(n));

    vector<pair<int,int>> rg(n);

    for(int i=0; i<n; i++) {
        int r, a, b; cin >> r >> a >> b;
        r--; a--; b--;
        rg[r] = {a,b} ;
    }

    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};


    queue<pair<int,int>> q ;
    q.push({stx,sty});

    while(!q.empty()) {
        auto [ndi,ndj] = q.front();
        q.pop();

    }

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
