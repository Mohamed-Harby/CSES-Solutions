// Problem statement: https://cses.fi/problemset/task/1636
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
	
	memset(dp, 0, sizeof dp);
	int n, x;
	cin >> n >> x;
	vi v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
 
	dp[0] = 1; // 4 -> 4, 2 + 2
 
	for(int i = 0; i < n; ++i) for (int cur = 1; cur <= x; ++cur) if(cur - v[i] >= 0) { // reverse loops
		dp[cur] += dp[cur - v[i]];
		dp[cur] %= mod;
	}
	cout << dp[x];
}
