/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** HitPoint
*/

/**
 * @file        HitPoint.hpp
 * @brief       HitPoint component
 * @details     ECS are fun, ECS are life.
 * @author      Tom Wederich (@TheGorb)
 * @date        11/11/2021
 */

#ifndef HITPOINT_HPP_
#define HITPOINT_HPP_

namespace ne {
    class HitPoint {
        public:
            HitPoint()
            {
            };

            HitPoint(int hitpoint)
            {
                hp = hitpoint;
            };

            ~HitPoint()
            {
            };

            void OnHit()
            {
                hp--;
            }

            void setHp(int hitpoint)
            {
                hp = hitpoint;
            }
            int hp = 1;
        protected:
        private:
    };
}

#endif /* !HITPOINT_HPP_ */
