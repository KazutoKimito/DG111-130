#include <stdio.h>
int main()
{
    // ประกาศและกําหนดค่าตัวแปร
    char name[50];
    int age;
    float gpa;
    char subject[30];

    // ใส่ข้อมูลส่วนตัว
    printf("=== Enter Data ===\n");
    printf("Name: ");
    scanf("%49s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("GPA: ");
    scanf("%f", &gpa);
    printf("Subject: ");
    scanf("%29s", subject);

    // แสดงข้อมูลส่วนตัว
    printf("\n=== Personal Card ===\n");
    printf("│ Name: %-19s │\n", name);
    printf("│ Age: %d years old %-8s│\n", age, "");
    printf("│ GPA: %-20.2f │\n", gpa);
    printf("│ Subject: %-16s │\n", subject);
    printf("└───────────────────────────┘\n");
    return 0;
}