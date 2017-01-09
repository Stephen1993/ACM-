#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 999999999
using namespace std;

const int MAX = 10000;
int len, s[MAX], temp[MAX];
/*
 * 思路: 由于有一个数多余数组的一半，所以必有abacadae...或者aa..ba..ca..d这种情况，
 * 则只需要建立两个指针i,j对比s[i]和s[j], 如果s[i] != s[j], 则将两个数置空，如果s[i] == s[j]则j指针后移
 * 最后剩下没有置空的数一定是多余一半数组的数
 */
// 数据: 1 1 2 2 3 5 6 3 2 2, 对于不存在的会出错，这组数据会出现2，但是2不是多于数组一半, 所以需要一个辅助数组判断（暂时没想到如何原地判断）
int search(int *s, int len) {
    int i = 0, j = 1;
    while(i < len && j < len) {
        while(s[i] == s[j] && j < len) ++j;
        if(j < len) {
            s[i] = -INF; // 其他语言可以直接置为null, 这里用-INF表示置为null
            s[j] = -INF; // 其他语言可以直接置为null, 这里用-INF表示置为null
        }
        ++i;
        ++j;
        while(i < len && s[i] == -INF) ++i;
        while(j < len && j <= i && s[j] == -INF) ++j;
    }
    int num = -INF;
    for(int k = 0; k < len; ++k) {
        if(s[k] != -INF) {
            num = s[k];
            break;
        }
    }
    int sum = 0;
    for(int k = 0; k < len; ++k) {
        if(temp[k] == num) ++sum;
    }
    if(sum < (len + 1) / 2) num = -INF;
    return num;
}

int main() {
    while(cin >> len) {
        for(int i = 0; i < len; ++i) {
            cin >> s[i];
            temp[i] = s[i];
        }
        cout << search(s, len) << endl;
    }
    return 0;
}
