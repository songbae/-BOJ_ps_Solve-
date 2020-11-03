#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string s;
stack<char>st;
int main() {
	int num = 1;
	while (1) {
		int cnt = 0;
		cin >> s;
		if (s[0] == '-')break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{') st.push('{');
			else {
				if (!st.empty() && st.top() == '{')st.pop();
				else if (st.empty()) {
					st.push('{');
					cnt++;
				}
				
			}
		}
		int res = 0;
		while (!st.empty()) {
			st.pop();
			res++;
		}
		cout <<num<<". "<< cnt+res/2 << endl;
		num++;
	}
}