#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char in[BUFFER_SIZE];
  char out[BUFFER_SIZE];

  while (1){

    printf("[client] enter a phrase: ");
    fgets(in, sizeof(in), stdin);
    write(to_server, in, sizeof(in));
    read(from_server, out, sizeof(out));
    printf("[client] returned response: %s\n", out);

  }

  return 0;
}
