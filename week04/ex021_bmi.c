#include <stdio.h>
#include <math.h>
int main()
{
    float weight, height, bmi;
    printf("BMI Calculator\n");
    printf("Input Weight (kg): ");
    scanf("%f", &weight);
    printf("Input Height (cm): ");
    scanf("%f", &height);
    float height_m;
    height_m = height / 100; // convert cm to m
    bmi = weight / (height_m * height_m);

    if (bmi < 18.5)
    {
        printf("Output BMI: %.2f →Underweight\n", bmi);
    }
    else if (bmi >= 18.5 && bmi < 24.9)
    {
        printf("Output BMI: %.2f → Normal ✓\n", bmi);
    }
    else if (bmi >= 25 && bmi < 29.9)
    {
        printf("Output BMI: %.2f → Overweight\n", bmi);
    }
    else
    {
        printf("Output BMI: %.2f → Obese\n", bmi);
    }

    return 0;
}