#include <matplot/matplot.h>
#include "boltzman.hpp"

namespace mpp = matplot;

float srcFunc(float);

int main(int argc, char * argv[])
{
	srand((unsigned)time(NULL));
	float minBorder = -20.0;
	float maxBorder = -8.0;

	vector <float> a = SimulatedAnnealing(
		srcFunc, minBorder, maxBorder
	);

	vector<double> axisX = mpp::linspace(minBorder, maxBorder);
	vector<double> axisY = mpp::transform(axisX, [](auto axisX) { return srcFunc(axisX); });

	string label = "<- (" + to_string(a[0]) + ", " + to_string(a[1]) + ")";

	mpp::plot(axisX, axisY)->line_width(3);
	mpp::text(a[0], a[1], label);
	mpp::grid(mpp::on);
	mpp::xlabel("x");
	mpp::ylabel("y");
	mpp::show();

	return 0;
}

float srcFunc(float x)
{
	//return 25*x*x*x*(1 - 4*x*x)*exp(-5*x*x);
	return exp(sin(x)) * sin(x*x);
}

