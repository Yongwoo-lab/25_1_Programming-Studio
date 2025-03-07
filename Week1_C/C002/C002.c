#include <stdio.h>
int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수
int sum[3];       // ( , , ) 점호 인원 수 합계 남 여 전체
float ratio[3];   // ( , , ) 점호 인원 수 비율 남 여 전체
int i, j;         // 반복문을 위한 변수
int main() {
  printf("Check room (Men)\n");
  for (i = 1; i <= 2; i++) {
    for (j = 1; j <= 3; j++) {
      printf("Room #%d > ", ((100 * i) + j));
      scanf("%d", &person[i - 1][j - 1]);
      sum[0] += person[i - 1][j - 1];
      sum[2] += person[i - 1][j - 1];
    }
  }
  printf("Check room (Women)\n");
  for (i = 3; i <= 4; i++) {
    for (j = 1; j <= 3; j++) {
      printf("Room #%d > ", ((100 * i) + j));
      scanf("%d", &person[i - 1][j - 1]);
      sum[1] += person[i - 1][j - 1];
      sum[2] += person[i - 1][j - 1];
    }
  }
  ratio[0] = ((sum[0] / 24.0) * 100);
  ratio[1] = ((sum[1] / 24.0) * 100);
  ratio[2] = ((sum[2] / 48.0) * 100);
  printf("Check Result\n");
  printf("Men: %d/24 (%.1f%%)\n", sum[0], ratio[0]);
  printf("Women: %d/24 (%.1f%%)\n", sum[1], ratio[1]);
  printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[2]);

  return 0;
}