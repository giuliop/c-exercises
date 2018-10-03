#include "csapp.h"
#define TIMEOUT 5

jmp_buf buf;

void sigalarm_handler(int sig) {
	siglongjmp(buf, 1);
}

char * tgets(char * dst, int max, FILE *stream) {
	// install handler for alarm
	if (signal(SIGALRM, sigalarm_handler) == SIG_ERR) {
		unix_error("signal_error");
	}
	// set alarm
	alarm(TIMEOUT);
	return fgets(dst, max, stream);
}

int main() {
	char str[100];
	if (!sigsetjmp(buf, 1)) {
		tgets(str, 100, stdin);
		printf("You typed: %s\n", str);
	} else {
		printf("\nTimeout baby!\n");
	}
	return 0;
}
