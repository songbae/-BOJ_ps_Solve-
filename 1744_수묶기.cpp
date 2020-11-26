#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<int>big;
vector<int>small;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		if (a > 0)big.push_back(a);
		else small.push_back(a);
	}
	sort(big.begin(), big.end(), greater<int>());
	sort(small.begin(), small.end());
	int sum = 0;
	int T = big.size();
	int P = small.size();
	for (int i = 0; i <T-1; i++) {
		if (big[i] > 1 && big[i + 1] > 1) {
			sum += big[i] * big[i + 1];
			i++;
		}
		else sum += big[i];
	}
	if (big.size() == 1)sum += big[0];
	else if (big.size()!=0&&(big[big.size() - 1] == 1 || big.size() % 2 != 0))sum += big[big.size() - 1];

	for (int i = 0; i < P - 1; i++) {
		sum += small[i] * small[i + 1];
		i++;
	}
	if (small.size() % 2 != 0)sum += small[small.size() - 1];
	cout << sum;
}