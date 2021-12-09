#include "GameBoard.h"

//==============================================================================
GameBoard::GameBoard()
{
    setSize (600, 400);
    setFramesPerSecond(5);
    setWantsKeyboardFocus(true);
    addKeyListener(this);
    direction = Direction::RIGHT;
    piecesX = 20;
    box = getWidth() / piecesX;
    piecesY = getHeight() / box;
    snake = { juce::Point<int>(1 * box, 1 * box) };
    food = randomFood();
}

GameBoard::~GameBoard()
{
}

//==============================================================================
void GameBoard::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);
    g.setColour(juce::Colours::red);
    for (const auto &part: snake) {
        g.fillRect(part.getX(), part.getY(), box, box);
    }
    g.setColour(juce::Colours::green);
    g.fillRect(food.getX(), food.getY(), box, box);
}

void GameBoard::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void GameBoard::update() {
    // old head position
    auto oldHead{ snake[0] };
    if (direction == Direction::LEFT) oldHead.x -= box;
    else if (direction == Direction::RIGHT) oldHead.x += box;
    else if (direction == Direction::UP) oldHead.y -= box;
    else oldHead.y += box;

    if (oldHead.x == food.x && oldHead.y == food.y) {
        score++;
        food = randomFood();
    }
    else snake.pop_back();

    // add new head
    snake.insert(snake.begin(), oldHead);
}

bool GameBoard::keyPressed(const juce::KeyPress& key, juce::Component* comp) {
    if (key.getKeyCode() == key.leftKey && direction != Direction::RIGHT) direction = Direction::LEFT;
    else if (key.getKeyCode() == key.upKey && direction != Direction::DOWN) direction = Direction::UP;
    else if (key.getKeyCode() == key.rightKey && direction != Direction::LEFT) direction = Direction::RIGHT;
    else if (key.getKeyCode() == key.downKey && direction != Direction::UP) direction = Direction::DOWN;
    return true;
}