#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    pair<int, int> a_loc;
    queue<tuple<int, int, int>> q; //i j and dist
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<bool>> visa(n, vector<bool>(m, false));
    vector<vector<int>> distm(n, vector<int>(m, INT_MAX));
    vector<vector<int>> dista(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') {
                a_loc = {i, j};
                visa[i][j] = true;
                dista[i][j] = 0;
            }
            if(mat[i][j] == 'M') {
                q.push({i, j, 0});
                vis[i][j] = true;
                distm[i][j] = 0;
            }
        }
    }

    auto valid = [&](int i, int j) -> bool {return i>=0 && i<n && j >=0 && j <m;};

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto [i, j, dist] = q.front(); q.pop();
        vis[i][j] = true;

        for(int k = 0; k < 4; k++) {
            int nxi = i + dx[k];
            int nxj = j + dy[k];
            if(valid(nxi, nxj) && !vis[nxi][nxj] && mat[nxi][nxj] == '.') {
                vis[nxi][nxj] = true;
                q.push({nxi, nxj, dist+1});
                distm[nxi][nxj] = dist + 1;
            }
        }
    }

    q.push({a_loc.first, a_loc.second, 0});
    visa[a_loc.first][a_loc.second] = true;

    while(!q.empty()) {
        auto [i, j, dist] = q.front(); q.pop();

        for(int k = 0; k < 4; k++) {
            int nxi = i + dx[k];
            int nxj = j + dy[k];
            if(valid(nxi, nxj) && !visa[nxi][nxj] && mat[nxi][nxj] == '.' && dist + 1 < distm[nxi][nxj]) {
                visa[nxi][nxj] = true;
                q.push({nxi, nxj, dist+1});
                par[nxi][nxj] = {i, j};
                dista[nxi][nxj] = dist + 1;
            }
        }
    }

    par[a_loc.first][a_loc.second] = {-1, -1};

    vector<int> possexit;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j != 0 && i != 0) continue;

            if(mat[i][j] == '.' && dista[i][j] < distm[i][j]) {
                possexit.emplace_back(i);
                possexit.emplace_back(j);
                break;
            }
        }
    }

    if(possexit.empty()) cout << "IMPOSSIBLE";
    else {
        int ii = possexit[0], jj = possexit[1];
        string path;

        while(ii != -1 && jj != -1) {
            int pi = par[ii][jj].first;
            int pj = par[ii][jj].second;
            if(pi == ii) {
                if(jj > pj) path.push_back('R');
                else path.push_back('L');
            } else {
                if(ii > pi) path.push_back('D');
                else path.push_back('U');
            }
            ii = pi; jj = pj;
        }
        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path;
    }
}