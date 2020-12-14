#include <iostream>
#include <stack>
using namespace std;
int vec[1000001] = {0};
int min_window[1000001] = {0};
int max_window[1000001] = {0};
class stackQueue {//用栈模拟队列
public:
    stack<int> input;//输入栈
    stack<int> output;//输出栈
    stack<int> max_input;
    stack<int> max_output;//用来求队列最大值
    stack<int> min_input;
    stack<int> min_output;//用来求队列最小值
    void Push(const int item) {
        input.push(item);
        if (max_input.empty() || item >= max_input.top()) {
            max_input.push(item);
        } else {
            max_input.push(max_input.top());
        }
        if (min_input.empty() || item <= min_input.top()) {
            min_input.push(item);
        } else {
            min_input.push(min_input.top());
        }
    }

    void Pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                if (max_output.empty() || input.top() >= max_output.top()) {
                    max_output.push(input.top());
                } else {
                    max_output.push(max_output.top());
                }
                if (min_output.empty() || input.top() <= min_output.top()) {
                    min_output.push(input.top());
                } else {
                    min_output.push(min_output.top());
                }
                input.pop();
                max_input.pop();
                min_input.pop();
            }
        }
        output.pop();
        max_output.pop();
        min_output.pop();
    }
    int Max(){
        if(max_input.empty()){
            return max_output.top();
        }
        else if(max_output.empty()){
            return max_input.top();
        }
        else {
            if (max_input.top() > max_output.top()) {
                return max_input.top();
            } else {
                return max_output.top();
            }
        }
    }
    int Min(){
        if(min_input.empty()){
            return min_output.top();
        }
        else if(min_output.empty()){
            return min_input.top();
        }
        else {
            if (min_input.top() < min_output.top()) {
                return min_input.top();
            } else {
                return min_output.top();
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n, k;
    cin >> n >> k;
    int index = 0;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    stackQueue window;
    for(int i = 0; i < k; i++){
        window.Push(vec[i]);
    }
    max_window[index] = window.Max();
    min_window[index] = window.Min();
    index++;
    for(int i = k; i < n; i++){
        window.Pop();
        window.Push(vec[i]);
//        cout << window.min_input.top() << ' ' << window.min_output.top() << endl;
        max_window[index] = window.Max();
        min_window[index] = window.Min();
        index++;
    }
    for(int i = 0; i < n-k+1; i++){
        cout << min_window[i];
        if(i != n-k){
            cout << ' ';
        }
    }
    cout << endl;
    for(int i = 0; i < n-k+1; i++){
        cout << max_window[i];
        if(i != n-k){
            cout << ' ';
        }
    }
    return 0;
}