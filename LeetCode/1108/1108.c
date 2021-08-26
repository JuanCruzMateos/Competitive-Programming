#include <stdio.h>
#include <stdlib.h>
#define DIM 30

/*
1108. Defanging an IP Address:
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
*/
/*
Success Details :
Runtime: 0 ms, faster than 100.00% of C online submissions for Defanging an IP Address.
Memory Usage: 5.5 MB, less than 52.71% of C online submissions for Defanging an IP Address.
*/


char * defangIPaddr(char * address);


int main(int argc, char const *argv[])
{
	char address[DIM] = "120.12.3.8";
	char* dIP;

	dIP = defangIPaddr(address);
	printf("%s\n", address);
	printf("%s\n", dIP);
	free(dIP);

	return 0;
}

char * defangIPaddr(char * address){
	int i, j, n = 0;
	char *sol;

	sol = (char*) malloc(sizeof(char)*22);
	j = 0; i = 0;
	do {
		if (address[i] != '.')
			sol[j++] = address[i];
		else {
			sol[j++] = '[';
			sol[j++] = '.';
			sol[j++] = ']';
		}
		i++;
	} while (address[i-1] != '\0');
	return sol;
}