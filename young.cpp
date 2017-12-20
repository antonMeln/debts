#include <iostream>
using namespace std;
void vivod(int i, int j, int matr[3][3]){
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
           if (matr[i][j] == 0) cout << “∞ “;
            else cout << matr[i][j] << ” “;
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    int matr[3][3], i, j, p, k = 0, l, f, m;
    char op;
    bool res = false, sim = false;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            matr[i][j] = 0;
        }
    }
    while (res == false){
        cin >> op;
        switch (op){
            /*case ‘=’:
                vivod(i, j, matr);
                break; */
            case ‘q’:
                res = true;
                break;
            case ‘+’:
                cin >> p;
                for (i = 0; i < 3; i++){
                    for (j = 0; j < 3; j++) {
                        for (l = 0; l < 3; l++){
                            if (matr[l][1] == 0) ++k;
                        }
                        if (k != 0) {
                            if ((matr[i][j] == 0) && (sim == false) && (j != 2)) {
                                matr[i][j] = p;
                                sim = true;
                                for (m = 0; m <= i; m++ ){
                                    if (matr[i -m][j] > p){
                                        matr[i - m + 1][j] = matr[i - m][j];
                                        matr[i - m][j] = p;
                                    }
                                }
                            }
                            else if ((p < matr[i][j]) && (sim == false) && (j == 0) && (matr[i][1] == 0)) {
                                matr[i][j + 1] = matr[i][j];
                                matr[i][j] = p;
                                sim = true;
                                for (m = 0; m <= i; m++ ){
                                    if (matr[i -m][j] > p){
                                        matr[i - m + 1][j] = matr[i - m][j];
                                        matr[i - m][j] = p;
                                    }
                                }
                                if (matr[i - 1][j] > p) {
                                    matr[i][j] = matr[i - 1][j];
                                    matr[i - 1][j] = p;
                                }
                                if (matr[i - 2][j] > p){
                                    matr[i - 1][j] = matr[i - 2][j];
                                    matr[i - 2][j] = p;
                                }
                                if ((matr[i - 1][j + 1] > matr[i][j + 1]) && (matr[i - 1][j + 1] != 0)) {
                                    f = matr[i - 1][j + 1];
                                    matr[i - 1][j + 1] = matr[i][j + 1];
                                    matr[i][j + 1] = f;
                                }
                            }
                        }
                        else {
                            for (l = 2; l > -1; l--){
                                if (matr[l][2] == 0){
                                    if ((matr[l][0] > p) && (sim == false)){
                                        matr[l][2] = matr[l][1];
                                        matr[l][1] = matr[l][0];
                                        matr[l][0] = p;
                                        sim = true;
                                        if (matr[l][0] < matr[l - 1][0]){
                                            f = matr[l - 1][0];
                                            matr[l -1][0] = matr[l][0];
                                            matr[l][0] = f;
                                        }
                                        if (matr[l][1] < matr[l - 1][1]){
                                            f = matr[l - 1][1];
                                            matr[l -1][1] = matr[l][1];
                                            matr[l][1] = f;
                                        }
                                        if (matr[l][2] < matr[l - 1][2]){
                                            f = matr[l - 1][2];
                                            matr[l -1][2] = matr[l][2];
                                            matr[l][2] = f;
                                        }
                                    }
                                    else if ((matr[l][1] > p) && (sim == false)){
                                        matr[l][2] = matr[l][1];
                                        matr[l][1] = p;
                                        sim = true;
                                        if (matr[l][1] < matr[l - 1][1]){
                                            f = matr[l - 1][1];
                                            matr[l -1][1] = matr[l][1];
                                            matr[l][1] = f;
                                        }
                                        if (matr[l][2] < matr[l - 1][2]){
                                            f = matr[l - 1][2];
                                            matr[l -1][2] = matr[l][2];
                                            matr[l][2] = f;
                                        }
                                    }
                                    else if ((matr[l][0] < p) && (matr[l][1] < p) && (matr[l][2] == 0) && (sim == false)){
                                        matr[l][2] = p;
                                        if ((matr[l + 1][2] < p) && ((l == 1) || (l == 0))){
                                            matr[l][2] = matr[l + 1][2];
                                            matr[l + 1][2] = p;
                                        }
                                        if ((matr[l + 2][2] < p) && (l == 0)){
                                            matr[l + 1][2] = matr[l + 2][2];
                                            matr[l + 2][2] = p;
                                        }
                                        sim = true;
                                    }
                                    else if ((p > matr[l][0]) && (p > matr[l][1]) && (sim == false)){
                                        if (matr[l + 1][2] < p){
                                            matr[l][2] = matr[l + 1][2];
                                            matr[l + 1][2] = p;
                                        }
                                        if (matr[l + 2][2] < p){
                                            matr[l + 1][2] = matr[l + 2][2];
                                            matr[l + 2][2] = p;
                                        }
                                        sim = true;
                                    }
                                }
                            }
                        }
                    }
                }
                sim = false;
                k = 0;
                vivod(i, j, matr);
                break;
        }
    }
    return (0);
}
