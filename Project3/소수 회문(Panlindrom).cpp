#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 2000000
using namespace std;

bool prime[MAX];
int  n;
int main() {
	cin >> n;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i])continue;
		for (int j = i+i; j < MAX; j +=i) {
			if (i == j||prime[j])continue;
			if (j % i == 0)prime[j] = true;
		}
		
	}
	for (int i = n; i < MAX; i++) {
		if (prime[i])continue;
		string s = to_string(i);
		reverse(s.begin(), s.end());
		int k = stoi(s);
		if (k!=i)continue;
		cout << i;
		return 0;
	}
}