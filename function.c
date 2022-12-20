#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// Tüm dizileri bulunduğu dosyayı ekler
#include "array.c"

// Maksimum küre sayısı
const int max = 5;

// Boş satır
void nullLine()
{
    printf("\n");
}

// Küre oluşturucu
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

// Kişilik testinde çıkan sonuca göre açıklama yapar
void getPersonalityTypeDescription(char *personality)
{
    int x = 0;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // I N T J - A 
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

// Kişilik testi sonucunu kullanıcıya veriyor
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
    // key = 13 Enter tuşu
    // key = 77 Sağ ok tuşu
    // key = 75 Sol ok tuşu
    char key;
    int count = 1;

    while (key != 13)
    {
        key = getch();
        // Bulunduğu satırı siliyor
        printf("\33[2K\r");
        if (key == 77 && count < max)
        {
            count++;
        }
        else if (key == 75 && count > 1)
        {
            count--;
        }

        createCircle(count);
    }

    nullLine();
    return scores[line][count - 1];
}

// Kişilik testinin sorularını metin belgesinden çeken fonksiyondur
void getPersonalityQuestionData()
{
    FILE *textfile;
    char line[255];

    int i = 0;

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
            }
            nullLine();
        }
        i++;
    }

    fclose(textfile);

    getPersonalityType();
}
