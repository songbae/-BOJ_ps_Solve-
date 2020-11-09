#include <string>
#include <vector>

using namespace std;
string solution(string penter, string pexit, string pescape, string data) {
    string answer = "";
    int n = penter.size();
    answer += penter;
    for (int i = 0; i < data.size()/n; i++) {
        int k = i * n;
        string D = data.substr(k,  n);
        if (D == penter || D == pexit || D == pescape) {
            answer += pescape;
            answer += D;
        }
        else answer += D;
    }
    answer += pexit;
    return answer;
}