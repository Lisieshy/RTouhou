/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** EntityType
*/

#ifndef ENTITYTYPE_HPP_
#define ENTITYTYPE_HPP_

namespace ne {
    class EntityType {
        public:
            enum Type {
                BasicEnnemy,
                DarkEnnemy,
                GreenEnnemy,
                OrangeEnnemy,
                WhiteEnnemy,
                WhiteBullets, 
                Tier2Bullets,
                Tier3Bullets,
                Bullets,
                Bonus,
                Player
            };
    };
}

#endif /* !ENTITYTYPE_HPP_ */
