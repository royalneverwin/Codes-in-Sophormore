#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct BinaryTreeNode TreeNode;
struct BinaryTreeNode{
    int info;
    TreeNode *left;
    TreeNode *right;
};
struct BinarySearchTree{
    TreeNode *root;
};
struct BinarySearchTree tree = {NULL};


queue<TreeNode *> q;


void BFS(){
    TreeNode *pointer = tree.root;
    if(pointer){
        q.push(pointer);
    }
    while(!q.empty()){
        pointer = q.front();
        q.pop();
        cout << pointer->info << ' ';
        if(pointer->left != NULL){
            q.push(pointer->left);
        }
        if(pointer->right != NULL){
            q.push(pointer->right);
        }
    }
}


void Insert(int info){
    TreeNode *temp = new TreeNode;
    TreeNode *current = tree.root;
    temp->info = info;
    temp->left = temp->right = NULL;
    if(current == NULL){
        tree.root = temp;
        return;
    }
    while(true){
        if(temp->info == current->info){
            return;
        }
        else if(temp->info < current->info){
            if(current->left == NULL){
                current->left = temp;
                return;
            }
            else{
                current = current->left;
            }
        }
        else{
            if(current->right == NULL){
                current->right = temp;
                return;
            }
            else{
                current = current->right;
            }
        }
    }
}



void Delete(TreeNode *root){
    if(root->left != NULL) {
        Delete(root->left);
    }
    if(root->right != NULL) {
        Delete(root->right);
    }
    delete root;
}
int main(){
    int num;
    while(cin >> num) {
        Insert(num);
    }
    BFS();
    Delete(tree.root);
    return 0;
}
