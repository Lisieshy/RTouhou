/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ScoreUp
*/

#include "ScoreUp.hpp"

ne::ScoreUp::ScoreUp()
{
    std::random_device rd;
    std::random_device rd3;
    std::mt19937 gen(rd());
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> distrib(0, 800);
    std::uniform_int_distribution<> distribY(0, 600);

    ne::Transform transform;
    transform.position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), 0.f, 0.f},
    transform.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transform.scale = ne::Math::Vector3f{32.f, 32.f, 0.f};
    setTransform(transform);

    ne::Skin skin;
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/Bonus/BonusImage.png"));
    skin.sprite.setTextureRect(sf::IntRect(47, 1, 16, 16));
    setSkin(skin);

    ne::EntityType::Type newType = ne::EntityType::Type::ScoreUp;
    setType(newType);

    setPattern(std::bind(&ne::Patterns::topToBotSnakePattern, &this->getPattern()));
}

ne::ScoreUp::~ScoreUp()
{
}
