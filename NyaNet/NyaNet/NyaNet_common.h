/*
** EPITECH PROJECT, 2021
** nn_common
** File description:
** nn_common
*/

#ifndef NN_COMMON_H_
#define NN_COMMON_H_

#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <optional>
#include <deque>
#include <chrono>
#include <iostream>
#include <cstdint>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#ifndef ASIO_STANDALONE
#define ASIO_STANDALONE
#endif

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#endif /* !NN_COMMON_H_ */
