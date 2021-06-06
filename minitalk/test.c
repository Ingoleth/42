#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "libft.h"

int main (void)
{
	char c[10];
	t_list *test;

	test = NULL;
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	//ft_lstadd_back(&test, ft_lstnew((void *)'\n'));
	c[7] = '\n';
	gettimeofday(&stop, NULL);
	printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}