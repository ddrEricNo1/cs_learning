content = '''
王亚摩，13500344799,89
徐志摩，15900785634,23
周根源，13909875678,44
'''

if __name__ == "__main__":
    import re
    p = re.compile(r'\d{11}')
    for one in p.findall(content):
        print(one)
