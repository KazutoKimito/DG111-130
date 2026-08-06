#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()

{

    // 1. for loop — เหมาะสมเมื่อทราบจํานวนรอบที่แน่นอน
    printf("วิธีที่ 1: for loop\n");
    for (int i = 1; i <= 10; i++)
    {
        // โค้ดที่ต้องการให้ทํางานซํ้า
        printf("รอบที่ %d\n", i);
    }

    // 2. while loop — เช็คเงื่อนไขก่อนท างาน (อาจไม่ท างานเลยถ้าเงื่อนไขเป็นเท็จตั้งแต่แรก)
    printf("วิธีที่ 2: while loop\n");
    int i = 1;
    while (i <= 10)
    {
        // โค้ดที่ต้องการให้ทํางานซํ้า
        printf("รอบที่ %d\n", i);
        i++;
    }

    // 3. do-while loop — ทํางานก่อนอย่างน้อย 1 รอบ แล้วจึงเช็คเงื่อนไข
    printf("วิธีที่ 3: do-while loop\n");
    int i = 1;
    do
    {
        // โค้ดที่ต้องการให้ทํางานซํ้า
        printf("รอบที่ %d\n", i);
        i++;
    } while (i <= 10);

    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += i;
    }
    printf("แสดง: Sum = %d\n", sum);
}