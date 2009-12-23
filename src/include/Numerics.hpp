/**
 * \file Numerics.hpp
 * \author Douglas W. Paul
 *
 * Defines some standard numeric functions and values.
 */
#pragma once

#include <valarray>

namespace peek {

	/** Pi (the transcendental) */
	const double PI(4.0 * std::atan2(1.0, 1.0));

	inline double sign(double d) {
		return (d > 0 ? 1.0 : -1.0);
	}

	template <typename T>
	inline T sign(T t) {
		return (t > 0 ? 1 : -1);
	}

	/**
	 * The square of a number
	 * \param n The number to be squared
	 * \return The square of n
	 */
	inline double square(double n) {
		return n * n;
	}

	/**
	 * Generates uniform random numbers
	 * \return A uniform random number in the range [0.0, 1.0]
	 */
	inline double uniformRand() {
		return ( (double) rand() / ((double)RAND_MAX + 1.0) );
	}

	/**
	 * Generates uniform random numbers
	 * \param min The minimum value to return
	 * \param max The maximum value to return
	 * \return A uniform random number in the range [min, max]
	 */
	inline double uniformRand(double min, double max) {
		double range = max - min;
		return (uniformRand() * range) + min;
	}

}
