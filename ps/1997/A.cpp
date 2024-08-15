#include<bits/stdc++.h>
using namespace std;

char s[20];

char getdiff(char c) {
	char d;
	for (int j = 0; j < 26; j++) {
		if (j != (c - 'a')) {
			d = (char)('a' + j);
			break;
		}
	}
	return d;
}

void solve() {
	cin >> s;
	int n = strlen(s);
	char c;
	int idx;
	int ok = 0;

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i+1]) {
			idx = i;
			ok = 1;
			c = getdiff(s[i]);
			break;
		}
	}

	if (ok == 0) {
		c = getdiff(s[0]);
		cout << c << s;
	} else {
		for (int i = 0; i <= idx; i++) {
			cout << s[i];
		}
		cout << c;
		for (int i = idx + 1; i < n; i++) {
			cout << s[i];
		}
	}

	cout << "\n";
}
int main() {
	int t; cin >> t;
	while (t--) solve();
}
