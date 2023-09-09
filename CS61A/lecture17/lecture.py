class Food:
    def __init__(self, name, type, calories):
        self.name = name
        self.type = type
        self.calories = calories


class Elephant:
    species_name = "African Savanna Elephant"
    scientific_name = "Loxodonta africana"
    calories_needed = 8000


    def __init__(self, name, age=0):
        self.name = name
        self.age = age
        self.calories_eaten = 0
        self.happiness = 0


    def play(self, num_hours):
        self.happiness += (num_hours * 4)
        print("WHEE PLAY TIME")


    def eat(self, food):
        self.calories_eaten += food.calories
        print(f"Om non nom yummy {food.name}")
        if self.calories_eaten > self.calories_needed:
            self.happiness -= 1
            print("Ugh so full")

    
    def interact_with(self, animal2):
        self.happiness += 1
        print(f"Yay happy fun time with {animal2.name}")


class Rabbit:
    species_name = "European rabbit"
    scientific_name = "Oryctolagus cuniculus"
    calories_needed = 200

def __init__(self, name, age=0):
    self.name = name
    self.age = age
    self.calories_eaten = 0
    self.happiness = 0


def play(self, num_hours):
    self.happiness += (num_hours * 10)
    print("WHEEE PLAY TIME!")


def eat(self, food):
    self.calories_eaten += food.calories
    print(f"Om nom nom yummy {food.name}")
    if self.calories_eaten > self.calories_needed:
        self.happiness -= 1
        print("Ugh so full")


def interact_with(self, animal2):
    self.happiness += 4
    print(f"Yay happy fun time with {animal2.name}")