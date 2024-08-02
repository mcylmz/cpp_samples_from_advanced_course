// Simple forward implementation
template <typename T>
constexpr T&& Forward(typename std::remove_reference_t<T>& t) noexcept
{
	return static_cast<T&&>(t);
}

// reference collapsing applies here
