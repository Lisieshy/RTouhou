/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Parallax
*/

#include "../include/Parallax.hpp"

ne::Parallax::Parallax()
{
    sf::Sprite par1;
    sf::Sprite par2;
    sf::Sprite par3;
    sf::Sprite par4;
    sf::Sprite par5;
    sf::Sprite par6;

    par1.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_1.png"));
    par2.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_2.png"));
    par3.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_3.png"));
    par4.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_4.png"));
    par5.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_5.png"));
    par6.setTexture(ne::GlobalTexture::Instance().GetData("resources/parallax/bkgd_6.png"));
    
    par1.setScale({1.5, 1.5});
    par2.setScale({1.5, 1.5});
    par3.setScale({1.5, 1.5});
    par4.setScale({1.5, 1.5});
    par5.setScale({1.5, 1.5});
    par6.setScale({1.5, 1.5});

    par1.setPosition({0.f, 0.f});
    par2.setPosition({0.f, -1000.f});
    par3.setPosition({0.f, -2000.f});
    par4.setPosition({0.f, -3000.f});
    par5.setPosition({0.f, -4000.f});
    par6.setPosition({0.f, -5000.f});

    _par.push_back(par1);
    _par2.push_back(par2);
    _par3.push_back(par3);
    _par4.push_back(par4);
    _par5.push_back(par5);
    _par6.push_back(par6);
}

ne::Parallax::~Parallax()
{
}

void ne::Parallax::update(float dt)
{
    size_t x = 0;

    for (auto &i : _par) {
        float pos = i.getPosition().y;
        pos += 200 * dt;
        if (pos > ne::Graphics::Window::getWindow().y + 800) {
            pos = -3500.f;
        } 
        i.setPosition({0.f, pos});
        ne::Graphics::Window::draw(i);
        x++;
    }

    for (auto &i : _par3) {
        float pos = i.getPosition().y;
        pos += 400 * dt;
        if (pos > ne::Graphics::Window::getWindow().y + 1100) {
            pos = -4900.f;
        } 
        i.setPosition({0.f, pos});
        ne::Graphics::Window::draw(i);
        x++;
    }

    for (auto &i : _par2) {
        float pos = i.getPosition().y;
        pos += 400 * dt;
        if (pos > ne::Graphics::Window::getWindow().y + 900) {
            pos = -4200.f;
        } 
        i.setPosition({0.f, pos});
        ne::Graphics::Window::draw(i);
        x++;
    }
}