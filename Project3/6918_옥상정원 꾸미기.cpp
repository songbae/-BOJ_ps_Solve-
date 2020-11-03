#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
long long ans;
vector<int>v;
stack<int>st;
int n;
int main() {
	cin >> n; f;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
		for(int i=0; i<n;i++){
			while (!st.empty() && st.top() <= v[i])st.pop();
			ans += st.size();
			st.push(v[i]);
			cout << ans << " ";
	}
		cout << ans;
}