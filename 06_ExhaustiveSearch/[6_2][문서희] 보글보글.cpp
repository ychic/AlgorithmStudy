#include<iostream>
#include <string>
using namespace std;
char arr[5][5] = { { 'U','R','L','P','M' },{ 'X','P','R','E','T' },{ 'G','I','A','E','T' },{ 'X','T','N','Z','Y' },{ 'X','O','Q','R','S' } };
int xy[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
bool flag=false;

void boggle(string word, int x, int y) {
	if (word == "") {
		flag = true;
	}
	if (arr[x][y] == word[0]) {
		for (int i = 0; i < 8; i++) {
			if (x + xy[i][0] >= 0 && y + xy[i][1] >= 0 && x + xy[i][0] <5 && y + xy[i][1] < 5) {
				boggle(word.substr(1), x + xy[i][0], y + xy[i][1]);
			}
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word = "AQ";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			boggle(word, i, j);
		}
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	system("PAUSE");


	return 0;
}