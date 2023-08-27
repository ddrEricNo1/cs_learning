def is_a_zero(lowest, highest, func):
	"""Return true if there is a value v such that LOWEST <= v <= HIGHEST and FUNC(v) == 0. Assume that FUNC is a non-decreasing function 
	from integers to integers."""
	

	middle = (lowest + highest) // 2
	return lowest <= highest \ 
		and (func(middle) == 0 \
		or (func(middle) < 0 and is_a_zero(middle + 1, highest, func))
		or (func(middle) > 0 and is_a_zero(lowest, middle - 1, func)))
