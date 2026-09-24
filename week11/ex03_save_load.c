#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAVE_FILE_PATH "save.bin"

// ==========================================
// ส่วนที่ 1 — ค่าคงที่และ struct GameData
// ==========================================
typedef struct
{
    float x, y;
    int hp, max_hp, level, score;
} GameData;

// ==========================================
// ส่วนที่ 2 — saveGame
// เขียนไฟล์ด้วยโหมด "w"
// คืน 1 ถ้าสำเร็จ, 0 ถ้าเปิดไฟล์ไม่ได้
// ==========================================
int saveGame(const char *path, const GameData *d)
{
    FILE *f = fopen(path, "wb"); // "wb" = write binary
    if (!f)
        return 0;
    fwrite(d, sizeof(GameData), 1, f); // เขียน struct ทั้งก้อนลงไฟล์
    fclose(f);
    return 1;
}

// ==========================================
// ส่วนที่ 3 — loadGame
// อ่านด้วย fscanf ลงตัวแปรชั่วคราว tmp
// ก่อนค่อยคัดลอกเมื่ออ่านครบ 6 ค่า
// เพื่อให้ไฟล์เสียแล้วข้อมูลเดิมไม่พัง
// ==========================================
int loadGame(const char *path, GameData *d)
{
    FILE *f = fopen(path, "rb"); // "rb" = read binary
    if (!f)
        return 0;
    GameData tmp;
    size_t n = fread(&tmp, sizeof(GameData), 1, f); // อ่านกลับมาทั้งก้อน
    fclose(f);
    if (n != 1)
        return -1; // อ่านได้ไม่ครบ = ไฟล์เสีย
    *d = tmp;
    return 1;
}

// ==========================================
// ส่วนที่ 4 — printData
// แสดงค่าทั้งหมดในบรรทัดเดียว
// ใช้เทียบค่าก่อน/หลัง
// ==========================================
void printData(const GameData *d)
{

    printf("POS:%.1f,%.1f HP:%d/%d LEVEL:%d SCORE:%d\n",
           d->x,
           d->y,
           d->hp,
           d->max_hp,
           d->level,
           d->score);
}

// ==========================================
// ส่วนที่ 5 — randomAction
// สุ่มด้วย rand() % 5
// เลือก 1 ใน 5 action ที่เปลี่ยนค่าใน struct
//
// Action และผลต่อข้อมูล
// Move      -> x, y เปลี่ยน
// Fight     -> hp ลด, score เพิ่ม
// Potion    -> hp เพิ่ม (ไม่เกิน max_hp)
// Treasure  -> score เพิ่ม
// Trap      -> hp ลด
//
// หลังทำ action:
// hp <= 0              -> เกิดใหม่ที่ (100,100)
//                          HP เต็ม และคะแนนลดครึ่ง
// score >= level * 400 -> Level Up
//                          max_hp + 10 และ HP เต็ม
// ==========================================
void randomAction(GameData *d)
{

    switch (rand() % 5)
    {

    // --------------------------------------
    // Move
    // --------------------------------------
    case 0:
    {
        int dx = rand() % 41 - 20;
        int dy = rand() % 41 - 20;

        d->x += dx;
        d->y += dy;

        printf("[Move] You walked (%+d,%+d)\n",
               dx, dy);

        break;
    }

    // --------------------------------------
    // Fight
    // --------------------------------------
    case 1:
    {
        int dmg = 5 + rand() % 21;
        int gain = 50 + rand() % 101;

        d->hp -= dmg;
        d->score += gain;

        printf("[Fight] Defeated a monster! -%d HP, +%d score\n",
               dmg, gain);

        break;
    }

    // --------------------------------------
    // Potion
    // --------------------------------------
    case 2:
    {
        int heal = 10 + rand() % 21;

        d->hp += heal;

        if (d->hp > d->max_hp)
        {
            d->hp = d->max_hp;
        }

        printf("[Potion] Found a potion, +%d HP\n",
               heal);

        break;
    }

    // --------------------------------------
    // Treasure
    // --------------------------------------
    case 3:
    {
        int gain = 100 + rand() % 201;

        d->score += gain;

        printf("[Treasure] Found a chest, +%d score\n",
               gain);

        break;
    }

    // --------------------------------------
    // Trap
    // --------------------------------------
    default:
    {
        int dmg = 20 + rand() % 21;

        d->hp -= dmg;

        printf("[Trap] Ouch! -%d HP\n",
               dmg);

        break;
    }
    }

    // ==========================================
    // ตรวจสอบ HP หลังจากทำ Action
    // ==========================================
    if (d->hp <= 0)
    {

        printf("You died! Respawn at (100,100) "
               "with full HP, score halved\n");

        d->x = 100.0f;
        d->y = 100.0f;
        d->hp = d->max_hp;
        d->score /= 2;
    }

    // ==========================================
    // ตรวจสอบ Level Up
    // ทุก 400 คะแนนต่อ 1 Level
    // Lv.N ต้องมีคะแนนอย่างน้อย N * 400
    // ==========================================
    while (d->score >= d->level * 400)
    {

        d->level++;
        d->max_hp += 10;
        d->hp = d->max_hp;

        printf("LEVEL UP! Now Lv.%d (max HP %d)\n",
               d->level,
               d->max_hp);
    }
}

// ==========================================
// ส่วนที่ 6 — main
// เรียก srand ครั้งเดียวต้นโปรแกรม
// วนแสดง menu จนกดเลือก 5
// ตอน Load จะแสดง Before load เทียบกับ Loaded!
// ==========================================
int main()
{

    // สุ่มตัวเลขครั้งเดียวตอนเริ่มโปรแกรม
    srand((unsigned)time(NULL));

    GameData data = {
        234.5f,
        189.0f,
        85,
        100,
        7,
        2350};

    int choice;

    while (1)
    {

        printf("1. Save, 2. Load, 3. Random action, "
               "4. Show state, 5. Quit: ");

        if (scanf("%d", &choice) != 1)
        {

            // invalid input เช่น letters
            // ต้อง clear buffer ไม่เช่นนั้น loop จะไม่จบ
            int c;

            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            if (c == EOF)
            {
                break;
            }

            continue;
        }

        // ======================================
        // Choice 1 — Save
        // ======================================
        if (choice == 1)
        {

            if (saveGame(SAVE_FILE_PATH, &data))
            {

                printf("Saved to %s\n",
                       SAVE_FILE_PATH);
            }
            else
            {

                printf("Cannot open %s for writing\n",
                       SAVE_FILE_PATH);
            }
        }

        // ======================================
        // Choice 2 — Load
        // ======================================
        else if (choice == 2)
        {

            printf("Before load: ");
            printData(&data);

            int result = loadGame(SAVE_FILE_PATH, &data);

            if (result == 1)
            {

                printf("Loaded! ");
                printData(&data);
            }
            else if (result == 0)
            {

                printf("No save file found (%s)\n",
                       SAVE_FILE_PATH);
            }
            else
            {

                printf("Save file %s is corrupted\n",
                       SAVE_FILE_PATH);
            }
        }

        // ======================================
        // Choice 3 — Random Action
        // ======================================
        else if (choice == 3)
        {

            randomAction(&data);

            printf("Now: ");
            printData(&data);
        }

        // ======================================
        // Choice 4 — Show State
        // ======================================
        else if (choice == 4)
        {

            printData(&data);
        }

        // ======================================
        // Choice 5 — Quit
        // ======================================
        else if (choice == 5)
        {

            break;
        }
    }

    return 0;
}
