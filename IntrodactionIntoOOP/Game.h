#pragma once
#include <iostream>
#include <string>
#define MAX_HEALTH 100.0;
using namespace std;

/*
1. различие между классом и структурой - возможность сокрытия информации, контролируемый доступ - сеттеры и геттеры.
2. с чего начинается работа над классом - определение набора классов и их полей.
2.5 вывод на экран.
3. конструкторы!!!! 3 штуки!!!
4. выделение классов: что класс, а что структура.
5. сокрытие важных данных, их обрабока в сеттерах и геттерах
6. а нужно ли наследование? - организация родительского класса
7. protected - для доступа поля родителя в потомке.
8. реализуете нужный функционал!
*/

// Общий класс оружий
class Weapon {
protected:
    string name;
    double damage;

public:
    // Конструктор по умолчанию
    Weapon() {
        name = "Unarmed";
        damage = 1.0;
    };

    // Конструктор инициализации
    Weapon(string _name, double _damage) {
        name = _name;
        damage = _damage;
    };

    // Конструктор копирования
    Weapon(const Weapon& w) {
        name = w.name;
        damage = w.damage;
    };

    // Метод получения имени (Геттер)
    string getName() { return name; };

    // Метод установки имени (Сеттер)
    void setName(string _name) {
        name = _name;
    };

    // Метод получения урона (Геттер)
    double getDamage() { return damage; };

    // Метод установки урона (Сеттер)
    void setDamage(double _damage) {
        if (_damage < 0 || _damage > 50) {
            cout << "[warning] invalid values entered" << endl;
            damage = 1;
        }
        else
            damage = _damage;
    };

    // Метод вывода информации 
    void print_weapon_info() {
        cout << "Weapon name: " << name << endl 
        << "Weapon damage: " << damage << endl;
    };
};

// Класс оружия Gun -> Human
class Gun : public Weapon {
private:
  int cartridges;

public:

    // Конструктор по умолчанию
    Gun() {
        name = "Pistol";
        damage = 40.0;
        cartridges = 5;
    };

    // Конструктор инициализации
    Gun(string _name, double _damage, int _cartriges) {
        name = _name;
        damage = _damage;
        cartridges = _cartriges;
    };

    // Конструктор копирования
    Gun(const Gun& g) {
        name = g.name;
        damage = g.damage;
        cartridges = g.cartridges;
    };

    // Метод получения кол-ва обойм (Геттер)
    int getCartriges() { return cartridges; };

    // Метод установки кол-ва обойм (Сеттер) 
    void setCartriges(int _cartridges) {
        cartridges = _cartridges;
    };

    // Метод вывода информации
    void print_weapon_info() {
        Weapon::print_weapon_info();
        cout << "Weapon cartridges: " << cartridges << endl;
    };
};

// Класс оружия Bow -> Archer
class Bow : public Weapon {
private:
  int arrows;
  double extraDamage;
  int time;

public:

    // Конструктор по умолчанию
    Bow() {
        name = "Common Bow";
        damage = 25.0;
        arrows = 7;
        extraDamage = 3.5;
        time = 2;
    };

    // Конструктор инициализации
    Bow(string _name, double _damage, int _arrows, double _extraDamage, int _time) {
        name = _name;
        damage = _damage;
        arrows = _arrows;
        extraDamage = _extraDamage;
        time = _time;
    };

    // Конструктор копирования
    Bow(const Bow& b) {
        name = b.name;
        damage = b.damage;
        arrows = b.arrows;
        extraDamage = b.extraDamage;
        time = b.time;
    };

    // Метод получения кол-ва стрел (Геттер)
    int getArrows() { return arrows; };

    // Метод установки кол-ва стрел (Сеттер)
    void setArrows(int _arrows) {
        arrows = _arrows;
    };

    // Метод получения доп.урона в секунду (Геттер)
    double getExtraDamage() { return extraDamage; };

    // Метод установки доп.урона в секунду (Сеттер)
    void setExtraDamage(double _extraDamage) {
        extraDamage = _extraDamage;
    };

    // Метод получаения вермени дейстявия доп.урона (Геттер)
    int getTime() { return time; };

    // Метод установки времени действия доп.урона (Сеттер)
    void setTime(int _time) {
        time = _time;
    };

    // Метод вывода информации
    void print_weapon_info() {
        Weapon::print_weapon_info();
        cout << "Weapon arrows: " << arrows << endl
            << "Weapon extra damage: " << extraDamage << endl
            << "Weapon time: " << time << endl;
    };
};

// Класс оружия Axe -> Warrior
class Axe : public Weapon {
private:
    int strenght;

public:
    // Конструктор по умолчанию
    Axe() {
        name = "Gorehowl";
        damage = 30.0;
        strenght = 100.0;
    };

    // Конструктор инициализации
    Axe(string _name, double _damage, int _strenght) {
        name = _name;
        damage = _damage;
        strenght = _strenght;
    };

    // Конструктор копирования
    Axe(const Axe& a) {
        name = a.name;
        damage = a.damage;
        strenght = a.strenght;
    };

    // Метод получения силы (Геттер)
    int getStrenght() { return strenght; };

    // Метод установки силы (Сеттер)
    void setStrenght(int _strenght) {
        strenght = _strenght;
    };

    // Метод вывода информации
    void print_weapon_info() {
        Weapon::print_weapon_info();
        cout << "Strength: " << strenght << endl;
    };

};

// Общий класс персонажей 
class Character {
protected:
  string name;
  string  gender;
  double power;
  double health;

public:
  // Конструктор по умолчанию
  Character() {
    name = "Bob";
    gender = "male";
    power = 1.0;
    health = MAX_HEALTH;
  };

  // Конструктор инициализации
  Character(string _name, string  _gender, double _power, double _health) {
    name = _name;
    gender = _gender;
    power = _power;
    health = _health;
  };

  // Конструктор копирования
  Character(const Character& w) {
    name = w.name;
    gender = w.gender;
    power = w.power;
    health = w.health;
  };

  // Вывод информации
  virtual void print_character_info() = 0;

  // Метод получения имени (Геттер)
  string getName() { return name; };

  // Метод установки имени (Сеттер)
  void setName(string _name) {
      name = _name;
  };

  // Метод получения гендера (Геттер)
  string getGender() { return gender; };

  // Метод установки гендера (Сеттер)
  void setGender(string _gender) {
      gender = _gender;
  };

  // Метод получения мощности (Геттер)
  double getPower() { return power; };

  // Метод установки можности (Сеттер)
  void setPower(double _power) {
      power = _power;
  };

  // Метод получения здоровья (Геттер)
  double getHealth() { return health; };

  // Метод установки здоровья (Сеттер)
  void setHealth(double _health) {
      health = _health;
  };

  // Метод восстановления здровья
  void healing() {
      health = MAX_HEALTH;
  }

  // Метод атаки (частичная реализация)
  virtual void attack(Character *attacked) = 0;

  // Метод получения урона
  virtual void attacked(double _damage,
      double _extraDamage, 
      int _time,
      int _arrows,
      int _cartridges,
      int _strenght,
      int _dexterity,
      int _technics,
      int power,
      int type) = 0;
};

// Класс персонажа Human -> Gun
class Human : public Character {
private:
    int technics;

public:
    Gun weapon;
    // Конструктор по умолчанию
    Human() {
        name = "Kue";
        gender = "female";
        power = 10.0;
        health = MAX_HEALTH;
        technics = 1;
    };

    // Конструктор инициализации расширенный
    Human(string _name, string  _gender, double _power,
        double _health, int _technics, string _nameWeapon, double _damage,
        int _cartridges) : Character(_name, _gender, _power, _health) {
        weapon.setName(_nameWeapon);
        weapon.setDamage(_damage);
        weapon.setCartriges(_cartridges);

        technics = _technics;
    };

    // Конструктор инициализации
    Human(string _name, string  _gender, double _power,
        double _health, int _technics, Gun _weapon)
        : Character(_name, _gender, _power, _health) {
        technics = _technics;
        weapon = _weapon;
    };

    // Конструктор копирования
    Human(const Human& h) : Character(h.name, h.gender, h.power, h.health) {
        technics = h.technics;
        weapon = h.weapon;
    };

    // Метод получения техники
    int getTechnics() { return technics; };

    // Метод установки техники
    void setTechnics(int _technics) {
        technics = _technics;
    };

    // Метод вывода информации
    void print_character_info() override {
        double tmp;
        cout << "Name: " << name << endl <<
            "Gender: " << gender << endl <<
            "Power: " << power << endl <<
            "Health: " << health << endl << 
            "Technics: " << technics << endl;
        tmp = weapon.getDamage();
        weapon.setDamage(tmp + (1.175 * technics));
        weapon.print_weapon_info();
        weapon.setDamage(tmp);
    };

    // Метод атаки
    void attack(Character* attacked) override {
        if (weapon.getCartriges() > 0) {
            attacked->attacked(weapon.getDamage(), 0.0, 0, 0, weapon.getCartriges(), 0, 0, technics, power, 1);
            weapon.setCartriges(weapon.getCartriges() - 1);
            technics++;
        };
    };

    // Метод получения урона
    void attacked(double _damage, double _extraDamage, int _time, int _arrows,
        int _cartridges, int _strenght, int _dexterity, int _technics, int power, int type) override {
        if (type == 1) {
            _damage += (1.175 * _technics);
        }
        else if (type == 3) {
            _damage = _damage / 100 * _strenght;
        };
        health -= _damage;
        if (type == 1 && _strenght > 50) {
            _strenght -= 4;
        }
        else if (type == 3) {
            _technics++;
        };
    };
};

// Класс песонажа Archer -> Bow
class Archer : public Character{
private:
  int dexterity;

public:
    Bow weapon;
    // Конструктор по умолчанию
    Archer() {
        name = "Robin the Hood";
        gender = "male";
        power = 15.0;
        health = MAX_HEALTH;
        dexterity = 1;
    };

    // Конструктор инициализации расширенный
    Archer(string _name, string  _gender, double _power,
        double _health, int _dexterity, string _nameWeapon, double _damage,
        int _arrows, double _extraDamage, int _time) 
        : Character(_name, _gender, _power, _health) {
        weapon.setName(_nameWeapon);
        weapon.setDamage(_damage);
        weapon.setArrows(_arrows);
        weapon.setExtraDamage(_extraDamage);
        weapon.setTime(_time);

        dexterity = _dexterity;
    };

    // Конструктор инициализации
    Archer(string _name, string  _gender, double _power,
        double _health, int _dexterity, Bow _weapon)
        : Character(_name, _gender, _power, _health) {
        dexterity = _dexterity;
        weapon = _weapon;
    };

    // Конструктор копирования
    Archer(const Archer& a) : Character(a.name, a.gender, a.power, a.health){
        dexterity = a.dexterity;
        weapon = a.weapon;
    }

    // Метод получения Ловкости
    int getDexterity() { return dexterity; };

    // Метод установки Ловкости
    void setDexterity(int _dexterity) {
        dexterity = _dexterity;
    };

    // Метод вывода информации
    void print_character_info() {
        cout << "Name: " << name << endl <<
            "Gender: " << gender << endl <<
            "Power: " << power << endl <<
            "Health: " << health << endl << 
            "Dexterity: " << dexterity << endl;
        weapon.print_weapon_info();
    };

    // Метод атаки
    void attack(Character* attacked) {
        if (weapon.getArrows() > 0) {
            attacked->attacked(weapon.getDamage(), weapon.getExtraDamage(), weapon.getTime(), weapon.getArrows(), 0, 0, dexterity, 0, power, 2);
            weapon.setArrows(weapon.getArrows() - 1);
        };
    };
    
    // Метод получения урона
    void attacked(double _damage, double _extraDamage, int _time, int _arrows,
        int _cartridges, int _strenght, int _dexterity, int _technics, int power, int type) override {
        if (type == 1) {
            _damage += (1.175 * _technics);
        }
        else if (type == 3) {
            _damage = _damage / 100 * _strenght;
        };
        health -= _damage;
        if (type == 1 && _strenght > 50) {
            _strenght -= 4;
        }
        else if (type == 3) {
            _technics++;
        };
    };
};

// Класс персонажа Warrior -> Axe
class Warrior : public Character {
private:
    double armor;

public:
    Axe weapon;
    // Конструктор по умолчанию
    Warrior() {
        name = "Garrosh Hellscream";
        gender = "male";
        power = 10.0;
        health = MAX_HEALTH;
        armor = 30.0;
    };

    // Конструктор инициализации расширенный
    Warrior(string _name, string  _gender, double _power,
        double _health, string _nameWeapon, double _damage, int _strenght,
        double _armor) : Character(_name, _gender, _power, _health) {

        weapon.setName(_nameWeapon);
        weapon.setDamage(_damage);
        weapon.setStrenght(_strenght);

        armor = _armor;
    };

    // Конструктор инициализации
    Warrior(string _name, string  _gender, double _power,
        double _health, double _armor, Axe _weapon)
        : Character(_name, _gender, _power, _health) {
        weapon = _weapon;
        armor = _armor;
    };

    // Конструктор копирования
    Warrior(const Warrior& w) : Character(w.name, w.gender, w.power, w.health) {
        weapon = w.weapon;
        armor = w.armor;
    };

    // Метод получения Брони
    int getArmor() { return armor; };

    // Метод установки Брони
    void setArmor(int _armor) {
        armor = _armor;
    };

    // Метод вывода информации
    void print_character_info() {
        double tmp;
        cout << "Name: " << name << endl <<
            "Gender: " << gender << endl <<
            "Power: " << power << endl <<
            "Health: " << health << endl <<
            "Armor: " << armor << endl;
        tmp = weapon.getDamage();
        weapon.setDamage(tmp / 100 * weapon.getStrenght());
        weapon.print_weapon_info();
        weapon.setDamage(tmp);
    };
    
    // Метод атаки
    void attack(Character* attacked) override {
        attacked->attacked(weapon.getDamage(), 0.0, 0, 0, 0, weapon.getStrenght(), 0, 0, power, 3);
        weapon.setStrenght(weapon.getStrenght() - 4);
    };

    // Метод получения урона
    void attacked(double _damage, double _extraDamage, int _time, int _arrows,
        int _cartridges, int _strenght, int _dexterity, int _technics, int power, int type) override {
        double tmp;
        if (type == 1) {
            _damage += (1.175 * _technics);
        }
        else if (type == 3) {
            _damage = _damage / 100 * _strenght;
        };
        if (armor > 0) {
            if (armor < _damage) {
                tmp = (armor - _damage) * (-1);
                armor = 0;
                health -= tmp;
            }
            else {
                armor -= _damage;
            };
        }
        else { health -= _damage; };
    };
};

// Функция тестирования правильности создания персонажей
//int tests(); (не доделан)
