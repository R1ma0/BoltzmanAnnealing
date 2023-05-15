#ifndef BOLTZMAN_HPP
#define BOLTZMAN_HPP

#include <cmath>
#include <vector>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

#define M_PI 3.14159265358979323846

using namespace std;

float RandomNumber(float, float);
float prob(float, float, float);
vector<float> SimulatedAnnealing(float(*)(float), float, float);

#endif
