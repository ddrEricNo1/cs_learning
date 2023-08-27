def is_path(blocked, x0, y0):
	"""True iff there is a path of squares from (X0, Y0) to some square (X1, 0) such that all squares on the path(including first and last)
	are unoccupied. BLOCKED is a predicate such that BLOCKED(x, y) is true iff the grid square at (x, y) is occupied or off the edge.
	Each step of a path goes down one row and 1 or 0 column left or right"""
	
	# base case
	if blocked(x0, y0):
		return False
	elif y0 == 0:
		return True
	else:
		return is_path(blocked, x0, y0 - 1) \
		or is_path(blocked, x0 - 1, y0 - 1) \
		or is_path(blocked, x0 + 1, y0 - 1)
