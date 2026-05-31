#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct test {
    int country;
    int num;
    int score;
};

bool cmp(vector<int> &v1, vector<int> &v2) {
	if(v1[0] == v2[0]) return v1[1]>v2[1];
	else return v1[0]>v2[0];
}

int main() {
    int n, c = 1;
    cin >> n;
    vector<test> arr(n);

    sort(arr.begin(),arr.end(),cmp);
    cout << arr[0].score;
    return 0;
}