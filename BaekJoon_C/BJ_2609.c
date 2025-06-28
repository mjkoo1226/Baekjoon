#include <stdio.h>

int lcd_calc(int a, int b){
    if(a>b){
        return lcd_calc(a-b, b);
    }
    else if(a<b){
        return lcd_calc(b-a, a);
    }
    else{
        return a;
    }
}

int main(void){
    int a, b;
    int lcd, gcm;
    scanf("%d %d", &a, &b);
    lcd = lcd_calc(a , b);
    gcm = a * b / lcd;
    printf("%d\n%d", lcd, gcm);
    return 0;
}