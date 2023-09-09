def num_paths(blocked, x0, y0):
	"""Return the number of unoccupied paths thatrun from (X0, Y0) to some square (x1, 0). BLOCKED is a predicate such that BLOCKED(x, y) is true
	iff the grid square at (x, y) is occupied or off the edge."""
	if blocked(x0, y0):
		return 0
	elif y0 == 0:
		return 1
	else:
		return num_paths(x0 - 1, y0 - 1) + num_paths(x0, y0 - 1) + num_paths(x0 + 1, y0 -1)
