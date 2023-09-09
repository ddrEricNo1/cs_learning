class Lamb:
    species_name = "Lamb"
    scientific_name = "Ovis aries"

    def __init__(self, name):
        self.name = name


class Human:
    
    species_name = "Human"
    scientific_name = "Homo sapiens"


    def __init__(self, name):
        self.name = name
        self.pets = []

    
    def adopt(self, pet):
        self.pets.append(pet)


    # 类似于java的toString
    def __str__(self):
        return f"😀 {self.name}"
    

eric = Human("Ding")
print(eric)