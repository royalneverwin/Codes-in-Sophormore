#include <iostream>
#include <unordered_map>
using namespace std;

/*简单的并查集问题*/


int f[50010];


int getf(int a){
    if(a == f[a]){
        return a;
    }
    else{
        return (f[a] = getf(f[a]));
    }
}


int merge(int a, int b){
    int pa = getf(a);
    int pb = getf(b);
    f[pa] = pb;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    int a, b;
    int count;
    int countCase = 1;
    cin >> n >> m;
    while(n && m){
        count = 0;
        for(int i = 1; i <= n; i++){
            f[i] = i;
        }
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            merge(a, b);
        }
        unordered_map<int, int> mmap;
        for(int i = 1; i <= n; i++){
            if(!mmap[getf(i)]){
                mmap[f[i]] = 1;
                count++;
            }
        }
        cout << "Case " << countCase << ": " << count << endl;
        countCase++;
        cin >> n >> m;
    }
    return 0;
}