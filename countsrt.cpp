#include <iostream>
#include <sstream>
using namespace std;
bool read(int *mas, int n) {
	string line;
	getline(cin, line);
	istringstream stream(line);
	for (unsigned int i = 0; i < n; ++i) 	if (!(stream >> mas[i])) return false; 
	return true;
}
void countsort(int *mas, int n) {
	int bet[256]={0}; int x = 0;
	for (int i = 0; i < n; i++)  bet[mas[i]]++; 
	for (int j = 0; j < 256; j++) {
		for (int i = 0; i < bet[j]; i++) 	mas[x] = j; x++;
	}
}
int main() {
	int n; string line1;
	getline(cin, line1);
	istringstream stream(line1);
	if (!(stream >> n || n > 0)) {
		cout << "An error has occuried while reading input data.";
		return 0;
	}
	int *mas = new int[n];
read(mas, n);
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			cout << "An error has occuried while reading input data.";
			return 0;
		}
	}
	countsort(mas, n);
	for (int i = 0; i < n; i++)  cout << mas[i] <<" "; 
	return 0;

}
