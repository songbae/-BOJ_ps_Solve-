#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m,i;
int v[5000001];
priority_queue<pair<int, int>>pq;
int main() {
	cin >> n >> m; f;
	for (i = 0; i < n; i++)cin >>v[i];
	for(i=0; i<n; i++){
			pq.push({ -v[i],i });;
			while (!pq.empty() && pq.top().second <=i - m) pq.pop();
			cout << -pq.top().first << " ";
			}

}