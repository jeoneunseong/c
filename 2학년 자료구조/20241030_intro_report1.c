#include <stdio.h>

int main() {
    int scores[10];  
    int sum = 0;    
    float average;   

    for (int i = 0; i < 10; i++) {
        printf("학생 %d의 성적을 입력하세요 (0~100): ", i + 1);
        scanf("%d", &scores[i]);

      
        if (scores[i] < 0 || scores[i] > 100) {
            printf("잘못된 입력입니다. 0~100 사이의 값을 입력하세요.\n");
            i--; 
            continue;
        }

        sum += scores[i]; 
    }

    average = sum / 10.0;

    printf("전체 학생의 평균 점수: %.2f\n", average);

    return 0;
}
