#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int korean;
    int english;
    int math;
    int science;
    int social;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void input_student()
{
    if (student_count >= MAX_STUDENTS)
    {
        printf("더 이상 학생을 추가할 수 없습니다.\n");
        return;
    }

    printf("학생 이름: ");
    scanf("%s", students[student_count].name);
    printf("국어 성적: ");
    scanf("%d", &students[student_count].korean);
    printf("영어 성적: ");
    scanf("%d", &students[student_count].english);
    printf("수학 성적: ");
    scanf("%d", &students[student_count].math);
    printf("과학 성적: ");
    scanf("%d", &students[student_count].science);
    printf("사회 성적: ");
    scanf("%d", &students[student_count].social);

    student_count++;
}

void view_students()
{
    if (student_count == 0)
    {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    for (int i = 0; i < student_count; i++)
    {
        printf("%d. %s\n", i + 1, students[i].name);
        printf("국어: %d, 영어: %d, 수학: %d, 과학: %d, 사회: %d\n",
               students[i].korean, students[i].english,
               students[i].math, students[i].science, students[i].social);
    }
}

void modify_student()
{
    int index;
    printf("수정할 학생 번호를 입력하세요 (1 ~ %d): ", student_count);
    scanf("%d", &index);

    if (index < 1 || index > student_count)
    {
        printf("잘못된 번호입니다.\n");
        return;
    }

    index--; // 배열 인덱스는 0부터 시작

    printf("새로운 학생 이름: ");
    scanf("%s", students[index].name);
    printf("새로운 국어 성적: ");
    scanf("%d", &students[index].korean);
    printf("새로운 영어 성적: ");
    scanf("%d", &students[index].english);
    printf("새로운 수학 성적: ");
    scanf("%d", &students[index].math);
    printf("새로운 과학 성적: ");
    scanf("%d", &students[index].science);
    printf("새로운 사회 성적: ");
    scanf("%d", &students[index].social);
}

void delete_student()
{
    int index;
    printf("삭제할 학생 번호를 입력하세요 (1 ~ %d): ", student_count);
    scanf("%d", &index);

    if (index < 1 || index > student_count)
    {
        printf("잘못된 번호입니다.\n");
        return;
    }

    index--; // 배열 인덱스는 0부터 시작

    for (int i = index; i < student_count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    student_count--;
}

void sort_students()
{
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = i + 1; j < student_count; j++)
        {
            int total_i = students[i].korean + students[i].english +
                          students[i].math + students[i].science + students[i].social;
            int total_j = students[j].korean + students[j].english +
                          students[j].math + students[j].science + students[j].social;
            if (total_i < total_j)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("총점 순으로 정렬되었습니다.\n");
}

void calculate_average()
{
    if (student_count == 0)
    {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    int total_korean = 0, total_english = 0, total_math = 0, total_science = 0, total_social = 0;
    for (int i = 0; i < student_count; i++)
    {
        total_korean += students[i].korean;
        total_english += students[i].english;
        total_math += students[i].math;
        total_science += students[i].science;
        total_social += students[i].social;
    }

    printf("국어 평균 성적: %.2f\n", (double)total_korean / student_count);
    printf("영어 평균 성적: %.2f\n", (double)total_english / student_count);
    printf("수학 평균 성적: %.2f\n", (double)total_math / student_count);
    printf("과학 평균 성적: %.2f\n", (double)total_science / student_count);
    printf("사회 평균 성적: %.2f\n", (double)total_social / student_count);
}

void display_menu()
{
    printf("\n학생 성적 관리 프로그램\n");
    printf("1. 학생 정보 입력\n");
    printf("2. 학생 정보 조회\n");
    printf("3. 학생 정보 수정\n");
    printf("4. 학생 정보 삭제\n");
    printf("5. 학생 정보 정렬 (총점 순)\n");
    printf("6. 평균 성적 계산\n");
    printf("7. 종료\n");
    printf("선택: ");
}

int main()
{
    int choice;

    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input_student();
            break;
        case 2:
            view_students();
            break;
        case 3:
            modify_student();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            sort_students();
            break;
        case 6:
            calculate_average();
            break;
        case 7:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
