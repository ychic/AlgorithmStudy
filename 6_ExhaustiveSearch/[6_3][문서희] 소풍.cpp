#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> vec;
int c = 0;

bool sp(int i, vector<int> student) {
	int flag1 = -1, flag2=-1;
	int size = student.size();
	for (int j = 0; j < size; j++) {
		if (vec[i].first == student[j]) {
			flag1 = j;
			if (flag2 != -1) {
				student.erase(student.begin() + flag1);
				student.erase(student.begin() + flag2);
				break;
			}
		}
		if (vec[i].second == student[j] ) {
			flag2 = j;	
			if (flag1 != -1) {
				student.erase(student.begin() + flag2);
				student.erase(student.begin() + flag1);
				break;
			}
		}
	}
	if (flag1 == -1 || flag2 == -1) {
		return false;
	}
	if (student.empty()) {
		c++;
		return true;
	}

	for (int j = i+1; j < vec.size(); j++) {
		
		if (vec[j].first == student.front() || vec[j].second == student.front()) {
			sp(j, student);
		}
	}
	if (!student.empty()) {
		return false;
	}
	
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test_case, n, m, s1, s2;
	cin >> test_case;
	vector<int> student;
	while (test_case--) {
		cin >> n >> m;
		while (m--) {
			cin >> s1 >> s2;
			vec.push_back(make_pair(s1, s2));
		}
		for (int i = 0; i < n; i++) {
			student.push_back(i);
		}
		for (int i = 0; i < vec.size(); i++) {
			sp(i, student);
		}

		vec.clear();
		student.clear();
		cout << c << '\n';
		c = 0;

	}

	system("PAUSE");


	return 0;
}