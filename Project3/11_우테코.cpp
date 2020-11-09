#include <string>
#include <vector>

using namespace std;
long long cmp(int a, int b,string p) {
    if (p == "+")return a+b;
    if (p == "-")return a-b;
    if (p == "*")return a*b;

}
vector<long long> solution(string s, string op) {
    vector<long long> answer;

    for (int i = 1; i < s.size(); i++) {
        string st = s.substr(0, i);
        string ed = s.substr(i, 10);
        long long ans = cmp(stoi(st), stoi(ed),op);
        answer.push_back(ans);
    }

    return answer;
}