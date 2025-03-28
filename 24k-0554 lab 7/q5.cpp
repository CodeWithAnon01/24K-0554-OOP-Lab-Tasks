#include <iostream>
using namespace std;

class Character {
protected:
    int characterID, level, healthPoints;
    string name, weaponType;
public:
    Character(int id, string n, int lvl, int hp, string weapon = "None")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    virtual void attack() { cout << name << " attacks with " << weaponType << "\n"; }
    virtual void defend() { cout << name << " defends\n"; }
    virtual void displayStats() {
        cout << "ID: " << characterID << "\nName: " << name << "\nLevel: " << level
             << "\nHP: " << healthPoints << "\nWeapon: " << weaponType << "\n";
    }
};

class Warrior : public Character {
    int armorStrength, meleeDamage;
public:
    Warrior(int id, string n, int lvl, int hp, int armor, int dmg)
        : Character(id, n, lvl, hp, "Sword"), armorStrength(armor), meleeDamage(dmg) {}
    void attack() override { cout << name << " swings sword for " << meleeDamage << " damage!\n"; }
};

class Mage : public Character {
    int manaPoints, spellPower;
public:
    Mage(int id, string n, int lvl, int hp, int mana, int power)
        : Character(id, n, lvl, hp, "Magic Staff"), manaPoints(mana), spellPower(power) {}
    void defend() override { cout << name << " casts a magic barrier!\n"; }
};

class Archer : public Character {
    int arrowCount, rangedAccuracy;
public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy)
        : Character(id, n, lvl, hp, "Bow"), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void attack() override { cout << name << " shoots an arrow!\n"; }
};

class Rogue : public Character {
    int stealthLevel, agility;
public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agi)
        : Character(id, n, lvl, hp, "Dagger"), stealthLevel(stealth), agility(agi) {}
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << "\n";
    }
};

int main() {
    Warrior w(1, "Thor", 10, 100, 50, 30);
    Mage m(2, "Merlin", 12, 80, 100, 40);
    Archer a(3, "Legolas", 9, 90, 30, 85);
    Rogue r(4, "Ezio", 11, 85, 70, 95);

    w.attack();
    m.defend();
    a.attack();
    r.displayStats();
    
    return 0;
}
