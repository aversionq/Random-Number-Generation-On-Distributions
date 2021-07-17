#include <iostream>
#include <map>
#include <iomanip>
#include <vector>


double getRandomnumber()
{
	return (double)rand() / (double)RAND_MAX;
}


double exponentialDistribution(double ly)
{
	double x, u;
	u = getRandomnumber();
	x = log(1 - u) * (1 / (-ly));   // Случайное число, взятое из экспоненциального распределения.
	return x;
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	double ly;
	std::cout << "Введите количество событий: ";
	std::cin >> ly;
	std::vector<double> arr;


	std::map<int, int> hist;
	double randNum;
	for (int n = 0; n < 300; ++n) {
		randNum = exponentialDistribution(ly);
		++hist[2 * randNum];
		arr.push_back(randNum);
	}
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << std::endl;
	}
	for (auto p : hist) {
		std::cout << std::fixed << std::setprecision(1)
			<< p.first / 2.0 << '-' << (p.first + 1) / 2.0 <<
			' ' << std::string(p.second, '*') << '\n';
	}


	return 0;
}