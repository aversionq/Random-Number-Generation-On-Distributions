#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <map>
#define sqrt_2 1.414213562373
#define sqrt_pi_2 1.253314137316
#define eps 1e-5


const double values[] = { 0.0,        //reversedFunction(0.5)
                      0.125661,       //reversedFunction(0.55)
                      0.253347,       //reversedFunction(0.6)
                      0.385320,       //reversedFunction(0.65)
                      0.524401,       //reversedFunction(0.7)
                      0.674490,       //reversedFunction(0.75)
                      0.841621,       //reversedFunction(0.8)
                      1.036433,       //reversedFunction(0.85)
                      1.281552,       //reversedFunction(0.9)
                      1.554774,       //reversedFunction(0.94)
                      1.644854,       //reversedFunction(0.95)
                      1.880794,       //reversedFunction(0.97)
                      2.053749,       //reversedFunction(0.98)
                      2.326348 };     //reversedFunction(0.99)


double normalFunction(double x)
{
    if (x == 0.5) {
        return 0.0;
    }
    if (x < eps) {
        return -4.3;
    }
    if (x > 1 - eps) {
        return 4.3;
    }


    int sign = 1;
    if (x < 0.5) {
        x = 1 - x;
        sign = -1;
    }
    double xk1 = values[(int)(round(10 * x) - 5)], xk = xk1;
    double b = 1 - 2 * x;
    do 
    {
        xk = xk1;
        double t = xk / sqrt_2;
        xk1 = xk - sqrt_pi_2 * exp(t * t) * (erf(t) + b);
    } 
    while (fabs(xk - xk1) >= eps);


    return sign == 1 ? xk1 : -xk1;
}


double getNormRandVal()
{
    return normalFunction((double)rand() / ((double)RAND_MAX));
}


double finalResult(double m, double sigma)
{
    std::vector<double> vec;
    double randNum;
    randNum = m + sigma * getNormRandVal();


    return randNum;
}


int main()
{
    srand(time(0));
    double mean, sigma, n;
    std::cout << "Input mean: ";
    std::cin >> mean;
    std::cout << "Input standard deviation: ";
    std::cin >> sigma;
    std::cout << "Input amount of numbers: ";
    std::cin >> n;
    std::cout << std::endl;


    std::map<int, int> hist{};
    std::vector<double> arr;
    double randNum;
    for (int i = 0; i < n; ++i) {
        randNum = finalResult(mean, sigma);
        ++hist[std::round(randNum)];
        arr.push_back(randNum);
    }
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << std::setprecision(8) << arr[i] << std::endl;
    }
    //for (auto p : hist) {
    //    std::cout << std::setw(2)
    //        << p.first << ' ' << std::string(p.second / 200, '*') << '\n';    // This is for building diagram of those numbers
    //}
}