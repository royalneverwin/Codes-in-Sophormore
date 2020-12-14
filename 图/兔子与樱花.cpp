#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAXNUM 10000


struct vertex{//邻接矩阵表示法的图的顶点
    int index;
    string name;
};


struct vertex vNum[50];//节点集合


/*用于Floyd算法*/
int adj[50][50];
int path[50][50];


void Floyd(int P){//Floyd算法构造adj和path矩阵
    for(int i = 1; i <= P; i++){
        for(int j = 1; j <= P; j++){
            for(int k = 1; k <= P; k++){
                if(adj[j][i] + adj[i][k] < adj[j][k]){
                    adj[j][k] = adj[j][i] + adj[i][k];
                    path[j][k] = path[j][i];
                }
            }
        }
    }
}


int main(){
    int P, Q, R;
    string name1, name2;
    int v1, v2;
    int weight;
    cin >> P;
    for(int i = 1; i <= P; i++){
        cin >> name1;
        vNum[i].index = i;
        vNum[i].name = name1;
    }
    for(int i = 1; i <= P; i++){
        for(int j = 1; j <= P; j++){
            if(i == j){
                adj[i][j] = 0;
                path[i][j] = i;
            }
            else{
                adj[i][j] = MAXNUM;
                path[i][j] = -1;
            }
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> name1 >> name2 >> weight;
        for(int j = 1; j <= P; j++){
            if(vNum[j].name == name1){
                v1 = vNum[j].index;
            }
            else if(vNum[j].name == name2){
                v2 = vNum[j].index;
            }
        }
        adj[v1][v2] = weight;
        adj[v2][v1] = weight;
        path[v1][v2] = v2;
        path[v2][v1] = v1;
    }
    Floyd(P);
    cin >> R;
    for(int i = 0; i < R; i++){
        cin >> name1 >> name2;
        for(int j = 1; j <= P; j++){
            if(vNum[j].name == name1){
                v1 = vNum[j].index;
            }
            if(vNum[j].name == name2){
                v2 = vNum[j].index;
            }
        }
        while(v1 != v2){//输出
            cout << vNum[v1].name << "->(" << adj[v1][path[v1][v2]] << ")->";
            v1 = path[v1][v2];
        }
        cout << vNum[v1].name << endl;
    }
    return 0;
}