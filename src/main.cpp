#include <cmath>
#include <matplot/matplot.h>
#include "boltzman.hpp"

namespace mpp = matplot;

int main(int argc, char * argv[])
{
	std::vector<double> x = mpp::linspace(0, 2 * mpp::pi);
	std::vector<double> y = mpp::transform(x, [](auto x) {return sin(x); });

	mpp::plot(x, y);
	mpp::show();

	return 0;
}
