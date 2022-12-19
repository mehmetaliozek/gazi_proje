#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// ○
// ●

const int max = 5;

char categories[5][2] = {
    {'E', 'I'},
    {'N', 'S'},
    {'T', 'F'},
    {'J', 'P'},
    {'A', 'T'},
};

char type[32][7] = {
    {"INTJ-A\0"},
    {"INTJ-T\0"},
    {"INTP-A\0"},
    {"INTP-T\0"},
    {"ENTJ-A\0"},
    {"ENTJ-T\0"},
    {"ENTP-A\0"},
    {"ENTP-T\0"},
    {"INFJ-A\0"},
    {"INFJ-T\0"},
    {"INFP-A\0"},
    {"INFP-T\0"},
    {"ENFJ-A\0"},
    {"ENFJ-T\0"},
    {"ENFP-A\0"},
    {"ENFP-T\0"},
    {"ISTJ-A\0"},
    {"ISTJ-T\0"},
    {"ISFJ-A\0"},
    {"ISFJ-T\0"},
    {"ESTJ-A\0"},
    {"ESTJ-T\0"},
    {"ESFJ-A\0"},
    {"ESFJ-T\0"},
    {"ISTP-A\0"},
    {"ISTP-T\0"},
    {"ISFP-A\0"},
    {"ISFP-T\0"},
    {"ESTP-A\0"},
    {"ESTP-T\0"},
    {"ESFP-A\0"},
    {"ESFP-T\0"},
};

char typeDescription[16][500] = {
    {"Her şey için bir planı olan hayalperest ve stratejik düşünenler.\n\nÖrnek: Elon Musk - Walter White - Gandalf\0"},
    {"Bilgi için bastırılamaz bir susuzluğu olan yenilikçi mucitler.\n\nÖrnek: Bill Gates - Albert Einstain - Neo\0"},
    {"Her zaman bir yolunu bulan ya da bir yol yaratan cesur, hayalperest ve dirayetli liderler.\n\nÖrnek:  Steve Jobs - Doctor Strange - Franklin D. Roosevelt\0"},
    {"Entelektüel zorluklara direnemeyen akıllı ve meraklı düşünürler.\n\nÖrnek: Thomas Edison - Captain Jack Sparrow - Joker\0"},
    {"Sessiz ve mistik fakat halen ilhan verici ve yılmaz idealistler.\n\nÖrnek: Goethe - Martin Luther King - Aragorn\0"},
    {"İyi bir davaya yardım etmeye her zaman hazır Şiirsel, kibar ve fedakâr insanlar.\n\nÖrnek: Jhonny Depp - Tom Hiddleston - William Shakespeare\0"},
    {"Dinleyicilerini büyüleme yeteneği olan karizmatik ve ilham verici liderler.\n\nÖrnek: Barack Obama - Morpheus - Ben Affleck\0"},
    {"Gülmek için her zaman bir sebep bulabilen coşkulu, yaratıcı ve sosyal özgür ruhlar.\n\nÖrnek: Will Smith - Spider-Man - Willy Wonka\0"},
    {"Güvenirliklerinden kuşku edilemez pratik ve hakikat merkezli bireyler.\n\nÖrnek: George Washington - Hermione Granger - Geralt of Rivia\0"},
    {"Sevdiklerini savunmaya her zaman hazır kendini cidden adamış ve sıcakkanlı korunmacılar.\n\nÖrnek: Queen Elizabeth - Captain America - Vito Corleone\0"},
    {"Bir şeyleri veya insanları idare etmek konusunda emsalsiz olan mükemmel yöneticiler.\n\nÖrnek: John D. Rockefeller - Judge Judy - Ella Baker\0"},
    {"Her zaman yardıma hazır olağanüstü alakadar, sosyal ve popüler insanlar.\n\nÖrnek: Taylor Swift - Jennifer Lopez - Steve Harvey\0"},
    {"Her türlü alette usta cesur ve pratik denemeciler.\n\nÖrnek: Bear Grylls - Michaek Jordon - Indiana Jones\0"},
    {"Yeni bir şeyi araştırmaya ve deneyim etmeye hazır rahat ve büyüleyici sanatçılar.\n\nÖrnek: Frida Kahlo - Michael Jackson - Beatrix Kiddo\0"},
    {"Uçlarda yaşamaktan gerçekten zevk alan zeki, enerjik ve perspektif sahibi insanlar.\n\nÖrnek: Rocket - Ant-Man - Madonnda\0"},
    {"Etraflarında hayatın hiçbir sıkıcı olmayan spontane, enerjik ve coşkulu eğlendiriciler.\n\nÖrnek: Marilyn Monroe - Captain Marvel - Jack Dawson\0"},
};

int categoriesScores[5] = {50, 50, 50, 50, 50};

int scores[20][5] = {
    {-4, -2, 0, 2, 4},
    {-8, -4, 0, 4, 8},
    {-4, -2, 0, 2, 4},
    {4, 2, 0, -2, -4},
    {-6, -3, 0, 3, 6},

    {-8, -4, 0, 4, 8},
    {-4, -2, 0, 2, 4},
    {6, 3, 0, -3, 6},
    {-10, -5, 0, 5, 10},
    {-6, -3, 0, 3, 6},

    {-8, -4, 0, 4, 8},
    {4, 2, 0, -2, -4},
    {-10, -5, 0, 5, 10},
    {-10, -5, 0, 5, 10},
    {-8, -4, 0, 4, 8},

    {-10, -5, 0, 5, 10},
    {-8, -4, 0, 4, 8},
    {4, 2, 0, -2, -4},
    {-6, -3, 0, 3, 6},
    {-6, -3, 0, 3, 6},
};

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

    // TODO: Açıklama yaz
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

void main()
{
    printf("\e[1;1H\e[2J");
    printf("BİLGİLENDİRME\n\n");
    printf("-------------------------------\n");
    printf("1-Kesinlikle katılmıyorum\n");
    printf("2-Katılmıyorum\n");
    printf("3-Kararsızım\n");
    printf("4-Katılıyorum\n");
    printf("5-Kesinlikle katılıyorum\n");
    printf("-------------------------------\n\n");
    getPersonalityQuestionData();
}