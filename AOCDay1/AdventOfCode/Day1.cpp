#include <iostream>
#include <string>
using namespace std;

int depthReport[] = { 199, 200, 208, 210, 200, 207, 240, 269, 260, 263 };
int counter = 0;

void main(void) 
{
	for (int i = 1; i < sizeof(depthReport)/sizeof(depthReport[0]); i++) {
		if(depthReport[i] > depthReport[i-1])
		{
			counter++;
		}
	}

	printf("%i\n", counter);
}
