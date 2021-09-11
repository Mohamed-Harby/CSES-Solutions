// Problem statement: https://cses.fi/problemset/task/1634
// Solution

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ll long long
 
const int N = 1000 * 1000;
const int mod = 1e9 + 7;
 
int dp[N + 9];
vi coins;
int n, x;
int main() {
	cin >> n >> x;
	coins = vi(n);
	for (int i = 0; i < n; ++i)
		cin >> coins[i];
 
	for (int i = 1; i <= N; ++i)
		dp[i] = 1e7;
 
	for (int i = 1; i <= x; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - coins[j] < 0)
				continue;
			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
	if (dp[x] == 1e7)
		cout << -1;
	else
		cout << dp[x];
}
