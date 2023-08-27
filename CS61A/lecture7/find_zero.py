def find_zero(lowest, biggest, func):
	"""Return a value v such that LOWEST <= v <= HIGHEST and
	FUNC(v)=0, or None if there is no such value. 
	Assumes that FUNC is a non-decreasing function from integers 
	to integers (that is, if a < b. then FUNC(a) <= FUNC(b)."""
	

	if lowest > highest:
		return None
	elif func(lowest) == 0:
		return lowest
	else:
		return find_zero(lowest + 1, highest, func)
