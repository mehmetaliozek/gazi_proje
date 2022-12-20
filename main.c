// Tüm fonksiyonların bulunduğu dosyayı ekler
#include "function.c"

void main()
{
    // Terminali temizler
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