def if_function(condition, true_result, false_result):
    """return true_result if condition is a true value, and false_result otherwise"""
    if condition:
        return true_result
    else:
        return false_result
    

def cond():
    return False
    

def true_func():
    print("42")


def false_func():
    print("47")

def with_if_statement():
    if cond():
        return true_func()
    else:
        return false_func()
    

def with_if_function():
    return if_function(cond(), true_func(), false_func())


if __name__ == "__main__":
    # with_if_statement()
    with_if_function()