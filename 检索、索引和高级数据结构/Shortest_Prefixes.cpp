#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

/*Trial 树*/
struct Node{
    char c;
    struct Node *pNode[30];
    int cnt = 0;
};


struct Node *tree;


void Insert(char *word){//向Trial 树中插入字符串
    int length = strlen(word);
    struct Node *p = tree;
    for(int i = 0; i < length; i++){
        if(p->pNode[word[i]-'a'] == NULL){
            struct Node *tmp;
            tmp = new struct Node;
            tmp->c = word[i];
            for(int j = 0; j < 30; j++){
                tmp->pNode[j] = NULL;
            }
            tmp->cnt = 1;
            p->pNode[word[i]-'a'] = tmp;
            p = tmp;
        }
        else{
            p = p->pNode[word[i]-'a'];
            p->cnt++;
        }
    }
}


void Prefix(char *word){//输出Trial 树的Prefix
    int length = strlen(word);
    struct Node *p = tree;
    for(int i = 0; i < length; i++){
        p = p->pNode[word[i] - 'a'];
        cout << p->c;
        if(p->cnt == 1){//如果p->cnt == 1，则到此为止就可以成为该字符串的前缀了
            return;
        }
    }
}
int main(){
    tree = new struct Node;
    tree->c = 0;
    for(int i = 0; i < 30; i++){
        tree->pNode[i] = NULL;
    }
    tree->cnt = -1;
    char word[1010][30];
    int cnt = 0;
    while(~scanf("%s", word[cnt])){//注意EOF是-1！
        Insert(word[cnt++]);
    }
    for(int i = 0; i < cnt; i++){
        cout << word[i] << ' ';
        Prefix(word[i]);
        cout << endl;
    }
    return 0;
}