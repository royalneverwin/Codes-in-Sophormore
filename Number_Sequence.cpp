#include <iostream>
#include <string>
#include <sstream>
#define MAX 50000
using namespace std;
void  Create_Sequence(string & str, int n){ //创建Sn用
    stringstream sstream;
    string temp;
    for (int j = 1; j <= n; j++){
//        sstream << j;
//        sstream >> temp;
//        sstream.clear();
//        sstream.str("");
//        str.append(temp);
//        temp.clear();
        str += to_string(j); //用to_string()函数
    }
}
int main(){
    int t;
    int i;
    int i_left;
    int kmax;
    cin >> t;
    string str;
    int S[MAX+1]; //记录Sn字符数
    for(int j = 1; j <= MAX; j++){
        if(j == 1){
            S[j] = 1;
        }
        else{
            S[j] = S[j-1] + to_string(j).length();
        }
    }
    for(int j = 0; j < t; j++){
        cin >> i;
        for(int k = 1; k <= MAX; k++){
            if(i > S[k]){
                i -= S[k];
            }
            else{
                kmax = k;
                break;
            }
        }
        Create_Sequence(str, kmax);
        cout << str[i - 1] << endl;
        str.clear();
    }
    return 0;
}
//如果像这种题，求S1到Sn之和再和i比较会太大的话，就直接用i减S1到Sn，减到i为0或负，就能知道S1到Sn之和小于i的最大的n是多少了。