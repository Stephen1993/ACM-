#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <iomanip>
#define INF 999999999
typedef long long LL;
using namespace std;

const int MAX = 10000;
int len, arr[MAX];

void output(int *arr, int len) {
    cout << "\n------\n";
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "\n------\n";
}

void quickSort(int *arr, int st, int end) { // 升序排序
    if(st >= end) return;
    int left = st, right = end;
    int val = arr[right]; // 从左边开始寻找合适的数去填充右边的位置
    while(left < right) { // 如果每次left = right = (right + left) / 2则算法复杂度为nlog(n)，如果每次left = right = st或者end则复杂度为n*n
        while(left < right && arr[left] < val) ++left;
        arr[right] = arr[left]; // 左边的数填充了右边的位置，则需要从右边寻找合适的数去填充这个空出的位置
        while(left < right && arr[right] >= val) --right;
        arr[left] = arr[right];
    }
    arr[left] = val; // 最终剩下一个位置用来填充val，则val左边的比val小，val右边的比val大
    quickSort(arr, st, left - 1);
    quickSort(arr, left + 1, end);
}

int main() {
    while(cin >> len) {
        for(int i = 0; i < len; ++i) {
            cin >> arr[i];
        }
        quickSort(arr, 0, len -1);
        output(arr, len);
    }
    return 0;
}
