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
int len, arr[MAX];

void heapAdjust (int *arr, int st, int end) {
    int tmp;
    while(st * 2 + 1 <= end) { // 更新最大堆，进行升序排序, 本次循环最坏情况log(end-st)次
        tmp = st;
        if(arr[tmp] < arr[st * 2 + 1]) {
            tmp = st * 2 + 1;
        }
        if(st * 2 + 2 <= end && arr[tmp] < arr[st * 2 + 2]) {
            tmp = st * 2 + 2;
        }
        if(st == tmp) { // 不需要交换节点，则无需更新该节点下的子堆
            break;
        }
        arr[st] = arr[st] ^ arr[tmp];
        arr[tmp] = arr[st] ^ arr[tmp];
        arr[st] = arr[st] ^ arr[tmp];
        st = tmp;
    }
}

void output(int *arr, int len) {
    cout << "--------------------";
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "------------------\n";
}

void heapSort(int *arr, int len) { // 复杂度nlog(n)
    for(int i = len / 2 - 1; i >= 0; --i) { // 建立堆，从最后一个非叶子节点开始建立, (2 * k + 1)或者(2 * k + 2) = n => 最后一个非叶子节点k = n/ 2 - 1
        heapAdjust(arr, i, len - 1);
    }
    for(int i = len - 1; i > 0; --i) { // 筛选和更新堆, 本次循环n次
        heapAdjust(arr, 0, i);
        arr[0] = arr[0] ^ arr[i];
        arr[i] = arr[0] ^ arr[i];
        arr[0] = arr[0] ^ arr[i];
        // output(arr, len);
    }
}

int main() {
    cin >> len;
    for(int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    heapSort(arr, len);
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}
