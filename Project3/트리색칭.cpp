#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
#define	INF 1e9
#define num 10
using namespace std;
int n, ans;
vector<int>v[MAX];
bool check[MAX];
int color[MAX];
int dp[MAX][num];//
void treedp(int x){ 
	for (auto t : v[x]){
		int next = t;
		if (!check[next]) {
			check[next] = true;
			treedp(next);
			for (int k = 0; k < num; k++) {
			int MIN = INF;
				for (int j = 0; j < num; j++) {
					if (k == j)continue;
					MIN = min(MIN, dp[next][j]);
				}
				dp[x][k] += MIN;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		dp[x][i] += color[i + 1];
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= num; i++) color[i]=i;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = true;
	treedp(1);
	int small = 1e9;
	for (int i = 0; i < num; i++) {
		small = min(small, dp[1][i]);
	}
	cout << small;
}