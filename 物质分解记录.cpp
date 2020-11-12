#include <iostream>
#include <stack>
#include <cstring>
using namespace std;


typedef struct TreeNode tnode;
struct TreeNode{
    char name[20];
    int if_Child;
    tnode *pChild;
    tnode *pSibling;
};
struct Tree{
    tnode *root;
};
struct Tree t = {NULL};


tnode *Check(tnode *root, char *line){
    tnode *temp = NULL;
    if(root){
        if(strcmp(root->name, line) == 0){
            return root;
        }
        temp = Check(root->pChild, line);
        if(temp == NULL){
            temp = Check(root->pSibling, line);
        }
    }
    return temp;
}


int main(){
    int n;
    int count;
    char line[20];
    tnode *temp = NULL;
    stack<tnode *> s;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        count = 0;
        while(count < 1){
            cin.getline(line, 20, '\n');
            if(strlen(line) == 0){
                count++;
            }
            else{
                if(line[0] == '!'){
                    return 0;
                }
                else if(line[0] == '{'){
                    temp = s.top();
                    temp->if_Child = 1;
                }
                else if(line[0] == '}'){
                    temp = s.top();
                    while(temp->if_Child == 0){
                        s.pop();
                        temp = s.top();
                    }
                    temp->if_Child = 0;
                }
                else{
                    tnode *node = new tnode;
                    node->pChild = NULL;
                    node->pSibling = NULL;
                    node->if_Child = 0;
                    sscanf(line, "%s", node->name);
                    if(!s.empty()) {
                        temp = s.top();
                        if (temp->if_Child == 0) {
                            temp->pSibling = node;
                        } else {
                            temp->pChild = node;
                        }
                    }
                    s.push(node);
                    if(t.root == NULL){
                        t.root = node;
                    }
                }
            }
        }
        while(!s.empty()){
            s.pop();
        }
        cin.getline(line, 20, '\n');
        temp = Check(t.root, line);
        if(!temp){
            cout << "No";
        }
        else {
            while (temp->pSibling) {
                temp = temp->pSibling;
                cout << temp->name;
            }
        }
        if(i != n) {
            cout << endl;
        }
        cin.ignore();
        cin.ignore();
        t.root = NULL;
    }
    return 0;
}
