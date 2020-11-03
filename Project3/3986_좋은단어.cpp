#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
vector<char>v;
int main() {
	int n; cin >> n;
	int cnt = 0;
	while (n--) {
		bool check = false;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (v.empty())v.push_back(s[i]);
			else {
				if (v.back() == s[i])v.pop_back();
				else v.push_back(s[i]);
			}
			cout << v.size() << endl;
			if (v.size() > 2) {
				check = true;
				break;
			}
			
		}
		if (!check && v.size() == 0)cnt++;
		v.clear();
	}
	cout << cnt;
}