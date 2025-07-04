#include "../../Common.h"  // 공통 헤더 파일 포함

#define BUF_SIZE 1024               // 버퍼 크기 정의
#define RLT_SIZE 4                  // 결과값 크기 정의
#define OPSZ 4                      // 피연산자 크기 정의

void ErrorHandling(const char* message);  // 에러 처리 함수 선언

int main(int argc, char* argv[]) {
    WSADATA wsaData;
    SOCKET hSocket;
    char opmsg[BUF_SIZE];
    int result, opndCnt, i;
    SOCKADDR_IN servAdr;

    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("WSAStartup() error!");

    hSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (hSocket == INVALID_SOCKET)
        ErrorHandling("socket() error");

    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = inet_addr(argv[1]);
    servAdr.sin_port = htons(atoi(argv[2]));

    if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
        ErrorHandling("connect() error!");
    else
        puts("Connected...........");

    fputs("Operand count: ", stdout);
    scanf("%d", &opndCnt);
    opmsg[0] = (char)opndCnt;

    for (i = 0; i < opndCnt; i++) {
        printf("Operand %d: ", i + 1);
        scanf("%d", (int*)&opmsg[i * OPSZ + 1]);
    }

    fgetc(stdin);  // 개행 제거용
    fputs("Operator: ", stdout);
    scanf("%c", &opmsg[opndCnt * OPSZ + 1]);

    send(hSocket, opmsg, opndCnt * OPSZ + 2, 0);
    recv(hSocket, (char*)&result, RLT_SIZE, 0);

    printf("Operation result: %d \n", result);
    closesocket(hSocket);
    WSACleanup();

    return 0;
}

// 에러 메시지 출력 함수
void ErrorHandling(const char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}