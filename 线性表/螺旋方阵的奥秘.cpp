#include <iostream>
using namespace std;
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define UP 4
int main(){
    int N;
    int M;
    cin >> N;
    int forward = RIGHT;
    int row = 0;
    int col = 0;
    int square[N][N];
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < N; j++){
            square[i][j] = -1;
        }
    }
    for(size_t _ = 1; _ <= N*N; _++){
        square[row][col] = _;
        switch(forward){
            case RIGHT:
                if((square[row][col+1] != -1) || col+1 == N){
                    forward = DOWN;
                    row += 1;
                }
                else{
                    col += 1;
                }
                break;
            case DOWN:
                if((square[row+1][col] != -1) || row+1 == N){
                    forward = LEFT;
                    col -= 1;
                }
                else{
                    row += 1;
                }
                break;
            case LEFT:
                if((square[row][col-1] != -1) || col-1 == -1){
                    forward = UP;
                    row -= 1;
                }
                else{
                    col -= 1;
                }
                break;
            case UP:
                if((square[row-1][col] != -1) || row-1 == -1){
                    forward = RIGHT;
                    col += 1;
                }
                else{
                    row -= 1;
                }
                break;
        }
    }
//    for(size_t i = 0; i < N; i++){
//        for(size_t j = 0; j < N; j++){
//            cout << square[i][j] << ' ';
//        }
//        cout << endl;
//    }
    cin >> M;
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < N; j++){
            if(square[i][j] == M){
                cout << i+1 << ' ' << j+1;
            }
        }
    }
    return 0;
}