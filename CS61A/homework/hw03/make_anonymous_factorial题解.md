# Make_anonymous_factorial题目解析
> 原题为：![截屏2023-09-08 13.41.17](/Users/eric/Desktop/截屏2023-09-08 13.41.17.png)

```python
def make_anonymous_factorial():
	# 因为函数匿名，并不能直接获得原来函数绑定的名字，从而获得对于变量值为n-1的sub case的返回值
  # 所以问题核心在于：如何在没有函数名的情况下，在递归中调用这个函数
  # 可以自己写一个函数，将自身作为参数传递进去
  def function(n, func):
    if n == 1:
      return 1
    else:
      return func(n - 1, func) * n
  return lambda x: function(x, function)
```

但是需要写成一行的形式，因此可以采用lambda表达式的方法

```python
def make_anonymous_factorial():
	# 因为函数匿名，并不能直接获得原来函数绑定的名字，从而获得对于变量值为n-1的sub case的返回值
  # 所以问题核心在于：如何在没有函数名的情况下，在递归中调用这个函数
  # 可以自己写一个函数，将自身作为参数传递进去
  return lambda n: (lambda x, func: 1 if x == 1 else x * func(x - 1, func))(n, lambda x, func: 1 if x == 1else x * func(x - 1, func))
```

其实本质是将func本身作为参数传入之后，用lambda表达式替换所有的func