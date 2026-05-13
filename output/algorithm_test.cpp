#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k1, k2;
    std::cin >> n >> k1 >> k2;

    std::vector<std::vector<int>> s_c_l(n, std::vector<int>(2));
    for (int i = 0; i < n; ++i) {
        std::cin >> s_c_l[i][0] >> s_c_l[i][1];
    }

    std::vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        std::vector<int> arr = s_c_l.front();
        s_c_l.erase(s_c_l.begin());
        int x = n - i - 1;
        for (int j = 0; j < x; ++j) {
            int k = std::abs(arr[0] - s_c_l[j][0]);
            if (arr[1] == s_c_l[j][1] && k <= k1) {
                ans[i] += 1;
                ans[j + n - x] += 1;
            } else if (arr[1] != s_c_l[j][1] && k <= k2) {
                ans[i] += 1;
                ans[j + n - x] += 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
