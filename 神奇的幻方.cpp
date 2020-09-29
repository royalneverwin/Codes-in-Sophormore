#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int square[2*N-1][2*N-1];
    for (int i = 0; i < 2*N-1; i++){
        for(int j = 0; j < 2*N-1; j++){
            square[i][j] = -1;
        }
    }
    int row, col;
    row = 0;
    col = (2*N-1)/2;
    for(int i = 1; i <= (int)pow(2*N-1, 2); i++){
        square[row][col] = i;
        int temprow = row, tempcol = col;
        if (row == 0 && col == 2*N-2){
            temprow = row + 1;
        }
        else {
            if (row == 0) {
                temprow = 2 * N - 2;
            } else {
                temprow = row - 1;
            }
            if (col == 2 * N - 2) {
                tempcol = 0;
            }
            else{
                tempcol = col + 1;
            }
            if (square[temprow][tempcol] != -1){
                temprow = row + 1;
                tempcol = col;
            }
        }
        row = temprow;
        col = tempcol;
    }
    for (int i = 0; i < 2*N-1; i++){
        for(int j = 0; j < 2*N-1; j++){
            cout << square[i][j];
            if (j != 2*N-2){
                cout << ' ';
            }
            else{
                cout << '\n';
            }
        }
    }
    return 0;
}

