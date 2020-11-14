#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int test_case, num;
long long mod,MAX;
long long prefix[100001];
int main() {
	cin >> test_case; f;
	while (test_case--) {
		cin >> num >> mod;
		vector<long long>v;
		set<long long>s;
		memset(prefix, false, sizeof(prefix));
		for (int i = 0; i < num; i++) {
			long long a; cin >> a;
			v.push_back(a % mod);
		}
		prefix[0] = v[0];
		s.insert(prefix[0]);
		MAX = v[0];
		for (int i = 1; i < num; i++)prefix[i] = (prefix[i - 1] + v[i]) % mod;
		for (int i = 1; i < num; i++) {
			s.insert(prefix[i]);
			long long x = (prefix[i] - prefix[i - 1]+mod) % mod;
			auto index = s.lower_bound(mod - x);
			if (index == s.begin()) {
				MAX = max(x, MAX);
				continue;
			}
			long long nx = *(--index);
			MAX = max(x + nx, MAX);
		}
		

		cout << MAX << endl;
		}
}