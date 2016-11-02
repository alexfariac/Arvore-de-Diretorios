/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <time.h>
#include "arrdir.h"

int main(int argc, char *argv[]) {
	const time_t timer = time(NULL);
	printf("%s\n", ctime(&timer));	
	return 0;
}
