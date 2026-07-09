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
    printf("\n=== Personal Info ===\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Subject: %s\n", subject);
    return 0;
}