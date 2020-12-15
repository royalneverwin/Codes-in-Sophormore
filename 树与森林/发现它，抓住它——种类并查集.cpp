#include <iostream>
#include <algorithm>
using namespace std;
#define LIM 100010


/*存案件的父节点*/
int f[2*LIM];


int getf(int a){
    if(a == f[a]){
        return a;
    }
    else{
        return (f[a] = getf(f[a]));
    }
}


void merge(int a, int b){
    int pa = getf(a);
    int pb = getf(b);
    f[pa] = pb;
}


/*种类并查集：f[a]和f[b]一类说明是一个犯罪团伙，否则不是*/
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    int N, M;
    char info;//表示信息是提供还是查找
    int a, b;//提供信息的两个案件
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M;
        for(int j = 1; j <= N; j++){//初始化
            f[j] = j;
            f[j+LIM] = j+LIM;
        }
        for(int j = 0; j < M; j++){
            cin >> info >> a >> b;
            if(info == 'D'){
                merge(a, b+LIM);
                merge(a+LIM, b);
            }
            else{
                if(getf(a) == getf(b)){
                    cout << "In the same gang." << endl;
                }
                else if(getf(a) == getf(b+LIM) || getf(a+LIM) == getf(b)){
                    cout << "In different gangs." << endl;
                }
                else{
                    cout << "Not sure yet." << endl;
                }
            }
        }
    }
    return 0;
}