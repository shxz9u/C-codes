#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    system("cls");

    int random;
    int number = 0;
    int select = 0, select2;

    srand(time(NULL));

    printf("수 범위: ");
    scanf("%d", &number);

    printf("%d 중에서 랜덤 수 뽑기\n\n", number);

    while (1)
    {
        system("cls");

        printf("1. 뽑기\n");
        printf("2. 나가기\n");
        scanf("%d", &select);

        if (select == 2)
        {
            exit(1);
        }

        random = rand() % number + 1;

        switch (select)
        {
        case 1:
            system("cls");
            printf("%d번 당첨\n", random);

            printf("1. 다시하기\n");
            printf("2. 나가기\n");
            scanf("%d", &select2);

            if (select2 == 2)
            {
                exit(1);
            }

            break;

        case 2:
            exit(1);

        default:
            printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }
    return 0;
}
