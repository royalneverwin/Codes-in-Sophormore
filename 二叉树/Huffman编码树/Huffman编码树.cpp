#include <iostream>
using namespace std;

/*利用最小堆*/
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


struct minHeap{//最小堆
    struct HuffmanNode *node[200];
    int sum;
};
struct minHeap heap;


int total = 0;

/*SiftDown和SiftUp算法一定要注意，在循环时一直是用temp的值在比较大小，因为你并没有交换比较的两个值！你只是不断地将要交换的值填充到它上方的空白处，然后不断比较填充找到放置temp的新位置*/
void SiftDown(int pos){//向下筛查
    int i = pos;
    int minChild = 2*i+1;
    struct HuffmanNode *temp;
    temp = heap.node[i];
    while(minChild < heap.sum){
        if(minChild+1 < heap.sum && heap.node[minChild+1]->ele < heap.node[minChild]->ele){
            minChild += 1;
        }
        if(temp->ele > heap.node[minChild]->ele){
            heap.node[i] = heap.node[minChild];
            i = minChild;
            minChild = 2*i+1;
        }
        else{
            break;
        }
    }
    heap.node[i] = temp;
}


void SiftUp(int pos){//向上筛查
    int tempPos = pos;
    struct HuffmanNode *temp;
    temp = heap.node[tempPos];
    while(tempPos > 0 && heap.node[(tempPos-1)/2]->ele > temp->ele){
        heap.node[tempPos] = heap.node[(tempPos-1)/2];
        tempPos = (tempPos-1)/2;
    }
    heap.node[tempPos] = temp;
}


void CreateMinHeap(){//创造最小堆
    for(int i = heap.sum/2-1; i >=0; i--){
        SiftDown(i);
    }
}


struct HuffmanNode *RemoveMin(){//移除最小值
    struct HuffmanNode *temp = heap.node[0];
    heap.node[0] = heap.node[heap.sum-1];
    heap.sum -= 1;
    if(heap.sum > 1) {
        SiftDown(0);
    }
    return temp;
}


void InsertNode(struct HuffmanNode *newNode){//向堆中插入元素
    heap.node[heap.sum] = newNode;
    heap.sum += 1;
    SiftUp(heap.sum-1);
}


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
            heap.node[j] = node;
        }
        heap.sum = n;
        CreateMinHeap();
        while(heap.sum > 1){
            temp1 = RemoveMin();
            temp2 = RemoveMin();
            struct HuffmanNode *temp = new struct HuffmanNode;
            temp->ele = temp1->ele + temp2->ele;
            temp->wei = -1;
            temp->left = temp1;
            temp->right = temp2;
            tree.root = temp;
            InsertNode(temp);
        }
        tree.root = heap.node[0];
        PreOrder(tree.root, 0);
        cout << total << endl;
        DeleteTree(tree.root);
    }
    return 0;
}