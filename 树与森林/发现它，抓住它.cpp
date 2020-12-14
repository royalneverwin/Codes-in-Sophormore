#include <iostream>
using namespace std;

/*并查集，参考网上的做法*/
/*首先每个元素自成一个集合。将知道相对关系的成员所在的集合合并成一个集合，这里就利用了并查集。*/
/*注意使用路径压缩，因此没必要保证i和father[i]的关系是否一定相同或者相异，只要保证father[i]的tag能影响i的tag*/
/*合并集合时改变father[i]的tag使之与新合并的集合调和，再利用GetFather改变所有父节点是father[i]的节点的tag*/
int father[100010];
int tag[100010];


int GetFather(int i){/*在find father的同时改变tag*/
    int temp;
    if(i != father[i]){
        temp = GetFather(father[i]);/*注意这里要先用GetFather，确保自己的父节点的tag已经是按照最早的节点改过的了*/
        tag[i] = (tag[i] + tag[father[i]]) % 2;/*father[i]的tag为1，就变i的tag，为0，就不变*/
        father[i] = temp;
    }
    return father[i];
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int T;
    int N, M;
    char sign;
    int num1, num2;
    int f1, f2;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> N >> M;
        for (int j = 1; j <= N; j++) {
            father[j] = j;
            tag[j] = 0;
        }
        for (int j = 1; j <= M; j++) {
            cin >> sign >> num1 >> num2;
            f1 = GetFather(num1);
            f2 = GetFather(num2);
            if(sign == 'D'){
                father[f1] = f2;
                tag[f1] = (tag[num1] - tag[num2] + 1) % 2;/*num1和num2tag相同，father[i]的tag为1，说明要变，不同father[i]的tag为0，说明不要变*/
            }
            else{
                if(f1 != f2){
                    cout << "Not sure yet." << endl;
                }
                else if(tag[num1] != tag[num2]){
                    cout << "In different gangs." << endl;
                }
                else{
                    cout << "In the same gang." << endl;
                }
            }
        }
    }
    return 0;
}