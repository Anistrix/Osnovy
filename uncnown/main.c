#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000

void process_LINE(char buffer[], char *bgn, char *end); // ob'yavlayem funktsiuu

int main(void)
{
	char LINE[MAXLINE]; // ob'yevlayem massiv LINE
	char *bgn; // adres nachala funktsii LINE
	char *end; // adres kontsa funktii LINE
	int i; // dlya nahojdeniya \0
	int c;

	printf("Enter words:\n");
	gets(LINE); // schitivayem stroku i vnosim v massiv LINE
	bgn = &LINE[0]; // prisvaivayem ukasatelu bgn adres raspolozhenia nachala massiva LINE
	for (i = 0, c = LINE[i]; c != '\0'; ++i) // ishem /0
	{
		c = LINE[i];
	}
	end = &LINE[i]; // prisvaivayem ukasatelu end adres raspolozhenia kontsa stroki v massive LINE
	printf("\n%d\n%c\n%c\n%d\n%c", bgn, *bgn, *(bgn+1), end, *end);
	process_LINE(LINE, bgn, end); // vipolnayem funktsiu
	printf("Result: ");
	puts(LINE); // vivodim massiv LINE

	return 0;
}

void process_LINE(char buffer[], char *bgn, char *end) // telo funktsii
{
	int c; // tekushii simvol
	int prev_c; // predidushii simvol
	int i; // pozitsiya simvola
	int post_i; // positsiya simvola v finalnom variante
	int j; // positsiya pervogo simvola slova
	int k; // peremennaya
	int length; // dlina slova
	int img_length; // dlina mnimogo slova
	int img_i; // mnimii tekushii simvol
	int counter; // schyotchik bukv
	int flag; //
	int found; // ne slovo
	int finish; // ...

	found = NO;
	i = 0;
	prev_c = ' ';
	post_i = -1;
	finish = NO;

	do
	{
		c = buffer[i];
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // proverka na ne slovo
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // ishem konets slova
		{
			if (c == '\0')
			{
				finish = YES;
			}
			if (prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\t')
			{
				++post_i;
				buffer[post_i] = c;
			}
			else
			{
				flag = 0;
				length = i - j;
				if (found == NO)
				{
					counter = 0;
					for (img_i = 0, img_length = 0; bgn + img_i < end; ++img_i, ++k)
					{
						if (*(bgn + img_i) == ' ' || *(bgn + img_i) == '.' || *(bgn + img_i) == ',' || *(bgn + img_i) == '\n' || *(bgn + img_i) == '\t')
						{
							counter = 0;
						}
						if (counter == 0)
						{
							k = j;
						}
						if (buffer[k] == *(bgn + img_i))
						{
							++counter;
						}
						if (counter == length)
						{
							++flag;
						}
					}
				}
				if (flag < 2 || found == YES)
				{
					img_length = post_i + length + 1;
					for (k = j; post_i < img_length; ++k)
					{
						++post_i;
						buffer[post_i] = buffer[k];
					}
				}
				found = NO;
			}
		}
		else
		{
			if (prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\t')
			{
				j = i;
			}
			
		}
		prev_c = c;
		++i;

	} while (finish != YES);
}