content = '''
Python3 高级开发工程师 上海互助教育科技有限公司 上海浦东新区2万/月02-18满员
Python3 开发工程师 上海德拓信息技术股份有限公司 上海徐汇区1.3万/每月02-18剩余11人
测试开发工程师（Python）赫里普（上海）信息科技有限公司上海-浦东新区1.1万/每月02-18剩余5人
Python高级开发工程师 上海行动教育科技股份有限公司上海-闵行区2.8万/月02-18剩余255人
'''

# 将文本内容按行放入列表
lines = content.splitlines()
for line in lines:
    # 查找万/月在字符串的什么地方
    pos2 = line.find('万/月')
    if pos2 < 0:
        # 查找‘万/每月在字符串中什么地方’
        pos2 = line.find('万/每月')
        # 都找不到
        if pos2 < 0:
            continue

    # 执行到这里，说明可以找到薪资关键字
    # 接下来分析薪资数字的起始位置
    # 方法是找到pos2前面薪资数字开始的位置
    idx = pos2 - 1

    while line[idx].isdigit() or line[idx] == '.':
        idx -= 1

    # 现在idx指向薪资数字前面的那个字，所以薪资开始的索引就是idx + 1
    pos1 = idx + 1
    print(line[pos1: pos2])

