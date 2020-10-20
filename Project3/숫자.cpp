#include<bits/stdc++.h>
using namespace std;
long long i,n,k;
int main() {
	cin >> n >> k;
	if (n == k||abs(n-k)==1) {
		cout << "0" << endl;
		return 0;
	}
	cout << abs(k-n - 1) << "\n";
	if (n > k)swap(n, k);
	for (i = n + 1; i < k; i++) cout << i << " ";
}