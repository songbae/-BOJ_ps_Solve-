#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
long long histo[100000];

long long dfs(int left, int right) {
	if (left == right) return histo[left];
	int mid = (left + right) / 2;
	long long result = max(dfs(left, mid), dfs(mid + 1, right));
	int lo = mid, hi = mid + 1;
	long long height = min(histo[lo], histo[hi]);
	result = max(result, height * 2);

	while (lo > left || hi < right) {
		if (hi < right && (lo == left || histo[hi + 1] > histo[lo - 1])) {
			hi++;
			height = min(histo[hi], height);
		}
		else {
			lo--;
			height = min(histo[lo], height);
		}
		result = max(result, (hi - lo + 1) * height);
	}
	return result;
}

int main() {
	f;
	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)cin >> histo[i];
		cout << dfs(0, n - 1) << "\n";
		memset(histo, false, sizeof(histo));
	}
}