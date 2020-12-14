#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct HuffmanNode{//Huffman树的节点
    int ele;
    int wei;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};


struct HuffmanTree{//Huffman树
    struct HuffmanNode *root;
};
struct HuffmanTree tree = {NULL};
vector<struct HuffmanNode *> heap;


int total = 0;


void PreOrder(struct HuffmanNode *root, int wei){//前序遍历，赋值Li
    if(root) {
        root->wei = wei;
        if(root->left == NULL && root->right == NULL){
            total += root->wei * root->ele;
        }
        PreOrder(root->left, wei+1);
        PreOrder(root->right, wei+1);
    }
}

void PreOrderPlus(struct HuffmanNode *root){
    if(root) {
        cout << root->ele << ' ' << root->wei << endl;
        PreOrderPlus(root->left);
        PreOrderPlus(root->right);
    }
}

void DeleteTree(struct HuffmanNode *root){
    if(root){
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}


bool operator < (const struct HuffmanNode node1, const struct HuffmanNode node2){
    if(node1.ele < node2.ele){
        return true;
    }
    else{
        return false;
    }
}


bool cmp(struct HuffmanNode *node1, struct HuffmanNode *node2){
    return node1->ele < node2->ele;
}


int main(){
    int t, n;
    struct HuffmanNode *temp1;
    struct HuffmanNode *temp2;
    cin >> t;
    for(int i = 1; i <= t; i++){
        total = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            struct HuffmanNode *node = new struct HuffmanNode;
            cin >> node->ele;
            node->wei = -1;
            node->left = NULL;
            node->right = NULL;
            heap.push_back(node);
        }
        sort(heap.begin(), heap.end(), cmp);
        while(heap.size() > 1){
            temp1 = heap[0];
            temp2 = heap[1];
            heap.erase(heap.begin());
            heap.erase(heap.begin());
            struct HuffmanNode *temp = new struct HuffmanNode;
            temp->ele = temp1->ele + temp2->ele;
            temp->wei = -1;
            temp->left = temp1;
            temp->right = temp2;
            heap.push_back(temp);
            sort(heap.begin(), heap.end(), cmp);
        }
        tree.root = heap[0];
        PreOrder(tree.root, 0);
        cout << total << endl;
        heap.clear();
    }
    return 0;
}