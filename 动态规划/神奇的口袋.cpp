#include <iostream>
#include <cstdio>
using namespace std;


int Ways[41][21];//Ways[i][j]表示前j个物品一共i大小有多少种方法


int main(){
    int n;
    int a[21];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int j = 0; j <= n; j++){//大小为零只有一种方法，选0个物品
        Ways[0][j] = 1;
    }
    for(int i = 1; i <= 40; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0){//若无物品，则方法数为0
                Ways[i][j] = 0;
            }
            else {
                Ways[i][j] = Ways[i][j - 1];//不用a[j]的方法数
                if ((i-a[j]) >= 0){
                    Ways[i][j] += Ways[i-a[j]][j-1];//用a[j]的方法数
                }
            }
        }
    }
    cout << Ways[40][n];
    return 0;
}