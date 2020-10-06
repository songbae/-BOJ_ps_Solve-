#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
long long k;
long long answer;
string s;
int sum[10] = { 6,2,5,5,4,5,6,3,7,6 };
void dfs(int cnt ,int num, string t) {
	if (num == k) {
		if (t.size() != 1 && t[0] == '0')return;
		answer ++ ;
		return;
	}
	if (num > k)return;
	for (int i = 0; i < 10; i++) {
		dfs(cnt + 1,num+sum[i], t + to_string(i));
	}
	return;
}

int main() {
	cin >> k;
	dfs(0,0, "");
	cout << answer;
}