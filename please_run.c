/**
 * KNOWN BUG LOG:
 * 
 *
 * FEATURES TO ADD:
 * other math functions
 * random functionality
 * compare functions
 */

/**
 * C POLITE COMPILER AND RUNNER
 * CREATED BY LOGAN FRANKE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// ### Program accessable variables ###
int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
char g[100];
char h[100];
char i[100];
char j[100];

// getNum - Gets a number for a math command with variable handling
int getNum(int line, FILE* fp) {
	char next[50];
	if(fscanf(fp, "%s", next) != 1) {
		printf("ERROR: not enough arguments line %d!\n", line);			
		fclose(fp);
		return -1;
	}

	if(strcmp(next, "$") == 0) {
		int var;
		fscanf(fp, "%d", &var);
		if(var > 6 || var < 0) {
			printf("ERROR: Specified variable %d is not availible line %d!\n", var, line);
			fclose(fp);
			return INT_MIN;
		}
		switch(var) {
			case(1):
				return a;
				break;	
			case(2):
				return b;
				break;
			case(3):
				return c;
				break;
			case(4):
				return d;
				break;
			case(5):
				return e;
				break;
			case(6):
				return f;
				break;
			default:
				printf("ERROR: Something terrible has happened on line %d!\n", line);
				return INT_MIN;
				break;
		}
	} else {
		return atoi(next);
	}
}

int main(int argc, char** argv) {
		
	// Check that all arguments are present
	if(argc < 2) {
		printf("Invalid input! Use \"please_run -h\" for help.\n");
		return 0;
	}

	// please_run -h code
	if(strcmp(argv[1], "-h") == 0) {
		printf("       ***** C POLITE *****\n");
		printf(" ** program parser and executer **\n");
		printf(" Usage: please_run <program.cpol>\n");
		printf("\n");
		printf(" Users have six integer variables\n");
		printf(" under the indexes of 1-6 and four\n");
		printf(" string variables with max length\n");
		printf(" of 100 chars with indexes 7-10\n");
		printf("\n");
		printf(" cpol commands:\n");
		printf(" please - Asks the computer nicely\n");
		printf(" to do a command (required)\n");
		printf(" usage: please <command>\n");
		printf(" println - Prints a message with a line break\n");
		printf(" usage: println <message> donethankyoucomputer\n");
		printf(" print - Prints a message\n");
		printf(" usage: print <message> donethankyoucomputer\n");
		printf(" printvar: Prints the value of a variable (no line break)\n");
		printf(" usage: printvar <1-10>\n");
		printf(" input - Allows user specified input\n");
		printf(" fed into one of the ten variables\n");
		printf(" usage: input <1-10>\n");
		printf(" add - Adds two numbers (use \"$ \" before variable indexes)\n");
		printf(" example: add 3 $ 1 $ 4 ... adds variable 1 and 4\n");
		printf(" usage: add <destination> <num1> <num2>\n");
		printf(" sub - Subtracts two numbers (use \"$ \" before variable indexes)\n");
		printf(" example: sub 3 $ 1 $ 4 ... subtracts variable 1 and 4\n");
		printf(" usage: sub <destination> <num1> <num2>\n");
		printf(" mult - Multiplies two numbers (use \"$ \" before variable indexes)\n");
		printf(" example: mult 3 $ 1 $ 4 ... multiplies variable 1 and 4\n");
		printf(" usage: mult <destination> <num1> <num2>\n");
		printf(" div - Divides two numbers (use \"$ \" before variable indexes)\n");
		printf(" example: div 3 $ 1 $ 4 ... Divides variable 1 and 4\n");
		printf(" usage: div <destination> <num1> <num2>\n");
		printf(" thankyou - Ends the program nicely (required)\n");
		printf(" usage: thankyou\n");
		return 0;
	}

	
	// Open the program file
	FILE* fp = fopen(argv[1], "rb");

	if(fp == NULL) {
		printf("ERROR: Failed to open file!\n");
		return 1;
	}
	
	// Parse the program file until it is over
	char cursor[50];
	int line = 1;
	int thanked = 0;

	while((fscanf(fp, "%s", cursor)) == 1) {
		
		// Ensure the programmer is saying please before each command
		if(strcmp("please", cursor) == 0) {
			
			fscanf(fp, "%s", cursor);
			
			// println code
			if(strcmp(cursor, "println") == 0) {
				
				char lineBuffer[600];
				
				// Attempt to read message
				if(fgets(lineBuffer, 600, fp) == NULL) {
					printf("ERROR: Failed to read line %d!\n", line);
					fclose(fp);
					return 1;
				}
				
				// Check for string closure
				char *end = strstr(lineBuffer, "donethankyoucomputer");
				if(end == NULL) {
					printf("ERROR: donethankyoucomputer expected on line %d!\n", line);
					fclose(fp);
					return 1;
				}
				*end = '\0';

				// Remove leading space from fscanf
				if(lineBuffer[0] == ' ') {
					memmove(lineBuffer, lineBuffer + 1, strlen(lineBuffer));
				}

				printf("%s\n", lineBuffer);
			}

			// print code
			else if(strcmp(cursor, "print") == 0) {
				
				char lineBuffer[600];
				
				// Attempt to read message
				if(fgets(lineBuffer, 600, fp) == NULL) {
					printf("ERROR: Failed to read line %d!\n", line);
					fclose(fp);
					return 1;
				}
				
				// Check for string closure
				char *end = strstr(lineBuffer, "donethankyoucomputer");
				if(end == NULL) {
					printf("ERROR: donethankyoucomputer expected on line %d!\n", line);
					fclose(fp);
					return 1;
				}
				*end = '\0';

				// Remove leading space from fscanf
				if(lineBuffer[0] == ' ') {
					memmove(lineBuffer, lineBuffer + 1, strlen(lineBuffer));
				}

				printf("%s", lineBuffer);
			}

			// printvar code
			else if(strcmp(cursor, "printvar") == 0) {
				int var = 0;
				if(fscanf(fp, " %d", &var) != 1) {
					printf("ERROR: No specified variable to print line %d!\n", line);
					printf("printvar usage: printvar <1-10>\n");
					fclose(fp);
					return 1;
				}
				switch(var) {
					case(1):
						printf("%d", a);
						break;
					case(2):
						printf("%d", b);
						break;
					case(3):
						printf("%d", c);
						break;
					case(4):
						printf("%d", d);
						break;
					case(5):
						printf("%d", e);
						break;
					case(6):
						printf("%d", f);
						break;
					case(7):
						printf("%s", g);
						break;
					case(8):
						printf("%s", h);
						break;
					case(9):
						printf("%s", i);
						break;
					case(10):
						printf("%s", j);
						break;
					default:
						printf("ERROR: Specified variable %d is not availible line %d!\n", var, line);
						fclose(fp);
						return 1;
				}
			}
			// input code - user has six int variables to input into and four str
			else if(strcmp(cursor, "input") == 0) {
				int into = 0;
				if(fscanf(fp, " %d", &into) != 1) {
					printf("ERROR: No specified input variable line %d!\n", line);
					printf("input usage: input <1-10>\n");
					fclose(fp);
					return 1;
				}
				char buffer[100];
				switch(into) {
					case(1):
						fgets(buffer, 100, stdin);
						a = atoi(buffer);
						break;
					case(2):
						fgets(buffer, 100, stdin);
						b = atoi(buffer);
						break;
					case(3):
						fgets(buffer, 100, stdin);
						c = atoi(buffer);
						break;
					case(4):
						fgets(buffer, 100, stdin);
						d = atoi(buffer);
						break;
					case(5):
						fgets(buffer, 100, stdin);
						e = atoi(buffer);
						break;
					case(6):
						fgets(buffer, 100, stdin);
						f = atoi(buffer);
						break;
					case(7):
						fgets(g, 100, stdin);
						g[strcspn(g, "\n")] = 0;
						break;
					case(8):
						fgets(h, 100, stdin);
						h[strcspn(h, "\n")] = 0;
						break;
					case(9):
						fgets(i, 100, stdin);
						i[strcspn(i, "\n")] = 0;
						break;
					case(10):
						fgets(j, 100, stdin);
						j[strcspn(j, "\n")] = 0;
						break;
					default:
						printf("ERROR: Specified variable %d is not availible line %d!\n", into, line);
						fclose(fp);
						return 1;
				}
			}

			// add code
			else if(strcmp(cursor, "add") == 0) {
				int dest;
				if(fscanf(fp, "%d", &dest) != 1) {
					printf("ERROR: Specified variable %d is not availible line %d!\n", dest, line);
					fclose(fp);
					return 1;
				}
				int num1 = getNum(line, fp);
				int num2 = getNum(line, fp);
				if(num1 == INT_MIN || num2 == INT_MIN) {
					return 1;
				}
				switch(dest) {
					case(1):
						a = num1 + num2;
						break;
					case(2):
						b = num1 + num2;
						break;
					case(3):
						c = num1 + num2;
						break;
					case(4):
						d = num1 + num2;
						break;
					case(5):
						e = num1 + num2;
						break;
					case(6):
						f = num1 + num2;
						break;
					default:
						printf("ERROR: Something terrible has happened on line %d!\n", line);
						return 1;
						break;
				}
			}

			// sub code 
			else if(strcmp(cursor, "sub") == 0) {
				int dest;
				if(fscanf(fp, "%d", &dest) != 1) {
					printf("ERROR: Specified variable %d is not availible line %d!\n", dest, line);
					fclose(fp);
					return 1;
				}
				int num1 = getNum(line, fp);
				int num2 = getNum(line, fp);
				if(num1 == INT_MIN || num2 == INT_MIN) {
					return 1;
				}
				switch(dest) {
					case(1):
						a = num1 - num2;
						break;
					case(2):
						b = num1 - num2;
						break;
					case(3):
						c = num1 - num2;
						break;
					case(4):
						d = num1 - num2;
						break;
					case(5):
						e = num1 - num2;
						break;
					case(6):
						f = num1 - num2;
						break;
					default:
						printf("ERROR: Something terrible has happened on line %d!\n", line);
						return 1;
						break;
				}
			}

			// mult code
			else if(strcmp(cursor, "mult") == 0) {
				int dest;
				if(fscanf(fp, "%d", &dest) != 1) {
					printf("ERROR: Specified variable %d is not availible line %d!\n", dest, line);
					fclose(fp);
					return 1;
				}
				int num1 = getNum(line, fp);
				int num2 = getNum(line, fp);
				if(num1 == INT_MIN || num2 == INT_MIN) {
					return 1;
				}
				switch(dest) {
					case(1):
						a = num1 * num2;
						break;
					case(2):
						b = num1 * num2;
						break;
					case(3):
						c = num1 * num2;
						break;
					case(4):
						d = num1 * num2;
						break;
					case(5):
						e = num1 * num2;
						break;
					case(6):
						f = num1 * num2;
						break;
					default:
						printf("ERROR: Something terrible has happened on line %d!\n", line);
						return 1;
						break;
				}
			}
			
			// div code
			else if(strcmp(cursor, "div") == 0) {
				int dest;
				if(fscanf(fp, "%d", &dest) != 1) {
					printf("ERROR: Specified variable %d is not availible line %d!\n", dest, line);
					fclose(fp);
					return 1;
				}
				int num1 = getNum(line, fp);
				int num2 = getNum(line, fp);
				if(num1 == INT_MIN || num2 == INT_MIN) {
					return 1;
				}
				if(num2 == 0) {
					printf("ERROR: Divide by zero on line %d!\n", line);
					fclose(fp);
					return 1;
				}

				switch(dest) {
					case(1):
						a = num1 / num2;
						break;
					case(2):
						b = num1 / num2;
						break;
					case(3):
						c = num1 / num2;
						break;
					case(4):
						d = num1 / num2;
						break;
					case(5):
						e = num1 / num2;
						break;
					case(6):
						f = num1 / num2;
						break;
					default:
						printf("ERROR: Something terrible has happened on line %d!\n", line);
						return 1;
						break;
				}
			}

			// Invalid command code
			else {
				printf("ERROR: Unknown command line %d: %s!\n", line, cursor);
				fclose(fp);
				return 1;
			}
		
		// thankyou to end the program
		} else if(strcmp(cursor, "thankyou") == 0) {
			thanked = 1;
			break;

		// Invalid command code - Suggest the user forgor to say please
		} else {
			printf("ERROR: Unknown command line %d: %s!\n", line, cursor);
			printf("Did you forget to say please?\n");
			fclose(fp);
			return 1;
		}

		line++;
			
	}
	
	// Close the file
	fclose(fp);
	
	// Print an error if the user never thanked the computer
	if(thanked != 1) {
		printf("ERROR: Computer was not thanked at the end of the program!\n");
		printf("Add thankyou to line %d or later and try again!\n", line);
	}

	return 0;
}
