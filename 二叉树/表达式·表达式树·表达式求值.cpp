#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;


typedef struct BinTreeNode TreeNode;
struct BinTreeNode{//二叉树节点
    char op;
    TreeNode *left;
    TreeNode *right;
    int x;
    int y;
};


struct BinTree{
    TreeNode *root;
};
struct BinTree tree = {NULL};//二叉树——链式


struct directory{
    char key;
    int ele;
};
struct directory dir[10];


stack<TreeNode *>charNumber;//构建二叉树用
stack<TreeNode *> oper;
stack<int> number;//计算表达式的值用


char treeGraph[201][201];//画出二叉树用的图，数组开大一点！！！！！！！
int xStop[201] = {0};//略去末行空格用，数组开大一点！！！！！！
int maxHeight = 0;//树高，总高度等于2*maxHeight-1


void BuildTree(){//建造二叉树——链式，同时计算表达式的值
    TreeNode *op;
    TreeNode *num1;
    TreeNode *num2;
    int op1, op2, sum;
    op = oper.top();
    oper.pop();
    num1 = charNumber.top();
    charNumber.pop();
    num2 = charNumber.top();
    charNumber.pop();
    op->left = num2;
    op->right = num1;
    charNumber.push(op);
//    tree.root = op;
    /*下面是计算表达式的值的步骤*/
    op1 = number.top();
    number.pop();
    op2 = number.top();
    number.pop();
    switch(op->op){
        case '+':
           sum = op2 + op1;
           break;
        case '-':
            sum = op2 - op1;
            break;
        case '*':
            sum = op2 * op1;
            break;
        case '/':
            sum = op2 / op1;
            break;
    }
    number.push(sum);
}


void PostOrder(TreeNode *pointer,int height){//后根遍历
    if(pointer){
        PostOrder(pointer->left, height+1);
        PostOrder(pointer->right, height+1);
        pointer->y = 2*height-1;
        cout << pointer->op;
        if(maxHeight < height){
            maxHeight = height;
        }
    }
}


void CreateTree(TreeNode *pointer,int start, int end) {//前序周游创造树图
    if (pointer->y == 2*maxHeight-1) {
        pointer->x = start;
        treeGraph[pointer->y][pointer->x] = pointer->op;
        xStop[pointer->y] = pointer->x;
    } else {
        pointer->x = (start + end) / 2;
        treeGraph[pointer->y][pointer->x] = pointer->op;
        xStop[pointer->y] = pointer->x;
        if (pointer->left != NULL) {
            treeGraph[pointer->y + 1][pointer->x - 1] = '/';
            treeGraph[pointer->y + 1][pointer->x + 1] = '\\';
            xStop[pointer->y + 1] = pointer->x + 1;
            CreateTree(pointer->left, start, pointer->x - 1);
            CreateTree(pointer->right, pointer->x + 1, end);
        }
    }
//    for(int i = 1; i < 2*maxHeight; i++){
//        for(int j = 1; j < xStop[i]+1; j++){
//            cout << treeGraph[i][j];
//        }
//        cout << endl;
//    }
}


int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dir[i].key >> dir[i].ele;
    }
    string::iterator pi = s.begin();
    while(pi != s.end()){//遍历中缀表达式
        TreeNode *node = new TreeNode;
        node->op = *pi;
        node->left = NULL;
        node->right = NULL;
        node->x = -1;
        node->y = -1;
        if(*pi >= 'a' && *pi <= 'z'){
            charNumber.push(node);
            for(int i = 1; i <= n; i++){
                if(dir[i].key == *pi){
                    number.push(dir[i].ele);
                    break;
                }
            }
        }
        else{
            if(oper.empty()){
                oper.push(node);
            }
            else{
                if(*pi == '('){
                    oper.push(node);
                }
                else if(*pi == ')'){
                    while((oper.top())->op != '('){
                        BuildTree();
                    }
                    oper.pop();
                }
                else if(*pi == '+' || *pi == '-'){
                    while(!oper.empty() && (oper.top())->op != '('){
                        BuildTree();
                    }
                    oper.push(node);
                }
                else{
                    while(!oper.empty() && ((oper.top())->op == '*' || (oper.top())->op == '/')){
                        BuildTree();
                    }
                    oper.push(node);
                }
            }
        }
        pi++;
    }
    while(!oper.empty()) {
        BuildTree();
    }
    while(!charNumber.empty()){
        tree.root = charNumber.top();
        charNumber.pop();
    }
    for(int i = 1; i < 201; i++){
        for(int j = 1; j < 201; j++){
            treeGraph[i][j] = ' ';
        }
    }
    PostOrder(tree.root, 1);
    cout << endl;
    int xMax = (int)pow(2, maxHeight-1);
    xMax = 2*xMax - 1;//最下面一行的长度
    CreateTree(tree.root, 1, xMax);
    for(int i = 1; i < 2*maxHeight; i++){
        for(int j = 1; j < xStop[i]+1; j++){
            cout << treeGraph[i][j];
        }
        cout << endl;
    }
    cout << number.top();
    return 0;
}