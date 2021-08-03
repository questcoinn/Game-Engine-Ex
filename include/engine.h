#ifndef GE_ENGINE_H
#define GE_ENGINE_H

#include <string>
#include <SFML/Graphics.hpp>

namespace ge {

class Engine {
public:
    Engine(unsigned int width, unsigned int height, std::string title)
        :win(sf::VideoMode(width, height), title)
    {
    }

    ~Engine() = default;

public:
    void run() {
        this->init();

        while(this->win.isOpen()) {
            sf::Event event;
            while(this->win.pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    this->win.close();
                }
            }

            this->win.clear();
            this->draw();
            // this->win.draw(shape);
            this->win.display();
        }
    }

// virtuals
public:
    virtual void init() {}
    virtual void draw() {}

protected:
    sf::RenderWindow win;
};

} // namespace ge

#endif