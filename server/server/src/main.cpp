#include "Server.h"

int main() {
	srand(time(NULL));
	Server server;
	server.Run();
	return EXIT_SUCCESS;
}