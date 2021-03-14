#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	const long long r = RAND_MAX / 2;
	long long x, y;
	unsigned int epoch, cnt_in;
	int i;
	long double pi;
	
	srand((unsigned int)time(NULL));

	for(epoch = 0, cnt_in = 0; epoch < INT_MAX;) {
		for(i = 0; i <= 1000000; i++) {
			x = rand() - r;
			y = rand() - r;
			
			if(x*x + y*y <= r*r) {
				cnt_in++;
			}
		}
		
		epoch += i;
		pi = (long double)cnt_in / (epoch >> 2);

		printf("%10u, %Lf\n", epoch, pi);
	}
	
	printf("\nPI calcurated is: %Lf\n", pi);

	return 0;
}
