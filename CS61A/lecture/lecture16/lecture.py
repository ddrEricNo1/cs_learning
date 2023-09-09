class Product:

    def __init__(self, name, price, nutrition_info):
        self._name = name
        self._price = price
        self._nutrition_info = nutrition_info
        self._inventory = 0

    def increase_inventory(self, amount):
        self._inventory += amount

    def reduce_inventory(self, amount):
        self._inventory -= amount
        if self._inventory <= 0:
            print("OH NO, WE OUT!")

    def get_nutrition_label(self):
        return "|".join(self._nutrition_info)
    
    def get_inventory_report(self):
        return f"We have {self._inventory} bars"
    

pina_bar = Product("Pina Chocolatta", 7.99, ["24 g sugar"])
pina_bar.increase_inventory(2)