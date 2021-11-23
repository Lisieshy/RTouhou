/*
** EPITECH PROJECT, 2021
** NyaNet_tsqueue
** File description:
** NyaNet_tsqueue
*/

#ifndef NYANET_TSQUEUE_H_
#define NYANET_TSQUEUE_H_

#include "NyaNet_common.h"

namespace nn {
    template<typename T>
    class tsqueue {
        public:
            tsqueue() = default;
            tsqueue(const tsqueue<T>&) = delete;
            virtual ~tsqueue() { clear(); }

            /**
             * @brief The front of the queue
             * 
             * @return T const& 
             */
            auto front(
            ) -> T const&
            {
                std::scoped_lock lock(_mutex);
                return _queue.front();
            }
            /**
             * @brief The back of the queue
             * 
             * @return T const& 
             */
            auto back(
            ) -> T const&
            {
                std::scoped_lock lock(_mutex);
                return _queue.back();
            }
            /**
             * @brief Push an item at the front of the queue
             * 
             * @param const T& 
             */
            auto push_front(
                const T& item
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.emplace_front(std::move(item));

                std::unique_lock<std::mutex> ul(_mutexBlocking);
                _cvBlocking.notify_one();
            }
            /**
             * @brief Push an item at the back of the queue
             * 
             * @param item 
             */
            auto push_back(
                const T& item
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.emplace_back(std::move(item));
                std::unique_lock<std::mutex> ul(_mutexBlocking);
                _cvBlocking.notify_one();
            }
            /**
             * @brief Is the queue empty
             * 
             * @return true 
             * @return false 
             */
            auto empty(
            ) -> bool
            {
                std::scoped_lock lock(_mutex);
                return _queue.empty();
            }
            /**
             * @brief Count the number of element in the queue
             * 
             * @return size_t 
             */
            auto count(
            ) -> size_t
            {
                std::scoped_lock lock(_mutex);
                return _queue.size();
            }
            /**
             * @brief Clear the queue
             * 
             */
            auto clear(
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.clear();
            }
            /**
             * @brief Pop the first element of the queue
             * 
             * @return T 
             */
            auto pop_front(
            ) -> T
            {
                std::scoped_lock lock(_mutex);
                auto t = std::move(_queue.front());
                _queue.pop_front();
                return t;
            }
            /**
             * @brief Pop the last element of the queue
             * 
             * @return T 
             */
            auto pop_back(
            ) -> T
            {
                std::scoped_lock lock(_mutex);
                auto t = std::move(_queue.back());
                _queue.pop_back();
                return t;
            }
            /**
             * @brief Wait while the queue is empty
             * 
             */
            auto wait(
            ) -> void
            {
                while (empty()) {
                    std::unique_lock<std::mutex> ul(_mutexBlocking);
                    _cvBlocking.wait(ul);

                }
            }

        protected:
            std::mutex _mutex;
            std::deque<T> _queue;
            std::condition_variable _cvBlocking;
            std::mutex _mutexBlocking;
    };
}

#endif /* !NYANET_TSQUEUE_H_ */
