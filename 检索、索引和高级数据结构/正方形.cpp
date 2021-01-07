#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


/*
 * 给定正方形两个点，就一定能算出来另外两个点，因此只需要枚举点A，B，再用hash查找点C，D是否存在即可
 * 注意最后应该除以4，因为一个正方形有4条边，所以一个正方形被算了4遍
 */


struct Point{
    int x;
    int y;
};


bool operator == (const struct Point &p1, const struct Point &p2){
    return (p1.x == p2.x) && (p1.y == p2.y);
}

unordered_map<int, vector<struct Point>> dic;


struct Point allPoint[1001];

void Insert_p(const struct Point &point){
    int key = point.x * point.x + point.y * point.y;
    if(dic.find(key) == dic.end()){
        dic[key] = vector<struct Point>();
    }
    dic[key].push_back(point);
}


int Find_p(const struct Point &point){
    int key = point.x * point.x + point.y * point.y;

    if(dic.find(key) == dic.end()){
        return 0;
    }
    else{
        for(auto i = dic[key].begin(); i < dic[key].end(); i++){
            if((*i) == point){
                return 1;
            }
        }
        return 0;
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    int cnt;
    struct Point tmp1;
    struct Point tmp2;
    int dx, dy;
    cin >> n;
    while(n){
        dic.clear();//initiate
        cnt = 0;//initiate
        for(int i = 0; i < n; i++){
            cin >> allPoint[i].x;
            cin >> allPoint[i].y;
            Insert_p(allPoint[i]);
        }
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                dx = allPoint[i].x - allPoint[j].x;
                dy = allPoint[i].y - allPoint[j].y;
                /*One way*/
                tmp1.x = allPoint[i].x + dy;
                tmp1.y = allPoint[i].y - dx;
                tmp2.x = allPoint[j].x + dy;
                tmp2.y = allPoint[j].y - dx;
                cnt += Find_p(tmp1) && Find_p(tmp2);
                /*Another way*/
                tmp1.x = allPoint[i].x - dy;
                tmp1.y = allPoint[i].y + dx;
                tmp2.x = allPoint[j].x - dy;
                tmp2.y = allPoint[j].y + dx;
                cnt += Find_p(tmp1) && Find_p(tmp2);
            }
        }
        cout << cnt/4 << endl;
        cin >> n;
    }
    return 0;
}