/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(
    int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20],
                 int wr[10], int wc); // 배정 결과를 출력한다.

int main() {
  char mnames[10][20];        // 남학생명단(최대 10명)
  int mroom[10];              // 남학생명단별 호실 배정 목록
  char wnames[10][20];        // 여학생명단(최대 10명)
  int wroom[10];              // 여학생명단별 호실 배정 목록
  int person[2][5] = {0};     // 2개 층별 5개 호실의 배정 인원 수
  int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
  int menu;

  srand(time(0));
  printf("===========================================\n");
  printf("생활관 호실 배정 프로그램\n");
  printf("===========================================\n");
  while (1) {
    printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
    scanf("%d", &menu);
    if (menu == 0)
      break;
    else if (menu == 1) {
      if (mcount >= 10) {
        printf("정원 초과입니다. 등록불가!\n");
        continue;
      }
      printf("학생 이름은? > ");
      scanf("%s", mnames[mcount]);
      int roomno = findRoom(person[0]);
      mroom[mcount] = 100 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
      mcount++;
    } else if (menu == 2) {
      if (wcount >= 10) {
        printf("정원 초과입니다. 등록불가!\n");
        continue;
      }
      printf("학생 이름은? > ");
      scanf("%s", wnames[wcount]);
      int roomno = findRoom(person[1]);
      wroom[wcount] = 200 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
      wcount++;
    }
  }

  printf("===========================================\n");
  printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
  printf("===========================================\n");
  printReport(mnames, mroom, mcount, wnames, wroom, wcount);

  return 0;
}

int findRoom(int persons[5]) {
  /*
  5개의 호실 중 빈방을 랜덤으로 찾음 (각 방마다 최대 2인) ->
  랜덤한 호실을 선택한 후, 해당 방의 인원이 2명 미만이라면 배정하고 리턴 ->
  모든 방이 가득 찬 경우, -1을 반환하여 더 이상 배정할 수 없도록 함.
  */

  int full = 1; 
  for (int i = 0; i < 5; i++) {
    if (persons[i] < 2) {
      full = 0;
      break;
    }
  }

  if (full) {
    return -1;
  }

  int roomno;
  while (1) {
    roomno = rand() % 5;
    if (persons[roomno] < 2) {
      persons[roomno]++;
      return roomno + 1;
    }
  }
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20],
                 int wr[10], int wc) {
  /*
  남학생과 여학생의 호실 배정 결과를 출력 -> 
  각각의 학생 명단과 해당 배정된 방 번호를 출력 ->
  호실별로 배정된 학생 명단을 정리해서 출력
*/
  printf("\n=== 남학생 호실 배정 ===\n");
  for (int i = 0; i < mc; i++) {
    printf("%s - %d호\n", mn[i], mr[i]);
  }

  printf("\n=== 여학생 호실 배정 ===\n");
  for (int i = 0; i < wc; i++) {
    printf("%s - %d호\n", wn[i], wr[i]);
  }

  printf("\n=== 호실별 배정 명단 ===\n");
  for (int i = 1; i <= 5; i++) {
    printf("%d호실: ", 100 + i);
    for (int j = 0; j < mc; j++) {
      if (mr[j] == 100 + i)
        printf("%s ", mn[j]);
    }
    printf("\n");

    printf("%d호실: ", 200 + i);
    for (int j = 0; j < wc; j++) {
      if (wr[j] == 200 + i)
        printf("%s ", wn[j]);
    }
    printf("\n");
  }
}
