#include <iostream>
#include <string>
using namespace std;


string s;


int main() {
    int if_string = 0;
    int if_note = 0;
    string temp;
    while(getline(cin, temp, '\n') && temp != "wxhtxdi"){
        if(s.empty()){
            s = temp;
        }
        else{
            s += temp;
        }
        s += "\n";
    }
    string::iterator pi = s.begin();
    while(pi != s.end()){
        if(*pi == '"' && if_string == 0 && if_note == 0){
            if_string = 1;
        }
        else if(*pi == '"' && if_string == 1 && *(pi-1) != '\\' && if_note == 0){//注意else if一定要用！！！！不要那么自信
            if_string = 0;
        }
        if(*pi == '/' && *(pi+1) == '*' && if_string == 0){
            pi+=2;
            if_note = 1;
            continue;
        }
        if(*pi == '*' && *(pi+1) == '/' && if_string == 0 && if_note == 1){
            pi += 2;
            if_note = 0;
            continue;
        }
        if(if_note == 0){
            cout << *pi;
        }
        pi++;
    }
    return 0;
}