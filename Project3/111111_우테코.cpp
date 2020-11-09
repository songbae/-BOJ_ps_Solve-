#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int score[10000][101];// 수험번호  문제번호 ->점수
int cnt[10000];//수험번호 -> 문제수 
bool before[10000][101];// 수험번호 푼번호 true
vector<int>v;// 수험번호
bool check;
vector<string> answer;
map<string, int>m;
void cmp(int a, int b) {
    if (cnt[a] != cnt[b])return;//비교 문제수 
    if (cnt[a] < 5 || cnt[b] < 5)return;// 둘중한명 5보다작으면 pass
    for (int i = 0; i < 101; i++) {// 문제번호 뒤지기
        if (before[a][i] != before[b][i])return;// 푼문제가 다르면 pass
        if (score[a][i] != score[b][i])return;// 점수가 다르면 pass
    }
    string t = to_string(a);
    string tt = to_string(b);
    while(t.size()<4){// a=1 로되어있기 때문에 0001로 변환
        t.insert(0, "0");
    }
    while (tt.size() < 4) {// 마찬가지
        tt.insert(0, "0");
    }
    m[t] = 1;//map에 집어넣는다 
    m[tt] = 1;
    return;
}
vector<string> solution(vector<string> logs) {
    for (int i = 0; i < logs.size(); i++) {
        check = false;
        string s = logs[i].substr(0, 4);// 수험번호 읽기
        string D = "";// 문제 번호
        string P = "";// 문제 점수 
        for (int j = 5; j < logs[i].size(); j++) {
            if (logs[i][j] == ' ') {
                check = true;// 한칸띄어져있으면 그때부터 점수 입력
                continue;
            }
            if (!check)D += logs[i][j];// 번호 입력 
            if (check)P += logs[i][j];// 점수 입력 
        }
        score[stoi(s)][stoi(D)] = stoi(P);//수험번호->문제번호->점수입력
        before[stoi(s)][stoi(D)] = true;//수험번호 -문제
        v.push_back(stoi(s));//수험번호 저장
    }
    v.erase(unique(v.begin(), v.end()), v.end());//수험번호 겹치는거지우기
    for (int i = 0; i < 10001; i++) {// 수험번호 
        for (int j = 0; j < 101; j++) {// 번호 
            if (before[i][j])cnt[i]++;// 수험번호 개수 카운트 
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            cmp(v[i], v[j]);// 비교
        }
    }
    for (auto t : m)answer.push_back(t.first);// 어차피 정렬되어있다.집어넣기 
    if (answer.empty())answer.push_back("None");//비었다면 none입력
    return answer;
}

int main() {
    vector<string>pp = { "0001 3 95", "0001 5 90", "0001 5 100", "0002 3 95", "0001 7 80", "0001 8 80", "0001 10 90", "0002 10 90", "0002 7 80", "0002 8 80", "0002 5 100", "0003 99 90" };
    for (auto T : solution(pp))cout << T << endl;;
}