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
    // Parametre olarak alınan count değeri içi dolu kadar küre koyar
    for (int i = 0; i < count; i++)
    {
        printf("●");
    }
    // Parametre olarak alınan count değerini 5 e tamamlıcak kadar içi boş kadar küre koyar
    for (int i = 0; i < max - count; i++)
    {
        printf("○");
    }
}

// Kişilik testinde çıkan sonuca göre açıklama yapar
void getPersonalityTypeDescription(char *personality)
{
    int x;
    // Test sonucunda çıkan kişiliğin elimizde type dizinde hangi indexte diye arama yapar
    // 16 tane kişilik olduğu için 16 defa döner
    for (int i = 0; i < 16; i++)
    {
        x = 0;
        // type dizisindeki her bir eleman 4 karakterden olduğu için 4 defa çalışcak bir for
        for (int j = 0; j < 4; j++)
        {
            // For her çalıştığında bulunduğu indexteki tipin her bir harfini test sonucundaki tipin her bir harfiyle kıyaslar
            if (personality[j] == type[i][j])
            {
                // Harfler aynı ise x değişkenini artırır
                x++;
            }
        }
        // x değişkeni 4 ise tüm harfler eşit anlama gelir
        if (x == 4)
        {
            // i değeri type dizisinde test sonucunda çıkan tipin bulunduğu indextir
            // Bu indexi ilerde kullanmak için x değişkenine atıyoruz ve döngüyü kırıyoruz
            x = i;
            break;
        }
    }
    // typeDescription dizisinden bizim tipimize ait olan açıklamayı ekrana yazdırır
    printf("%s", typeDescription[x]);
}

// Kişilik testi sonucunu kullanıcıya veriyor
void getPersonalityType()
{
    char personality[6];

    for (int i = 0; i < 6; i++)
    {
        // categoriesScores[i] nin değerine göre categories dizinden hangi harfi alcağını belirler
        if (categoriesScores[i] < 50)
        {
            personality[i] = categories[i][0];
        }
        else
        {
            personality[i] = categories[i][1];
        }
    }

    printf("Kişilik tipiniz: ");

    printf("%s\n\nAçıklama: ", personality);
    getPersonalityTypeDescription(personality);
    getch();
}

// İlgili sorunun cevabına göre puanını döndüren fonksiyon
int getPersonalityQuestionScore(int line)
{
    // key = 13 Enter tuşu
    // key = 77 Sağ ok tuşu
    // key = 75 Sol ok tuşu
    // Klavyeden hangi tuşa basıldığını tutan değişkenimiz
    char key;
    // Ekranda oluşcak küre sayısı
    int count = 3;

    while (key != 13)
    {
        key = getch();
        // Bulunduğu satırı siliyor
        printf("\33[2K\r");
        // Sağ ok tuşuna basıldıysa ve ekranda max değerinden az küre varsa küre sayısını arttırıyor
        if (key == 77 && count < max)
        {
            count++;
        }
        // Sol ok tuşuna basıldıysa ve ekranda 1 den fazla küre varsa küre sayısını azaltıyor
        else if (key == 75 && count > 1)
        {
            count--;
        }

        // Küre oluşturucu fonksiyon
        createCircle(count);
    }

    nullLine();
    // line değişkeni sorunun kaçıncı satırda olduğunu yani numarası tutuyor
    // count ise bulununan sorunun hangi seçeneğini işaretlendiğini tutuyor
    // scores dizisinden yukardaki bilgiler yardımıyla soruya ve seçeneğe özgü puanı geri döndürüyor
    return scores[line][count - 1];
}

// Kişilik testinin sorularını metin belgesinden çeken fonksiyondur
void getPersonalityQuestionData()
{
    FILE *textfile;
    // Her bir satırdan gelen soruları aktardığımız dizi
    char line[255];

    // Satır sayısının 1 eksiğini tutuyor ki gerekli dizilerde azaltma yapmadan kullanabilelim
    int i = 0;

    textfile = fopen("question.txt", "r");

    while (fgets(line, 255, textfile))
    {
        // Metin belgesinden boş satır gelmediği sürece aşağıdaki işlemleri gerçekleştirir
        if (line != "")
        {
            // Soruyu ekrana yazdırır
            printf("%s", line);
            // Varsayılan küre sayısını (Kararsızım) hazırlar
            printf("●●●○○");
            // Her 5 soru bir kategoriyi ilgilendiriyor ve bizde bu soruları sırayla soruyoruz
            // i satır saysını 5 e bölerek kategori geçişlerini tespit etmekteyiz
            // Buna görede ilgili kategorinin puanı artmakta
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
