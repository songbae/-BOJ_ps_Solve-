#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int k = a * b * c;
	string s = to_string(k);

		for (int j = 0; j < 10; j++) {
			int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (j == s[i] - '0')cnt++;
		}
	cout << cnt << endl;
	}
}