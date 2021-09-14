//SFML Images
#include<iostream>
using namespace std;


#include "SFML/Graphics.hpp"
const int HEIGHT = 500;
const int WIDTH = 500;
const std::string title = "a";

void quiz(int spot);

sf::Texture img1;
sf::Texture img2;
sf::Texture img3;
sf::Texture img4;

sf::Sprite pic1;
sf::Sprite pic4;
sf::Sprite pic2;
sf::Sprite pic3;

sf::Text question;

int questionNum = 0;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
bool triggered = false;

int main() {
    sf::RectangleShape TL;
    sf::RectangleShape TR;
    sf::RectangleShape BL;
    sf::RectangleShape BR;
    TL.setFillColor(sf::Color::Red);
    BL.setFillColor(sf::Color::Green);
    TR.setFillColor(sf::Color::Yellow);
    BR.setFillColor(sf::Color::Blue);
    TL.setSize({ WIDTH / 2, HEIGHT / 2 });
    TR.setSize({ WIDTH / 2, HEIGHT / 2 });
    BL.setSize({ WIDTH / 2, HEIGHT / 2 });
    BR.setSize({ WIDTH / 2, HEIGHT / 2 });
    TL.setPosition({0,0});
    TR.setPosition({ WIDTH / 2,0 });
    BL.setPosition({0, HEIGHT / 2});
    BR.setPosition({WIDTH/2, HEIGHT / 2});

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) return 0;
    question.setFont(font);
    question.setCharacterSize(24);

    //game set up (you'll need these two lines in every game)
    sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), title); //set up screen
    sf::Event event; //set up event queue

    //Here's how to load an image: clicke file->save as to see where to store "dog.png"

    if (!img1.loadFromFile("dog.png")) return 0; //this line loads the image AND kills your program if it doesn't load
    if (!img2.loadFromFile("dog.png")) return 0; //this line loads the image AND kills your program if it doesn't load
    if (!img3.loadFromFile("dog.png")) return 0; //this line loads the image AND kills your program if it doesn't load
    if (!img4.loadFromFile("dog.png")) return 0; //this line loads the image AND kills your program if it doesn't load

    pic1.setScale({ 0.5, 0.5 });
    pic2.setScale({ 0.5, 0.5 });
    pic3.setScale({ 0.5, 0.5 });
    pic4.setScale({ 0.5, 0.5 });

    pic1.setTexture(img1);
    pic2.setTexture(img2);
    pic3.setTexture(img3);
    pic4.setTexture(img4);

    pic1.setPosition({ 0 , 30 });
    pic2.setPosition({ 250, 30 });
    pic3.setPosition({ 0, 250 });
    pic4.setPosition({ 250, 250 });

    question.setString("Click on a box to continue");
    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (renderWindow.isOpen()) {//keep window open until user shuts it down

        while (renderWindow.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

            
            

        }//end event loop---------------------------------------------------------------
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!triggered) {
                triggered = true;
                sf::Vector2i position = sf::Mouse::getPosition(renderWindow);
                //printf("%d, %d", position.x, position.y);
                if (position.x < WIDTH / 2 && position.y < HEIGHT / 2)
                    quiz(1);
                if (position.x > WIDTH / 2 && position.y < HEIGHT / 2)
                    quiz(2);
                if (position.x < WIDTH / 2 && position.y > HEIGHT / 2)
                    quiz(3);
                if (position.x > WIDTH / 2 && position.y > HEIGHT / 2)
                    quiz(4);
            }
        }
        else {
            triggered = false;
        }

        //render section-----------------------------------------
        renderWindow.clear(); //wipes screen, without this things smear
        renderWindow.draw(BL);
        renderWindow.draw(TL);
        renderWindow.draw(TR);
        renderWindow.draw(BR);
        renderWindow.draw(pic1); 
        renderWindow.draw(pic2); 
        renderWindow.draw(pic3); 
        renderWindow.draw(pic4); 
        renderWindow.draw(question);
        renderWindow.display(); 

    }//######################## end game loop ###################################################################################

} //end game

void quiz(int spot) {
    if (questionNum < 5) {
        switch (spot) {
        case 1:
            if (questionNum == 1) {
                p1++;
            }
            if (questionNum == 2) {
                p2++;
            }
            if (questionNum == 3) {
                p3++;
            }
            if (questionNum == 4) {
                p4++;
            }
            if (questionNum == 5) {
                p2++;
            }
            questionNum++;
            question.setString("Question " + to_string(questionNum));
            break;
        case 2:
            if (questionNum == 1) {
                p2++;
            }
            if (questionNum == 2) {
                p3++;
            }
            if (questionNum == 3) {
                p4++;
            }
            if (questionNum == 4) {
                p1++;
            }
            if (questionNum == 5) {
                p1++;
            }
            questionNum++;
            question.setString("Question " + to_string(questionNum));
            break;
        case 3:
            if (questionNum == 1) {
                p3++;
            }
            if (questionNum == 2) {
                p4++;
            }
            if (questionNum == 3) {
                p1++;
            }
            if (questionNum == 4) {
                p2++;
            }
            if (questionNum == 5) {
                p3++;
            }
            questionNum++;
            question.setString("Question " + to_string(questionNum));
            break;
        case 4:
            if (questionNum == 1) {
                p4++;
            }
            if (questionNum == 2) {
                p1++;
            }
            if (questionNum == 3) {
                p2++;
            }
            if (questionNum == 4) {
                p3++;
            }
            if (questionNum == 5) {
                p4++;
            }
            questionNum++;
            question.setString("Question " + to_string(questionNum));
            break;
        };
    } else {
        printf("%d, %d, %d, %d", p1, p2, p3, p4);
        if (p1 >= p2 && p1 >= p3 && p1 >= p4)
            question.setString("You are p1");
        else if (p2 >= p1 && p2 >= p3 && p2 >= p4)
            question.setString("You are p2");
        else if (p3 >= p1 && p3 >= p2 && p3 >= p4)
            question.setString("You are p3");
        else if (p4 >= p1 && p4 >= p2 && p4 >= p3)
            question.setString("You are p4");
    }
    if (questionNum == 1) {
        if (!img1.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img2.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img3.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img4.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
    }
    if (questionNum == 2) {
        if (!img1.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img2.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img3.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img4.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
    }
    if (questionNum == 3) {
        if (!img1.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img2.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img3.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img4.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
    }
    if (questionNum == 4) {
        if (!img1.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img2.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img3.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
        if (!img4.loadFromFile("dog.png")); //this line loads the image AND kills your program if it doesn't load
    }
}
