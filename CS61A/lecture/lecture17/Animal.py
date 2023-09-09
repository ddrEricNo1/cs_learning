class Animal:
    species_name = "Animal"
    scientific_name = "Animalia"
    play_multiplier = 2
    interact_increment = 1

def __init__(self, name, age=0):
    self.name = name
    self.age = age
    self.calories_eaten = 0
    self.happiness = 0


def play(self, num_hours):
    self.happiness += (num_hours * self.play_multiplier)
    print("WHEEE PLAY TIME!")


def eat(self, food):
    self.calories_eaten += food.calories
    print(f"Om nom nom yummy {food.name}")
    if self.calories_eaten > self.calories_needed:
        self.happiness -= 1
        print("Ugh so full")


def interact_with(self, animal2):
    self.happiness += self.interact_increment
    print(f"Yay happy fun time with {animal2.name}")


class Elephant(Animal):
    species_name = "African Savanna Elephant"
    scientific_name = "Loxodonta africana"
    calories_needed = 80000
    play_multiplier = 4
    interact_increment = 2
    num_tusks = 2


class Rabbit(Animal):
    species_name = "European rabbit"
    scientific_name = "Oryctolagus cuniculus"
    calories_needed = 200
    play_multiplier = 8
    interact_increment = 4
    num_in_litter = 12