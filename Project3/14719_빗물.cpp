#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
int arr[501];
int Left[501];
int Right[501];
int n, m, ans;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> arr[i];
	int maxL = arr[0];
	int maxR = arr[m - 1];
	for (int i = 0; i < m; i++) {
		maxL = max(maxL, arr[i]);
		Left[i] = maxL;
	}
	for (int j = m - 1; j >= 0; j--) {
		maxR = max(maxR, arr[j]);
		Right[j] = maxR;
	}
	for (int i = 1; i < m-1; i++) {
		int diff = min(Right[i + 1], Left[i - 1]);
		if (arr[i] <diff)ans += diff-arr[i];
	}
	cout << ans;
}