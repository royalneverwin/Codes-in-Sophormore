#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define LIM 5010


/*
 * 种类并查集加unordered_map辅助离散化：
 * 将并查集分成两类，如果a和b在同一类中则表示二者之间是even：fa[a] = fa[b]((0, a), (0, b)奇偶性相同)，
 * 如果在不同类中则表示二者之间是odd: fa[a] = fa[b+LIM] || fa[a+LIM] = fa[b]((0, a), (0, b)奇偶性不同)
 *
 * unordered_map可直接将a和b转化成离散化后的index，因为本题不需要按照从小到大的顺序（只需要比较两个区间的边界是否相同）
*/


unordered_map<int, int> id;


int fa[2*LIM];
int oddeven[LIM];//记录每次回答的结果


int getf(int a) {
    if (a == fa[a]) {
        return a;
    } else {
        return (fa[a] = getf(fa[a]));
    }
}


bool merge(int a, int b){
    int pa = fa[a];
    int pb = fa[b];
    fa[pb] = pa;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n, sum;
    int tmp1, tmp2;
    string tmp;
    int index = 1;
    cin >> n >> sum;
    int i;
    for(i = 0; i < sum; i++){
        cin >> tmp1 >> tmp2 >> tmp;
        tmp1--; //这是这道题中特殊性，让左区间-1做到区间连续，便于并查集归并
        if(!id[tmp1]){
            id[tmp1] = index++;
            tmp1 = id[tmp1];
            fa[tmp1] = tmp1;
            fa[tmp1+LIM] = tmp1 + LIM;
        }
        else{
            tmp1 = id[tmp1];
        }
        if(!id[tmp2]){
            id[tmp2] = index++;
            tmp2 = id[tmp2];
            fa[tmp2] = tmp2;
            fa[tmp2+LIM] = tmp2 + LIM;
        }
        else{
            tmp2 = id[tmp2];
        }
        if(tmp == "even"){
            if(getf(tmp1) == getf(tmp2+LIM) || getf(tmp1+LIM) == getf(tmp2)){
                break;
            }
            else{
                merge(tmp1, tmp2);
                merge(tmp1+LIM, tmp2+LIM);
            }
        }
        else{
            if(getf(tmp1) == getf(tmp2)){
                break;
            }
            else{
                merge(tmp1, tmp2+LIM);
                merge(tmp2, tmp1+LIM);
            }
        }
    }
    cout << i << endl;
    return 0;
}