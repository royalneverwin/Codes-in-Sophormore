#include <iostream>
#include <string>
#include <stack>
using namespace std;


typedef struct TreeNode tnode;
struct TreeNode{
    int index;
    int height;
    int if_Child;
    tnode *pChild;
    tnode *pSibling;
};
struct Tree{
    tnode *root;
};
struct Tree t = {NULL};


string DFS;


stack<tnode *> s;
int h1, h2;


/*如此构造的树可被同步视为等价二叉树，直接用就行*/
void CreateTree(){
    /*初始建一个根节点，读到d就创建一个根节点的子女节点，用if_Child判断是连接到根节点的Child上还是其子女的Sibling上。
     读到u就弹出设为temp，作为下次使用。*/
    tnode *temp1 = NULL;
    tnode *temp2 = NULL;
    int index = 0;
    tnode *node = new tnode;
    node->index = index;
    node->height = -1;
    index++;
    node->pSibling = NULL;
    node->pChild = NULL;
    node->if_Child = 0;
    s.push(node);
    t.root = node;
    for(int i = 0; i < DFS.length(); i++){
        if(DFS[i] == 'd'){
            tnode *node1 = new tnode;
            node1->index = index;
            node1->height = -1;
            index++;
            node1->pSibling = NULL;
            node1->pChild = NULL;
            node1->if_Child = 0;
            temp1 = s.top();
            if(temp1->if_Child == 0){
                temp1->pChild = node1;
                temp1->if_Child = 1;
            }
            else{
                temp2->pSibling = node1;
            }
            s.push(node1);
        }
        else if(DFS[i] == 'u'){
            temp2 = s.top();
            s.pop();
        }
    }
}


void DeleteTree(tnode *root){
    if(root){
        DeleteTree(root->pChild);
        DeleteTree(root->pSibling);
        delete root;
    }
}


void CountH1(tnode *root, int height){//PreOrder
    if(root){
        if(h1 < height){
            h1 = height;
        }
        root->height = height;
        CountH1(root->pChild, height+1);
        CountH1(root->pSibling, height);
    }
}


void CountH2(tnode *root, int height){//PreOrder
    if(root){
        if(h2 < height){
            h2 = height;
        }
        root->height = height;
        CountH2(root->pChild, height+1);
        CountH2(root->pSibling, height+1);
    }
}


int main(){
    cin >> DFS;
    tnode *temp;
    int countTree = 1;
    while(DFS[0] != '#'){
        CreateTree();
        h1 = h2 = 0;
        temp = t.root;
        CountH1(temp, 0);
        CountH2(temp, 0);
        cout << "Tree " << countTree << ": " << h1 << " => " << h2 << endl;
        DeleteTree(t.root);
        countTree++;
        cin >> DFS;
    }
}