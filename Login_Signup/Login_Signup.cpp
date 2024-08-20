#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 6031)
#pragma warning (disable : 6054)
#pragma warning (disable : 4996)

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#define MAX_USERS 100
#define FILE_NAME "user_data.txt"

typedef struct {
    char id[50];
    char pw[50];
} User;

User users[MAX_USERS];
int user_count = 0;

void signUp();
void login();
void loadUserData();
void saveUserData();
void inputPassword(char* pw);

int main(void)
{
    loadUserData();

    int option = 0;

    while (1) {
        printf("1. Login\n");
        printf("2. Sign up\n");
        printf("3. Exit\n\n\n");
        printf("-->   ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            login();
            break;
        case 2:
            signUp();
            break;
        case 3:
            saveUserData();
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void signUp()
{
    system("cls");
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot sign up new users.\n");
        return;
    }

    printf("Sign up\n");
    printf("ID: ");
    scanf("%s", users[user_count].id);
    printf("PW: ");
    inputPassword(users[user_count].pw);

    user_count++;
    system("cls");
    printf("Sign up successful!\n");
}

void login()
{
    system("cls");
    char id[50];
    char pw[50];
    int found = 0;

    printf("Login\n");
    printf("ID: ");
    scanf("%s", id);
    printf("PW: ");
    inputPassword(pw);

    system("cls");

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i].id, id) == 0 && strcmp(users[i].pw, pw) == 0) {
            printf("Login successful! Welcome, %s.\n", id);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID or password.\n");
    }
}

void loadUserData()
{
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%s %s", users[user_count].id, users[user_count].pw) != EOF) {
        user_count++;
        if (user_count >= MAX_USERS) {
            break;
        }
    }

    fclose(file);
}

void saveUserData()
{
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Failed to save user data.\n");
        return;
    }

    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].id, users[i].pw);
    }

    fclose(file);
}

void inputPassword(char* pw)
{
    char ch;
    int index = 0;

    while (1) {
        ch = getch();

        if (ch == 13)
        {
            pw[index] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (index > 0)
            {
                index--;
                printf("\b \b");
            }
        }
        else if (ch >= 32 && ch <= 126) 
        {
            pw[index++] = ch;
            printf("*");
        }
    }

    printf("\n");
}
