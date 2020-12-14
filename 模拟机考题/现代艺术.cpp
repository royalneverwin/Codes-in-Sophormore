#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


/*普通方法：模拟画图——result：超时

struct Paint{
    int color;//最终颜色
    int laser;//层数
};
struct Paint p[100001];//记录图画的颜色和出度


int N[100001];//记录图画


int color_start[100001] = {0};//记录该颜色的开始


int color_end[100001] = {0};//记录该颜色的结束


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> N[i];
        color_end[N[i]] = i;
        if(color_start[N[i]] == 0){
            color_start[N[i]] = i;
        }
        p[i].color = 0;
        p[i].laser = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = color_start[i]; j <= color_end[i]; j++){
            p[j].color = i;
            p[j].laser++;
        }
    }
    int maxLaser = 0;
    for(int i = 1; i <= n; i++){
        if(p[i].color != N[i]){
            cout << -1;
            return 0;
        }
        maxLaser = max(p[i].laser, maxLaser);
    }
    cout << maxLaser << endl;
    return 0;
}
*/


/*改进：利用栈*/
int N[100001];//记录图画


int color_start[100001] = {0};//记录该颜色的开始


int color_end[100001] = {0};//记录该颜色的结束


int start_color[100001] = {0};//该点是否是某个颜色的开始点，如果是是哪个颜色


int end_color[100001] = {0};//该点是否是某个颜色的结束点，如果是是哪个颜色


stack<int> s;


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n;
    size_t maxLaser = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){//i代表点
        cin >> N[i];
        color_end[N[i]] = i;
        if(color_start[N[i]] == 0){
            color_start[N[i]] = i;
        }
    }
    for(int i = 1; i <= n; i++){//i代表颜色
        if(color_start[i] != 0){
            start_color[color_start[i]] = i;
        }
        if(color_end[i] != 0){
            end_color[color_end[i]] = i;
        }
    }
    for(int i = 1; i <= n; i++){//i代表点
        if(start_color[i] != 0){//遇到了某个颜色的开头，该颜色入栈
            s.push(start_color[i]);
            maxLaser = max(maxLaser, s.size());
        }
        if(!s.empty() && s.top() != N[i]){//注意开头可能有未涂色，所以要先判断栈是否为空，否则N[i]的颜色应该始终与栈顶颜色相同
            cout << -1 << endl;
            return 0;
        }
        if(end_color[i] != 0){//遇到了某个颜色的结尾，栈顶颜色出栈
            s.pop();
        }
    }
    cout << maxLaser << endl;
    return 0;
}