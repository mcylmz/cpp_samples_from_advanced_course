template <typename T>
struct remove_reference {
	using type = T;
};

template <typename T>
struct remove_reference<T&> {
	using type = T;
};

template <typename T>
struct remove_reference<T&&> {
	using type = T;
};

template <typename T>
using remove_reference_t = remove_reference<T>::type;

template <typename T>
remove_reference_t<T>&& move(T&& t) noexcept
{
	return static_cast<remove_reference_t<T>&&>(t);
}

