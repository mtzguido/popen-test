#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f;
	char buf[1024];

	f = popen("./test.sh", "r");
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

