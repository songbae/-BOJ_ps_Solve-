#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[100001];
int num[100001];
int n, m;
bool ok;
bool no;
int main() {
	cin >> n;
	while (n--) {
		memset(arr, false, sizeof(arr));
		memset(num, false, sizeof(num));
		cin >> m;
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			int a; cin >> a;
			arr[j] = { a };
		}
		ok = false;
		no = false;
		while (1) {
			ok = false;
			for (int k = 1; k <= m; k++) {
				if (arr[k] == k)continue;
				if (num[arr[k]] == 2)continue;
				if (arr[k + 1] < arr[k]) {
					num[arr[k]]++;
					swap(arr[k], arr[k + 1]);
					cnt++;
					ok = true;
				}
			}
				if (!ok)break;
			}
			for (int k = 1; k <= m; k++) {
				if (arr[k] == k)continue;
				else {
					no = true;
					break;
				}
			}
			if (no)cout << "Too chaotic" << endl;
			else cout << cnt << endl;
		}
	
}