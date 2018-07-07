#pragma once

#include <memory>

template <typename T>
class Singleton {
public:
    static std::shared_ptr<T> get() {
        static std::shared_ptr<T> inst{new T()};
        return inst;
    }

    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};
