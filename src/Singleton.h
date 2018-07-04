#pragma once

class State;

template <typename T>
class Singleton {
public:
    static T& get(State& state) {
        static T inst(state);
        return inst;
    }

    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};
