#include <iostream>
#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int damage;
    int defense;

    Item(const std::string& itemName, int itemDamage, int itemDefense)
        : name(itemName), damage(itemDamage), defense(itemDefense) {}
};

class Character
{
public:
    std::string name;
    int health;
    int attack;
    int defense;

    Character(const std::string& characterName, int characterHealth, int characterAttack, int characterDefense)
        : name(characterName), health(characterHealth), attack(characterAttack), defense(characterDefense) {}

    void equipItem(const Item& item)
    {
        attack += item.damage;
        defense += item.defense;
        std::cout << name << " equips " << item.name << ". Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackMonster(Character& monster)
    {
        int damageDealt = attack - monster.defense;
        if (damageDealt < 0)
            damageDealt = 0;
        monster.health -= damageDealt;
        std::cout << name << " attacks " << monster.name << " for " << damageDealt << " damage." << std::endl;
    }

    bool isAlive() const
    {
        return health > 0;
    }
};

int main()
{
    Character player("Hero", 100, 20, 10);
    Character monster("Dragon", 150, 25, 5);

    Item sword("Sword", 15, 0);
    Item shield("Shield", 0, 10);

    player.equipItem(sword);
    player.equipItem(shield);

    while (player.isAlive() && monster.isAlive())
    {
        player.attackMonster(monster);
        if (monster.isAlive())
        {
            monster.attackMonster(player);
        }
    }

    if (player.isAlive())
        std::cout << "Hero wins!" << std::endl;
    else
        std::cout << "Dragon wins!" << std::endl;

    return 0;
}