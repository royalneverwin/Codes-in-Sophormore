#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


/*最小生成树问题——并查集*/


struct Edge{
    int x;
    int y;
    int weight;
};


bool operator < (struct Edge e1, struct Edge e2){
    return e1.weight > e2.weight;
}


priority_queue<struct Edge> pq;
struct Edge edge[500010];
int Map[510][510];//记录是否是路径点
int Heap[510][510];//记录高度
int SigPoint = 0;//记录路经点总数
int if_Sig[500010];//记录该点是否是路径点
int f[500010];//记录该点的父节点
int Max = 0;//记录最大难度值
stack<int> End;//记录已经被包括到最小生成树但未与start形成通路的路径点（很重要！不要忽略有可能路径点之间不连通即使已经包括到最小生成树中）


int getf(int a){
    if(a == f[a]){
        return a;
    }
    else{
        return (f[a] = getf(f[a]));
    }
}


void Merge(int a, int b){
    int pa = getf(a);
    int pb = getf(b);
    f[pa] = pb;
}


int main(){
    int M, N;
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Heap[i][j];
            f[i*501+j] = i*501+j;//初始化
            if_Sig[i*501+j] = 0;//初始化
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            if(Map[i][j]){
                SigPoint++;
                if_Sig[i*501+j] = 1;
            }
        }
    }
    int tmpW;//记录两点高度之差的绝对值
    int countE = 0;//记录边总数
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            /*每个节点构建与右边和下边节点形成的边*/
            if(j != N-1) {
                tmpW = abs(Heap[i][j] - Heap[i][j+1]);
                edge[countE].x = i*501+j;
                edge[countE].y = i*501+j+1;
                edge[countE].weight = tmpW;
                pq.push(edge[countE]);
                countE++;

            }
            if(i != M-1){
                tmpW = abs(Heap[i][j] - Heap[i+1][j]);
                edge[countE].x = i*501+j;
                edge[countE].y = (i+1)*501+j;
                edge[countE].weight = tmpW;
                pq.push(edge[countE]);
                countE++;
            }
        }
    }
    struct Edge tmp;
    if(SigPoint == 1 || SigPoint == 0){//1个或0个路径点
        cout << 0 << endl;
        return 0;
    }
    int start = -1;//记录第一个进入最小生成树的路径点
    int End_top;//记录End栈的栈顶元素
    while(!pq.empty()) {
        /*正常最小生成树构建*/
        tmp = pq.top();
        pq.pop();
        if (getf(tmp.x) != getf(tmp.y)) {
            Merge(tmp.x, tmp.y);
            Max = max(Max, tmp.weight);
            if(if_Sig[tmp.x]){//如果加入了路径点
                if(start == -1){
                    start = tmp.x;
                }
                else{
                    if(getf(start) != getf(tmp.x)){
                        End.push(tmp.x);
                    }
                }
                SigPoint--;
                if_Sig[tmp.x] = 0;
            }
            if(if_Sig[tmp.y]){//如果加入了路径点
                if(start == -1){
                    start = tmp.y;
                }
                else{
                    if(getf(start) != getf(tmp.y)){
                        End.push(tmp.y);
                    }
                }
                SigPoint--;
                if_Sig[tmp.y] = 0;
            }
            if(SigPoint == 0){//全部路径点都加入了
                if(End.empty()){
                    break;
                }
                End_top = End.top();
                while(getf(start) == getf(End_top)){//比较现在每个路径点是否都和start连通，如果连通则正确，否则继续加边
                    End.pop();
                    if(End.empty()){
                        break;
                    }
                    End_top = End.top();
                }
                if(End.empty()){
                    break;
                }
            }
        }
    }
    cout << Max << endl;
    return 0;
}