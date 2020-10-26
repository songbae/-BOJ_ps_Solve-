#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
stack<string>st;
queue<string>q;
string s;
string ans;
int main() {
	cin >> s;
	string T;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(T);
			T.clear();
		}
		else if (s[i] == ')') {
			if (!T.empty()) {
				string k = st.top();
				st.pop();
				int ed = k.back() - '0';
				k.erase(k.end()-1);
				ans += k;
				for (int i = 0; i < ed; i++) {
					ans += T;
				}
				T.clear();
			}
			else {
				string k = st.top();
				st.pop();
				int ed = k.back() - '0';
				k.erase(k.end()-1);
				string temp = ans;
				for (int i = 0; i < ed-1; i++) {
					ans += temp;
				}
				ans += k;
			}
		}
		else T += s[i];
		
	}
	cout << ans.size();
}