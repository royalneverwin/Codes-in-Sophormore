#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


/* 注意这一点！！！！！！！！
           创建虚拟结点0，其到i的边值为建立发电站的价格
           这样就可以将结点0视为全图电力之源
           接下来就是很简单的最小生成树问题了
       */


struct Edge{
    int v1;
    int v2;
    int weight;
    int visited;
};


priority_queue<struct Edge> pq;


bool operator < (struct Edge e1, struct Edge e2){//重载小于号
    return e1.weight > e2.weight;
}

/*
int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    struct Edge edge[250000];
    int n;
    int Web[500][500];
    int if_Visited[500];//判断点是否被visited
    int cnt = 0;
    int countVertex;
    int countEdge = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        //构造Edge最小堆
        int temp;
        edge[countEdge].v1 = i;
        edge[countEdge].v2 = n;
        edge[countEdge].visited = 0;
        cin >> edge[countEdge].weight;
        if_Visited[i] = 0;
        countEdge++;
    }
    if_Visited[n] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> Web[i][j];
        }
    }
    //构造Edge最小堆
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            edge[countEdge].v1 = i;
            edge[countEdge].v2 = j;
            edge[countEdge].weight = Web[i][j];
            edge[countEdge].visited = 0;
            countEdge++;
        }
    }
    //构造最小生成树
    if_Visited[n] = 1;
    for(int i = 0; i < countEdge; i++){//未被visited的edge
        if(edge[i].visited == 0 && (edge[i].v1 == n || edge[i].v2 == n)){
            pq.push(edge[i]);
            edge[i].visited = 1;
        }
    }
    countVertex = 1;
    while(countVertex <= n){
        struct Edge tmp = pq.top();
        pq.pop();
        if(if_Visited[tmp.v1] == 0){
            if_Visited[tmp.v1] = 1;
            cnt += tmp.weight;
            countVertex++;
            for(int i = 0; i < countEdge; i++){
                if(edge[i].visited == 0 &&(edge[i].v1 == tmp.v1 || edge[i].v2 == tmp.v1)){
                    pq.push(edge[i]);
                    edge[i].visited = 1;
                }
            }
        }
        else if(if_Visited[tmp.v2] == 0){
            if_Visited[tmp.v2] = 1;
            cnt += tmp.weight;
            countVertex++;
            for(int i = 0; i < countEdge; i++){
                if(edge[i].visited == 0 &&(edge[i].v1 == tmp.v2 || edge[i].v2 == tmp.v2)){
                    pq.push(edge[i]);
                    edge[i].visited = 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
*/


/*法2：Kruskal算法，并查集*/


int f[500];//存放所有节点的父亲


int getf(int x){/*重量权衡归并规则找父亲*/
    if(x == f[x]){
        return x;
    }
    else{
        return (f[x] = getf(f[x]));
    }
}


void merge(int x, int y){/*合并两个节点*/
    int fx = f[x], fy = f[y];
    f[fx] = fy;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    struct Edge edge[250000];
    int n;
    int Web[500][500];
    int cnt = 0;
    int countEdge = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        /*构造Edge最小堆*/
        f[i] = i;
        edge[countEdge].v1 = i;
        edge[countEdge].v2 = n;
        cin >> edge[countEdge].weight;
        pq.push(edge[countEdge]);
        countEdge++;
    }
    f[n] = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> Web[i][j];
        }
    }
    /*构造Edge最小堆*/
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            edge[countEdge].v1 = i;
            edge[countEdge].v2 = j;
            edge[countEdge].weight = Web[i][j];
            pq.push(edge[countEdge]);
            countEdge++;
        }
    }
    /*构造最小生成树*/
    while(!pq.empty()){
        struct Edge tmp = pq.top();
        pq.pop();
        if(getf(tmp.v1) != getf(tmp.v2)){
            cnt += tmp.weight;
            merge(tmp.v1, tmp.v2);
        }
    }
    cout << cnt << endl;
    return 0;
}
