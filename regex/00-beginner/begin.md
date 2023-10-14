# 1. 什么是正则表达式

用简单字符串来描述，匹配文中全部符合制定格式的字串

```python
content = '''
Python3 高级开发工程师 上海互助教育科技有限公司上海-浦东新区2万/月02-18满员
Python3开发工程师 上海德拓信息技术股份有限公司-徐汇区1.3万/每月02-18剩余11人
测试开发工程师（Python）赫里普（上海）信息科技有限公司上海-浦东新区1.1万/每月02-18剩余5人
Python高级开发工程师 上海行动教育科技股份有限公司上海-闵行区2.8万/月02-18剩余255人
python开发工程师 上海优腾软件开发有限公司上海-浦东新区2.5万/每月02-18满员
'''

import re
# 正则表达式的语法
p = re.compile(r'([\d.]+)万/每{0, 1}月')
for one in p.findall(content):
    print(one)
```

# 2. metacharacter(元字符)

* .

  表示要匹配除了换行符之外的任何单个字符

  例如要从下面文本中选择出所有的颜色

  > 苹果是绿色的
  >
  > 橙子是橙色的
  >
  > 香蕉是黄色的
  >
  > 乌鸦是黑色的

```python
# 正则表达式的形式
# r" .色
# python代码对应的形式
content = '''
苹果是绿色的
香蕉是黄色的
乌鸦是黑色的
'''
import re
# r表示原始的字符含义，不需要转移
p = re.compile(r'.色')
for one in p.findall(content):
    print(one)
```




* \*

  表示匹配前面的子表达式任意次，包括0次

  比如，你要从下面的文本中，选择每行逗号后面的字符串内容，包括逗号本身，注意，这里的逗号是中文的逗号

  > 苹果，是绿色的
  >
  > 橙子，是橙色的
  >
  > 香蕉，是黄色的
  >
  > 乌鸦，是黑色的
  >
  > 猴子，

  就可以这样写正则表达式 ，.* (中文逗号，.表示匹配任意的单个字符)

  * 紧跟在.后面，表示任意字符可以出现任意次，所以整个表达式的意思就是在逗号后面的所有字符，包括逗号

```python
content = '''
苹果，是绿色的
橙子，是橙色的
香蕉，是黄色的
乌鸦，是黑色的
猴子，
'''

import re
p = re.compile(r'，.*')
for one in p.findall(content)
	print(one)
```




* \+

  表示匹配前面的子表达式一次或多次，不包括0次

  比如，还是上面的例子，你要从文本中，选择每行逗号后面的字符串内容，包括逗号本身

  但是，添加一个条件，如果逗号后面没有内容，就不要选择了

  比如，下面的文本中，最后一行逗号后面没有内容，就不要选择了

  > 苹果，是绿色的
  >
  > 橙子，是橙色的
  >
  > 香蕉，是黄色的
  >
  > 乌鸦，是黑色的
  >
  > 猴子，

  可以用如下正则表达式表示 ，.+

```python
content = '''
苹果，是绿色的
橙子，是橙色的
香蕉，是黄色的
乌鸦，是黑色的
猴子，
'''
if __name__ == "__main__":
    import re
    p = re.compile(r'，.+')
    for one in p.findall(content):
        print(one)
```




* {}

  匹配指定次数

  > 红彤彤，绿油油，黑乎乎，绿油油油油

  表达式 油{3,4}表示匹配连续的油字至少3次，至多4次

```python
content = '''
红彤彤，绿油油，黑乎乎，绿油油油油
'''
if __name__ == "__main__":
    import re
    p = re.compile(r'油{3,4}')
    for one in p.findall(content):
        print(one)
```

```python
# 找出电话号码
content = '''
王亚辉，13500344799,89
徐志摩，15900785634,23
周根源，13909875678,44
'''
if __name__ == "__main__":
    import re
    p = re.compile(r'\d{11}')
    for one in p.findall(content):
        print(one)
```

# 3. 贪婪模式和非贪婪模式

我们要把下面的字符串中的所有html标签都提取出来，

> source = '<html><head><title>Title</title>'

得到这样一个列表

> ['<html>', '<head>', '<title>', '</title>']

很容易想到使用正则表达式 <.*>

写出如下代码

```python
source = '<html><head><title>Title</title>'
import re
p = re.compile(r'<.*>')
print(p.findall(source))
```

但是运行结果，确是

> ['<html><head><title>Title</title>']

在正则表达式中，'*', '+', '?'都是贪婪的，会尽可能多的匹配内容。

解决这个问题，就需要使用非贪婪模式，也就是在星号后面加上?, 变成 <.*?>

代码为:

```python
source = '<html><head><title>Title</title>'
import re
p = re.compile(r'<.*?>')
print(p.findall(source))
```

# 4. metacharacter (continue)

* \
  对元字符进行转义，比如下面的例子中需要搜索所有点前面的字符串

> 苹果.是绿色的
> 
> 橙子.是橙色的
> 
> 香蕉.是黄色的

如果我们这样写正则表达式 .*.

因为.是元字符，直接出现在正则表达式中，表示匹配任意的单个字符，不能表示.本身的意思
如果要搜索的内容中本身就包括元字符，可以使用反斜杠进行转义
因此，正确的正则表达式如下
.*\\.

```python
content = '''
苹果.是绿色的
橙子.是橙色的
香蕉.是黄色的
'''
import re
p = re.compile(r'.*\.')
for one in p.findall(content):
    print(one)
```

\d表示匹配0-9之间任意一个数字字符

\D匹配任意一个不是0-9之间的数字字符，等价于\[^0-9]

\s匹配任意一个空白字符，包括空格，tab，换行符等，等价于表达式\[\t\n\r\f\v]

\S匹配任意一个非空白字符，等价于表达式\[^ \t\n\r\f\v]

\w匹配任意一个文本字符，包括大小写字母，数字，下划线，等价于表达式\[a-zA-Z0-9]

\W匹配任意一个非文本字符，等价于表达式\[^  a-zA-Z0-9]

```python
source = '''
王亚辉
tony
刘文武
'''

import re
# 第二个参数re.A指定ASCII码格式
p = re.compile(r'\w{2,4}', re.A)
print(p.findall(source))
```

```python
# 查询有效的电话号码
content = '''
王亚辉，13500344799,89
徐志摩，1b900785634,23
周根源，15909875678,44
周根源，17909875678,44
赫云摩，05900785634,23
李根源，23909875678,44
'''
import re
# 方括号可以表示可以选择的字符，也可以表示范围，例如[3-7]
p = re.compile(r'1[35]\d{9}')
for one in p.findall(content):
    print(one)
```

反斜杠也可以用在方括号里面，比如[\s,.]表示匹配：任何空白字符，或者逗号，或者点

如果在方括号中使用^,表示非的概念，非方括号里面的字符集合

```python
# 取出文本中所有的非数字
source = 'a1b2c3d4e5'
import re
p = re.compile(r'[^ \d]')
print(p.findall(source))
```

* ^

  表示匹配文本的起始位置

  正则表达式可以设定单行模式和多行模式

  如果是单行模式，表示匹配整个文本的开头位置

  如果是多行模式，表示匹配文本每行的开头位置

```python
# 只需要提取出水果的编号
# 但是python代码默认的是单行模式，需要切换到多行模式
content = '''
001-苹果价格-60,
002-橙子价格-70,
003-香蕉价格-80,
'''
import re
# re.M 指定multiple line模式
p = re.compile(r'^\d+', re.M)
for one in p.findall(content):
    print(one)
```

* []

  character class

  A pattern of the form [c1, c2, c3], where each ci is a character, is called a character class and matches any one of the character ci.

  Inside a character class, c1-c2 is short for all the characters between c1 and c2, inclusive. 

  A character class of the form begining with ^ matches any one character that isn't one of the characters ci.   

* $

  表示匹配文本的结束位置

  如果是单行模式，表示匹配整个文本的结束位置

  如果是多行模式，表示匹配文本每行的结束位置

  比如下面的文本中，每行最前面的数字表示水果的编号，最后的数字表示价格

  > 001-苹果价格-60
  >
  > 002-橙子价格-70
  >
  > 003-香蕉价格-80

  如果我们要提取所有的水果编号，用这样的正则表达式 \d+$

```python
content = '''001-苹果价格-60
002-香蕉价格-40
003-葡萄价格-30
'''
import re
if __name__ == "__main__":
    p = re.compile(r'\d+$')
    for one in p.findall(content):
        print(one)
```

* ()

  组选择，是从正则表达式匹配的内容里面扣取出其中的某些部分

  例如，从下面的文本中，选择每行逗号前面的字符串，也包括逗号本身

  > 苹果，苹果是绿色的
  >
  > 橙子，橙子是橙色的
  >
  > 香蕉，香蕉是黄色的

  就可以这样写正则表达式 ^.*,

  但如果要求不包括逗号，不可以写成^.*

  解决方法就是使用组选择符: 括号

  写成 ^(.*)，

```python
content = '''苹果，苹果是绿色的
橙子，橙子是橙色的
香蕉，香蕉是黄色的
'''

import re
p = re.compile(r'^(.*)，')
for one in p.findall(content):
    pri
```

```python
# 生成人名和手机号码的对应信息
content = '''张三，手机号码15945678901
李四，手机号码13945677701
王二，手机号码13845666901
'''
import re
p = re.compile(r'^(.+)，.+(\d{11})')
for one in p.findall(content):
    print(one)
```

# 5. 回收开头

从下面的文本里面抓去所有职位的薪资

> Python3 高级开发工程师 上海互教教育科技有限公司上海-浦东新区2万/月02-18满员
>
> 测试开发工程师(C++/python) 上海数码科技有限公司上海-浦东新区2.5万/每月02-18未满员
>
> python3 开发工程师 上海德拓信息技术股份有限公司上海-徐汇区1.3万/每月02-18剩余11人
>
> 测试开发工程师(python)赫里普(上海)信息科技有限公司上海浦东新区1.1万/每月02-18剩余5人

使用的正则表达式为 ([\d.]+)万/每{0,1}月

其中:

[\d.]+表示匹配数字或者点的多次出现

万/每{0,1}月是后面紧接着的，如果没有这个，就会匹配到别的数字，比如python3里面的3

其中每{0,1}月表示每月每这个字可以出现0次或者1次

# 6. 使用正则表达式切割字符串

字符串对象的split()方法只适用于非常简单的字符串分割情形。当需要更灵活的切割字符串时，就不好用了

比如，需要从下面字符串中提取武将的名字

`names = '关羽; 张飞, 赵云, 马超, 黄忠 李逵'`

名字之间，有的是用分号隔开，有的用逗号隔开，有的是空格隔开，而且分割符号周围还有不定数量的空格

这时，最好使用正则表达式里面的split方法

```python
import re
names = '关羽; 张飞, 赵云, 马超, 黄忠 李逵'
namelist = re.split(r'[;,\s]\s*', names)
print(namelist)
```

# 7. sub替换，参数为回调函数 

匹配模式替换

字符串对象的replace方法只适应于简单的替换。有时需要更加灵活的替换。

比如，需要在下面这段文本中所有的链接中找到以/avxxxxxx/这种以/av开头，后面接一串数字，这种模式的字符串

然后，这些字符串全部替换为/cn345677/

被替换的内容是不固定的，所以没法用字符串的replace方法

这时，可以使用正则表达式里面的sub方法

```python
import re
names = '''
下面是这学期需要学习的课程：
a href='https://www.bilibili.com/video/av66771949/?p=1' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是牛顿第2运动定律

<a href='https://www.bilibili.com/video/av46349552/?p=125' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是毕达哥拉斯公式

<a href='https://www.bilibili.com/video/av90571967/?p=33' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是切割磁力线
'''

newStr = re.sub(r'/av\d+?/','/cn345677',names)
print(newStr)
```

sub方法就是替换字符串，但是被替换的内容用正则表达式来表示符合特征的所有字符串

比如，第一个参数/av\d+?/这个正则表达式，表示以/av开头，后面是一串数字，再以/结尾的这种特征的字符串，是需要被替换的

第二个参数，这里是‘/cn345677/’这个字符串，表示用什么来替换

第三个参数是源字符串

# 8.指定替换函数

刚才的例子中，用来替换的是一个固定的字符串，如果要求替换后的内容是原来的数字+6,比如/av66771949/替换为/av66771955/

可以把sub的第二个参数指定为一个函数，该函数的返回值，就是用来替换的字符串

```python
import re
names = '''
下面是这学期要学习的课程：

<a href='https://www.bilibili.com/video/av66771949/?p=1' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是牛顿第2运动定律

<a href='https://www.bilibili.com/video/av46349552/?p=125' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是毕达哥拉斯公式

<a href='https://www.bilibili.com/video/av90571967/?p=33' target='_blank'>点击这里，边看视频讲解，边学习以下内容</a>
这节讲的是切割磁力线
'''

# 替换函数，参数是Match对象
# Match对象是正则表达式中定义好的对象
def subFunc(match):
    # Match对象的group(0)返回的是整个匹配上的字符串
    src = match.group(0)
    
    # Match对象的group(1)返回的是第一个group分组的内容
    number = int(match.group(1)) + 6
    dest = f'/av{number}/'
    print(f'{src}替换为{dest}')
    
    # 返回值就是最终替换的字符串
    return dest

# ?问号表示非贪婪模式
newStr = re.sub(r'av(\d+?)/', subFunc, names)
print(newStr)
```

# 9. 练习

[网站](http://www.listeningexpress.com/studioclassroom/ad/)

* 使用wget获得上面网站的源码，并使用正则表达式获得所有mp3文件的网址

* 调用正确外部程序wget依次下载下来

注意：

* 获取的音频网址需要加上前缀http://www.listeningexpress.com/studioclassroom/ad/才是完整的下载地址

* MP3文件中有空格字符，组成下载网址时，需要进行url编码，否则空格会被当成命令行分割符。参考代码如下:

  ```python
  from urlib.parse import quote
  quote('2019-04-13 NEWSworthy Clips.mp3')
  # >>> '2019-04-13%20NEWSworthy%20Clips.mp3'```
  
  
