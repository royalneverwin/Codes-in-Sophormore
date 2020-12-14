#include <iostream>
#include <string>
using namespace std;

string s1, s2;




int max(int a, int b){
    return (a > b) ? a : b;
}

//状态：s1的前i个字符和s2的前j个字符的最长公共子序列长度为maxlength[i][j]
int main(){
    int maxlength[1000][1000];//row表示s1字符串长度，col表示s2字符串长度
    int length1;
    int length2;
    int row, col;
    while(cin >> s1 >> s2) {
        length1 = s1.length();
        length2 = s2.length();
        for (int i = 0; i <= length1; i++) {
            maxlength[i][0] = 0;
        }
        for (int j = 0; j <= length2; j++) {
            maxlength[0][j] = 0;
        }
        for (row = 1; row <= length1; row++) {
            for (col = 1; col <= length2; col++) {
                if (s1[row-1] == s2[col-1]) {
                    maxlength[row][col] = maxlength[row - 1][col - 1] + 1;
                } else {
                    maxlength[row][col] = max(maxlength[row - 1][col], maxlength[row][col - 1]);
                }
            }
        }
        cout << maxlength[length1][length2] << endl;
    }
    return 0;
}
