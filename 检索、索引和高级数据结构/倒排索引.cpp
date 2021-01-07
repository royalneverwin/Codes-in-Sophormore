#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string, int> charts[1001];



int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m ,n;
    int cnt;
    int flag;
    string s;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> cnt;
        for(int j = 0; j < cnt; j++){
            cin >> s;
            charts[i][s] = 1;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        flag = 0;
        for(int j = 0; j < m; j++){
            if(charts[j][s]){
                flag = 1;
                cout << j+1 << ' ';
            }
        }
        if(!flag){
            cout << "NOT FOUND";
        }
        cout << endl;
    }
    return 0;
}