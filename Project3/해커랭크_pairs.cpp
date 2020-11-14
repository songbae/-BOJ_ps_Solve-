#include<bits/stdc++.h>
using namespace std;
int n, target,ans;
vector<int>v;
int main() {
	cin >> n >> target;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) { //라이브러리 안에서도 탐색을 하고 그 시간을 걸리는데 log n 으로 탐색을해서 포문두개보다는 빠르다.
		int x = lower_bound(v.begin() + i + 1, v.end(), v[i] + target) - v.begin();// 로우바운드로 인덱스를 찾는다 
		if(x!=n&&v[x]-v[i]==target)ans++;// 인덱스가 없을경우 n즉 v.end()를 반환하기때문에 n인경우를 제외하고 탐색
	}
	cout << ans;
}

/// 테스트ㅡ준비는 8월부터 -> 이때부터 1~2문제 처음 하루씩->