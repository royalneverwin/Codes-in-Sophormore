#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct{
    char s[16];
    int length;
}Dic;

Dic dic[10001];
int like_index[10001];//记录相似的单词的下标
int cnt = 0;//记录词典中单词数量


void Compare(char *s){//拼写检查
    char tmp[16];
    int like_cnt = 0;
    for(int i = 0; i < cnt; i++){
        if(!strcmp(dic[i].s, s)){//找到一样的
            cout << s << " is correct" << endl;
            return;
        }
        else if(strlen(s) == dic[i].length){//可能相似情况1，替换
            for(int j = 0; j < dic[i].length; j++){
                if(dic[i].s[j] != s[j]){//找到第一个不一样的地方，替换，如果相同则相似
                    strcpy(tmp, dic[i].s);
                    tmp[j] = s[j];
                    if(!strcmp(tmp, s)){
                        like_index[like_cnt++] = i;
                    }
                    break;
                }
            }
        }
        else if(abs((int)strlen(s) - dic[i].length) == 1){//可能相似情况2，添加或删除
            int length;
            length = max((int)strlen(s), (int)dic[i].length);//注意这里要比较两个字符串直到更长的一个的末尾
            for(int j = 0; j < length; j++){
                if(dic[i].s[j] != s[j]){//找到第一个不一样的地方，分别判断多的单词删除和少的单词添加后，是否相同，如果相同则相似
                    if(strlen(s) > dic[i].length){//s更长
                        strcpy(tmp, s);
                        for(int k = j; k < strlen(s); k++){//删除
                            tmp[k] = tmp[k+1];
                        }
                        if(!strcmp(tmp, dic[i].s)){
                            like_index[like_cnt++] = i;
                            break;
                        }
                        strcpy(tmp, dic[i].s);
                        for(int k = dic[i].length+1; k > j; k--){//添加
                            tmp[k] = tmp[k-1];
                        }
                        tmp[j] = s[j];
                        if(!strcmp(tmp, s)){
                            like_index[like_cnt++] = i;
                        }
                        break;
                    }
                    else {//词典单词更长
                        strcpy(tmp, dic[i].s);
                        for(int k = j; k < dic[i].length; k++){//删除
                            tmp[k] = tmp[k+1];
                        }
                        if(!strcmp(tmp, s)){
                            like_index[like_cnt++] = i;
                            break;
                        }
                        strcpy(tmp, s);
                        for(int k = strlen(s)+1; k > j; k--){//添加
                            tmp[k] = tmp[k-1];
                        }
                        tmp[j] = dic[i].s[j];
                        if(!strcmp(tmp, dic[i].s)){
                            like_index[like_cnt++] = i;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << s << ":";
    for(int i = 0; i < like_cnt; i++){
        cout << " " << dic[like_index[i]].s;
    }
    cout << endl;
}
int main(){
    char tmp[16];
    while(true){
        scanf("%s", tmp);
        if(strcmp(tmp, "#")){
            strcpy(dic[cnt].s, tmp);
            dic[cnt++].length = strlen(tmp);
        }
        else{
            break;
        }
    }
    while(true){
        scanf("%s", tmp);
        if(strcmp(tmp, "#")){
            Compare(tmp);
        }
        else{
            break;
        }
    }
    return 0;
}

