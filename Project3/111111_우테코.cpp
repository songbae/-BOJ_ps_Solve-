#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int score[10000][101];// �����ȣ  ������ȣ ->����
int cnt[10000];//�����ȣ -> ������ 
bool before[10000][101];// �����ȣ Ǭ��ȣ true
vector<int>v;// �����ȣ
bool check;
vector<string> answer;
map<string, int>m;
void cmp(int a, int b) {
    if (cnt[a] != cnt[b])return;//�� ������ 
    if (cnt[a] < 5 || cnt[b] < 5)return;// �����Ѹ� 5���������� pass
    for (int i = 0; i < 101; i++) {// ������ȣ ������
        if (before[a][i] != before[b][i])return;// Ǭ������ �ٸ��� pass
        if (score[a][i] != score[b][i])return;// ������ �ٸ��� pass
    }
    string t = to_string(a);
    string tt = to_string(b);
    while(t.size()<4){// a=1 �εǾ��ֱ� ������ 0001�� ��ȯ
        t.insert(0, "0");
    }
    while (tt.size() < 4) {// ��������
        tt.insert(0, "0");
    }
    m[t] = 1;//map�� ����ִ´� 
    m[tt] = 1;
    return;
}
vector<string> solution(vector<string> logs) {
    for (int i = 0; i < logs.size(); i++) {
        check = false;
        string s = logs[i].substr(0, 4);// �����ȣ �б�
        string D = "";// ���� ��ȣ
        string P = "";// ���� ���� 
        for (int j = 5; j < logs[i].size(); j++) {
            if (logs[i][j] == ' ') {
                check = true;// ��ĭ����������� �׶����� ���� �Է�
                continue;
            }
            if (!check)D += logs[i][j];// ��ȣ �Է� 
            if (check)P += logs[i][j];// ���� �Է� 
        }
        score[stoi(s)][stoi(D)] = stoi(P);//�����ȣ->������ȣ->�����Է�
        before[stoi(s)][stoi(D)] = true;//�����ȣ -����
        v.push_back(stoi(s));//�����ȣ ����
    }
    v.erase(unique(v.begin(), v.end()), v.end());//�����ȣ ��ġ�°������
    for (int i = 0; i < 10001; i++) {// �����ȣ 
        for (int j = 0; j < 101; j++) {// ��ȣ 
            if (before[i][j])cnt[i]++;// �����ȣ ���� ī��Ʈ 
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            cmp(v[i], v[j]);// ��
        }
    }
    for (auto t : m)answer.push_back(t.first);// ������ ���ĵǾ��ִ�.����ֱ� 
    if (answer.empty())answer.push_back("None");//����ٸ� none�Է�
    return answer;
}

int main() {
    vector<string>pp = { "0001 3 95", "0001 5 90", "0001 5 100", "0002 3 95", "0001 7 80", "0001 8 80", "0001 10 90", "0002 10 90", "0002 7 80", "0002 8 80", "0002 5 100", "0003 99 90" };
    for (auto T : solution(pp))cout << T << endl;;
}