#ifndef _RANDOM_H
#define _RANDOM_H

#ifndef _RANGE_H
#include "Math/Objects/Range.h"
#endif

#ifndef _ASSERT_H
#include "Core/Defines/assert.h"
#endif

template <typename T> class Random;
typedef Random<float> RandomFloat;
typedef Random<double> RandomDouble;
typedef Random<int> RandomInt;
typedef Random<unsigned int> RandomUInt;

template <typename T>
class Random
{
public:
	static T getValue()
	{
		return static_cast<T>(fmod(rand(), RAND_MAX));
	}
	static T getValue(T min, T max)
	{
		//Minimum value needs to be smaller than maximum value
		assert(min < max);

		return static_cast<T>(fmod(rand(), max) + min);
	}
	static T getValue(const Range<T>& range)
	{
		return static_cast<T>(fmod(rand(), range.max_value) + range.min_value);
	}
};

#endif