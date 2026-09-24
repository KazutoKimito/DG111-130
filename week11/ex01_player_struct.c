#include <stdio.h>
#include <string.h>

// ==========================================
// ส่วนที่ 1 — ประกาศ struct Player
// ==========================================
typedef struct
{
    char name[30];
    int hp, max_hp, attack, defense, level, gold;
} Player;

// ==========================================
// ส่วนที่ 2 — createPlayer สร้าง Player ใหม่และคืนค่ากลับ
// ==========================================
Player createPlayer(const char *name, int hp, int atk, int def, int level)
{
    Player p;
    // คัดลอกชื่อและป้องกัน buffer overflow
    strncpy(p.name, name, sizeof(p.name) - 1);
    p.name[sizeof(p.name) - 1] = '\0';

    p.hp = hp;
    p.max_hp = hp; // max_hp เท่ากับ hp เริ่มต้น
    p.attack = atk;
    p.defense = def;
    p.level = level;
    p.gold = 0; // gold เริ่มที่ 0
    return p;
}

// ==========================================
// ส่วนที่ 3 — displayPlayer แสดงข้อมูล Player
// ==========================================
void displayPlayer(const Player *p)
{
    printf("Name: %s\n", p->name);
    printf("Level: %d\n", p->level);
    printf("HP: %d/%d\n", p->hp, p->max_hp);
    printf("ATK: %d\n", p->attack);
    printf("DEF: %d\n", p->defense);
    printf("Gold: %d\n", p->gold);
}

// ==========================================
// ส่วนที่ 4 — ฟังก์ชันการทำงานของระบบเกม
// ==========================================

// level + 1, attack/defense +10%, max_hp + 25
void levelUp(Player *p)
{
    p->level += 1;
    p->attack = p->attack * 110 / 100;   // เพิ่ม ATK 10%
    p->defense = p->defense * 110 / 100; // เพิ่ม DEF 10%
    p->max_hp += 25;                     // เพิ่ม Max HP 25
}

// คืนค่า 1 ถ้า hp > 0, ถ้าไม่ใช่คืนค่า 0
int isAlive(const Player *p)
{
    return p->hp > 0;
}

// ลด hp ตามค่า dmg และไม่ให้ต่ำกว่า 0 (clamped at 0)
void takeDamage(Player *p, int dmg)
{
    p->hp -= dmg;
    if (p->hp < 0)
    {
        p->hp = 0;
    }
}

// ==========================================
// ส่วนที่ 5 — main ทดสอบทุก function
// ==========================================
int main()
{
    // 1. สร้างตัวละคร Dragon Knight
    Player p = createPlayer("Dragon Knight", 100, 55, 40, 7);
    p.gold = 2350; // กำหนดเงิน

    // 2. ทดสอบรับความเสียหาย 15
    takeDamage(&p, 15);
    displayPlayer(&p);
    printf("Alive: %s\n", isAlive(&p) ? "yes" : "no");

    // 3. ทดสอบเลเวลอัป
    printf("\n--- Level Up ---\n");
    levelUp(&p);
    displayPlayer(&p);

    // 4. ทดสอบรับความเสียหายรุนแรง (ตาย)
    printf("\n--- Take 999 damage ---\n");
    takeDamage(&p, 999);
    displayPlayer(&p);
    printf("Alive: %s\n", isAlive(&p) ? "yes" : "no");

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}