def find_zero2(lowest, highest, func):
	if lowset > highest:
		return None
	middle = (lowest + highest) // 2
	if func(middle) == 0:
		return middle
	elif func(middle) < 0:
		return find_zero2(middle + 1, highest, func)
	else:
		return find_zero2(lowest, middle - 1, func)


# equivalent iterative solution
def find_zero2(lowest, highest, func):
	while lowest < highest:
		middle = (lowest + highest) // 2
		if func(middle) == 0:
			return middle
		elif func(middle) < 0:
			lowest = middle + 1
		else:
			highest = middle - 1
	return None	
