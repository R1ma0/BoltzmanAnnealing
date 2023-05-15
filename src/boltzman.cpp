#include "boltzman.hpp"

float RandomNumber(float minBorder, float maxBorder) 
{
	return ((float)rand()) / (float)RAND_MAX * (maxBorder - minBorder) + minBorder;
}

float prob(float x1, float x2, float T) 
{
	return pow(2.71828, (x1 - x2) / T);
}

vector<float> SimulatedAnnealing(float(*func)(float), float minBorder, float maxBorder) 
{
	float new_x1, new_x2, newstate, accept_prob;
	float x1 = RandomNumber(minBorder, maxBorder);
	float currentstate = func(x1);
	float T0 = 0.001;
	float T = T0;
	float Tmin = 0.0001;

	while (T > Tmin) 
	{
		int i = 1;
		while (i <= 500000) 
		{
			new_x1 = RandomNumber(minBorder, maxBorder);
			newstate = func(new_x1);
			accept_prob = prob(currentstate, newstate, T);

			if (accept_prob> rand()) 
			{
				currentstate = newstate;
				x1 = new_x1;
			}

			T = T0 / log(1 + i);
			i++;
		}
	}

	return vector<float> {x1, func(x1)};
}
