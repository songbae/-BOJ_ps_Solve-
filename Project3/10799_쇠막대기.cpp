#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else if (s[i - 1] != '(' && s[i] == ')') {
			cnt--;
			ans++;
		}
		else if (s[i] == ')') {
			cnt--;
			ans += cnt;
		}
	}
	cout << ans;
}