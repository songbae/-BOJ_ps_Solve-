#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v[3];
long long ans,arr[3];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		v[i].resize(arr[i]);
	}
	for (int i = 0; i < 3; i++)for (int j = 0; j < arr[i]; j++)cin >> v[i][j];
	for (int i = 0; i < 3; i++)sort(v[i].begin(), v[i].end());
	for (int i = 0; i < 3; i++) {
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
	}
	for (int i = 0; i < v[0].size(); i++) {

	}
	for (int i = 0; i < v[1].size(); i++) {
		int q = v[1][i];
		int p = upper_bound(v[0].begin(), v[0].end(), q) - v[0].begin();
		int r = upper_bound(v[2].begin(), v[2].end(), q) - v[2].begin();
		if (p != 0 && r != 0)ans +=(long long)p * r;//10만 *10만 이기때문에 100억 까지 나온다 long long으로 변환하자
		
	}
	cout << ans;
}