#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

const int width = 800;
const int height = 800;
const int r = 200;
float x = 200;
float y = 200;
float vx = 6;
float vy = 2;

int main()
{
    int keyonoff = 1;
    RenderWindow window(VideoMode(width, height), "Lista 7");
    window.setFramerateLimit(60); // limit generowanych klatek
    
    CircleShape shape(r);
    shape.setFillColor(Color::Green);
    shape.setPosition(x, y);
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
            if(event.type == Event::KeyPressed) keyonoff = 1 - keyonoff;
            if((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) window.close();
        }
        
        if (shape.getPosition().x + r * 2 > width || shape.getPosition().x < 0) vx *= -1;
        if (shape.getPosition().y + r * 2 > height || shape.getPosition().y < 0) vy *= -1;

        //ruch ko�a
        x += vx;
        y += vy;

        shape.setPosition(x, y);

        window.clear(Color::Black);
        if (keyonoff)
        {
            window.draw(shape);
        }
        window.display();
    }
}