#include <iostream>
#include <map>
using namespace std;
typedef map<int, int, greater<int>> intmap;
int main(){
    intmap Monomial;
    int n;
    int c, e;
    pair<intmap::iterator, bool>  pi;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> e;
        while(e >= 0){
            pi = Monomial.insert(intmap::value_type(e, c));
            if(!pi.second){
                pi.first->second += c;
            }
            cin >> c >> e;
        }
        cin >> c >> e;
        while(e >= 0){
            pi = Monomial.insert(intmap::value_type(e, c));
            if(!pi.second){
                pi.first->second += c;
            }
            cin >> c >> e;
        }
        intmap::iterator mi = Monomial.begin();
        for(; mi != Monomial.end(); mi++){
            if(mi->second != 0){
                cout << "[ " << mi->second << ' ' << mi->first << " ] ";
            }
        }
        cout << '\n';
        Monomial.clear();
    }
    return 0;
}
