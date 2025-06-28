// #include <stdio.h>

// int main(void){
//     int n, n2, len = 0;
//     scanf("%d", &n);
    
//     // n의 자리수 세기에 사용할 변수
//     // n을 그대로 사용하면 나중에 자리수 추출 시 사용 불가
//     n2 = n;

//     // 자리수 세기
//     while (n2 > 0) {
//         n2 /= 10;
//         len++;
//     }
//     // printf("%d", len);

//     // 가장 높은 자리수부터 출력해야하므로 10^len 구해놓기
//     int digit = 1;
//     for(int i = 0; i < len; i++){
//         digit *= 10;
//     }

//     for (int i = 0; i < len; i++){
//         // k번째 자리수는 10^(k-1)로 나눈 몫
//         digit /= 10;
//         int num = n / digit;
//         n %= digit;
//         printf("%d", num);
        
//         // 맨 마지막엔 콤마 안찍어야함
//         if ((i + 1 - len % 3) % 3 == 0 && i != len - 1){
//             printf(",");
//         }
//     }

//     return 0;
// }
#include <stdio.h>

int main(void){
    int a, b, a2, b2;
    int gcd, lcm;
    scanf("%d %d", &a, &b);
    
    // gcd(최대공약수, greatest common deviser) 구하기
    a2 = a;
    b2 = b;
    while(a2 != 0 && b2 !=0){
        if (a2 > b2){
            a2 -= b2;
        }
        else{
            b2 -= a2;
        }
    }
    gcd = a2;

    // lcm(최소공배수, least common multipliser) 구하기
    lcm = a * b / gcd;

    printf("%d\n%d", gcd, lcm);
    return 0;
}