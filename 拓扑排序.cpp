#include <iostream>
#include <queue>
using namespace std;


struct list{
    int index;
    struct list *next;
};


struct vertex{//邻接表表示法的图的顶点
    int index;
    int du;
    int mark;
//    struct list *l;
};


bool operator < (const struct vertex vNum1, const struct vertex vNum2){//重载小于号
    return vNum1.index > vNum2.index;
}


struct edge{
    int in;
    int out;
};


priority_queue <struct vertex> q;//用于TopoSort，优先队列保证index小的先输出


struct vertex vNum[101];//顶点集合
struct edge eNum[200];


/*
void BuildLink(struct vertex *vNum, int m, int n){//创建vertex的邻接表
    struct list *temp = vNum[m-1].l->next;
    struct list *ptemp = vNum[m-1].l;
    struct list *p = new struct list;
    p->next = NULL;
    p->index = n;
    while(temp && temp->index < n) {
        ptemp = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        ptemp->next = p;
        return;
    }
    else if(temp->index == n){
        return;
    }
    else{
        ptemp->next = p;
        p->next = temp;
        return;
    }
}
*/


int main(){
    int v, a;
    cin >> v >> a;
    for(int i = 1; i <= v; i++){
        vNum[i].index = i;
        vNum[i].du = 0;
        vNum[i].mark = 0;
/*      struct list *temp = new struct list;
        temp->index = -1;
        temp->next = NULL;
        vNum[i].l = temp;*/
    }
    int m, n;
    for(int i = 0; i < a; i++){
        cin >> m >> n;
        vNum[n].du++;
        eNum[i].out = m;
        eNum[i].in = n;
//        BuildLink(vNum, m, n);
    }
    for(int i = 1; i <= v; i++){
        if(vNum[i].du == 0){
            vNum[i].mark = 1;
            q.push(vNum[i]);
        }
    }
    while(!q.empty()){
        struct vertex temp = q.top();
        q.pop();
        cout << 'v' << temp.index << ' ';
        for(int i = 0; i < a; i++){
            if(eNum[i].out == temp.index){
                vNum[eNum[i].in].du--;
                if(vNum[eNum[i].in].du == 0){
                    q.push(vNum[eNum[i].in]);
                    vNum[eNum[i].in].mark = 1;
                }
            }
        }
    }
    return 0;
}