#include <bits/stdc++.h> 
#include <iostream> 
#define int long long 
using namespace std; 

void solve(int n, vector<int>& v) 
{ 
	vector<int> dp(n, -2); 
	int maxmoney = 0; 
	if (n == 1 || n == 2) { 
		cout << "Maximum loot possible : "; 
		cout << *max_element(v.begin(), v.end()) << endl; 
		return; 
	} 
	dp[0] = v[0]; 
	dp[1] = v[1]; 
	for (int i = 2; i < n; i++) { 
		int money = 0; 
		dp[i] = v[i]; 
		for (int j = i - 2; j >= 0; j--) { 
			money = max(money, dp[j]); 
		} 
		dp[i] += money; 
	} 
	int m = *max_element(dp.begin(), dp.end()); 
	cout << "Maximum loot possible : "; 
	cout << m << endl; 
	return; 
} 
signed main() 
{ 
	// int t;cin>>t; 
	// while(t--){ 
	int n = 7; 
	vector<int> v{ 6, 7, 1, 3, 8, 2, 4 }; 
	solve(n, v); 
	//} 
	return 0; 
}
