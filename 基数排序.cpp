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
const int RADIX = 10;
int len, arr[MAX], arr2[MAX], temp[MAX];
int sum[RADIX],
    rate[] = {
    1, 1, 10, 100, 1000, 10000,
    100000, 100000, 10000000, 100000000, 1000000000
};

void output(int *arr, int len) {
    cout << "--------------------";
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "------------------\n";
}
// 基数排序感觉像是在计数排序上的升级版本，通过根据位进行计数排序，使得对所有数据排序通用
void msdSort(int *arr, int st, int end, int d) { // 高位升序排序
    if(st >= end || d <= 0) return;
    for(int i = 0; i <= RADIX; ++i) sum[i] = 0;
    for(int i = st; i <= end; ++i) ++sum[(arr[i] / rate[d]) % 10];
    for(int i = 1; i < RADIX; ++i) sum[i] += sum[i - 1];
    for(int i = st; i <= end; ++i) { // 这边就类似计数排序的思想了, 相当于0 ~ 9的排序，只不过0 ~ 9有很多的重复
       temp[--sum[(arr[i] / rate[d]) % 10]] = arr[i];
    }
    for(int i = st; i <= end; ++i) arr[i] = temp[i]; // 将排序好的数组
    for(int i = 0; i < RADIX; ++i) {
        int left = st + sum[i]; // i桶左界限
        int right = st + sum[i+ 1] - 1; // i桶右界
        msdSort(arr, left, right, d - 1);
    }
}

void lsdSort(int *arr, int st, int end, int d) { // 低位升序排序
    for(int k = 1; k <= d; ++k) {
        for(int i = 0; i <= RADIX; ++i) sum[i] = 0;
        for(int i = st; i <= end; ++i) ++sum[(arr[i] / rate[k]) % 10];
        for(int i = 1; i < RADIX; ++i) sum[i] += sum[i - 1];
        for(int i = end; i >= st; --i) { // 必须从右往左边扫描,比如: 10 3 4进行十位排序时4需要放在3后面, 位值相同时需要保证上一步的顺序
            temp[--sum[(arr[i] / rate[k]) % 10]] = arr[i];
        }
        for(int i = st; i <= end; ++i) {
            arr[i] = temp[i];
        }
    }
}

int getDight(int val) {
    int h = 0;
    while(val) ++h, val /= 10;
    return h;
}

int main() {
    while(cin >> len) {
        int h = 0, max = 0;
        for(int i = 0; i < len; ++i) {
            cin >> arr[i];
            arr2[i] = arr[i];
            max = max > arr[i] ? max : arr[i];
        }
        h = getDight(max);
        msdSort(arr, 0, len - 1, h);
        output(arr, len);
        lsdSort(arr2, 0, len - 1, h);
        output(arr2, len);
    }
    return 0;
}
