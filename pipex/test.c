#include <stdio.h>

int main(int argc, char **argv, char *const *envp) {
	int i;

	i = 0;
    while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
    }
    return 0;
}

