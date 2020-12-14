#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


/*带权并查集加正常离散化*/

int fa[10010];
int oddeven[5001];//记录每次回答的结果
int trueRelation[10010];//记录离散化后每个节点和其父节点之间的odd&even


int getf(int a){
    if(a == fa[a]){
        trueRelation[a] = 0;
        return a;
    }
    else{
        int tmp2 = trueRelation[a];
        int tmpf = fa[a];//下一步会改变fa[a]！所以这里要先保存
        fa[a] = getf(fa[a]);
        int tmp1 = trueRelation[tmpf];
        if(tmp1 == tmp2){
            trueRelation[a] = 0;
        }
        else{
            trueRelation[a] = 1;
        }
    }
    return fa[a];
}


bool merge(int a, int b, int i ){
    int pa = getf(a);
    int pb = getf(b);
    if(pa == pb){
        if((trueRelation[a] ^ trueRelation[b] ^ oddeven[i]) == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        fa[pb] = pa;
        trueRelation[pb] = oddeven[i] ^ trueRelation[a] ^ trueRelation[b];
        return true;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n, sum;
    int a[5001], b[5001];
    int newindex[10002];//用于数据离散化
    cin >> n >> sum;
    for(int i = 0; i < sum; i++){
        string tmp;
        cin >> a[i] >> b[i] >> tmp;
        a[i]--;//这是这道题中特殊性，让左区间-1做到区间连续，便于并查集归并
        newindex[2*i] = a[i];
        newindex[2*i+1] = b[i];
        if(tmp == "even"){
            oddeven[i] = 0;
        }
        else{
            oddeven[i] = 1;
        }
    }
    sort(newindex, newindex + 2*sum);
    int newSum = unique(newindex, newindex + 2*sum) - newindex;//离散化后总数据
    for(int i = 0; i < sum; i++){
        a[i] = find(newindex, newindex+newSum, a[i]) - newindex;//将a[i]变为其映射
        fa[a[i]] = a[i];
        trueRelation[a[i]] = 0;
        b[i] = find(newindex, newindex+newSum, b[i]) - newindex;//将b[i]变为其映射
        fa[b[i]] = b[i];
        trueRelation[b[i]] = 0;
    }
    int i;
    for(i = 0; i < sum; i++){
        if(merge(a[i], b[i], i)){
            continue;
        }
        break;
    }
    cout << i << endl;
    return 0;
}