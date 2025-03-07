#include <stdio.h>

int main() {
  int size;                  // 크기
  int stars, blank1, blank2; // , 1 , 2 별의 갯수 빈칸 의 갯수 빈칸 의 갯수
  int i, j;                  // 반복문을 위한 변수

  scanf("%d", &size);

  blank1 = (size * 2) - 2;
  blank2 = 0;

  for (i = 0; i < size; i++) {
    for (blank2 = 0; blank2 < i; blank2++) {
      printf(" ");
    }
    printf("*");
    for (j = 0; j < blank1; j++) {
      printf(" ");
    }
    blank1 = blank1 - 2;
    printf("*\n");
  }

  stars = size * 2;

  for (i = 0; i < size; i++) {
    for (j = 0; j < stars; j++) {
      printf("*");
    }
    printf("\n");
  }

  for (i = 0; i < size; i++) {
    for (blank2 = 0; blank2 < i; blank2++) {
      printf(" ");
    }  
    for (j = 0; j < (stars-(i*2)); j++) {
      printf("*");
    }
    printf("\n");
  }

  for (i = 0; i < stars; i++) {
    printf("*");
  }
  printf("\n");
  return 0;
}