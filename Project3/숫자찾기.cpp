#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, k;
vector<int>v;
vector<int>ans;
bool ok;
int main() {
	cin >> n >> m >> k;
	if (k == 1) {
		if (n != m) {
			cout << "NO";
			return 0;
		}
		else {
			cout << n;
			return 0;
		}
}
	if (k == 2) {
		int st = n / 2;
		for (int i = st; i <= n; i++) {
			int mok = m / i;
			if (mok * i == m) {
				for (int j = 1; j <= mok; j++) {
					if (ok)break;
					if (mok % j == 0 && i + j == n) {
						ans.push_back(i);
						ans.push_back(j);
						ok = true;
					}
;				}
			}
		}
	}
	if (k == 3) {
		int st = n / 3;
		for (int i = st; i <= n; i++) {
			if (ok)break;
			int mok = m / i;
			if(i*mok==m){
				for (int j = 1; j <= mok; j++) {
					if (mok % j == 0)v.push_back(j);
				}
			
		for (int k = 0; k < v.size(); k++) {
			if (ok)break;
			for (int p = 0; p < v.size(); p++) {
				if (ok)break;
				if (v[k] + v[p] == n - i && v[k] * v[p] == mok) {
					ans.push_back(v[k]);
					ans.push_back(v[p]);
					ans.push_back(i);
					ok = true;
				}
			}
		}

		v.clear();
			}
		}
	}
	if (k == 4) {
		int st = n / 4;
		for (int i = st; i <= n; i++) {
			if (ok)break;
			int mok = m / i;
			if (i * mok == m) {
				for (int j = 1; j <= mok; j++) {
					if (mok % j == 0)v.push_back(j);
				}
			
			for (int k = 0; k < v.size(); k++) {
				if (ok)break;
				for (int p = 0; p < v.size(); p++) {
					if (ok)break;
					for (int t = 0; t < v.size(); t++) {
						if (ok)break;
						if (v[k] + v[p] + v[t] == n - i && v[t] * v[k] * v[p] == mok) {
							ans.push_back(v[k]);
							ans.push_back(v[p]);
							ans.push_back(v[t]);
							ans.push_back(i);
							ok = true;
						}
						}
					}
				}

			v.clear();
			}
		}

	}
	sort(ans.begin(), ans.end());
	if (ans.empty())cout <<"NO";
	else {
		for (auto T : ans) {
			cout << T << " ";
		}
	}
	
}