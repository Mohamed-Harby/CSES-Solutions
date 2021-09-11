// https://cses.fi/problemset/task/1637
// Solution

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long
 
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int dp[N];
 
int main() {
	lol
	int n;
	int curr_dig, sz;
	for (int i = 1; i < N; ++i) {
		dp[i] = INT_MAX;
	}
	cin >> n;
	for (int v = 1; v < N; ++v) {
		sz = ceil(log10(v)) + 1;
		for (int i = 1; i <= sz; ++i) {
			curr_dig = v % int(pow(10, i));
			curr_dig /= pow(10, i - 1);
 
			if (curr_dig == 0)
				continue;
 
			dp[v] = min(dp[v], dp[v - curr_dig] + 1);
		}
 
	}
	cout << dp[n];
}
