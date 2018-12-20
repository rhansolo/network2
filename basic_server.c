#include "pipe_networking.h"

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("wkp");
    exit(1);
  }
}

int main() {
	

	int to_client;
	int from_client;
	char in[BUFFER_SIZE];
	signal(SIGINT, sighandler);

	while (1)
	{
	    from_client = server_handshake( &to_client );
	    while (read(from_client, in, sizeof(in)) ){
	      	printf("[server] received message: %s", in);
	      	char* tmp = in;
	      	while (*tmp){
		       *tmp = toupper((unsigned char) *tmp);
	   			tmp++;
	      	}
	      	write(to_client, in, sizeof(in));
   	 	}
	}
}
