#include "boltzman.hpp"

double processedFunction(double x)
{
	return 25*x*x*x*(1 - 4*x*x)*exp(-5*x*x);
}
