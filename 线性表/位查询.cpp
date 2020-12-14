#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int M, N;
    int d;
    char func;
    int check;
    int sum;
    cin >> N >> M;
    int num[100001];
    for(size_t i = 0; i < N; i++){
        cin >> num[i];
    }
    for(size_t i = 0; i < M; i++){
        check = 0;
        sum = 0;
        cin >> func >> d;
        if(func == 'C'){
            for(size_t j = 0; j < N; j++){
                num[j] += d;
                num[j] %= 65536;
            }
        }
        else if(func == 'Q'){
            check += (int)pow(2, d);
            for(size_t j = 0; j < N; j++){
                if((num[j] & check) == check){
                    sum += 1;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}