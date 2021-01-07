#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


/*将多项式化简成a1x1^3 + a2x2^3 = -a3x3^3 - a4x4^3 - a5x5^3，减少时间复杂度*/
unordered_map<int, int>sum;//记录a1x1^3+a2x2^3的结果

int cube(int a){
    return a*a*a;
}
int main(){
    int a1, a2, a3, a4, a5;
    int x1, x2, x3, x4, x5;
    int tmp;
    int cnt = 0;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    for(int i = -50; i <= 50; i++){
        x1 = cube(i);
        if(i == 0){
            continue;
        }
        for(int j = -50; j <= 50; j++){
            if(j == 0){
                continue;
            }
            x2 = cube(j);
            tmp = a1*x1 + a2*x2;
            if(!sum[tmp]){
                sum[tmp] = 1;
            }
            else{
                sum[tmp]++;
            }
        }
    }
    for(int i = -50; i <= 50; i++){
        if(i == 0){
            continue;
        }
        for(int j = -50; j <= 50; j++){
            if(j == 0){
                continue;
            }
            for(int k = -50; k <= 50; k++){
                if(k == 0){
                    continue;
                }
                x3 = cube(i);
                x4 = cube(j);
                x5 = cube(k);
                tmp = a3*x3 + a4*x4 + a5*x5;
                cnt += sum[-tmp];
            }
        }
    }
    cout << cnt;
    return 0;
}