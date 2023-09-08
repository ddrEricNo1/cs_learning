def make_anonymous_factorial():
    def function(x, function):
        if x == 1:
            return x
        else:
            return function(x - 1, function) * x 
    return lambda n: function(n, function)