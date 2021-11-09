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

            auto front(
            ) -> T const&
            {
                std::scoped_lock lock(_mutex);
                return _queue.front();
            }

            auto back(
            ) -> T const&
            {
                std::scoped_lock lock(_mutex);
                return _queue.back();
            }

            auto push_front(
                const T& item
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.emplace_front(std::move(item));
            }

            auto push_back(
                const T& item
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.emplace_back(std::move(item));
            }

            auto empty(
            ) -> bool
            {
                std::scoped_lock lock(_mutex);
                return _queue.empty();
            }

            auto count(
            ) -> size_t
            {
                std::scoped_lock lock(_mutex);
                return _queue.size();
            }

            auto clear(
            ) -> void
            {
                std::scoped_lock lock(_mutex);
                _queue.clear();
            }

            auto pop_front(
            ) -> T
            {
                std::scoped_lock lock(_mutex);
                auto t = std::move(_queue.front());
                _queue.pop_front();
                return t;
            }

            auto pop_back(
            ) -> T
            {
                std::scoped_lock lock(_mutex);
                auto t = std::move(_queue.back());
                _queue.pop_back();
                return t;
            }

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
