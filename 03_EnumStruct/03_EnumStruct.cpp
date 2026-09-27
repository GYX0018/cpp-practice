#include <iostream>	
#include <string>



enum Mood
{
    happy,
    normal,
    angry
};

enum class PetType
{
    Dog,
    Cat,
    Monkey
};

struct Pet
{
    std::string name;
    int health{ 100 };
    Mood mood{ happy };
    PetType type{ PetType::Dog };
};


void printPet(const Pet& pet);
void damagePet(Pet& pet, int damage);
void changeMood(Pet& pet, Mood mood);

int main()
{
    Pet pet1{ "Max",100,happy,PetType::Dog };
    Pet pet2{ "Milo",70,angry,PetType::Cat };



    printPet(pet1);
    std::cout << std::endl;
    printPet(pet2);

    damagePet(pet1, 30);
    changeMood(pet1, angry);

    std::cout << std::endl;
    printPet(pet1);

    return 0;
}

void printPet(const Pet& pet)
{
    std::cout << pet.name << std::endl;
    std::cout << pet.health << std::endl;
    //std::cout << pet1.mood << std::endl;
    switch (pet.mood)
    {
    case happy:
        std::cout << "feel happy\n";
        break;
    case normal:
        std::cout << "feel hormal\n";
        break;
    case angry:
        std::cout << "feel angry\n";
        break;
    }



    //std::cout << pet1.type << std::endl;
    switch (pet.type)
    {
    case PetType::Dog:
        std::cout << "It's a dog\n";
        break;
    case PetType::Cat:
        std::cout << "It's a cat\n";
        break;
    case PetType::Monkey:
        std::cout << "It's a monkey\n";
        break;

    }


}

void damagePet(Pet& pet, int damage)
{
    if (pet.health > 0)
    {
        pet.health -= damage;
    }

    if (pet.health <= 0)
    {
        pet.health = 0;
    }

}

void changeMood(Pet& pet, Mood mood)
{
    pet.mood = mood;
}
