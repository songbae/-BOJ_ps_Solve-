#include <string>
#include <vector>

using namespace std;
int answer = 0;
int score[9] = { 10,9,8,7,6,5,4,3,0 };
int solution(vector<string> grades, vector<int> weights, int threshold) {
    for (int i = 0; i < grades.size(); i++) {
        string a = grades[i];
        int num = 0;
        if (a == "A+") num=score[0];
        if (a == "B+") num = score[2];
        if (a == "C+") num = score[4];
        if (a == "D+") num = score[6];
        if (a == "F") num = score[8];
        if (a == "A0") num = score[1];
        if (a == "B0") num = score[3];
        if (a == "C0") num = score[5];
        if (a == "D0") num = score[7];
        int T = num * weights[i];
        answer += T;


    }

    return answer;
}