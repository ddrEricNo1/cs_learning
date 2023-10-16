# Python decorators

## Definition

Python provides special syntax to apply higher-order functions as part of executing a def statement, called a decorator. 

```python
def trance(fn):
  def wrapped(x):
    print('->', fn, '(', x, ')')
    return fn(x)
  return wrapped

@trace
def triple(x):
  return 3 * x
```

In this example, A higher-order function *trace* is defined, which returns a function that precedes a call to its argument with a *print* statement that outputs the argument. The *def* statement for *triple* has an annotation, @trace, which affects the execution rule for *def*. As usual, the function *triple* is created. But the name *triple* is not bound to this function. Instead, the name *triple* is bound to the returned function value of calling *trance* on the newly defined *triple* function. In code, this is equivalent to: 

```python
def triple(x):
  return 3 * x

triple = trance(triple)
```