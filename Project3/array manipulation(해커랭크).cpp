#include <bits/stdc++.h>
using namespace std;
long long arr[10000001];
long long sum;
long long ans;
int n, m;
vector<vector<int>>queries;
int main()
{
    cin >> n >> m;
    queries.resize(n);
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        queries[i].push_back(a);
        queries[i].push_back(b);
        queries[i].push_back(c);
}
    for (int i = 0; i <m; i++) {
        int start = queries[i][0];
        int end = queries[i][1];
        long long cost = queries[i][2];
        arr[start] += cost;
        arr[end + 1] -= cost;
    }
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        ans = max(sum, ans);
    }
    cout << ans;
   
}
