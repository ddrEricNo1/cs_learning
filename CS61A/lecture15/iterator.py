toppings = ["roasted red pepper", "pineapple", "pepper", "mushroom"]
topperator = iter(toppings)

eng_nums = ["one", "two", "three"]
esp_nums = ["uno", "dos", "tres"]

zip_iter = zip(eng_nums, esp_nums)
eng, esp = next(zip_iter)
print(eng, esp)

for eng, esp in zip(eng_nums, esp_nums):
    print(eng, esp)