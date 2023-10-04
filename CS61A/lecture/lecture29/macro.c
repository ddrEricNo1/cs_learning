#define doArray(var, A, low, high) \
	for (int var ## _index =low; var ## _index < high; \
	var ## _index +=1) {	\
		int var = (A)[var ## _index];
	#define endDo
}
// ## is to do the string concatation
doArray(p, anArray, 0, N)
