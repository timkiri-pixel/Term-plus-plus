#include <cctype>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

class Player {
private:
  std::string name;
  int health = 100;

public:
  Player() {};

  void setName(const std::string &playerName) { name = playerName; }

  void takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
      health = 0;
    }
  }

  void displayInfo() const {
    std::cout << "Name: " << name << '\n';
    std::cout << "Health: " << health << '\n';
  }

  int getHealth() const { return health; }
};

class Enemy {
private:
  std::string name;
  int health = 100;

public:
  Enemy(const std::string &enemyName) : name(enemyName) {}

  void takeDamage(int damage) {
    health -= damage;

    if (health < 0)
      health = 0;
  }

  void displayInfo() const {
    std::cout << "Name: " << name << '\n';
    std::cout << "Health: " << health << '\n';
  }

  int getHealth() const { return health; }
};

void enemyAttack(Player &player) { player.takeDamage(25); }

bool askRestart() {
  std::string input;

  while (true) {
    std::cout << "Do you want to start over? (yes/no): ";
    std::cin >> input;

    for (char &c : input) {
      c = static_cast<char>(std::tolower(c));
    }

    if (input == "yes") {
      return true;
    } else if (input == "no") {
      return false;
    }

    std::cout << "Please enter yes or no.\n";
  }
}

void cleanupInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int startGame() {
  std::cout << "Starting RPG game...\n";

  bool firstTime = true;

  int weaponChoice;

  std::string characaterChoice;

  std::string input;

  Player alexandr;
  Player mindalia;

  Player *currentPlayer = nullptr;

  Enemy enemy("Goblin");

  while (true) {
    if (firstTime) {
      firstTime = false;
      std::cout << "Welcome to the RPG game!\n";
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Select a character: (1/2/exit): ";

    std::cin >> characaterChoice;

    if (characaterChoice == "1") {
      currentPlayer = &mindalia;
    } else if (characaterChoice == "2") {
      currentPlayer = &alexandr;
    } else if (characaterChoice == "exit") {
      cleanupInput();
      return 0;
    } else {
      std::cout << "Invalid choice '" << characaterChoice << "'" << std::endl;
      continue;
    }

    std::cout << "-- Info\n";
    currentPlayer->displayInfo();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "-- Action(s)\n";
    std::cout << "An enemy attacks you!\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    enemyAttack(*currentPlayer);

    if (currentPlayer->getHealth() == 0 && enemy.getHealth() == 0) {
      std::cout << "Both died!\n";

      if (askRestart()) {
        continue;
      } else {
        std::cout << "Goodbye.\n";
        break;
      }
    } else if (currentPlayer->getHealth() == 0) {
      std::cout << "You died!\n";

      if (askRestart()) {
        continue;
      } else {
        std::cout << "Goodbye.\n";
        break;
      }
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    currentPlayer->displayInfo();

    std::cout << "-- Weapon Choice\n";
    std::cout << "1. Axe - deals the maximum of damage\n";
    std::cout << "2. Sword - deals medium damage\n";
    std::cout << "3. Stick - deals the least damage\n";
    std::cout << ">>> ";

    std::cin >> weaponChoice;

    if (weaponChoice == 1) {
      enemy.takeDamage(30);
      enemy.displayInfo();
    } else if (weaponChoice == 2) {
      enemy.takeDamage(25);
      enemy.displayInfo();
    } else if (weaponChoice == 3) {
      enemy.takeDamage(10);
      enemy.displayInfo();
    } else {
      std::cout << "Choose one of the three weapons." << std::flush;
    }

    if (enemy.getHealth() == 0) {
      std::cout << "The enemy died!\n";
      std::cout << "Victory!\n";

      if (askRestart()) {
        continue;
      } else {
        std::cout << "Goodbye.\n";
        break;
      }
    }
  }
  return 0;
}
