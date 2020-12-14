#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct MinHeap{
    int num[100002];
    int size;
};


struct MinHeap heap;


void SiftUp(int pos){
    int temppos = pos;
    int temp = heap.num[pos];
    while(temppos > 0){
        if(heap.num[(temppos-1)/2] > temp){
            heap.num[temppos] = heap.num[(temppos-1)/2];
            temppos = (temppos-1)/2;
        }
        else{
            break;
        }
    }
    heap.num[temppos] = temp;
}


void SiftDown(int pos){
    int temppos = pos;
    int tempchild = 2*temppos+1;
    int temp = heap.num[pos];
    while(tempchild < heap.size){
        if(tempchild+1 < heap.size){
            if(heap.num[tempchild+1] < heap.num[tempchild]){
                tempchild++;
            }
        }
        if(heap.num[tempchild] < temp){
            heap.num[temppos] = heap.num[tempchild];
            temppos = tempchild;tempchild = 2*temppos+1;
        }
        else{
            break;
        }
    }
    heap.num[temppos] = temp;
}


int main(){
    int t;
    scanf("%d", &t);
    int n;
    int type;
    int num;
    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        heap.size = 0;
        for(int j = 1; j <= n; j++){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d", &num);
                heap.num[heap.size] = num;
                SiftUp(heap.size);
                heap.size++;
            }
            else{
                cout << heap.num[0] << endl;
                heap.num[0] = heap.num[heap.size-1];
                heap.size--;
                SiftDown(0);
            }
        }
    }
    return 0;
}
