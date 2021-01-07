#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int Start[30];
int End[30];
int an[30][30];//an[i][j]
/*高斯消元*/
void Gauss(int n){
    int k = 0;//代表处理的是xk未知量
    int tmp;
    for(int col = 0; k < n && col < n; k++, col++){//每个xk对应第col列,第k行
        tmp = k;
        while(tmp < n && !an[tmp][col]){//找到col列第一个xk系数不为0的行
            tmp++;
        }
        if(!an[tmp][col]){//如果col列xk系数全为零，k--，xk+1依然在xk行上
            k--;
            continue;
        }
        if(tmp != k){
            for(int i = col; i <= n; i++){//把系数不为0的行换到第k行
                swap(an[tmp][i], an[k][i]);
            }
        }
        for(int i = k+1; i < n; i++){
            if(an[i][col]){//把第k行下面的行的xk的系数全部化为0
                for(int j = col; j <= n; j++){
                    an[i][j] ^= an[k][j];
                }
            }
        }
    }
    /*此时k表示化简矩阵中所有系数不为0的xk的个数，且都在前k行*/
    for(int i = k; i < n; i++){
        if(an[i][n]){//如果存在0 0 0 0 0 0 ... a这样的情况，无解
            cout << "Oh,it's impossible~!!" << endl;
            return;
        }
    }
    cout << (1 << (n-k)) << endl;//每有一个自由变量，解的可能性x2（0和1两种可能）
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int K;
    int n;
    int a1, a2;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> n;
        memset(an, 0, sizeof(an));//initiate
        for(int j = 0; j < n; j++){
            cin >> Start[j];
        }
        for(int j = 0; j < n; j++){
            cin >> End[j];
            an[j][n] = Start[j]^End[j];//result
            an[j][j] = 1;//j can influence j
        }
        while((cin >> a1 >> a2) && (a1 || a2)){//a1 can influence a2
            an[a2-1][a1-1] = 1;
        }
        Gauss(n);
    }
}