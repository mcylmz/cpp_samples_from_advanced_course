template <typename Func, typename... Args>
decltype(auto) call(Func f, Args&&... args)
{
	decltype(auto) ret{ f(std::forward<Args>(args)...) };

	if constexpr (std::is_rvalue_reference_v<decltype(ret)>) {
		return std::move(ret);
	}
	else {
		return ret;
	}
}
