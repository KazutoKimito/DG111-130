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
    printf("\n=== Character Sheet ===\n");
    printf("╔════════════════════════════════╗\n");
    printf("║ Name  : %-22s ║\n", name);
    printf("╠════════════════════════════════╣\n");
    printf("║ Level : %-22d ║\n", level);
    printf("║ HP    : %d / %d %-12s ║\n", hp, hp, "");
    printf("║ ATK   : %-22d ║\n", atk);
    printf("║ DEF   : %-22d ║\n", def);
    printf("╠════════════════════════════════╣\n");
    printf("║ HP Bar: [██████████] %-9s ║\n", "100%");
    printf("║ Power Score: %-17d ║\n", atk * 2 + def + hp / 10);
    printf("╚════════════════════════════════╝\n");
    return 0;
}