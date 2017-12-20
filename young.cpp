#include <iostream>

using namespace std;

void vivod(int i, int j, int matr[3][3]){
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
           if (matr[i][j] == 0) cout << "∞ ";
            else cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    int matr[3][3], i, j, num, k = 0, l, f;
    char op;
    bool res = false, sym_check = false;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            matr[i][j] = 0;
        }
    }

    while (res == false){

        cin >> op;

        switch (op){

            /*case '=':
                vivod(i, j, matr);
                break; */

            case 'q':
                res = true;
                break;

            case '+':
                cin >> num;
                for (i = 0; i < 3; i++){
                    for (j = 0; j < 3; j++) {

                        for (l = 0; l < 3; l++){
                            if (matr[l][1] == 0) ++k;
                        }

                        if (k != 0) {

                            if ((matr[i][j] == 0) && (sym_check == false) && (j != 2)) {
                                matr[i][j] = num;
                                sym_check = true;

                                if (matr[i - 1][j] > num) {
                                    matr[i][j] = matr[i - 1][j];
                                    matr[i - 1][j] = num;
                                }
                            }

                            else if ((num < matr[i][j]) && (sym_check == false) && (j == 0) && (matr[i][1] == 0)) {
                                matr[i][j + 1] = matr[i][j];
                                matr[i][j] = num;
                                sym_check = true;

                                if (matr[i - 1][j] > num){
                                    matr[i][j] = matr[i - 1][j];
                                    matr[i - 1][j] = num;
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

                                    if ((matr[l][0] > num) && (sym_check == false)){

                                        matr[l][2] = matr[l][1];
                                        matr[l][1] = matr[l][0];
                                        matr[l][0] = num;
                                        sym_check = true;

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

                                    else if ((matr[l][1] > num) && (sym_check == false)){

                                        matr[l][2] = matr[l][1];
                                        matr[l][1] = num;
                                        sym_check = true;

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

                                    else if ((matr[l][0] < num) && (matr[l][1] < num) && (matr[l][2] == 0) && (sym_check == false)){
                                        matr[l][2] = num;
                                        if ((matr[l + 1][2] < num) && ((l == 1) || (l == 0))){
                                            matr[l][2] = matr[l + 1][2];
                                            matr[l + 1][2] = num;
                                        }
                                        if ((matr[l + 2][2] < num) && (l == 0)){
                                            matr[l + 1][2] = matr[l + 2][2];
                                            matr[l + 2][2] = num;
                                        }
                                        sym_check = true;
                                    }

                                    else if ((num > matr[l][0]) && (num > matr[l][1]) && (sym_check == false)){
                                        if (matr[l + 1][2] < num){
                                            matr[l][2] = matr[l + 1][2];
                                            matr[l + 1][2] = num;
                                        }
                                        if (matr[l + 2][2] < num){
                                            matr[l + 1][2] = matr[l + 2][2];
                                            matr[l + 2][2] = num;
                                        }
                                        sym_check = true;
                                    }
                                }
                            }
                        }
                    }
                }
                sym_check = false;
                k = 0;
                vivod(i, j, matr);
                break;
        }
    }
    return (0);
}
