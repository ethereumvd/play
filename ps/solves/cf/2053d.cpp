#include <bits/stdc++.h>
 
constexpr int MOD = 998244353;
int qpow(int a, int x = MOD - 2) {
	int res = 1;
	for (; x; x >>= 1, a = 1ll * a * a % MOD) if (x & 1) res = 1ll * res * a % MOD;
	return res;
}
 
#define MAXN 200001
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
void solve() {
	int n, q, res = 1; std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) std::cin >> a[i], c[i] = a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i], d[i] = b[i];
	std::sort(c + 1, c + n + 1), std::sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; ++i) res = 1ll * res * std::min(c[i], d[i]) % MOD;
	std::cout << res << " \n"[q == 0];
	for (int i = 1, op, x; i <= q; ++i) {
		std::cin >> op >> x;
		if (op == 1) {
			int p = std::upper_bound(c + 1, c + n + 1, a[x]) - c - 1;
			if (c[p] < d[p]) res = 1ll * res * qpow(c[p]) % MOD * (c[p] + 1) % MOD;
            std::cout << p << " ";
			++a[x], ++c[p];
		} else {
			int p = std::upper_bound(d + 1, d + n + 1, b[x]) - d - 1;
			if (d[p] < c[p]) res = 1ll * res * qpow(d[p]) % MOD * (d[p] + 1) % MOD;
            std::cout << p << " ";
			++b[x], ++d[p];
		}
        std::cout << "\n";
        std::cout << "c: ";
        for (int i = 1; i <= n; i++) {
            std::cout << c[i] << " ";
        }
        std::cout << "\n";
        std::cout << "d: ";
        for (int i = 1; i <= n; i++) {
            std::cout << d[i] << " ";
        }
        std::cout << "\n";
		std::cout << res << " \n"[i == q];
	}
}
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}