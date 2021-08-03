#include <iostream>
#include <SFML/Graphics.hpp>

#include "engine.h"

class MyEngine: public ge::Engine {
    using ge::Engine::Engine;

public:
    void init() {
        shape = sf::CircleShape(100.f);
        shape.setFillColor(sf::Color::Green);
    }

    void draw() {
        win.draw(shape);
    }

private:
    sf::CircleShape shape;
};

int main() {
    MyEngine e(200, 200, "SFML works!");
    e.run();
    return 0;
}