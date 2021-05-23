/*Exercise instructions explained in another file on repository named "Control_Structure_Explained".*/

#include <stdio.h>
#include <math.h>
int main() {
	char fName, lName;
	int choice;
	int flag = 1;
	long int phoneNum; //Option 1
	int digitSum, evenCnt, oddCnt, numQty1, numQty2, numQtyCnt, numQtyFlag, amazingCheck; //Option 1
	int nDavid, m; //Option 2
	int num1, num2, left, right, pwr, option3Flag = -1; //Option 3
	int a, b, c, aZero, bZero; //Option 4
	float sol1, solImg, sol2, sqr; //Option 4
	// Getting name initials and going into menu
	printf("Hello, what is the first letter of your name?\n");
	do
	{
		scanf(" %c", &fName);
	} while (!(('a' <= fName && fName <= 'z') || ('A' <= fName && fName <= 'Z')));
	do
	{
		scanf(" %c", &lName);
	} while (!(('a' <= lName && lName <= 'z') || ('A' <= lName && lName <= 'Z')));
	if ('a' <= fName && fName <= 'z')
		fName -= 32;
	if ('a' <= lName && lName <= 'z')
		lName -= 32;
	printf("Hello %c. %c, welcome to our menu!\n", fName, lName);
	//while loop runs as long as -1 isn't chosen
	while (flag)
	{
		printf("Choose 1 for phone, 2 for David, 3 for Mersenne, 4 for equation, -1 for exit\n");
		do
		{
			scanf("%d", &choice);
		} while (!(choice >= -1 && choice <= 4 && choice != 0));
		switch (choice)
		{
		//case 1 - getting phone number
		case 1:
			digitSum = 0;
			evenCnt = 0;
			oddCnt = 0;
			amazingCheck = -4;
			numQtyCnt = 0;
			numQtyFlag = 0;
			printf("Enter phone number (9 digits)\n");
			do
			{
				scanf("%ld", &phoneNum);
			} while (!(phoneNum > 99999999 && phoneNum < 1000000000));
			if (phoneNum % 2)
				printf("The number is odd\n");
			else
			{
				printf("The number is even\n");
				amazingCheck++;
			}
			for (int i = 0; i < 9; i++)
				digitSum += int(phoneNum / pow(10, i)) % 10;
			if (digitSum < 30)
				printf("The number is small\n");
			else if (digitSum < 40)
				printf("The number is medium\n");
			else
			{
				printf("The number is large\n");
				amazingCheck++;
			}
			for (int i = 0; i < 9; i++)
				if ((int(phoneNum / pow(10, i)) % 10) % 2)
					oddCnt++;
				else
					evenCnt++;
			if (oddCnt >= 7 || evenCnt >= 7)
			{
				printf("The number is special\n");
				amazingCheck++;
			}
			else
				printf("The number is not special\n");
			for (int i = 0; i < 9; i++)
			{
				numQtyCnt = 0;
				numQty1 = (int(phoneNum / pow(10, i)) % 10);
				for (int j = 0; j < 9; j++)
				{
					numQty2 = (int(phoneNum / pow(10, j)) % 10);
					if (numQty1 == numQty2)
						numQtyCnt++;
					if (numQtyCnt > 2)
					{
						printf("The number is not varied\n");
						numQtyFlag--;
						break;
					}
					if (i == 8 && j == 8)
					{
						printf("The number is varied\n");
						amazingCheck++;
					}
				}
				if (numQtyFlag)
					break;
			}
			if (!amazingCheck)
				printf("The number is amazing!\n");
			choice = 0;
			break;
		//case 2 - printing David's star
		case 2:
			printf("Enter size number:\n");
			do
			{
				scanf("%d", &nDavid);
			} while ((nDavid % 2 == 0) && !(nDavid > 6 && nDavid < 78));
			for (int i = -1; i < 2 ; i++) // loops for each star
			{
				for (int j = 0; j < 9 ; j++) // loops for each line
				{
					m = nDavid + i * 2;
					for (int k = 1; k < (2 * m); k++) // loops for each char
					{
						switch (j)
						{
						case 0:
						case 8:
							if (k == m )
								printf("O");
							else
								printf("-");
							break;
						case 1:
						case 7:
							if (k == m - 1 || k == m + 1)
								printf("O");
							else
								printf("-");
							break;
						case 2:
						case 6:
							printf("O");
							break;
						case 3:
						case 5:
							if (k == m - (m-2) || k == m + (m-2))
								printf("O");
							else
								printf("-");
							break;
						case 4:
							if (k == m - (m-3) || k == m + (m-3))
								printf("O");
							else
								printf("-");
							break;
						}
					}
					printf("\n");
				}
				printf("\n");
			}
			choice = 0;
			break;
		//case 3: - marsen numbers
		case 3:
			printf("Enter two numbers:\n");
			do
			{
				scanf("%d", &num1);
				scanf("%d", &num2);
			} while (num1 < 0 || num2 < 0);
			if (num1 > num2)
			{
				right = num1;
				left = num2;
			}
			else
			{
				right = num2;
				left = num1;	
			}
			pwr = int(ceil(log(left+1)/log(2))); // checking 2^x = left, what is x?
			while(pow(2,pwr)-1 <= right) // starting to check from the power of x
			{
				option3Flag = 0;
				printf("%d\n", int((pow(2, pwr)-1)));
				pwr++;
			}
			if (option3Flag)
				printf("None\n");
			choice = 0;
			break;
		// case 4 - solving an equation
		case 4:
			aZero = 0;
			bZero = 0;
			printf("Enter three numbers:\n");
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &c);
			if (a == 1)
				printf("x^2 ");
			else if (a == -1)
				printf("-x^2 ");
			else if (a == 0)
			{
				printf("");
				aZero = 1;
			}
			else
				printf("%dx^2 ", a);
			if (b > 0 && aZero)
				if (b == 1)
					printf("x ");
				else
					printf("%dx ", b);
			else if (b < 0 && aZero)
				if (b == -1)
					printf("-x ");
				else
					printf("%dx ", b);
			else if (b == 1)
				printf("+ x ");
			else if (b == -1)
				printf("- x ");
			else if (b == 0)
			{
				printf("");
				bZero = 1;
			}
			else if (b > 0)
				printf("+ %dx ", b);
			else
				printf("- %dx ", -b);
			if (c == 0 && bZero && aZero)
				printf("0 ");
			if (c == 0)
				printf("");
			else if (c > 0 && bZero && aZero)
				printf("%d ", c);
			else if (c < 0 && bZero && aZero)
				printf("%d ", c);
			else if (c > 0)
				printf("+ %d ", c);
			else
				printf("- %d ", -c);
			printf("= 0\n");
			if (a == 0 && a == b && c != 0)
			{
				printf("No solution!\n");
			}
			else if (a == b && b == c && c == 0)
			{
				printf("Infinite solutions!\n");
			}
			else if (a == 0)
			{
				sol1 = float(-c) / float(b);
				printf("x1 = %.3f\n", sol1);
			}
			else
			{
				sqr = float(pow(b, 2)) - 4 * float(a) * float(c);
				if (sqr < 0)
				{
					sqr = sqrt(-sqr);
					sol1 = float(-b)/float(2*a);
					solImg = float(pow(pow(sqr / (2 * a), 2), 0.5)); // making 'sqr/(2*a)' absolute by powering it by 2 and getting a root
					if (b == 0)
					{
						if (solImg == 1)
						{
							printf("x1 = i\n");
							printf("x2 = -i\n");
						}
						else
						{
							printf("x1 = %.3fi\n", solImg);
							printf("x2 = -%.3fi\n", solImg);
						}
					}
					else
					{
						if (solImg == 1)
						{
							if (sol1 == -0)
							{
								printf("x1 = 0 + i\n");
								printf("x2 = 0 - i\n");
							}
							else
							{
								printf("x1 = %.3f + i\n", sol1);
								printf("x2 = %.3f - i\n", sol1);
							}
						}
						else
						{
							printf("x1 = %.3f + %.3fi\n", sol1, solImg);
							printf("x2 = %.3f - %.3fi\n", sol1, solImg);
						}

					}
				}
				else if(sqr>0)
				{
					sqr = sqrt(sqr);
					sol1 = (-b + sqr) / (2 * a);
					sol2 = (-b - sqr) / (2 * a);
					if (sol1 == -0 && sol2 == -0)
						printf("x1 = 0\nx2 = 0\n");
					else if (sol1 == -0)
						if (sol1 > sol2)
							printf("x1 = 0\nx2 = %.3f\n", sol2);
						else
							printf("x1 = %.3f\nx2 = 0\n", sol2);
					else if (sol2 == -0)
						if (sol2 > sol1)
							printf("x1 = 0\nx2 = %.3f\n", sol1);
						else
							printf("x1 = %.3f\nx2 = 0\n", sol1);
					else if (sol1 > sol2)
						printf("x1 = %.3f\nx2 = %.3f\n", sol1, sol2);
					else
						printf("x1 = %.3f\nx2 = %.3f\n", sol2, sol1);
				}
				else
				{
					printf("x1 = %.3f\n", float(-b)/float(2*a));
				}
				
				
			}
			choice = 0;
			break;
		case -1:
			flag = 0;
			break;
		}
	}
	printf("Thank you, %c. %c, have a nice day!", fName, lName);
	return 0;
}
