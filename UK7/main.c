#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

#define YES 1
#define NO 0

int main(void)
{
	unsigned long int N; // dlinnyoe chislo N
	//long int COPY; // копия
	int i;
	int k;
	int n;
	int counter;
	unsigned long int mask;
	
	printf("Enter N\nN = ");
	scanf("%d", &N);

	mask = 0;
	i = 0;
	k = 31;

	while (i != 4)
	{
		for (n = 0, counter = 0; n != 8; ++n, --k)
		{
			if (N >> k & 01)
			{
				++counter;
			}
		}
		if (counter >= 4)
		{
			mask = mask << 8 | 0xff;
		}
		else
		{
			mask = mask << 8;
		}
		++i;
	}

	N = N & mask;

	//scanf("%d", &i);
	printf("Result: %lu", N);

	return 0;
}