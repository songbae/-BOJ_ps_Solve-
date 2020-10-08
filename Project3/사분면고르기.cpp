#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int x, y; cin >> x >> y;
	if (x > 0 && y > 0)cout << "1";
	if (x > 0 && y < 0)cout << "4";
	if (x < 0 && y < 0)cout << "3";
	if (x < 0 && y > 0)cout << "2";
}