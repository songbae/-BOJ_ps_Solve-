#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int num = 0;
bool check[11][11];
vector<int> v;
queue<pair<int, int>>q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int arr[101];
int sum;
void solution(int sizeOfMatrix, int** matrix) {
	// TODO: 이곳에 코드를 작성하세요.
	int n = sizeOfMatrix;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j])continue;
			if (matrix[i][j] == 0)continue;
			q.push({ i,j });
			num++;
			sum++;
			arr[num]++;
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
					if (check[nx][ny])continue;
					if (matrix[nx][ny] == 0)continue;
					check[nx][ny] = true;
					q.push({ nx,ny });
					arr[num]++;
				}
			}
		}
	}
	cout << sum << endl;
	for (int i = 1; i <= sum; i++)v.push_back(arr[i]);
	sort(v.begin(), v.end());
	for (auto T : v)cout << T << " ";
}

struct input_data {
	int sizeOfMatrix;
	int** matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int* [inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}