#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string inFileName = "kryptosIn.txt";
string outFileName = "kryptosOut.txt";

vector<char> k4letters({'O', 'B', 'K', 'R', 'U', 'O', 'X', 'O', 'G', 'H', 'U', 'L', 'B', 'S', 'O', 'L', 'I', 'F', 'B', 'B', 'W', 'F', 'L', 'R', 'V', 'Q', 'Q', 'P', 'R', 'N', 'G', 'K', 'S', 'S', 'O', 'T', 'W', 'T', 'Q', 'S', 'J', 'Q', 'S', 'S', 'E', 'K', 'Z', 'Z', 'W', 'A', 'T', 'J', 'K', 'L', 'U', 'D', 'I', 'A', 'W', 'I', 'N', 'F', 'B', 'N', 'Y', 'P', 'V', 'T', 'T', 'M', 'Z', 'F', 'P', 'K', 'W', 'G', 'D', 'K', 'Z', 'X', 'T', 'J', 'C', 'D', 'I', 'G', 'K', 'U', 'H', 'U', 'A', 'U', 'E', 'K', 'C', 'A', 'R'});
vector<int> k4numbers({14, 1, 10, 17, 20, 14, 23, 14, 6, 7, 20, 11, 1, 18, 14, 11, 8, 5, 1, 1, 22, 5, 11, 17, 21, 16, 16, 15, 17, 13, 6, 10, 18, 18, 14, 19, 22, 19, 16, 18, 9, 16, 18, 18, 4, 10, 25, 25, 22, 0, 19, 9, 10, 11, 20, 3, 8, 0, 22, 8, 13, 5, 1, 13, 24, 15, 21, 19, 19, 12, 25, 5, 15, 10, 22, 6, 3, 10, 25, 23, 19, 9, 2, 3, 8, 6, 10, 20, 7, 20, 0, 20, 4, 10, 2, 0, 17});

vector<int> convertToNumbers(vector<char> letterVect) {
	vector<int> resultVect;
	int thisVal;
	for (int i = 0; i < letterVect.size(); i++) {
		thisVal = letterVect[i] - 65;
		resultVect.push_back(thisVal);
	}
	return resultVect;
}
vector<char> convertToLetters(vector<int> numberVect) {
        vector<char> resultVect;  
        char thisVal;
        for (int i = 0; i < numberVect.size(); i++) {
                thisVal = 'A' + numberVect[i];
                resultVect.push_back(thisVal);
        }
        return resultVect;
}

//int matr[2][2] = {{14,1},{10,17}};
//int matr[2][2] = {{19,5},{24,8}};

int main() {
	cout << "k4numbers vector:" << endl;
	for (int i = 0; i < k4numbers.size(); i++) {
		cout << k4numbers[i] << " ";
	}
	cout << endl << "k4letters converted:" << endl;
	vector<int> outVect = convertToNumbers(k4letters);
	for (int i = 0; i < outVect.size(); i++) {
                cout << outVect[i] << " ";
        }
	cout << endl;
}


/*
int main() {
	ifstream inFile;
	inFile.open(inFileName);
	
	ofstream outFile;
	outFile.open(outFileName);
	
	int num1, num2;
	int out1, out2;
	char ch1, ch2;
	while (inFile >> num1) {
		inFile >> num2;
		out1 = ((matr[0][0] * num1) + (matr[0][1] * num2)) % 26;
		out2 = ((matr[1][0] * num1) + (matr[1][1] * num2)) % 26;
		ch1 = 'A' + out1;
		ch2 = 'A' + out2;
		outFile << ch1 << " " << ch2 << " ";
		
		
	}
	
	inFile.close();
	outFile.close();
}
*/
