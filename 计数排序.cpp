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
int mark[MAX], temp[MAX];

void output(int *arr, int len) {
    cout << "--------------------";
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "------------------\n";
}

void calSort(int *arr, int len) {
    for(int i = 0; i < MAX; ++i) mark[i] = 0;
    for(int i = 0; i < len; ++i) mark[arr[i]] += 1;
    for(int i = 1; i < MAX; ++i) mark[i] += mark[i-1];
    for(int i = 0; i < len; ++i) temp[--mark[arr[i]]] = arr[i];
    for(int i = 0; i < len; ++i) arr[i] = temp[i];
}

int main() {
    cin >> len;
    for(int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    calSort(arr, len);
    output(arr, len);
    return 0;

}
