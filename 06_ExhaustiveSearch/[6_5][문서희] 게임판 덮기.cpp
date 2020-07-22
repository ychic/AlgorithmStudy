#include<iostream>
#include <string>
#include<vector>
using namespace std;
vector<vector<pair<int, int>>> block = { { {0,0},{0,1},{1,1} }, {{0,0},{0,1},{1,0}},{{0,0},{1,0},{1,1}},{{0,0},{1,0},{1,-1}} };
//ㄱ, Γ, ㄴ, 」
int c=0;
int count_white(vector<string> vec) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == '.') {
				count++;
			}
		}
	}
	return count;
}

void cover(vector<string> vec, int x, int y, int count) {
	bool flag = true;

	//블록이 4가지 종류를 각각 넣어봄
	for (int i = 0; i < block.size(); i++) {
		flag = true;

		//블록을 놓을 수 있는 지 체크
		for (int j = 0; j < block[i].size(); j++) {
			if (x + block[i][j].first < vec.size() && y + block[i][j].second < vec[x].size()&& x + block[i][j].first>=0 && y + block[i][j].second>=0) {
				if (vec[x + block[i][j].first][y + block[i][j].second] == '#') {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
		}

		//놓을 수 있으면 변경
		if (flag) {
			for (int j = 0; j < block[i].size(); j++) {
				vec[x + block[i][j].first][y + block[i][j].second] = '#';
				count--;

			}
		}
		if (count == 0) {
			c++;
		}
		
		//다음 흰색 칸 위치로 
		for (int k = x; k < vec.size(); k++) {
			for (int z = 0; z < vec[k].size(); z++) {
				if (vec[k][z] == '.') {
					//흰색 위치부터 다시 블록 놓아봄
					if (z == y && k == x) {
						continue;
					}
					else if (z < y && k == x) {
						continue;
					}
					cover(vec, k, z, count);
				}
			}
		}
	}
	

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, h, w, white_count=0, result=0;
	string temp;
	vector<string> vec;
	cin >> test_case;
	while (test_case--) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			cin >> temp;
			vec.push_back(temp);
		}
		white_count = count_white(vec);
		if (white_count % 3 != 0) {
			c = 0;
		}
		else {
			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					if (vec[i][j] == '.') {
						cover(vec, i, j, white_count);
					}
				}
			}
		}
	}
	cout << c << '\n';
	c = 0;

	system("PAUSE");


	return 0;
}