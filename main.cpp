#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/VideoMode.hpp>

struct Body {
    float x;
    float y;
    float w;
    float h;
    float v;
    bool up;
    bool down;
    bool left;
    bool right;
};

int main()
{
    // Criar a janela principal
    sf::RenderWindow window(sf::VideoMode(800, 500), "SFML window");

    // Inicialização

    // Aqui você pode inicializar seus objetos.
   
    Body player1 = {720,10,20,100,1,false,false,false,false};
    Body player2 = {30,10,20,100,1,false,false,false,false};
    Body ball = {390,220,20,20,0.2,false,false,false,true};
    // Aqui você pode inicializar suas texturas e cores.

    sf::RectangleShape rectanglePlayer1;
    rectanglePlayer1.setSize(sf::Vector2f(player1.w, player1.h));
    rectanglePlayer1.setFillColor(sf::Color::Black);
    rectanglePlayer1.setPosition(player1.x,player1.y);

    sf::RectangleShape rectanglePlayer2;
    rectanglePlayer2.setSize(sf::Vector2f(player2.w, player2.h));
    rectanglePlayer2.setFillColor(sf::Color::Black);
    rectanglePlayer2.setPosition(player2.x,player2.y);


    sf::RectangleShape rectangleBall;
    rectangleBall.setSize(sf::Vector2f(ball.w, ball.h));
    rectangleBall.setFillColor(sf::Color::Black);
    rectangleBall.setPosition(ball.x,ball.y);

    // Loop principal do jogo
    while (window.isOpen())
    {
        // Processar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
    
            //================================Eventos de keyUP===========================================
            if (event.type == sf::Event::KeyReleased)
            {
                //Movimentação de keyup do player 1
                if (event.key.code == sf::Keyboard::Up)
                {
                    player1.up = false;
                };
                if (event.key.code == sf::Keyboard::Down)
                {
                    player1.down = false;
                };

                //Movimentação de keyup do player2
                if (event.key.code == sf::Keyboard::W)
                {
                    player2.up = false;
                };
                if (event.key.code == sf::Keyboard::S)
                {
                    player2.down = false;
                };
            };
        }


        //================================Eventos de KeyDown===========================================

        //Movimentação de keydown do player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player1.up = true;
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player1.down = true;
        };

        //Movimentação de keydown do player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player2.up = true;
        };

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player2.down = true;
        };

        //================================Atualiza o estado do jogo========================================

        //movimentação player1
        if(player1.up){
            player1.y -= player1.v;
        };
        if(player1.down){
            player1.y+=player1.v;
        };

        //movimentação player2
        if(player2.up){
            player2.y -= player2.v;
        };
        if(player2.down){
            player2.y += player2.v;
        };

        //movimentação da bola
        if(ball.up){
          ball.y -= ball.v;
        };
        if(ball.down){
          ball.y += ball.v;
        };
        if(ball.left){
            ball.x -= ball.v;
        };
        if(ball.right){
          ball.x += ball.v  ;
        };

        //================================Colisões e lógica===========================================

        //Colisões player 1
        if(player1.y<0){
            player1.y = 0;
        };
        if(player1.y+player1.h>500){
            player1.y = 500-player1.h;
        };

        //colisões player 2
        if(player2.y<0){
            player2.y = 0;
        };
        if(player2.y+player2.h>500){
            player2.y = 500-player2.h;
        };

        //colisões da bola com o player 1
        if(ball.x+ball.w >= player1.x){
            if(ball.y >= player1.y && ball.y <= player1.y+player1.h){
                ball.right=false;
                ball.left=true;
            }
            if(ball.y+ball.h >=player1.y && ball.y+ball.h <= player1.y+player1.h){
                ball.right=false;
                ball.left=true;
            };
        };

        //colisões da bola com o player 2
        if(ball.x <= player2.x+player2.w){
            if(ball.y >= player2.y && ball.y <= player2.y+player2.h){
                ball.left=false;
                ball.right=true;
            }
            if(ball.y+ball.h >=player2.y && ball.y+ball.h <= player2.y+player2.h){
                ball.left=false;
                ball.right=true;
            };
        };

        //Atualização das posições
        rectanglePlayer1.setPosition(player1.x,player1.y);
        rectanglePlayer2.setPosition(player2.x,player2.y);
        rectangleBall.setPosition(ball.x,ball.y);

        // Renderização
        window.clear(sf::Color::White);
        
        // Desenhar coisas na tela
        window.draw(rectanglePlayer1);
        window.draw(rectanglePlayer2);
        window.draw(rectangleBall);
        // Aqui você pode desenhar seus objetos, textos, etc.
        
        window.display();
    }

    return 0;
}
