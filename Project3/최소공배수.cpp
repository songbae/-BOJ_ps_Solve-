#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int lcd(int a, int b) {
	if (a < b)swap(a, b);
	int ans = 0;
	while (1) {
		
		int temp = b;
		b = a % b;
		if (b == 0) {
			ans = temp;
			break;
		}
		a = temp;
	}
	return ans;
}

int main() {
	int n; 
	cin >> n;
	for (; n--;) {
		int a, b; cin >> a >> b;
		cout << a*b/lcd(a, b) << "\n";
	}
}