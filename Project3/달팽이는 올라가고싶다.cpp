#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = c / (a - b)+1;
	cout << ans;
}