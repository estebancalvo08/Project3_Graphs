
#include "RandomVertex.h"
#include <ctime>

std::mt19937 RandomVertex::random(time(0));

int RandomVertex::Int(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random);
}
float RandomVertex::Float(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);
	return dist(random);
}