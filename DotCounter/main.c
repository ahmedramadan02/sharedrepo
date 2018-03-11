#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define NUM_ASCII_BASE 48
#define DOT_ASCII_DEF  46

void dotCounter(const char*, char*);
void dotCounterWithPointers(const char*, char*);

int main()
{
	char* myArr = "www.google.com";
	char destArr[15] = {0};

	puts("Dot Counter with simple counter");
	dotCounterWithPointers(myArr, destArr);
	puts(destArr);

	puts("Dot Counter with pure pointers");
	dotCounterWithPointers(myArr, destArr);
	puts(destArr);

	return 0;
}

//using the normal way, with counter
void dotCounter(const char* source, char* dest){
	char* destL = dest; //copy the first address of dest here
	size_t sourceSize = strlen(source);
	int dotCounterVar = 0;

	dest++; //skip the first char, count will be added later
	for (int i = 0; i <= sourceSize; i++) {

		if (*source == DOT_ASCII_DEF || *source == NULL) {
			//put the number of chars here
			destL[i - dotCounterVar] = dotCounterVar + NUM_ASCII_BASE;
			dotCounterVar = 0; //rest the counter

		}
		else {
			//normal copy for the chars
			*dest = *source;
			dotCounterVar++; //still counting
		}

		source++;
		dest++;
	}

	//Terminate the dest
	*dest = '\0';
}

//using pointers size, without counter
void dotCounterWithPointers(const char* source, char* dest){
	char* destL = dest; //the initial position at 0
	size_t sourceSize = strlen(source);

	dest++; //skip the first char, count will be added later
	for (int i = 0; i <= sourceSize; i++) {
		if (*source == DOT_ASCII_DEF || *source == NULL) {
			*destL = dest - destL + NUM_ASCII_BASE - 1;
			destL = dest; //copy the current dot address
		}else{
			//normal copy for the chars
			*dest = *source;
		}

		source++;
		dest++;
	}

	//Terminate the dest
	*dest = '\0';
}

