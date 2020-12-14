#include <iostream>
#include <cstring>
using namespace std;


struct Strings{
    char *string;
    int w;
};


int BubbleSort(char *string, int n){//利用冒泡排序计算逆序数
    int countNum = 0;
    bool noSwap;
    char tmp;
    for(int i = 1; i < n; i++){
        noSwap = true;
        for(int j = n-1; j >= i; j--){
            if(string[j] < string[j-1]){
                tmp = string[j];
                string[j] = string[j-1];
                string[j-1] = tmp;
                countNum++;
                noSwap = false;
            }
        }
        if(noSwap){
            return countNum;
        }
    }
    return countNum;
}


void Merge(struct Strings* strings, struct Strings* tmpStrings, int left, int middle, int right){//正常归并
    int i, index1, index2;
    index1 = left;
    index2 = middle+1;
    for(i = left; i <= right; i++){//数据存入临时数组
        tmpStrings[i].w = strings[i].w;
        strcpy(tmpStrings[i].string, strings[i].string);
    }
    i = left;
    while(index1 <= middle && index2 <= right){
        if(tmpStrings[index1].w <= tmpStrings[index2].w){
            strings[i].w = tmpStrings[index1].w;
            strcpy(strings[i].string, tmpStrings[index1].string);
            index1++;
        }
        else{
            strings[i].w = tmpStrings[index2].w;
            strcpy(strings[i].string, tmpStrings[index2].string);
            index2++;
        }
        i++;
    }
    /*处理多余值*/
    while(index1 <= middle){
        strings[i].w = tmpStrings[index1].w;
        strcpy(strings[i].string, tmpStrings[index1].string);
        i++;
        index1++;
    }
    while(index2 <= right){
        strings[i].w = tmpStrings[index2].w;
        strcpy(strings[i].string, tmpStrings[index2].string);
        i++;
        index2++;
    }
}


void MergeSort(struct Strings* strings, struct Strings* tmpStrings, int left, int right){//空间复杂度为O(1)的二路归并排序
    int middle;
    if(left < right){
        middle = (left + right)/2;
        MergeSort(strings, tmpStrings, left, middle);//左排序
        MergeSort(strings, tmpStrings, middle+1, right);//右排序
        Merge(strings, tmpStrings, left, middle, right);//合并
    }
}


int main(){
    int n, m;
    char tmp[60];
    struct Strings strings[101];
    struct Strings tmpStrings[101];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        strings[i].string = new char[60];
        tmpStrings[i].string = new char[60];
        cin >> strings[i].string;
        strcpy(tmp, strings[i].string);
        strings[i].w = BubbleSort(tmp, n);
    }
    MergeSort(strings, tmpStrings, 0, m-1);
    for(int i = 0; i < m; i++){
        cout << strings[i].string << endl;
    }
    for(int i = 0; i < m; i++){
        free(strings[i].string);
        free(tmpStrings[i].string);
    }
    return 0;
}

