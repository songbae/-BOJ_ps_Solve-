#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, int>M;
int n;
bool ok;
int main() {
	cin >> n;
	int st = 1;
	int ed = 1;
	while (ed * ed - st * st <= n || ed - st > 1) {
		if (ed * ed - st * st > n)st++;
		else if (ed * ed - st * st < n)ed++;
		else if (ed * ed - st * st == n) {
			ok = true;
			cout << ed << endl;
			ed++;
		}

	}
	if (!ok)cout << "-1";
}