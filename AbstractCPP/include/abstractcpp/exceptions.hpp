#pragma once

#include <stdexcept>

namespace abstractcpp {
	class NotImplementedException : public std::logic_error
	{
	public:
		NotImplementedException() : std::logic_error("Not implemented") {};
	};
}