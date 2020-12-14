#include <iostream>
#include <cstdio>
using namespace std;


struct charm{
    int w;
    int d;
};
int Sum[12881];//M，N数量较大，因此若用二维数组会导致内存溢出，用滚动的一维数组可以解决。表示前i个元素w和不超过j的最大价值。
struct charm charms[3403];


int max(int a, int b){
    return (a > b) ? a : b;
}


int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d%d", &charms[i].w, &charms[i].d);
    }
    for(int i = 1; i < N; i++){
        for(int j = M; j >= 1; j--){
            if(i == 1){
                if(charms[1].w <= j){
                    Sum[j] = charms[1].d;
                }
                else{
                    Sum[j] = 0;
                }
            }
            else{
                if((j - charms[i].w) >= 0){
                    Sum[j] = max(Sum[j], Sum[j-charms[i].w]+charms[i].d);
                }
            }
        }
    }
    if((M - charms[N].w) >= 0){
        Sum[M] = max(Sum[M], Sum[M-charms[N].w]+charms[N].d);
    }
    cout << Sum[M];
    return 0;
}