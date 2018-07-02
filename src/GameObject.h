#pragma once

class GameObject {
public:
    virtual void process() = 0;

protected:
    ~GameObject() = default;
};
