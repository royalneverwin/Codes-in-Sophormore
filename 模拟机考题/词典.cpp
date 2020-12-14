#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


map<string, string> dictionary;//用map实现即可


int main(){
    char line[30];//读取一行
    char first[12];//关键字 也就是外文单词
    char second[12];//内容，也就是英语单词
    string s1, s2, s3;
    map<string, string>::iterator pi;
    fgets(line, 30, stdin);//直接读一行
    while(line[0] != '\n'){
        int blank_pos;
        for(blank_pos = 0; blank_pos < strlen(line); blank_pos++){//找到空格的index
            if(line[blank_pos] == ' '){
                break;
            }
        }
        line[strlen(line)-1] = '\0';//把'\n'换成'\0'
        line[blank_pos] = '\0';//把空格换成'\0'
        strcpy(second, line);
        strcpy(first, line+blank_pos+1);
        s1 = first;
        s2 = second;
        dictionary.insert(pair<string, string>(s1, s2));
//        dictionary.insert(map<string ,string>::value_type(s1, s2));
        fgets(line, 30, stdin);
    }
    while(scanf("%s", line) != EOF){
        s3 = line;
        if((pi = dictionary.find(s3)) == dictionary.end()){//find查找
            printf("eh\n");
        }
        else{
            printf("%s\n", (pi->second).c_str());
        }
    }
    return 0;
}