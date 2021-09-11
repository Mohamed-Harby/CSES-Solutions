// Problem statement: https://cses.fi/problemset/task/1633
// Solution

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ll long long
 
const int N = 1000 * 1000;
const int mod = 1e9 + 7;
 
int mem[N + 9];
 
int ways(ll n) {
	if (n == 0)
		return 1;
 
	int &res = mem[n];
	if (res != 0)
		return res;
 
	for (int i = 1; i <= 6 and n >= i; i++) {
		res += ways(n - i);
		res %= mod;
	}
	return res;
}
 
int main() {
	for (int i = 1; i <= 1e6; ++i) {
		ways(i);
	}
	int x;
	cin >> x;
	cout << ways(x);
 
}
