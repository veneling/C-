#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <stdlib.h>		/* sleep */
#include <limits.h>		/* limits constants */
#include <string>

std::mutex mtx;

void consolePrint(bool errFlag, unsigned long long n, std::string inputType, float time)
{
	mtx.lock();
	if (errFlag)
	{
		std::cout << "overflow" << std::endl;
	}
	else
	{
		std::cout << " " << inputType << ": " << n << ", " << time << "ms \n" << std::endl;
	}
	mtx.unlock();
}

void calculate_primes()
{
	clock_t t;
	t = clock();
	unsigned int i = 2;

	while (i < USHRT_MAX)
	{
		bool isPrime = true;
		for (int j = 2; j < i; ++j)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			t = clock() - t;
			consolePrint(false, i, "Prime", ((float)t) / CLOCKS_PER_SEC);
		}
		++i;
	}
	consolePrint(true, i, "Prime", ((float)t) / CLOCKS_PER_SEC);
}

void calculate_fibonnaci()
{
	int i = 1;
	unsigned long long next = 0, first = 0, second = 1;
	clock_t t;
	t = clock();

	while (ULLONG_MAX - first >= second)
	{
		if (i <= 1)
			next = i;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		i++;
		t = clock() - t;
		consolePrint(false, next, "Fibonnacci", ((float)t) / CLOCKS_PER_SEC);
	}

	consolePrint(true, next, "Fibonnacci", ((float)t) / CLOCKS_PER_SEC);

}

int main()
{

	int n = 10000;

	std::thread primes(calculate_primes);
	std::thread fibonnacci(calculate_fibonnaci);

	primes.join();
	fibonnacci.join();

	system("PAUSE");
	return 0;
}