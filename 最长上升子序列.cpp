#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int N;
int num[1002];
int maxNum[1002];//子问题：求以i为终点的最长上升子序列


int max(int a, int b){
    return (a > b) ? a : b;
}


int main() {//递推
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
        maxNum[i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (num[i] > num[j]) {
                maxNum[i] = max(maxNum[i], maxNum[j] + 1);
            }
        }
    }
    cout << *max_element(maxNum + 1, maxNum + N + 1);
    return 0;
}


/*普通动规
int MaxSeq(int n) {//表示以num[n]为终点的最长上升子序列
    if (maxNum[n] != -1) {
        return maxNum[n];
    }
    if (n == 1) {
        maxNum[n] = 1;
    }
    else {
        int tempMax;
        for (int i = 1; i < n; i++) {
            if (num[n] > num[i]) {
                tempMax = MaxSeq(i) + 1;
                if (tempMax > maxNum[n]) {
                    maxNum[n] = tempMax;
                }
            }
        }
        if(maxNum[n] == -1){
            maxNum[n] = 1;
        }
    }
    return maxNum[n];
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &num[i]);
        maxNum[i] = -1;
    }
    int max = 1;
    for(int i = 1; i <= N; i++){
        if(MaxSeq(i) > max){
            max = MaxSeq(i);
        }
    }
    printf("%d", max);
    return 0;
}*/