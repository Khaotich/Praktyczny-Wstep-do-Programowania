#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>

using namespace sf;

//zmienne gry
const int N = 100;
bool one, play = true;
int points = 0;

//rozmiar pi³ki
float size = 41;

//zmienne prêdkoœci pi³ki
float vx = 6;
float vy = 5;

int main()
{
    srand(time(NULL));
    
    RenderWindow app(VideoMode(800, 600), "Arkanoid");
    app.setFramerateLimit(60);
    
    //inicjowanie tekstów i tekstur gry
    Texture ball_p, block_p, pandle_p;
    Text endgame, text, enter;
    Font font;
    font.loadFromFile("src/arial.ttf");
    
    //k³adka
    pandle_p.loadFromFile("src/pandle.png");
    Sprite pandle(pandle_p);
    pandle.setPosition(350, 550);

    //pi³ka
    ball_p.loadFromFile("src/ball.png");
    Sprite ball(ball_p);
    ball.setScale(0.08, 0.08);
    ball.setPosition(320, 400);
    
    //klocki
    Sprite blocks[N];
    block_p.loadFromFile("src/block.png");
    for (int i = 0; i < N; i++)
    {
        blocks[i].setTexture(block_p);
        blocks[i].setScale(1.5, 1.5);
    }
    
    int temp = 0;
    for (int y = 50; y < 370; y += 32)
    {
        for (int x = 75; x < 700; x += 65)
        {
            blocks[temp].setPosition(x, y);
            temp++;
        }
    }

    //tekst
    endgame.setFillColor(Color::White);
    endgame.setFont(font);
    endgame.setCharacterSize(28);
    endgame.setPosition(150, 150);
    endgame.setStyle(Text::Bold | Text::Underlined);
    
    enter.setFillColor(Color::White); 
    enter.setFont(font);
    enter.setCharacterSize(28);
    enter.setPosition(150, 200);
    enter.setStyle(Text::Bold | Text::Underlined);
    enter.setString("Nacisni ENTER aby zakonczyc gre.");

    text.setFont(font);
    text.setCharacterSize(18);
    text.setPosition(2, 2);
    text.setStyle(Text::Bold | Text::Underlined);
    

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if(event.type == Event::Closed) app.close();
            if(!play && Keyboard::isKeyPressed(Keyboard::Enter)) app.close();
        }

        //ruch k³adki
        if (play && Keyboard::isKeyPressed(Keyboard::Right) && pandle.getPosition().x < 698) pandle.move(8, 0);
        if (play && Keyboard::isKeyPressed(Keyboard::Left) && pandle.getPosition().x > 2) pandle.move(-8, 0);

        //ruch pi³ki
        //koniec gry
        if (ball.getPosition().y + size >= 600) play = false;
        //odbicia od œcianek
        else if (ball.getPosition().x <= 0 || ball.getPosition().x + size >= 800) vx = -vx;
        else if (ball.getPosition().y < 0) vy = -vy;

        //odbicia od klocków
        one = true;
        for (int i = 0; i < temp; i++)
        {
            if (FloatRect(ball.getPosition().x, ball.getPosition().y, size, size).intersects(blocks[i].getGlobalBounds()) && one)
            {
                blocks[i].setPosition(-1000,0);
                vx = -vx;
                vy = -vy;
                one = false;
                points++;
            }
        }
        
        //odbicia od k³adki
        if (FloatRect(ball.getPosition().x, ball.getPosition().y, size, size).intersects(pandle.getGlobalBounds()))
        {
            vy = -(rand()%5+2);
        }
        
        ball.move(vx, vy);

        //punkty
        text.setString("Punkty: " + std::to_string(points));

        if (points == 100) play = false;

        //czyszczenie i rysowanie obiektów
        if (play) //gra trwa
        {
            app.clear(Color::Blue);
            app.draw(ball);
            app.draw(pandle);
            app.draw(text);
            for (int i = 0; i < N; i++) app.draw(blocks[i]);
        }
        else //scena koñca gry
        {
            app.clear();
            endgame.setString("Koniec gry, konczysz z wynikiem: " + std::to_string(points) + "!");
            app.draw(endgame);
            app.draw(enter);
        }
        app.display();
    } 
    return 0;
}