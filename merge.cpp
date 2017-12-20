#include <iostream>
#include <sstream>
using namespace std;
void merge_mid(int *mas, int mas1, int mas2, int mas3){ 
	int *revmas = new int[mas3 + 1 - mas1];
	int par, tmp, m, k;
	par = mas1;
	tmp = 0;
	m = mas2 + 1;
  	while ((par <= mas2) && (m <= mas3)){
		if (mas[par] <= mas[m])	{
			revmas[tmp] = mas[par]; par++;
		}
		else {
			revmas[tmp] = mas[m]; m++;
		}
		tmp++;
	}
  	if (par>mas2)	{
		for (k = m; k <= mas3; k++)	{
			revmas[tmp] = mas[k]; tmp++;
		}
	}
	else	{
  		for (k = par; k <= mas2; k++){
			revmas[tmp] = mas[k]; tmp++;
		}
	}
	for (k = 0; k <= mas3 - mas1; k++){
		mas[k + mas1] = revmas[k];
	}
	delete[] revmas;
}
void merge_sotring(int *mas, int mas1, int mas3){
  	int mas2;
	if (mas1<mas3){
  		mas2 = (mas1 + mas3) / 2;
  		merge_sotring(mas, mas1, mas2);
  		merge_sotring(mas, mas2 + 1, mas3);
  		merge_mid(mas, mas1, mas2, mas3);
	}
}
bool read_numbers(int * mas, unsigned int n) {
	string str;
	getline(cin, str);
	istringstream stream(str);
	for (unsigned int i = 0; i < n; ++i) {
		if (!(stream >> mas[i])) return false;
	}
	return true;
}
int main() {
	int n = 0;
	if ((cin >> n) && (n>0)) {
		string str;
		getline(cin, str);
		istringstream stream(str);
		int * mas = new int[n];
		if (read_numbers(mas, n)) {
			merge_sotring(mas, 0, n-1);
			for (int i = 0; i < n; ++i) {
				cout << mas[i] << " ";
			}
		}
		else cout << "An error has occured while reading input data." << endl;
		delete[] mas;
	}
	else cout << "An error has occured while reading input data." << endl;
	return 0;cin.get();
}
