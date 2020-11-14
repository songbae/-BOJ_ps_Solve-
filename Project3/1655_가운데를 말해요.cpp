#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s, t;
deque<char>F;
deque<char>B;
int main() {
	cin >>s>>t;
	
	while (F.size() + B.size() < t.size()) {
		bool ok = false;
		int cur = 0;
		int cur_B = t.size() - 1;
		for (int i = cur; i < t.size()-s.size(); i++) {
			int cnt = 0;
			F.push_front(t[i]);
			if (t[i] != s[cnt])continue;
			for (int j = 0; j < s.size(); j++) {
				if (t[i + j] != s[j])break;
				cnt++;
			}
			if (cnt == s.size()) {
				F.pop_back();
				ok = true;
			}
			if (ok)break;
		}
	}
	

}