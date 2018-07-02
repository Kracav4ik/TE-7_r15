#pragma once

template <typename T>
class Singleton {
public:
    static T& get() {
        static T inst;
        return inst;
    }

    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};
