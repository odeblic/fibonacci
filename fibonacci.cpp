#include <iostream>
#include <tgmath.h>


const double GOLDEN_RATIO = 1.61803398875;

int fibo(int n)
{
	return (n <= 1) ? 1 : fibo(n - 2) + fibo(n - 1);
}

void displaySequence(int max)
{
	for(int n = 1; n <= max; ++n)
	{
		std::cout << "fibo(" << n << ") = " << fibo(n) << std::endl;
	}
}

void displayRatios(int max)
{
	for(int n = 1; n <= max; ++n)
	{
		double ratio = static_cast<double>(fibo(n)) / static_cast<double>(fibo(n - 1));

		std::cout << "fibo(" << n << ") / fibo(" << n - 1 << ") =\t" << ratio << std::endl;
	}
}

void displayGoldenRatio(int max)
{
	double sum = 0;
	int nb = 0;

	for(int n = 1; n <= max; ++n)
	{
		double ratio = static_cast<double>(fibo(n)) / static_cast<double>(fibo(n - 1));

		sum += ratio;
		++nb;
	}

	for(int n = 1; n <= max; ++n)
	{
		double ratio = static_cast<double>(fibo(n)) / static_cast<double>(fibo(n - 1));

		std::cout << "fibo(" << n << ") / fibo(" << n - 1 << ") =\t" << ratio << "\t(deviation is " << ratio - GOLDEN_RATIO << ")" << std::endl;
	}



	std::cout << "average of ratios : " << sum/nb << std::endl;
}

double infiniteFraction(double n)
{
	return (n <= 1) ? 1 : 1 + 1 / infiniteFraction(n - 1);
}

double infiniteSquare(double n)
{
	return (n <= 1) ? 1 : sqrt(1 + infiniteSquare(n - 1));
}

int main()
{
	std::cout << "fibo demo" << std::endl;

	std::cout << "infiniteFraction(...) : " << infiniteFraction(10) << std::endl;

	std::cout << "infiniteSquare(...) : " << infiniteSquare(10) << std::endl;

	return 0;

	displaySequence(10);

	displayRatios(10);

	displayGoldenRatio(10);

	return 0;
}

