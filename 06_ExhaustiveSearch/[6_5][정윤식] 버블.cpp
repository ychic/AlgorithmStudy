#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

string myDicSet[8] = { "A", "P", "T", "D", "S", "K", "J", "F" };
string** myTable;
vector<pair<int, int>>mvPoint = { {-1,1},{0,1},{1,1},
								{-1,0},{1,0},
								{-1,-1},{0,-1},{1,-1}, };


bool hasWord(int y, int x, string word, int array_size);
bool wordCheck(string word, int array_size);


void main() {

	static int arrayNum = 0;


	srand(time(NULL));


	//cout << "배열 크기 ?" << endl;
	cin >> arrayNum;


	cout << "Your Array is " << arrayNum << "X" << arrayNum << endl;


	////set Array 
	//myTable = setArray(arrayNum);
	
	
	myTable = new string*[arrayNum];

	for (int i = 0; i < arrayNum; i++)
	{
		myTable[i] = new string[arrayNum];
	
	}



	for (int i = 0; i < arrayNum; i++)
	{
		for (int j = 0; j < arrayNum; j++)
		{
			string temp = (myDicSet[rand() % 8]);

			myTable[i][j] = (temp);

			cout << myTable[i][j] << "   ";
		}
		cout << endl;
	}



	cout << "찾을 단어는 ? " << endl;
	string word;
	cin >> word;

	if (wordCheck(word, arrayNum)) {
		cout << "있음";
	}
	else {
		cout << "없음";

	}
}


bool hasWord(int y, int x, string word,int array_size) {

	
	//-------------------------------재귀 조건
	
	//out of sight
	if (y > array_size || x > array_size || y < 0 || x < 0)return false;
	
	//first word is wrong
	if (myTable[y][x] != word.substr(0,1)) return false;
	


	//--------------------------------------
	//right path
	//if word is just one 
	if (word.size() == 1) return true;
	



	//--------------------------------------재귀
	//if not, recursive
	for (int direction = 0; direction < 8; ++direction) {
		//8 kind of direction
		int nextY = y + mvPoint[direction].first, nextX = x + mvPoint[direction].second;
		
		//delete first world 
		if (hasWord(nextY, nextX, word.substr(1,word.length()-1),array_size)) {
			return true;
		}
	}
	return false;
}



bool wordCheck(string word,int array_size) {


	for (int i = 0; i <array_size ; ++i) {
		for (int j = 0; j < array_size; ++j) {
			

			//use hasWord
			if (hasWord(i,j,word,array_size)) {
				//if it found
				return true;
			}
		}

	}
	return false;
}
