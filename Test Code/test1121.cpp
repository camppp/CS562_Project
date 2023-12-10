// character_test.cpp
#include <gtest/gtest.h>
#include "character.h"

TEST(CharacterTest, Initialization) {
  Character character("Player1", 100);
  EXPECT_EQ("Player1", character.getName());
  EXPECT_EQ(100, character.getHealth());
}

// command_test.cpp
#include <gtest/gtest.h>
#include "command.h"

TEST(CommandTest, Execution) {
  Character character("Player1", 100);
  Command command("Attack", 20);
  command.execute(character);
  EXPECT_EQ(80, character.getHealth());
}

// enemy_test.cpp
#include <gtest/gtest.h>
#include "enemy.h"

TEST(EnemyTest, Initialization) {
  Enemy enemy("Goblin", 50, 10);
  EXPECT_EQ("Goblin", enemy.getName());
  EXPECT_EQ(50, enemy.getHealth());
  EXPECT_EQ(10, enemy.getDamage());
}

// hero_test.cpp
#include <gtest/gtest.h>
#include "hero.h"

TEST(HeroTest, InteractionWithEnemy) {
  Hero hero("Warrior", 150, 30);
  Enemy enemy("Orc", 80, 15);
  hero.attack(enemy);
  EXPECT_EQ(65, enemy.getHealth());
}

// world_test.cpp
#include <gtest/gtest.h>
#include "world.h"

TEST(WorldTest, Initialization) {
  World world;
  EXPECT_TRUE(world.isInitialized());
}

TEST(WorldTest, InteractionWithHeroesAndEnemies) {
  World world;
  Hero hero("Mage", 120, 25);
  Enemy enemy("Dragon", 200, 40);
  world.spawn(hero);
  world.spawn(enemy);
  world.processTurn();
  EXPECT_EQ(80, enemy.getHealth());
  world.processTurn();
  EXPECT_EQ(40, hero.getHealth());
}
