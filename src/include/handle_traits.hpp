/**
 * @file handle_traits.hpp
 */
#pragma once

#include <boost/shared_ptr.hpp>

using boost::shared_ptr;

namespace peek {

	template <typename T>
	struct handle_traits {
		typedef T T_type;
		typedef typename shared_ptr<T_type> handle_type;
	};

}
