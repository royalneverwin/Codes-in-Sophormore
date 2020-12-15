#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Vertex{
    int index;
    struct Vertex *next;//用来存放指向index的顶点，避免每次都要在边表中寻找，节省时间
};


struct Vertex vertex[100010];
int Chart[100010];//出度表
int flag[100010];//代表该元素是否访问过


queue<int> q;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    int N, M;
    int ru, chu;
    int op; int count;
    struct Vertex *cur;
    cin >> T;
    for(int i = 0; i < T; i++){
        count = 0;
        cin >> N >> M;
        for(int j = 1; j <= N; j++){
            vertex[j].index = j;
            vertex[j].next = NULL;
            Chart[j] = 0;
            flag[j] = 0;
        }
        for(int j = 0; j < M; j++){
            cin >> chu >> ru;
            struct Vertex *tmp;
            tmp = new struct Vertex;
            tmp->index = chu;
            tmp->next = NULL;
            cur = vertex[ru].next;
            if(cur == NULL){
                vertex[ru].next = tmp;
            }
            else{
                while(cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = tmp;
            }
            Chart[chu]++;
        }
        /*拓扑排序*/
        for(int j = 1; j <= N; j++){
            if(Chart[j] == 0){
                q.push(j);
                flag[j] = 1;
            }
        }
        while(!q.empty()) {
            op = q.front();
            q.pop();
            cur = vertex[op].next;
            while(cur != NULL){
                Chart[cur->index]--;
                if(Chart[cur->index] == 0 && flag[cur->index] == 0){//直接在这里判断，避免之后还要遍历vertex，会超时
                    q.push(cur->index);
                    flag[cur->index] = 1;
                }
                cur = cur->next;
            }
            count++;
        }
        if(count == N){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}

