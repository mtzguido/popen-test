#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f;
	char buf[1024];

	/*
	 * The "2>/dev/null" is there so messages output
	 * to stderr don't end up on _our_ stderr (since
	 * we fork() inside popen(), they're the same
	 * file).
	 */
	f = popen("./test.sh 2>/dev/null", "r");
	if (!f) {
		fprintf(stderr, "popen failed\n");
		return 1;
	}

	while (fgets(buf, sizeof buf, f)) {
		/* Remove trailing newline */
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		printf("Received line: %s\n", buf);
	}

	pclose(f);
	return 0;
}

