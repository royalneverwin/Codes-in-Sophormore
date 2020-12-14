#include <iostream>
#include <cstdio>
using namespace std;


//利用递推算法，不需要递归，程序运行速度飙升
int num[100][100];
int sumMax[100][100];
int N;

int max(int a, int b){
    return (a > b) ? a : b;
}


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    if(N == 1){
        printf("%d", num[0][0]);
    }
    else {
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                num[i][j] += max(num[i+1][j], num[i+1][j+1]);
            }
        }
        printf("%d", num[0][0]);
    }
    return 0;
}


/*动态规划1：记忆递归型动归程序
int max(int a, int b){
    return (a > b) ? a : b;
}


int Sum_Max(int i, int j){
    if(i == N-1){
        return num[i][j];
    }
    if(sumMax[i+1][j] == -1){
        sumMax[i+1][j] = Sum_Max(i+1, j);
    }
    if(sumMax[i+1][j+1] == -1){
        sumMax[i+1][j+1] = Sum_Max(i+1, j+1);
    }
    return max(sumMax[i+1][j+1], sumMax[i+1][j]) + num[i][j];
}


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &num[i][j]);
            sumMax[i][j] = -1;
        }
    }
    printf("%d", Sum_Max(0, 0));
    return 0;
}*/


/*普通递归算法 会超时
int max(int a, int b){
    return (a > b) ? a : b;
}


int Sum_Max(int i, int j){
    if(i == N-1){
        return num[i][j];
    }
    return max(Sum_Max(i+1, j), Sum_Max(i+1, j+1)) + num[i][j];
}


int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i+1; j++){
            scanf("%d", &num[i][j]);
        }
    }
    printf("%d", Sum_Max(0, 0));
    return 0;
}*/