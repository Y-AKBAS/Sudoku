#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void display(int arr[9][9])
{
    printf("  ");
    for (int i = 0; i < 9; i++)
        printf(" %d. ", i + 1);

    printf("\n   ");
    for (int i = 0; i < 9; i++)
        printf(" __ ");

    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d. |", i + 1);
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == -1)
                printf("  | ");
            else
                printf(" %d| ", arr[i][j]);
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            printf("   ");
            for (int t = 0; t < 9; t++)
                printf(" ~~ ");
            printf("\n");
        }
    }
    printf("\n");
}
bool isInnerRepeatingUtil(int *arr)
{
    bool check = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i] == arr[j] && i != j && arr[i] != (-1) && arr[j] != (-1))
                check = true;
        }
    }
    return check;
}

bool isInnerRepeating(int arr[9][9])
{
    bool check = false;
    int *temp = (int *)malloc(10 * sizeof(int));
    int count, i = 0, j = 0, ic = 2, jc = 2, in = 0, jn = 0;

    do
    {
        count = 0;
        while (i <= ic)
        {
            j = jn;
            while (j <= jc)
            {
                temp[count++] = arr[i][j];
                j++;
            }
            i++;
        }

        if (isInnerRepeatingUtil(temp))
        {
            check = true;
            return check;
        }

        jc += 3;
        jn += 3;

        if (j >= 8)
        {
            j = 0;
            jc = 2;
            ic += 3;
            in += 3;
            jn = 0;
        }
        i = in;

    } while (in != 9);
    free(temp);
    return check;
}

bool isRepeating(int arr[9][9])
{
    bool check = false;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                if ((arr[i][j] == arr[i][k]) && (k != j) && (arr[i][j] != -1))
                    check = true;
            }

            for (int x = 0; x < 9; x++)
            {
                if ((arr[j][i] == arr[x][i]) && (x != j) && (arr[j][i] != -1))
                    check = true;
            }
        }
    }
    if (isInnerRepeating(arr))
        check = true;
    return check;
}

bool hasMinus(int arr[9][9])
{
    bool check = false;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == -1)
                check = true;
        }
    }
    return check;
}

void generate(int arr[9][9])
{
    int a = (rand() % 1000);
    int b = (rand() % 1000);
    int x = (rand() % 100);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = (arr[i][j] + ((a * b + x) % 9) + 1) % 9 + 1;
        }
    }

    int row, column, sgrad;
    char str[20] = "", c = 'a';

    do
    {
        printf("\nFuer -Fortgeschrittenes Niveau- druecke bitte '3'\n");
        printf("Fuer -Mittleres Niveau- druecke bitte '2'\n");
        printf("Fuer -Anfaenger Niveau- druecke bitte '1' \n");

        fgets(str, 20, stdin);
        if (strlen(str) == 2)
        {
            c = str[0];
        }

        if (strlen(str) != 2 || !(c == '1' || c == '2' || c == '3'))
        {
            printf("\n\nUnzulaessige Eingabe!\n\n");
        }

    } while (!(c == '1' || c == '2' || c == '3'));

    sgrad = c - 48;
    sgrad = sgrad * 15 + 15;

    for (int i = 0; i < sgrad; i++)
    {
        row = (rand() % 9);
        column = (rand() % 9);

        if (arr[row][column] == (-1))
        {
            while (arr[row][column] != (-1))
            {
                if (row == 9 || column == 9)
                    break;
                row++;
                column++;
            }
            sgrad++;
        }
        if (arr[row][column] != (-1))
        {
            arr[row][column] = -1;
        }
    }
}

void provideBase(int arr[9][9], int arr1[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = arr1[i][j];
        }
    }
}

void insert(int arr[9][9])
{
    char rowch[20], columnch[20], valuech[20];
    int row, column, value;
    bool check = true;

    printf("Zeile: ");
    fgets(rowch, 20, stdin);
    if (strlen(rowch) == 2)
    {
        row = rowch[0];
        row -= 49;
    }
    else
        check = false;

    printf("Spalte: ");
    fgets(columnch, 20, stdin);
    if (strlen(columnch) == 2)
    {
        column = columnch[0];
        column -= 49;
    }
    else
        check = false;

    printf("Wert: ");
    fgets(valuech, 20, stdin);
    if (strlen(valuech) == 2)
    {
        value = valuech[0];
        value -= 48;
    }
    else
        check = false;

    if ((row < 9 && row >= 0) && (column < 9 && column >= 0) && (value <= 9 && value > 0) && check)
        arr[row][column] = value;
    else
        printf("Unzulaessige Operation! Bitte pruefe deine Eingabe!\n");

    printf("\n");
}

int main()
{
    printf("\n");
    srand(time(0));

    int arr[9][9] = {
        {2, 8, 6, 9, 3, 7, 1, 5, 4},
        {3, 4, 5, 6, 8, 1, 7, 9, 2},
        {7, 1, 9, 2, 4, 5, 3, 6, 8},
        {1, 7, 4, 5, 6, 8, 9, 2, 3},
        {6, 3, 8, 7, 2, 9, 4, 1, 5},
        {5, 9, 2, 3, 1, 4, 6, 8, 7},
        {4, 5, 3, 1, 9, 2, 8, 7, 6},
        {8, 2, 1, 4, 7, 6, 5, 3, 9},
        {9, 6, 7, 8, 5, 3, 2, 4, 1}};

    int temp[9][9];

    provideBase(temp, arr);

    printf("Herzlich Willkommen! Viel Spass mit dem Spiel!\n\n");

    char str[20], wahl = 'N';
    bool checkingForGenerate = false;
    bool checkingforNew = false;

    do
    {
        if (wahl == 'N' && checkingForGenerate == true && checkingforNew == false)
        {
            provideBase(arr, temp);
            generate(arr);
            display(arr);
        }
        if (wahl == 'N' && checkingForGenerate == false)
        {
            generate(arr);
            display(arr);
            checkingForGenerate = true;
        }

        printf("\n\nFuer neues Sudoku druecke bitte 'N'\n");
        printf("Um fortzufuehren druecke bitte 'F'\n");

        fgets(str, 20, stdin);
        str[0] = toupper(str[0]);

        if (strlen(str) == 2 && (str[0] == 'F' || str[0] == 'N'))
        {
            wahl = str[0];
            checkingforNew = false;
        }
        else
        {
            printf("\n\nUnzulaessige Eingabe!\n\n");
            checkingforNew = true;
        }

    } while (wahl != 'F');

    printf("\nJetzt geht's richtig los!\n");
    printf("\nIm Folgenden sollst du zuerst Zeilen-und Spaltennummer eingeben\n");
    printf("und dann deine Zahl einfuegen. Viel Erfolg!\n\n");

    while (wahl != 'P')
    {
        if (hasMinus(arr) == false)
        {
            printf("Um deine Loesung zu pruefen druecke bitte 'P'\n");
            printf("Um weiterzumachen druecke bitte eine andere beliebige Taste...\n");
            fflush(stdin);
            fgets(str, 20, stdin);
            //            while ((getchar()) != '\n')
            //                ;
            if (strlen(str) == 2 && (str[0] == 'P' || str[0] == 'p'))
            {
                break;
            }
        }
        insert(arr);
        display(arr);
    }

    if (isRepeating(arr) || hasMinus(arr))
    {
        printf("\nNetter Versuch! Aber Leider ist deine Loesung nicht korrekt!\n");
        printf("Bis zur naechsten Gehirngymnastik!\n");
    }
    else
    {
        printf("\nWoow! Gut gemacht! Deine Loesung ist korrekt!\n");
        printf("Bis zur naechsten Gehirngymnastik!\n");
    }

    printf("\n");
    return 0;
}
