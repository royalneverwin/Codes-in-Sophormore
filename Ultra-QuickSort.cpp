#include <iostream>
using namespace std;
#define MAX 500001


long long countNum;


void Merge(long long num[], long long tmpNum[], int left, int middle, int right){//正常归并
    int i, index1, index2;
    index1 = left;
    index2 = middle+1;
    for(i = left; i <= right; i++){//数据存入临时数组
        tmpNum[i] = num[i];
    }
    i = left;
    while(index1 <= middle && index2 <= right){
        if(tmpNum[index1] <= tmpNum[index2]){
            num[i] = tmpNum[index1];
            index1++;
        }
        else{
            num[i] = tmpNum[index2];
            countNum += middle - index1+1;
            index2++;
        }
        i++;
    }
    /*处理多余值*/
    while(index1 <= middle){
        num[i] = tmpNum[index1];
        i++;
        index1++;
    }
    while(index2 <= right){
        num[i] = tmpNum[index2];
        i++;
        index2++;
    }
}


void MergeSort(long long num[], long long tmpNum[], int left, int right){//二路归并排序
    int middle;
    if(left < right){
        middle = (left + right)/2;
        MergeSort(num, tmpNum , left, middle);//左排序
        MergeSort(num, tmpNum, middle+1, right);//右排序
        Merge(num, tmpNum, left, middle, right);//合并
    }
}


int main(){
    long long tmpNum[MAX];
    long long num[MAX];
    int total;
    while(cin >> total){
        if(total == 0)
            return 0;
        countNum = 0;
        for(int i = 0; i < total; i++){//初始化数组
            cin >> num[i];
        }
        MergeSort(num, tmpNum, 0, total-1);//归并排序，同时算逆序数
        cout << countNum << endl;
    }
    return 0;
}