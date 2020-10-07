#include<bits/stdc++.h>
using namespace std;
int n,k,b,i;vector<string> v;
typedef string p;
int main() {
cin >> k >> n;
for (;i < k; i++) {
int a; cin >> a;b=max(b, a);
v.push_back(to_string(a));}
n -=k;
for(;n--;)v.push_back(to_string(b));
sort(v.begin(),v.end(),[](p& a, p& b){return a + b>b + a;});
for (auto t : v)cout << t;
}