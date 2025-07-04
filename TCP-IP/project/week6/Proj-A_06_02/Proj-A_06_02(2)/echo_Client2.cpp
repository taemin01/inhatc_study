#include "../../Common.h"

#define BUF_SIZE 1024

void ErrorHandling(const char* message);

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	SOCKET hSocket;
	char message[BUF_SIZE];
	int strLen, recv_len, recv_cnt;
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
		ErrorHandling("connect() error");
	else
		puts("Connetcted.........");

	while (1) {
		fputs("Input message(Q to quit) : ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;
		
		strLen = send(hSocket, message, strlen(message), 0);

		recv_len = 0;
		while (recv_len < strLen) {
			recv_cnt = recv(hSocket, &message[recv_len], BUF_SIZE - 1, 0);
			if (recv_cnt == -1) ErrorHandling("read() error!");
			recv_len += recv_cnt;
		}
		message[recv_len] = 0;
		printf("Message from server : %s", message);
	}

	closesocket(hSocket);
	WSACleanup();
	return 0;
}

void ErrorHandling(const char* message) {
	fputs(message, stderr); //유니코드 문자열 출력
	fputc('\n', stderr);
	exit(1);
}