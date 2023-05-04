#include "boltzman.hpp"

double processedFunction(double x)
{
	return 25*x*x*x*(1 - 4*x*x)*exp(-5*x*x);
}
#include<vector>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<fstream>
using namespace std;
# define M_PI 3.14159265358979323846
#define MINBORDER 1
#define MAXBORDER 5
double grad;
double rad;
//float masx [19] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1 , 2, 3, 4, 5, 6, 7, 8};
//float masy[19] = { -2, 1, -6, -3, 1, -5, -1, 3, -7, -2, 2.5, 5, 7, -3, 6, -8, 3, 0, -9};
//Функция имеет много минимумов, но нужно скорректировать перевод градусов в радианы
float fun(int x){
	
	//return exp(sin(x*x) - x);
	//return masy[x];
	grad = x;
	rad = (grad * (M_PI / 180));
	x = rad;
	return exp(sin(x*x)-x)/(x*x);
}
//Рабочий вариант для нашей функци (но мало минимумов на графике)
//float fun(float x) {
//	//return exp(sin(x*x) - x);
//
//	//return 25 * x * x * x * (1 - 4 * x * x) * exp(-5 * x * x);
//}
float RandomNumber() {
	float random = ((float)rand()) / (float)RAND_MAX * (MAXBORDER - MINBORDER) + MINBORDER;
	return random;
}

float prob(float x1, float x2, float T) {
	return pow(2.71828, (x1 - x2) / T);
}

vector<double>SimulatedAnnealing() {
	float new_x1, new_x2, newstate, accept_prob;
	float x1 = RandomNumber();
	float currentstate = fun(x1);
	float T0 = 0.001;
	float T = T0;
	float Tmin = 0.0001;
	while (T > Tmin) {
		int i = 1;
		while (i <= 500000) {
			new_x1 = RandomNumber();
			newstate = fun(new_x1);
			accept_prob = prob(currentstate, newstate, T);
			if (accept_prob> rand()) {
				currentstate = newstate;
				x1 = new_x1;
			}
			T = T0 / log(1 + i);
			i++;
		}
		
	
	}
	return vector<double> {x1, fun(x1)};
}

int main()
{
	srand((unsigned)time(NULL));
	vector <double> a;
	a = SimulatedAnnealing();
	cout << a[0] << endl;
	cout << a[1] << endl;
	ofstream fout("GlobalMinimum.txt");
	fout << a[0] << ";" << a[1]<< endl;
	printf("Press Enter To Continue..");
	getchar();
	return 0;
}

