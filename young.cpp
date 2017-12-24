#include <iostream>
using namespace std;
void write(int matr[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++) {
			cout << matr[i][j] << " ";
		}
	}
	cout << endl;
}
void sort2(int &m1, int& m2) {
	if (m1>m2) swap(m1, m2);
}
void sort3(int &m1, int& m2, int& m3) {
	if (m1>m3) swap(m1, m3);
	if (m1>m2) swap(m1, m2);
	if (m2>m3) swap(m2, m3);
}
int main() {
	int matr[3][3] = { 0 }, num, k = 0;
	char oper;
	while (k < 9) {
		cin >> oper;
		switch (oper) {
		case 'q':
			exit(0);
			cin.get();
		case '=':
			write(matr);
		case '+':
			cin >> num;
			if (k == 0) matr[0][0] = num;
			if (k == 1) {
				matr[0][1] = num;
				sort2(matr[0][0], matr[0][1]);
			}
			if (k == 2) {
				matr[1][0] = num;
				sort2(matr[0][0], matr[1][0]);
				sort2(matr[0][0], matr[0][1]);
			}
			if (k == 3) {
				matr[1][1] = num;
				if(matr[1][0]>matr[1][1]){
				  sort2(matr[1][0],matr[1][1]);
				  sort2(matr[0][0],matr[1][0]);
				  sort2(matr[0][1],matr[1][1]);
				}
				else {
				  sort2(matr[0][1],matr[1][1]);
				  sort2(matr[0][0],matr[0][1]);
				  sort2(matr[1][0],matr[1][1]);
				}
			}
			if (k == 4) {
				matr[2][0] = num;
				sort3(matr[0][0], matr[1][0], matr[2][0]);
				sort2(matr[1][0],matr[1][1]);
				sort2(matr[0][0],matr[0][1]);
				sort3(matr[0][0], matr[1][0], matr[2][0]);
			}
			if (k == 5) {
				matr[2][1] = num;
			  sort2(matr[2][0],matr[2][1]);
			  sort3(matr[0][0], matr[1][0], matr[2][0]);
				sort3(matr[0][1], matr[1][1], matr[2][1]);
				sort2(matr[2][0],matr[2][1]);
				sort2(matr[1][0],matr[1][1]);
				sort2(matr[0][0],matr[0][1]);	
			}
			if (k == 6) {
				matr[2][2] = num;
			  sort3(matr[2][0], matr[2][1], matr[2][2]);
			  sort3(matr[0][0], matr[1][0], matr[2][0]);
				sort3(matr[0][1], matr[1][1], matr[2][1]);
				sort3(matr[2][0], matr[2][1], matr[2][2]);
				sort2(matr[0][0],matr[0][1]);
				sort2(matr[1][0],matr[1][1]);
				}
			}
			if (k == 7) {
				matr[1][2] = num;
				sort3(matr[1][0], matr[1][1], matr[1][2]);
				sort3(matr[2][0], matr[2][1], matr[2][2]);
				sort2(matr[0][0], matr[0][1]);
				sort3(matr[0][0], matr[1][0], matr[2][0]);
				sort3(matr[0][1], matr[1][1], matr[2][1]);
				sort2(matr[1][2], matr[2][2]);
			}
			if (k == 8) {
				matr[0][2] = num;
				sort3(matr[0][0], matr[0][1], matr[0][2]);
				sort3(matr[0][0], matr[1][0], matr[2][0]);
				sort3(matr[0][1], matr[1][1], matr[2][1]);
				sort3(matr[0][2], matr[1][2], matr[2][2]);
				sort3(matr[0][0], matr[0][1], matr[0][2]);
				sort3(matr[1][0], matr[1][1], matr[1][2]);
				sort3(matr[2][0], matr[2][1], matr[2][2]);	
			}
			write(matr);
			k++;
		}
		cin.get();
	}
