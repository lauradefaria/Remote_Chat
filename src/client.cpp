#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <thread>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <vector>
#include <list>
#include <map>
#include <mutex>
#include <fstream>

using namespace std;

void str_overwrite()
{
	printf("\r%s", "> ");
	fflush(stdout);
}

void receive_message(int client_fd)
{
	char recv_msg[100];

	while (1)
	{
		bzero(recv_msg, 100);
		read(client_fd, recv_msg, 100);

		// cout << string(recv_msg) << flush;
		printf("\r%s", recv_msg);
		str_overwrite();
	}
}

void send_message(int client_fd)
{
	char send_msg[100];

	while (1)
	{
		bzero(send_msg, 100);

		str_overwrite();
		fgets(send_msg, 100, stdin);

		write(client_fd, send_msg, strlen(send_msg) + 1);
	}
}

int main(int argc, char **argv)
{
	int port = atoi(argv[2]);
	string user_name = string(argv[3]);
	char *host = argv[1];

	/* Construção do cliente */
	int client_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_aton(host, &server_addr.sin_addr);

	cout << "Conectando-se ao servidor " << string(host) << " na porta " << port << "..." << endl;

	if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		cout << "Conexão com o servidor falhou\n";
		return 0;
	}

	/* envia o username e recebe o nome da sala*/

	write(client_fd, user_name.c_str(), user_name.length() + 1);
	char server_name[100];
	read(client_fd, server_name, 100);

	cout << "Mensagem do servidor: " << string(server_name) << endl;

	thread t(receive_message, client_fd);
	thread t2(send_message, client_fd);

	t.join();
	t2.join();

	// char send_msg[100];

	// while (1)
	// {
	// 	bzero(send_msg, 100);

	// 	str_overwrite();
	// 	fgets(send_msg, 100, stdin);

	// 	write(client_fd, send_msg, strlen(send_msg) + 1);
	// }

	return 0;
}
