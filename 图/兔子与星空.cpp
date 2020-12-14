#include <iostream>
#include <queue>
using namespace std;


struct vertex{//邻接表表示法的图的顶点
    char index;
    int mark;//该顶点是否被选中
};


struct edge{//边
    char v1;
    char v2;
    int weight;
    int mark;//该边是否被检验过
};


bool operator < (const struct edge e1, const struct edge e2){
    return e1.weight > e2.weight;
}


priority_queue<struct edge> p;
struct edge eNum[100];//边集合
struct vertex vNum[100];//节点集合


int main(){
    int n;//总节点数
    int k;//每个节点连接的新边数
    int eCount = 0;//总边数
    int vCount = 0;//已检验总节点数
    int sum = 0;//路径和
    int weight;//边权
    char c1;
    char c2;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> c1 >> k;
        vNum[i].index = c1;
        vNum[i].mark = 0;
        while(k > 0){
            cin >> c2 >> weight;
            eNum[eCount].v1 = c1;
            eNum[eCount].v2 = c2;
            eNum[eCount].weight = weight;
            eNum[eCount].mark = 0;
            eCount++;
            k--;
        }
    }
    vNum[n-1].index = 'A'+n-1;
    vNum[n-1].mark = 0;
    vNum[0].mark = 1;
    c1 = vNum[0].index;
    vCount = 1;
    while(vCount < n){
        for(int i = 0; i < eCount; i++){
            if(eNum[i].mark == 0 && (eNum[i].v1 == c1 || eNum[i].v2 == c1)){
                p.push(eNum[i]);
                eNum[i].mark = 1;
            }
        }
        struct edge temp;
        while(true) {
            temp = p.top();
            p.pop();
            if (vNum[temp.v1 - 'A'].mark == 0 || vNum[temp.v2 - 'A'].mark == 0) {
                break;
            }
        }
        sum += temp.weight;
        if(vNum[temp.v1 - 'A'].mark == 0){
            vNum[temp.v1 - 'A'].mark = 1;
            c1 = vNum[temp.v1 - 'A'].index;
        }
        else{
            vNum[temp.v2 - 'A'].mark = 1;
            c1 = vNum[temp.v2 - 'A'].index;
        }
        vCount++;
    }
    cout << sum;
}