#include <stdio.h>
int main()
{
    // ประกาศและกําหนดค่าตัวแปร
    char name[50];
    int hp;
    int atk;
    int def;
    int level;

    // ใส่ข้อมูลส่วนตัว
    printf("=== Create Character ===\n");
    printf("Character Name: ");
    scanf("%49s", name);
    printf("Max HP        : ");
    scanf("%d", &hp);
    printf("Attack Power  : ");
    scanf("%d", &atk);
    printf("Defense       : ");
    scanf("%d", &def);
    printf("Level         : ");
    scanf("%d", &level);

    // แสดงข้อมูลส่วนตัว
    printf("\n=== Character Summary ===\n");
    printf("Name  : %s\n", name);
    printf("Level : %d\n", level);
    printf("HP    : %d\n", hp);
    printf("ATK   : %d\n", atk);
    printf("DEF   : %d\n", def);
    return 0;
}