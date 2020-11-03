#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int arr[1001];
int Left[1001];
int Right[1001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr[a] = b;
	}
	int MAX = 0;
	for (int i = 0; i <= 1000; i++) {
		MAX = max(arr[i], MAX);
		Left[i] = MAX;
	}
	MAX = 0;
	for (int i = 1000; i >= 0; i--) {
		MAX =max(MAX, arr[i]);
		Right[i] = MAX;
	}
	int ans = 0;
	for (int i = 0; i <= 1000; i++) {
		arr[i] = min(Left[i], Right[i]);
		ans += arr[i];
	}
	cout << ans;
}