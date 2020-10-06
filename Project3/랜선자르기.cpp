#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long num[10001];
long long ans;
int main() {
	int a, b; cin >> a >> b; f;
 long long m = 0;
	for (int i = 0; i < a; i++) {
		int k; cin >> num[i];	
		m = max(m, num[i]);
	}
	long long st = 1;
	long long end = m;
	while (st<=end) {
		long long mid = (st + end) / 2;
		long long sum = 0;	
		for (int i = 0; i < a; i++)sum += num[i] / mid;
		if(sum<b)end=mid-1;
		else {
			ans = max(ans, mid);
			st = mid + 1;
		}
		
	}

	cout << ans;
}