.PHONY: all clean re test

NAME=popen-test
all: $(NAME)

%: %.c
	$(CC) -Wall -Wextra $< -o $@

clean:
	rm -f $(NAME)

re: clean all
