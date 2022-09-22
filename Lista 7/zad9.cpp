#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

const int width = 800;
const int height = 800;
const int N = 4;

const float r[N] = { 20, 40, 60, 80 };
float x[N] = { 100, 200, 400, 500 };
float y[N] = { 100, 200, 300, 100 };
float vx[N] = { 0.5, 0.6, 0.7, 0.8 };
float vy[N] = { 0, 0, 0, 0 };

Color colors[N] = { Color::Green, Color::Red, Color::Yellow, Color::Blue };
CircleShape shapes[N]{
        CircleShape(r[0]),
        CircleShape(r[1]),
        CircleShape(r[2]),
        CircleShape(r[3]),
};

int main()
{
    int keyonoff = 1;
    RenderWindow window(VideoMode(width, height), "Lista 7");
    window.setFramerateLimit(60); // limit generowanych klatek

    for (int i = 0; i < N; i++) shapes[i].setPosition(x[i], y[i]);
    for (int i = 0; i < N; i++) shapes[i].setFillColor(colors[i]);

    while (window.isOpen())
    {
        for (int i = 0; i < N; i++)
        {


            if (shapes[i].getPosition().x + r[i] * 2.0 >= width || shapes[i].getPosition().x <= 0) vx[i] *= -1.0;
            shapes[i].move(vx[i], vy[i]);
            if (shapes[i].getPosition().y + r[i] * 2.0 >= height || shapes[i].getPosition().y <= 0) vy[i] *= -1.0;
            shapes[i].move(vx[i], vy[i]);

            for (int n = 0; n < N; n++)
            {
                if ((shapes[i].getGlobalBounds().intersects(shapes[n].getGlobalBounds())) && n != i)
                {
                    vx[i] *= -1.0;
                    vy[i] *= -1.0;
                    vx[n] *= -1.0;
                    vy[n] *= -1.0;
                }
            }
            shapes[i].move(vx[i], vy[i]);

            vy[i] += 0.2;
            x[i] += vx[i];
            y[i] += vy[i];

            shapes[i].move(vx[i], vy[i]);
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) keyonoff = 1 - keyonoff;
            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) window.close();
        }

        window.clear(Color::Black);
        if (keyonoff)
        {
            for (int i = 0; i < N; i++) window.draw(shapes[i]);
        }
        window.display();
    }
}