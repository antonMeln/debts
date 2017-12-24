#include <iostream>
#include <sstream>
using namespace std;
bool read(int *mas, int len) {
	string line;
	getline(cin, line);
	istringstream stream(line);
	for (unsigned int i = 0; i < len; ++i) {
		if (!(stream >> mas[i])) {
			return false;
		}
	}
	return true;
}
void countsort(int *mas,int *bet,  int n) {
	int cnt[256]; 
	for (int i=0;i<n;i++){
	  bet[i]=i;
	}
	for (int i = 0; i < 256; i++)  cnt[i] = 0; 
	for (int i = 0; i < n; i++) cnt[mas[i]] = cnt[mas[i]] + 1;
	for (int j = 1; j < 256; j++) {
		cnt[j] = cnt[j] + cnt[j - 1];
	}
	for (int i = n-1; i > -1; i--){
	   cnt[mas[i]] = cnt[mas[i]] - 1;
        bet[cnt[mas[i]]] = mas[i];
	}
}
int main() {
	int len; string o;
	getline(cin, o);
	istringstream stream(o);
	if (!(stream >> len || len > 0)) {
		cout << "An error has occuried while reading input data.";
		return 0;
	}
	int *mas = new int[len];
	int *bet = new int[len];
	read(mas, len);
	for (int i = 0; i < len; i++) {

		if (mas[i] < 0) {

			cout << "An error has occuried while reading input data.";

			return 0;
		}
	}
	countsort(mas,bet, len);
	for (int i = 0; i < len; i++) { cout << bet[i] << ' '; }
	return 0;
}
