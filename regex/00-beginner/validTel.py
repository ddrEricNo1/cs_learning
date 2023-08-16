content = '''
王亚辉，13500344799,89
徐志摩，1b900785634,23
周根源，15909875678,44
周根源，15909875678,44
赫云摩，05909785634,44
李根源，23909875678,44
'''

if __name__ == "__main__":
    import re
    p = re.compile(r'1[35]\d{9}')
    for one in p.findall(content):
        print(one)
