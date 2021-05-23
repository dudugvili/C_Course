/*        -- An assignment I got in C coding course --
	Input: 2 strings and 1 num
	- Comparing how many chars are different and comparing different chars number to input number -
	Output: if input number equals the number of different chars print 'y', else print 'n'
	Exception: if any string is 'exit' terminate programm.
			   if input num is bigger than string length terminate programm.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define STR_ARRAY_MAX_SIZE 30

//checking if the strings are the same
int compareStrings(const char* p1 ,const char* p2)
{
	while (true)
	{
		if (*p1 == *p2 && *p1 == NULL)
			return 1;
		if (!(*p1 == *p2))
			return 0;
		*p1++;
		*p2++;
	}
}

//checking if the number is bigger than the 2 strings
int stringLength(char* p1, char* p2, int len)
{
	int i = 0;
	while (!(*(p1 + i) == NULL) || !(*(p2 + i) == NULL))
		i++;
	return (len > i);
}

//checking for difference number
void DiffersInNChars(char* s1, char* s2, int n)
{
	if (!(*s1 == *s2 && *s1 == NULL))
	{
		if (!(*s1 == *s2))
		{
			if(!(*s1 == NULL))
				*s1++;
			if (!(*s2 == NULL))
				*s2++;
			DiffersInNChars(s1, s2, n - 1);
		}
		else
		{
			if (!(*s1 == NULL))
				*s1++;
			if (!(*s2 == NULL))
				*s2++;
			DiffersInNChars(s1, s2, n);
		}
	}
	else
	{
		if (n == 0)
			printf("\"yes\"\n");
		else
			printf("\"no\"\n");
	}
}

int mains()
{
	int diff, flag = 1, compStr;
	char exit, firstString[STR_ARRAY_MAX_SIZE], secondString[STR_ARRAY_MAX_SIZE], * p1, * p2;
	while(flag)
	{
	printf("do you want to exit (y/n)?\n");
	scanf(" %c", &exit);
	if (!(exit == 'y'))
	{
		printf("please insert the first string (to exit please insert the word exit):\n");
		scanf(" %s", firstString);
		p1 = firstString;
		if (!(compareStrings(p1, "exit")))
		{
			printf("please insert the second string (to exit please insert the word exit):\n");
			scanf(" %s", secondString);
			p2 = secondString;
			if (!(compareStrings(p2, "exit")))
			{
				printf("please insert difference number:\n");
				scanf("%d", &diff);
				compStr = stringLength(p1, p2, diff);
				if (!compStr)
				{
					DiffersInNChars(p1, p2, diff);
				}
				else
					flag = 0;

			}
			else
				flag = 0;
		}
		else
			flag = 0;
	}
	else
		flag = 0;
	}
	return 0;
}
