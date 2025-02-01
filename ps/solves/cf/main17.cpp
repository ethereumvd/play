#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), o, e;
    for (int &i : a) {
        cin >> i;
        if (i & 1) o.emplace_back(i);
        else e.emplace_back(i);
    }

    sort(o.begin(), o.end());
    sort(e.begin(), e.end());

    if (abs((int)o.size() - (int)e.size()) <= 1) {
        cout << "0\n";
    } else {
        int diff = abs((int)o.size() - (int)e.size()) - 1;
        if (o.size() > e.size()) {
            cout << accumulate(o.begin(), o.begin() + diff, 0LL); 
        } else {
            cout << accumulate(e.begin(), e.begin() + diff, 0LL);
        }
        cout << "\n";
    }
}