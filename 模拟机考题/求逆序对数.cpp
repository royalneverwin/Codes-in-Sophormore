#include <iostream>
#include <algorithm>
using namespace std;


/*和Ultra-QuickSort一样，用归并排序求逆序数*/
int count_ni;
void Merge(int Array[], int tmpArray[], int left, int middle, int right){
    int i;
    int index1, index2;
    for(i = left; i <= right; i++){
        tmpArray[i] = Array[i];
    }
    index1 = left;
    index2 = middle+1;
    i = left;
    while(index1 <= middle && index2 <= right){
        if(tmpArray[index1] <= tmpArray[index2]){
            Array[i++] = tmpArray[index1++];
        }
        else{
            Array[i++] = tmpArray[index2++];
            /*注意这里是加middle-index1+1，因为这是tmpArray[index2]向前移动的个数*/
            count_ni += middle - index1 + 1;
        }
    }
    while(index1 <= middle){
        Array[i++] = tmpArray[index1++];
    }
    while(index2 <= right){
        Array[i++] = tmpArray[index2++];
    }
}


void MergeSort(int Array[], int tmpArray[], int left, int right){
    int middle;
    if(left < right){
        middle = (left+right)/2;
        MergeSort(Array, tmpArray, left, middle);
        MergeSort(Array, tmpArray, middle+1, right);
        Merge(Array, tmpArray, left, middle, right);
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);//加速C++输入输出流
    int n;
    int Array[20010];
    int tmpArray[20010];
    cin >> n;
    while(n != 0){
        count_ni = 0;
        for(int i = 0; i < n; i++){
            cin >> Array[i];
        }
        MergeSort(Array, tmpArray, 0, n-1);
        cout << count_ni << endl;
        cin >> n;
    }
    return 0;
}