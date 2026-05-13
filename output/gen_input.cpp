#include <iostream>
#include <cstdlib>
#include <cstdio>

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    int k1 = 100;
    int k2 = 100;
    std::printf("%d %d %d\n", n, k1, k2);
    std::srand(42);
    for (int i = 0; i < n; ++i) {
        int s = std::rand() % 1000;
        int c = std::rand() % 2;
        std::printf("%d %d\n", s, c);
    }
    return 0;
}
