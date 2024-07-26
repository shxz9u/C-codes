#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable : 6031)
#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#pragma warning(disable : 6054)

static int num1, num2;
static int m_num;
static int n_cnt;
static int m_cnt;
static int i_num;

void Random()
{
    num1 = rand() % ((99 - 1) + 1) + 1;
    num2 = rand() % ((99 - 1) + 1) + 1;
}

void m_Random() 
{
    m_num = rand() % ((10000 - 1000) + 1) + 1000;
}

void e_Random()
{
    n_cnt = rand() % ((9 - 1) + 1) + 1;
}

void mc_Random()
{
    m_cnt = rand() % ((5 - 1) + 1) + 1;
}

void i_Random()
{
    i_num = rand() % ((16 - 1) + 1) + 1;
}

int main(void) 
{
    srand(time(NULL));

    int select1, select2, select3, select4;
    int money = 0;
    int m_answer;
    int ccnt = 0, wcnt = 0;
    int escape = 0;

    char english[100];
    int math;
    char end[20];

    char information[] = "happycprogramming";

    while (1)
    {
        system("cls");
        printf("=============\t게\t임\t메\t뉴\t=============\n\n\n");
        printf("\t\t\t1. 게임시작\n");
        printf("\t\t\t2. 게임설명\n");
        printf("\t\t\t3. 게임종료\n\n\n");
        printf("=============================================================\n\n");
        printf("->    ");

        scanf("%d", &select1);

        switch (select1)
        {
        case 1:
            system("cls");
            printf("\n\n\n\n\n");
            printf("=============\t시\t작\t메\t뉴\t=============\n\n\n");
            printf("현재 돈 : %d\n\n", money);
            printf("\t\t1. 돈 벌기\n");
            printf("\t\t2. 정보 사기 (한 글자 당 10,000원)\n");
            printf("\t\t3. 정답 맞추기\n");
            printf("\t\t4. 게임메뉴로 가기\n\n\n");
            printf("=============================================================\n\n");
            printf("->    ");

            scanf("%d", &select2);

            switch (select2)
            {
            case 1:
                while (1)
                {
                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("=============\t돈\t벌\t기\t메\t뉴\t=============\n\n\n");
                    printf("\t\t1. 연산퀴즈\n");
                    printf("\t\t2. 영단어 퀴즈\n");
                    printf("\t\t3. 수학 넌센스 퀴즈\n\n\n");
                    printf("=====================================================================\n\n");
                    printf("->    ");

                    scanf("%d", &select3);

                    switch (select3)
                    {
                    case 1:

                        printf("\n\n\n\n\n\n\n");
                        for (int i = 0; i < 10; i++)
                        {
                            Random();
                            m_Random();

                            printf("%d + %d = ", num1, num2);
                            scanf("%d", &m_answer);

                            if (m_answer == num1 + num2)
                            {
                                printf("정답\n");
                                ccnt++;
                            }
                            else {
                                printf("오답\n");
                                wcnt++;
                            }

                            printf("\n");
                        }
                        printf("\n");

                        printf("맞은 개수 : %d\n", ccnt);
                        printf("틀린 개수 : %d\n", wcnt);

                        if (wcnt >= 6)
                        {
                            printf("오답이 7개 이상 확인되어 돈을 벌지 못했습니다.\n");
                        }

                        else if (ccnt >= 7)
                        {
                            printf("\n%d원 벌었습니다.\n\n", m_num);
                            money += m_num;
                        }

                        ccnt = 0;
                        wcnt = 0;

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();

                        printf("\n\n\n\n\n\n\n");

                        break;


                    case 2:

                        m_Random();
                        e_Random();
                        printf("\n\n\n\n\n\n\n");
                        if (n_cnt == 1)
                        {
                            system("cls");
                            printf("\"학교\"는 영어로 (모두 소문자)?\n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "school") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 2)
                        {
                            system("cls");
                            printf("\"행복한\"은 영어로 (모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "happy") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 3)
                        {
                            system("cls");
                            printf("\"여행하다\"는 영어로 (모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "travel") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 4)
                        {
                            system("cls");
                            printf("\"아픈\"은 영어로 (모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "sick") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 5)
                        {
                            system("cls");
                            printf("\"만들다\"는 영어로 (모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "make") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 6)
                        {
                            system("cls");
                            printf("\"사다\"의 과거형은 (모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "bought") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 7)
                        {
                            system("cls");
                            printf("\"책\"은 영어로(모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "book") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }
                        else if (n_cnt == 8)
                        {
                            system("cls");
                            printf("\"비\"는 영어로(모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "rain") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        else if (n_cnt == 9)
                        {
                            system("cls");
                            printf("\"눈\"은 영어로(모두 소문자) ? \n");
                            printf("->    ");

                            scanf("%s", english);

                            if (strcmp(english, "snow") == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                for (int i = 0; i < 100; i++)
                                {
                                    english[i] = {};
                                }
                                _getch();
                            }
                        }

                        printf("\n\n\n\n\n\n\n");
                        break;



                    case 3:
                        m_Random();
                        mc_Random();
                        printf("\n\n\n\n\n\n\n");
                        if (m_cnt == 1)
                        {
                            system("cls");
                            printf("다음 물음표에 들어갈 숫자는 무엇일까요?\n\n");

                            printf("6128 + 9091 = 9825\n");
                            printf("8159 + 1912 = ?\n");
                            printf("->    ");

                            scanf("%d", &math);

                            if (math == 8679)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                math = 0;
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                math = 0;
                                _getch();
                            }
                        }

                        else if (m_cnt == 2)
                        {
                            system("cls");
                            printf("다음 물음표에 들어갈 숫자는 무엇일까요?\n\n");

                            printf("2 + 2 + 2 + 2 + 2\n2 + 2 + 2 + 2 + 2\n2 + 2 X 0 + 2 = ?\n");
                            printf("->    ");

                            scanf("%d", &math);

                            if (math == 60)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                math = 0;
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                math = 0;
                                _getch();
                            }

                        }

                        else if (m_cnt == 3)
                        {
                            system("cls");
                            printf("8을 반으로 나누면?\n\n");
                            printf("->    ");

                            scanf("%d", &math);

                            if (math == 0)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                math = 0;
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                math = 0;
                                _getch();
                            }

                        }

                        else if (m_cnt == 4)
                        {
                            system("cls");
                            printf("다음 물음표에 들어갈 숫자는 무엇일까요?\n\n");

                            printf("7070 = 2\t5555 = 0\n");
                            printf("0011 = 2\t0880 = 6\n");
                            printf("5678 = 3\t8809 = 6\n");
                            printf("1111 = 0\t7662 = 2\n");
                            printf("1117 = 0\t9313 = 1\n");
                            printf("0000 = 4\t8080 = 6\n");
                            printf("0909 = 4\t1234 = 0\n");
                            printf("8989 = ?\n");
                            printf("->    ");

                            scanf("%d", &math);

                            if (math == 6)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                math = 0;
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                math = 0;
                                _getch();
                            }

                        }

                        else if (m_cnt == 5)
                        {
                            system("cls");
                            printf("이 문제의 답은 2개다.\n사과나무가 3개 있는데,\n첫번째 나무에는 사과가 1개,");
                            printf("\n두번째 나무에는 사과가 3개가 있다.\n그럼 세번째 나무의 사과 개수는 ? \n");
                            printf("->    ");

                            scanf("%d", &math);

                            if (math == 2)
                            {
                                printf("\n\n정답입니다.\n");
                                printf("\n%d원 벌었습니다.\n\n", m_num);
                                money += m_num;

                                math = 0;
                                _getch();
                            }

                            else
                            {
                                printf("\n\n틀렸습니다.\n");

                                math = 0;
                                _getch();
                            }

                        }

                        printf("\n\n\n\n\n\n\n");
                    }
                    break;
                }
                break;

            case 2:
                printf("\n\n\n\n\n\n\n");

                i_Random();

                if (i_num == 1)
                {
                    if (money < 10000)
                    {
                        system("cls");
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        system("cls");
                        money -= 10000;
                        printf("정답의 첫글자는 'h' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 2)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 두번째 글자는 'a' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 3)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 네번째 글자는 'p' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 4)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 다섯번째 글자는 'p' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 5)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 여섯번째 글자는 'y' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 6)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 일곱번째 글자는 'c' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 7)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 여덟번째 글자는 'p' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 8)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 아홉번째 글자는 'r' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 9)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열번째 글자는 'o' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 10)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열한번째 글자는 'g' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 11)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열두번째 글자는 'r' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 12)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열세번째 글자는 'a' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 13)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열네번째 글자는 'm' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 14)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열다섯번째 글자는 'm' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 15)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열여섯번째 글자는 'i' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 16)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열일곱번째 글자는 'n' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }

                else if (i_num == 17)
                {
                    system("cls");
                    if (money < 10000)
                    {
                        printf("돈이 부족합니다.\n");
                        break;
                    }

                    else
                    {
                        money -= 10000;
                        printf("정답의 열일곱번째 글자는 'g' 입니다.\n\n");

                        printf("아무 키나 누르면 게임메뉴로 돌아갑니다.\n");

                        _getch();
                    }

                    printf("\n\n\n\n\n\n\n");

                    break;
                }





            case 3:
                system("cls");
                printf("\n\n\n\n\n\n\n\n");

                printf("정답을 입력하세요\n");
                printf("->    ");

                scanf("%s", end);

                if (strcmp(end, information) == 0)
                {
                    Beep(260, 100);
                    Beep(290, 100);
                    Beep(330, 100);
                    Beep(340, 100);
                    Beep(380, 100);
                    Beep(420, 100);
                    Beep(480, 100);
                    Beep(520, 100);
                    printf("\n\n정답입니다!\n");
                    printf("아무 키나 누르면 게임을 종료합니다.\n");

                    _getch();
                    return 0;
                }

                else
                {
                    printf("\n\n오답입니다.\n");
                    break;
                }

            }
            break;

        case 2:
            system("cls");
            printf("\n\n\n\n\n");
            printf("=============\t게\t임\t설\t명\t=============\n\n\n");
            printf("\t\t1. 전체적인 게임 설명\n");
            printf("\t\t2. 돈벌기 메뉴 종류\n");
            printf("\t\t3. 게임메뉴로 가기\n\n\n");
            printf("=============================================================\n\n");
            printf("->    ");

            scanf("%d", &select4);

            switch (select4)
            {
            case 1:
                system("cls");
                printf("\n\n\n\n\n");
                printf("=============\t게\t임\t설\t명\t=============\n\n\n");
                printf("이 게임은 미니게임들을 풀며 돈을 얻고 정보를 사서 \n정해진 문자열을 맞추면 이기는 게임입니다.\n");
                printf("미니게임은 총 세종류로 이루어져있으며\n미니게임에서 한번에 버는 돈은 1,000원 이상, 10,000원 미만입니다.\n");
                printf("정보를 구매할 시 몇번째 자리에 무슨 문자가 들어가는지 보여주고\n한 글자 당 10,000원이 소비됩니다.\n");
                printf("정답을 맞추면 도레미파솔라시도 이렇게 비프음이 나오면서 정답이라는 창이 뜹니다.\n\n");
                printf("=============================================================\n\n");

                printf("아무 키나 누르면 메뉴로 돌아갑니다.\n");

                _getch();
                printf("\n\n\n\n\n");
                break;



            case 2:
                system("cls");
                printf("\n\n\n\n\n");
                printf("=============\t게\t임\t설\t명\t=============\n\n\n");
                printf("돈벌기 게임 종류는 세가지가 있습니다.\n");
                printf("1. 연산게임\n");
                printf("2. 영단어 퀴즈\n");
                printf("3. 수학 넌센스 퀴즈\n\n");
                printf("연산게임에서는 덧셈문제가 10문제가 나옵니다.\n이중 7개 이상을 맞추면 돈을 얻고, 맞추지 못하면 얻지 못합니다\n");
                printf("영단어 퀴즈에서는 여러 단어가 한글로 랜덤으로 나옵니다.\n그 한글을 영어로 맞추면 돈을 얻습니다\n");
                printf("수학 넌센스 퀴즈에서는 여러 수학관련 넌센스 퀴즈가 랜덤으로 나옵니다\n");
                printf("그 퀴즈의 답을 맞추면 돈을 얻습니다\n\n");
                printf("=============================================================\n\n");

                printf("아무 키나 누르면 메뉴로 돌아갑니다.\n");

                _getch();
                printf("\n\n\n\n\n");
                break;



            case 3:
                printf("\n\n\n\n\n");
                break;

            }

            break;

        case 3:
            system("cls");
            printf("5초 뒤 게임을 종료합니다.\n");
            for (int i = 5; i > 0; i--)
            {
                printf("%d   ", i);
                Sleep(1000);
            }
            return 0;
        }
    }

    return 0;
}