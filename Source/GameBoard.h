#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class GameBoard  : public juce::AnimatedAppComponent, public juce::KeyListener
{
public:
    //==============================================================================
    GameBoard();
    ~GameBoard() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void update() override;
    bool keyPressed(const juce::KeyPress&, juce::Component* comp) override;
    juce::Point<int> randomFood() {
        return juce::Point<int>(random.nextInt(piecesX) * box, random.nextInt(piecesY) * box);
    }
    //bool keyPressed(const juce::KeyPress &, Component*) override;
private:
    //==============================================================================
    // Your private member variables go here...
    enum class Direction {
        UP, DOWN, LEFT, RIGHT
    };
    Direction direction;
    juce::Random random;
    int piecesX;
    int piecesY;
    int box;
    std::vector<juce::Point<int>> snake;
    juce::Point<int> food;
    int score;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GameBoard)
};
