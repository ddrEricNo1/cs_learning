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


if __name__ == "__main__":
    newStr = re.sub(r'/av(\d+?)/', subFunc, names)
    print(newStr)
