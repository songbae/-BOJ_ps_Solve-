#include<bits/stdc++.h>
using namespace std;
int n, cnt;
int arr[100000 + 1];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		while (arr[i] != i) {
			int temp = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp;
			cnt++;
		}
	}
		
	cout << cnt;
}