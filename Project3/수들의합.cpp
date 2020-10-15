#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m,i,arr[10002];
int main() {
	cin >> n >> m;
	for (; i < n; i++)cin >> arr[i];
	int first = 0;
	int last = 0;
	long long sum = arr[0];
	int cnt = 0;
	while (first <= last&&last<n) {
		if (sum < m)sum += arr[++last];
		else if (sum > m) {
			sum -= arr[first++];
			if (first > last && first < n)last = first--;
		}
		else if (sum == m) {
				cnt++;
				sum =sum+ arr[++last]- arr[first++];
			}
	}
	cout << cnt;
}