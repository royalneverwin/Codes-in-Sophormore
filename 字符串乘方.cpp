#include <iostream>
#include <string>
using namespace std;


string s;



int main(){
    int time;
    string a;
    string temp;
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    cin >> s;
    string::iterator pi = s.begin();
    while(*pi != '.'){
        if(s.empty()){
            cout << 0;
            continue;
        }
        a = "";
        a.append(1, *pi);
        while(true) {
            while (s.length() % a.length() != 0) {
                pi++;
                a.append(1, *pi);
            }
            temp = "";
            time = s.length() / a.length();
            for(int i = 0; i < time; i++){
                temp.append(a);
            }
            if (temp == s) {
                cout << time << endl;
                break;
            }
            pi++;
            a.append(1, *pi);
        }
        cin >> s;
        pi = s.begin();
    }
    return 0;
}