#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
bool is_right(int begin, int end, int last, vector<int> num){//从begin到end的序列元素，last是出栈的最后一个元素，num存放了出栈元素序列
    if(begin == end){//就1个数，一定成立
        return true;
    }
    else {
        if (last == begin) {//最后一个出栈元素是begin或end，移除判断剩下的
            num.erase(num.end() - 1);
            return is_right(begin + 1, end, num[num.size() - 1], num);
        } else if (last == end) {
            num.erase(num.end() - 1);
            return is_right(begin, end - 1, num[num.size() - 1], num);
        } else {//判断last前的元素是不是都在last后的元素前出栈了
            int flag = 1;
            for(int i = begin; i < last; i++){
                if(find(num.begin(), num.begin()+last-begin, i) == (num.begin()+last-begin)){
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                return false;
            }
            else{//再判断last前的元素是否符合规则，last后的元素是否符合规则
                vector<int> num1(num.begin(), num.begin()+last-begin);
                vector<int> num2(num.begin()+last-begin, num.end()-1);
                return is_right(begin, last-1, num1[num1.size()-1], num1) && is_right(last+1, end, num2[num2.size()-1], num2);
            }
        }
    }
}
int main(){
    int n;
    int m;
    stack<int> s;
    vector<int> num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        num.push_back(m);
    }
    for(int i = 0; i < n; i++){
        if(num[i] < 1 || num[i] > n) {
            cout << "NO";
            return 0;
        }
    }
    if(is_right(1, n, num[num.size() - 1], num)){
        int instack = 1;
        for(int i = 0; i < n; i++){
            if(s.empty()){
                s.push(instack);
                cout << "PUSH " << instack << endl;
                instack++;
            }
            if(s.top() < num[i]){
                while(s.top() < num[i]) {
                    s.push(instack);
                    cout << "PUSH " << instack << endl;
                    instack++;
                }
                cout << "POP " << s.top() << endl;
                s.pop();
            }
            else if(s.top() == num[i]){
                cout << "POP " << s.top() << endl;
                s.pop();
            }
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}