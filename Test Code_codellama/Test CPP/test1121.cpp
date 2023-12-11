#include "gtest/gtest.h"
#include "character.h"

TEST(CharacterTest, CreateCharacter) {
    Character character("John", 10, 10);
    EXPECT_EQ(character.getName(), "John");
    EXPECT_EQ(character.getHealth(), 10);
    EXPECT_EQ(character.getStrength(), 10);
}

TEST(CharacterTest, SetCharacterName) {
    Character character("John", 10, 10);
    character.setName("Jane");
    EXPECT_EQ(character.getName(), "Jane");
}

TEST(CharacterTest, SetCharacterHealth) {
    Character character("John", 10, 10);
    character.setHealth(5);
    EXPECT_EQ(character.getHealth(), 5);
}

TEST(CharacterTest, SetCharacterStrength) {
    Character character("John", 10, 10);
    character.setStrength(5);
    EXPECT_EQ(character.getStrength(), 5);
}

TEST(CharacterTest, Attack) {
    Character character("John", 10, 10);
    Character enemy("Enemy", 10, 10);
    character.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 5);
}

TEST(CharacterTest, Defend) {
    Character character("John", 10, 10);
    Character enemy("Enemy", 10, 10);
    character.defend(enemy);
    EXPECT_EQ(enemy.getHealth(), 10);
}
