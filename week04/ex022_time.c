#include <stdio.h>
#include <math.h>
int main()
{
    int seconds, hours, minutes, secs;

    printf("Time Converter\n");

    printf("Input: ");
    scanf("%d", &seconds);

    hours = seconds / 3600;

    minutes = (seconds % 3600) / 60;

    secs = seconds % 60;

    printf("Output: %02d:%02d:%02d\n", hours, minutes, secs);

    return 0;
}