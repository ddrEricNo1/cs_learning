content = '''
<html><head><title>Title</title>
'''


if __name__ == "__main__":
    import re
    p = re.compile(r'<.*?>')
    for one in p.findall(content):
        print(one)
