#include <stdio.h>

int main() {
    char name[256];
    printf("이름을 입력하세요 : ");
    scanf("%s", name);

    int age;
    printf("나이를 입력하세요 : ");
    scanf("%d", &age);

    float height;
    printf("키를 입력하세요 : ");
    scanf("%f", &height);

    float weight;
    printf("몸무게를 입력하세요 : ");
    scanf("%f", &weight);

    printf("\n\n--- 범죄자 정보 ---\n\n");
    printf("이름 : %s\n", name);
    printf("나이 : %d\n", age);
    printf("키 : %.1f\n", height);
    printf("몸무게 : %.1f\n", weight);
    return 0;
}