#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
bool check;
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}
}