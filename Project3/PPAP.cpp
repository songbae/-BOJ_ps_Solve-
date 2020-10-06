#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s; int cnt = 0;
	for (auto i : s) {
		if (i == 'P')cnt++;
		else if (i == 'A') {
			if (cnt < 2 || i+1 != 'P') {
				cout << "NP";
				return 0;
			}
			else if (i+1 == 'P') {
				cnt--;
				i++;
			}
		}
	}
	if (cnt == 1)cout << "PPAP";
	else cout << "NP";
}