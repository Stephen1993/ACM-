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
int len, arr[MAX], sum[MAX];

int main() {
    while(cin >> len) {
        for(int i = 0; i < MAX; ++i) sum[i] = 0;
        for(int i = 0; i < len; ++i) cin >> arr[i];
        for(int i = 0; i < len; ++i) ++sum[arr[i]];
        int index = 0;
        for(int i = 0; i < MAX; ++i) {
            for(int j = 1; j <= sum[i]; ++j) {
                arr[index++] = i;
            }
        }
        for(int i = 0; i < len; ++i)cout << arr[i] << ' ';
    }
    return 0;
}
