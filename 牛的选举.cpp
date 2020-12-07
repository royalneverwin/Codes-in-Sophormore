#include <iostream>
using namespace std;


class Cow{//牛的类
private:
    int A;//投票Ai
    int B;//投票Bi
    int index;//下标
public:
    Cow(int a, int b, int i):A(a),B(b),index(i){}//构造函数
    Cow(){
        A = B = index = 0;
    }
    /*两个友元函数用来比较*/
    friend bool operator < (const Cow& c1, const Cow& c2);
    friend ostream& operator << (ostream& os, const Cow& c);
};


int flag = 0;//判断比较类时用A还是用B


bool operator < (const Cow& c1, const Cow& c2){
    if(flag == 0) {//先比较A
        return c1.A < c2.A;
    }
    else{//再比较B
        return c1.B < c2.B;
    }
}

ostream& operator << (ostream& os, const Cow& c){
    os << c.index;
    return os;
}


void Sort(Cow *cow[], int n, int delta){//正常的插入排序
    Cow *temp;
    for(int i = delta; i < n; i += delta){
        for(int j = i; j >= delta; j -= delta){
            if(*(cow[j-delta]) < *(cow[j])){
                temp = cow[j-delta];
                cow[j-delta] = cow[j];
                cow[j] = temp;
            }
            else{
                break;
            }
        }
    }
}


void ShellSort(Cow *cow[], int N){//Shell排序
    for(int delta = N/2; delta > 0; delta /= 2){
        for(int i = 0; i < delta; i++){
            Sort(&cow[i], N-i, delta);
        }
    }
}


int main(){
    int N, K;
    int Ai, Bi;
    cin >> N >> K;
    Cow *cow[50001];
    for(int i = 0; i < N; i++){//初始化cow
        cin >> Ai >> Bi;
        cow[i] = new Cow(Ai, Bi, i+1);
    }
    ShellSort(cow, N);
    flag = 1;
    ShellSort(cow, K);
    cout << *(cow[0]);
    for(int i = 0; i < N; i++){
        free(cow[i]);
    }
    return 0;
}