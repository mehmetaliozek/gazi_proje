#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "array.c"

const int max = 5;

void nullLine()
{
    printf("\n");
}

void createCircle(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("●");
    }
    for (int i = 0; i < max - count; i++)
    {
        printf("○");
    }
}

void getPersonalityTypeDescription(char *personality)
{
    int x = 0;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (personality[j] == type[i][j])
            {
                x++;
            }
        }
        if (x == 5)
        {
            x = i;
            break;
        }
        x = 0;
    }
    printf("%s", typeDescription[x / 2]);
}

void getPersonalityType()
{
    char personality[6];

    for (int i = 0; i < 6; i++)
    {
        if (i != 4)
        {
            if (categoriesScores[i] < 50)
            {
                personality[i] = i != 5 ? categories[i][0] : categories[i - 1][0];
            }
            else
            {
                personality[i] = i != 5 ? categories[i][1] : categories[i - 1][1];
            }
        }
        else
        {
            personality[i] = '-';
        }
    }

    printf("Kişilik tipiniz: ");

    printf("%s\n\nAçıklama: ", personality);
    getPersonalityTypeDescription(personality);
}

int getPersonalityQuestionScore(int line)
{
    char key;
    int score = 1;

    while (key != 13)
    {
        key = getch();
        printf("\33[2K\r");
        if (key == 77 && score < max)
        {
            score++;
        }
        else if (key == 75 && score > 1)
        {
            score--;
        }

        createCircle(score);
    }

    nullLine();
    return scores[line][score - 1];
}

void getPersonalityQuestionData()
{
    FILE *textfile;
    char line[255];

    int score = 0, i = 0;

    textfile = fopen("question.txt", "r");

    while (fgets(line, 255, textfile))
    {
        if (line != "")
        {
            printf("%s", line);
            printf("●○○○○");
            switch (i / 5)
            {
            case 0:
                categoriesScores[0] += getPersonalityQuestionScore(i);
                break;
            case 1:
                categoriesScores[2] += getPersonalityQuestionScore(i);
                break;
            case 2:
                categoriesScores[3] += getPersonalityQuestionScore(i);
                break;
            case 3:
                categoriesScores[4] += getPersonalityQuestionScore(i);
                break;
            case 4:
                categoriesScores[5] += getPersonalityQuestionScore(i);
                break;
            }
            nullLine();
        }
        i++;
    }

    fclose(textfile);

    getPersonalityType();
}
