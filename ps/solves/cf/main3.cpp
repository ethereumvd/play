#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <queue>
#include <random>
#include <unordered_map>
 
using namespace std;
 
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
 
long long MOD = (int) 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > a(n);
    map<int, int> occurrences;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            --a[i][j];

            ++occurrences[a[i][j]];
        }
    }

    for (int i = 0; i < n; ++i) {
        bool find = false;
        for (int j = 0; j < a[i].size(); ++j) {
            if (occurrences[a[i][j]] == 1) {
                find = true;
                break;
            }
        }

        if (!find) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    // freopen("input.txt", "r", stdin);

    int tests = 1;
    cin >> tests;
 
    for (int i = 1; i <= tests; ++i) {
        solve();
    }
}

