#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *getTime()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    static char date[100];
    sprintf(date, "%04d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    return date;
}

int main()
{
    int a, b, choice, c;

    while (1)
    {
        printf("1. addition\n");
        printf("2. substraction\n");
        printf("3. multiplication\n");
        printf("4. history\n");
        printf("5. exit\n");

        printf("please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            system("cls");
            printf("please enter the value of A: ");
            scanf("%d", &a);
            printf("please enter the value of B: ");
            scanf("%d", &b);

            c = a + b;
            printf("\n%d + %d = %d\n", a, b, c);
            FILE *f = fopen("logs.txt", "a");
            if (f != NULL)
            {
                fprintf(f, "[%s] %d + %d = %d\n", getTime(), a, b, c);
                fclose(f);
            }



            printf("\n\n\n");
        }
        else if (choice == 2)
        {
            system("cls");
            printf("please enter the value of A: ");
            scanf("%d", &a);
            printf("please enter the value of B: ");
            scanf("%d", &b);

            c = a - b;
            printf("\n%d - %d = %d\n", a, b, c);

            FILE *f = fopen("logs.txt", "a");
            if (f != NULL)
            {
                fprintf(f, "[%s] %d - %d = %d\n", getTime(), a, b, c);
                fclose(f);
            }
            printf("\n\n\n");
        }
        else if (choice == 3)
        {
            system("cls");
            printf("please enter the value of A: ");
            scanf("%d", &a);
            printf("please enter the value of B: ");
            scanf("%d", &b);

            c = a * b;
            printf("\n%d * %d = %d\n", a, b, c);

            FILE *f = fopen("logs.txt", "a");
            if (f != NULL)
            {
                fprintf(f, "[%s] %d * %d = %d\n", getTime(), a, b, c);
                fclose(f);
            }
            printf("\n\n\n");
        }
        else if (choice == 4)
        {
            system("cls");
            char str[1000];
            FILE *f = fopen("logs.txt", "r");

            if (f == NULL)
            {
                printf("\nNO PREVIOUS HISTORY!!!\n");
                continue;
            }
            while (fgets(str, sizeof(str), f))
            {
                printf("%s", str);
            }
            fclose(f);
            continue;
        }
        else if (choice == 5)
        {
            printf("Thank you for using :)\n");
            return 0;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
