#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;


void Create_Expr(stack<char> &op, char c, string &expr2){
    if(c == '('){
        op.push(c);
    }
    else if(c == ')'){
        while(op.top() != '('){
            expr2.append(1, ' ');
            expr2.append(1, op.top());
            op.pop();
        }
        op.pop();
    }
    else if(c == '+' || c == '-'){
        while(!op.empty() && op.top() != '('){
            expr2.append(1, ' ');
            expr2.append(1, op.top());
            op.pop();
        }
        op.push(c);
    }
    else if(c == '*' || c == '/'){
        while(!op.empty() && (op.top() == '*' || op.top() == '/')){
            expr2.append(1, ' ');
            expr2.append(1, op.top());
            op.pop();
        }
        op.push(c);
    }
}


void Cal(stack<int> &number, char c){
    int r, l,re;
    r = number.top();
    number.pop();
    l = number.top();
    number.pop();
    switch(c){
        case '+':
            re = l + r;
            break;
        case '-':
            re = l - r;
            break;
        case '*':
            re = l * r;
            break;
        case '/':
            re = l / r;
            break;
        default:break;
    }
    number.push(re);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int N;
    char c;
    int num;
    stack<char> op;
    stack<int> number;
    string expr1;
    string expr2;
    string OP = "+-*/()";
    string OP1 = "+-*/";
    string::iterator p;
    istringstream * sin;//把sin改成指针，每次初始化之后delete，可以节省空间，避免每次都要重新初始化一个输入流对象
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> expr1;
        p = expr1.begin();
        for(;p != expr1.end(); p++){
            if(OP.find(*p) != string::npos){
                expr2.append(1, ' ');
                Create_Expr(op, *p, expr2);
            }
            else{
                expr2.append(1, *p);
            }
        }
        while(!op.empty()){
            expr2.append(1, ' ');
            expr2.append(1, op.top());
            op.pop();
        }
        sin = new istringstream(expr2);//sstream流的用法我一直一知半解，唉。。。
        while(*sin >> c){
            if(OP1.find(c) != string::npos){
                Cal(number, c);
            }
            else{
                (*sin).putback(c);
                *sin >> num;
                number.push(num);
            }
        }
        cout << number.top() <<endl;
        expr1.clear();
        expr2.clear();
        number.pop();
        delete sin;
    }
    return 0;
}
//内存申请和释放比较耗时，可以把所有字符串放在一个大字符串中进行处理，不同字符串之间用特定符号间隔，只用一个sin就可完成
//算法还不完善，默认表达式合法，未考虑到表达式不成立的时候的情况，待完善。