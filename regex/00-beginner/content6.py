content = '''
红彤彤，绿油油，黑乎乎，绿油油油油
'''
if __name__ == "__main__":
    import re
    p = re.compile(r'油{3,4}')
    for one in p.findall(content):
        print(one)
