#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<int>v;
int main() {
	f;
	while(cin>>n){
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (v.empty())v.emplace_back(a);
			else {
				if (v.back() < a)v.emplace_back(a);
				else v[lower_bound(v.begin(), v.end(), a) - v.begin()] = a;
			}
		}
		cout << v.size() << "\n";
		v.clear();
	} 
}