#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
bool check[10001];
int main() {
	for (int i = 1; i <= 10000; i++) {
		string s = to_string(i);
		int sum = stoi(s);
		for (int j = 0; j < s.size(); j++) {
			sum += s[j] - '0';
		}
		check[sum] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!check[i])cout << i << endl;
	}
}