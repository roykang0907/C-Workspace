#include <stdio.h>

int main(void) {
    int age;
    printf("나이를 입력하세요 : ");
    scanf("%d", &age);

    if (age<=7) {
        printf("유치원생입니다\n");
    }
    else if (age>=8 && age<=13) {
        printf("초등학생입니다\n");
    }
    else if (age>=14 && age<=16) {
        printf("중학생입니다\n");
    }
    else if (age>=17 && age<=19) {
        printf("고등학생입니다\n");
    }
    else {
        printf("성인입니다\n");
    }
    return 0;
}