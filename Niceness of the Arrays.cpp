#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

const int MX = 50;
const int mod = (int) 1e9 + 7;
int fact[MX + 1];

int modpow(int a, int b, int mod) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * (long long) a % mod;
		}
		a = a * (long long) a % mod;
		b >>= 1;
	}
	return res;
}

void precompute() {
	fact[0] = 1;
	for (int i = 1; i <= MX; i++) {
		fact[i] = fact[i - 1] * (long long) i % mod;
	}
}

vector<vector<int> > data;

void rec(int idx, vector<int> v, int n, int sum, int desiredSum) {
	if (idx == n) {
		if (sum == desiredSum) {
			data.push_back(v);
		}
	} else {
		int last = v.size() ? v.back() : 1;
		for (int j = last; j <= MX; j++) {
			if (sum + j + (n - 1 - idx) <= desiredSum) {
				v.push_back(j);
				rec(idx + 1, v, n, sum + j, desiredSum);
				v.pop_back();
			}
		}
	}
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int calc(vector<int> v) {
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			ans += gcd(v[i], v[j]);
		}
	}
	return ans;
}

//
//void recursion(int idx, vector<int> v, int sum, int desiredSum) {
//	if (idx == v.size()) {
//		if (sum == desiredSum) {
//			data.push_back(v);
//		}
//	} else {
//		if (v[idx] != -1) {
//			if (sum + v[idx] <= desiredSum) {
//				recursion(idx + 1, v, sum + v[idx], desiredSum);
//			}
//		} else {
//			for (int x = 1; x <= MX; x++) {
//				v[idx] = x;
//				if (sum + v[idx] <= desiredSum) {
//					recursion(idx + 1, v, sum + v[idx], desiredSum);
//				}
//			}
//		}
//	}
//}


//long long bruteForce(vector<int> v, int desiredSum) {
//	data.clear();
//  	recursion(0, v, 0, desiredSum);
//	// cerr << "total " << data.size() << endl;
//
//	long long ans = 0;
//	for (auto v: data){
//		ans += calc(v);
//	}
//
//	return ans;
//}

int main() {
	precompute();

	int T;
	cin >> T;

	while (T--) {
		int n, desiredSum;
	  	cin >> n >> desiredSum;

		vector<int> a(n);
		vector<int> b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] != -1) {
				b.push_back(a[i]);
			}
		}

		data.clear();
	  	rec(0, vector<int>(), n, 0, desiredSum);
		cerr << "total " << data.size() << endl;

		long long ans = 0;
		for (auto v: data) {
			map<int, int> cnt;
			for (auto it: v) {
				cnt[it]++;
			}

			int ok = true;
			for (int x: b) {
				if (cnt.find(x) == cnt.end() || cnt[x] == 0) {
					ok = false;
					break;
				}
				cnt[x]--;
			}

			if (!ok) {
				continue;
			}

			int curWays = fact[n - b.size()];
			for (auto it: cnt) {
				if (it.second != 0) {
					curWays = curWays * (long long) modpow(fact[it.second], mod - 2, mod) % mod;
					// curWays /= fact[it.second];
				}
			}

			ans = (ans + curWays * (long long) calc(v)) % mod;
		}

		cout << ans << endl;
		// cout << "done " << endl;
		// long long bans = bruteForce(a, desiredSum);
		// cerr << "bans " << bans << endl;

		// cerr << endl;
	}

	return 0;
}
