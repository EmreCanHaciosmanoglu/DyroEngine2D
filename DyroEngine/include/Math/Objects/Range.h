#ifndef _RANGE_H
#define _RANGE_H

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

#ifndef _ASSERT_H
#include "Core/Defines/assert.h"
#endif

template <typename T> class Range;
typedef Range<float> RangeFloat;
typedef Range<double> RangeDouble;
typedef Range<int> RangeInt;
typedef Range<unsigned int> RangeUInt;
typedef Range<Vector2D> RangeVector2D;

template <typename T>
class Range
{
public:
	Range() = default;
	Range(T minValue, T maxValue)
		: min_value(minValue)
		, max_value(maxValue)
	{
		//Minimum value needs to be smaller than maximum value
		assert(min_value <= max_value);
	}

	bool operator== (const Range<T> & other) const
	{
		return this->min_value == other.min_value && this->max_value == other.max_value;
	}
	bool operator!= (const Range<T> & other) const
	{
		return !(*this == other);
	}

	T getDelta() const
	{
		return this->max_value - this->min_value;
	}
	T getCenter() const
	{
		return 0.5 * (this->min_value + this->max_value);
	}

	T getNormalizedValue(T value) const
	{
		return (value - this->min_value) / getDelta();
	}
	
	T min_value;
	T max_value;
};

#endif