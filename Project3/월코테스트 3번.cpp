#include <string>
#include <vector>
#include  <algorithm>
using namespace std;
vector<vector<pair<int,int>>>v;
vector<int>temp;
int ans = 0;
bool check[50001];
bool cmp(vector<int>a, vector<int>b) {
    return a.size() > b.size();
}
int solution(vector<int> a) {
    int answer = -1;
    v.resize(a.size());
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        v[x].push_back({ i,x });
    }
    sort(v.begin(), v.end(),cmp);// 인덱스별로 와 숫자 가먼지 
    for (int i = 0; i < v.size(); i++) {//50만의 크기를 갖고있다.
        temp.clear();
        int target = v[i][0].second;
        memset(check, false, sizeof(check));
        for (int j = 0; j < v[i].size(); j++) {
            int index = v[i][j].first;
            check[index] = true;
        }
        int cur = 0;
        int cnt = 0;
        while(1){
        for (int k = cur; k < a.size(); k++) {
            if (check[true])cnt++;
            if (a[k] == target)continue;
            cur = k;
            break;
        }
    }
   



    return answer;
}