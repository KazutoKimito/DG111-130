#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 5
#define NAME_LEN 30
#define FILE_NAME "highscores.txt"

// ==========================================
// ส่วนที่ 1 — ประกาศ struct Player
// ==========================================
typedef struct
{
    char name[NAME_LEN];
    int score;
} Entry;

// ==========================================
// ส่วนที่ 2 — สร้างไฟล์คะแนนเริ่มต้น
// ==========================================
void createDefault(const char *filename)
{
    FILE *f = fopen(filename, "w");

    if (f == NULL)
    {
        printf("Cannot create %s\n", filename);
        return;
    }

    fprintf(f, "Diana 15600\n");
    fprintf(f, "Bob 12300\n");
    fprintf(f, "Eve 9800\n");
    fprintf(f, "Alice 8500\n");
    fprintf(f, "Charlie 7200\n");

    fclose(f);
}

// ==========================================
// ส่วนที่ 3 — โหลดและบันทึกคะแนน
// ==========================================
int loadScores(const char *filename, Entry list[])
{
    FILE *f = fopen(filename, "r");

    if (f == NULL)
    {
        return 0;
    }

    int count = 0;
    Entry e;

    while (count < MAX_ENTRIES &&
           fscanf(f, "%29s %d", e.name, &e.score) == 2)
    {

        list[count] = e;
        count++;
    }

    fclose(f);
    return count;
}

void saveScores(const char *filename, const Entry list[], int count)
{
    FILE *f = fopen(filename, "w");

    if (f == NULL)
    {
        printf("Cannot write %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s %d\n", list[i].name, list[i].score);
    }

    fclose(f);
}

// ==========================================
// ส่วนที่ 4 — แสดงตารางคะแนน
// ==========================================
void showLeaderboard(const Entry list[], int count)
{
    printf("=== High Scores ===\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d. %-12s %6d\n",
               i + 1,
               list[i].name,
               list[i].score);
    }

    printf("===================\n");
}

// ==========================================
// ส่วนที่ 5 — เพิ่มคะแนนใหม่เข้าสู่ Top 5
// ==========================================
int addScore(Entry list[], int *count, const char *name, int score)
{

    int pos = *count;

    for (int i = 0; i < *count; i++)
    {
        if (score > list[i].score)
        {
            pos = i;
            break;
        }
    }

    if (pos >= MAX_ENTRIES)
    {
        return 0;
    }

    int last = (*count < MAX_ENTRIES)
                   ? *count
                   : MAX_ENTRIES - 1;

    for (int i = last; i > pos; i--)
    {
        list[i] = list[i - 1];
    }

    strncpy(list[pos].name, name, NAME_LEN - 1);
    list[pos].name[NAME_LEN - 1] = '\0';
    list[pos].score = score;

    if (*count < MAX_ENTRIES)
    {
        (*count)++;
    }

    return 1;
}

// ==========================================
// ส่วนที่ 6 — โปรแกรมหลัก
// ==========================================
int main()
{

    Entry list[MAX_ENTRIES];

    // โหลดไฟล์ ถ้าไม่มีไฟล์ให้สร้างไฟล์เริ่มต้น
    int count = loadScores(FILE_NAME, list);

    if (count == 0)
    {
        printf("%s not found. Creating default file...\n",
               FILE_NAME);

        createDefault(FILE_NAME);
        count = loadScores(FILE_NAME, list);
    }

    // แสดงตารางคะแนนปัจจุบัน
    showLeaderboard(list, count);

    // รับคะแนนใหม่ไปเรื่อย ๆ จนกว่าจะพิมพ์ q
    char name[NAME_LEN];
    int score;

    while (1)
    {

        printf("Enter name (q to quit): ");

        if (scanf("%29s", name) != 1 ||
            strcmp(name, "q") == 0)
        {
            break;
        }

        printf("Enter score: ");

        if (scanf("%d", &score) != 1)
        {

            // ล้างข้อมูลที่ไม่ถูกต้องออกจาก buffer
            int c;

            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Invalid score\n");
            continue;
        }

        // เพิ่มคะแนน ถ้าอยู่ใน Top 5
        if (addScore(list, &count, name, score))
        {

            printf("Congratulations! You made the top %d!\n",
                   MAX_ENTRIES);

            saveScores(FILE_NAME, list, count);
        }
        else
        {

            printf("Score too low for the top %d.\n",
                   MAX_ENTRIES);
        }

        // แสดงตารางคะแนนหลังเพิ่มคะแนน
        showLeaderboard(list, count);
    }

    printf("Goodbye!\n");

    return 0;
}
