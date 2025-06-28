#include <stdio.h>

void hanoi(int n, int a, int b, int c){
  if(n==0){
    return;
  }
  hanoi(n-1, a, c, b);
  printf("%d %d\n", a, c);
  hanoi(n-1, b, a, c);
}

int main(void) {
  int n;
  long long total=1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    total = total * 2;
  }
  printf("%lld\n", total - 1);
  hanoi(n, 1, 2, 3);
  return 0;
}