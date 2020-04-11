/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Yumi Lee                   ylee204@myseneca.ca
   2)Dongwook Hwang             dhwang10@myseneca.ca
   3)Byeongsuk Yoo              bsyoo@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "extra_helper.h"

// clearKeyboard: clear input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: to ask users whether to proceed to next step by pushing the enter button
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: to make sure if users input demical number
int getInt(void)
{
	char inputNL;
	int input, flag = 1;

	while (flag)
	{
		scanf("%d%c", &input, &inputNL);

		if (inputNL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else
		{
			flag = 0;
		}
	}

	return input;
}

// getIntInRange: to make sure if users input the number within the range of the menu
int getIntInRange(int min, int max)
{
	int flag = 1;
	int input;

	while (flag)
	{
		input = getInt();

		if (input < min || input > max)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
		else
		{
			flag = 0;
		}
	}

	return input;
}

// yes: to make sure yes or no
int yes(void)
{
	char input1, input2;
	int value, repeatFlag = 1;

	while (repeatFlag)
	{
		scanf(" %c%c", &input1, &input2);
		if ((input1 == 'Y' || input1 == 'y' || input1 == 'N' || input1 == 'n') && input2 == '\n')
		{
			repeatFlag = 0;
			value = (input1 == 'Y' || input1 == 'y') ? 1 : 0;
		}
		else
		{
			repeatFlag = 1;
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}

	return value;
}

// displayWelcome: to diplay welcome message
void displayWelcome(void)
{
	printf("******************** Seneca Cycling Race Results ********************\n");
}

// menu: to display default menu list and return the number users choose
int menu(void)
{
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
	printf(": ");

	return getIntInRange(0, 4);
}