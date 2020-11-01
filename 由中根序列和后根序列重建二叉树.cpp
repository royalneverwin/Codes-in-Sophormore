#include <iostream>
#include <cstdio>
using namespace std;


int num[2000];
int inOrder[1000];
int postOrder[1000];

typedef struct BeenTreeNode treeNode;
struct BeenTreeNode{
    int ele;
    treeNode *left;
    treeNode *right;
};


struct PTree{
    treeNode *root;
};
struct PTree tree = {NULL};


treeNode *CreateTree(int inStart, int inEnd, int postStart, int postEnd){
    int val = postOrder[postEnd];
    int locat = inStart;
    while(inOrder[locat] != val){
        locat++;
    }
    treeNode *node = new treeNode;
    node->ele = val;
    if(locat == inStart){
        node->left = NULL;
    }
    else{
        node->left = CreateTree(inStart, locat-1, postStart, postStart+(locat-1-inStart));
    }
    if(locat == inEnd){
        node->right = NULL;
    }
    else{
        node->right = CreateTree(locat+1, inEnd, postEnd+locat-inEnd,postEnd-1);
    }
    return node;
}

void PreOrder(treeNode *root){
    if(root){
        cout << root->ele << ' ';
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int main(){
    int count = 0;
    while(cin >> num[count]){
        count ++;
    }
    count /= 2;
    for(int i = 0; i < count; i++){
        inOrder[i] = num[i];
    }
    for(int i = count; i < 2*count; i++){
        postOrder[i-count] = num[i];
    }
    tree.root = CreateTree(0, count-1, 0, count-1);
    PreOrder(tree.root);
    return 0;
}