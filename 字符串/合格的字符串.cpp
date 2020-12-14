#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    int pos1;
    int pos2;
    int flag;
    int count;
    string::iterator p1, p2;
    cin >> n;
    string s[51];
    string st;
    string st_core;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cin >> st;
    pos1 = st.find('[');
    pos2 = st.find(']');
    st_core =  st.substr(pos1+1, pos2-pos1-1);
    for(int i = 0; i < n; i++){
        flag = 1;
        count = 0;
        p1 = s[i].begin();
        p2 = st.begin();
        while(count < pos1){
            if(*p2 >= '0' && *p2 <= '9'){
                if(*p2 != *p1){
                    flag = 0;
                    break;
                }
            }
            else if(*p2 >= 'a' && *p2 <= 'z'){
                if(*p1 != *p2 && (*p1+32) != *p2){
                    flag = 0;
                    break;
                }
            }
            else{
                if(*p1 != *p2 && (*p1-32) != *p2){
                    flag = 0;
                    break;
                }
            }
            p1++;
            p2++;
            count++;
        }
        if(!flag){
            continue;
        }
        if(*p1 >= '0' && *p1 <= '9' && st_core.find(*p1) == string::npos){
            flag = 0;
        }
        else if(*p1 >= 'a' && *p1 <= 'z' && st_core.find(*p1) == string::npos && st_core.find(*p1-32) == string::npos) {
            flag = 0;
        }
        else if(*p1 >= 'A' && *p1 <= 'Z' && st_core.find(*p1) == string::npos && st_core.find(*p1+32) == string::npos) {
            flag = 0;
        }
        if(!flag){
            continue;
        }
        p1++;
        p2 = st.begin() + pos2 + 1;
        while(p1 != s[i].end() && p2 != st.end()){
            if(*p2 >= 0 && *p2 <= 9){
                if(*p2 != *p1){
                    flag = 0;
                    break;
                }
            }
            else if(*p2 >= 'a' && *p2 <= 'z'){
                if(*p1 != *p2 && (*p1+32) != *p2){
                    flag = 0;
                    break;
                }
            }
            else{
                if(*p1 != *p2 && (*p1-32) != *p2){
                    flag = 0;
                    break;
                }
            }
            p1++;
            p2++;
        }
        if(p1 != s[i].end() || p2 != st.end()){
            flag = 0;
        }
        if(!flag){
            continue;
        }
        cout << i+1 << ' ' << s[i] << endl;
    }
    return 0;
}
