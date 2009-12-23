/**
 * @file ListType.hpp
 */
#pragma once

#include <vector>

using std::vector;

namespace peek {

	template <typename T>
	struct list_traits {
		typedef T T_type;
		typedef typename vector<T_type> list_type;
	};

}
