#include <stdio.h>
#include <stdbool.h>

#define SIZE 30  // 큐의 크기 30 ****

typedef struct {
    int data[SIZE];  // 고정된 크기의 배열
    int front;  // 큐의 첫 번째 요소 인덱스
    int rear;   // 큐의 마지막 요소 인덱스
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
}

// 큐가 비어 있는지 확인
bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;  // rear가 front보다 작으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue *q) {
    return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
}

// 삽입 함수
bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;  // rear 위치에 데이터 추가
    return true;
}

// 삭제 함수
int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        initQueue(q);  // 큐가 비었을 경우 초기화 ****
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

// 큐 상태 출력
void printQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }
    printf("큐의 현재 상태: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);

    int choice;
    int value;

    printf("선형 큐 프로그램\n");

    while (true) {
        printf("메뉴 선택:\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 상태 출력\n");
        printf("4. 종료\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // 삽입
                printf("삽입할 값을 입력하세요: ");
                scanf("%d", &value);
                if (enqueue(&q, value)) {
                    printf("삽입 완료: %d\n", value);
                }
                break;

            case 2:  // 삭제
                value = dequeue(&q);
                if (value != -1) {
                    printf("삭제된 값: %d\n", value);
                }
                break;

            case 3:  // 출력
                printQueue(&q);
                break;

            case 4:  // 종료
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("잘못된 선택입니다. 1~4 중에서 선택해주세요.\n");
        }
    }

    return 0;
}
 
