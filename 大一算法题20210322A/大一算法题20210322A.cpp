#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct A {
	int step;
	int x;
}arr[1000000];
int mark[200000];

int main()
{
	int start, end;
	int head, tail;
	int m;

	scanf("%d%d", &start, &end);
	
	if (start == end)
	{
		printf("0");
	}
	if (start > end)
	{
		printf("%d", start - end);
	}
	memset(mark, 0, sizeof(mark));
	head = tail = 0;
	arr[tail].step = 0;
	arr[tail++].x = start;
	mark[start] = 1;
	m = end-start;

	while (head < tail)
	{
	    if (arr[head].step > m)
		{
			head++;
			continue;
		}
		if (arr[head].x > 1 && !mark[arr[head].x - 1])
		{
			arr[tail].step = arr[head].step + 1;
			arr[tail++].x = arr[head].x - 1;
			mark[arr[head].x - 1] = 1;
		}
		if (arr[head].x < 200000 && !mark[arr[head].x + 1])
		{
			arr[tail].step = arr[head].step + 1;
			arr[tail++].x = arr[head].x + 1;
			mark[arr[head].x + 1] = 1;
		}
		if (arr[head].x < 100000 && !mark[2 * arr[head].x])
		{
			arr[tail].step = arr[head].step + 1;
			arr[tail++].x = 2 * arr[head].x;
			mark[2 * arr[head].x] = 1;
		}
		if (arr[head].x - 1 == end || arr[head].x + 1 == end || arr[head].x * 2 == end)
		{
			printf("%d", arr[head].step + 1);
			break;	
		}
		head++;
	}

	return 0;
}

