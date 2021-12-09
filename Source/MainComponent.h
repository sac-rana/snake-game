#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AnimatedAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void update() override;
    juce::Point<int> randomFood() {
        return juce::Point<int>(random.nextInt(pieces - 3) * box + box, random.nextInt(pieces - 3) * box + box);
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
    int pieces;
    int box;
    std::vector<juce::Point<int>> snake;
    juce::Point<int> food;
    int score;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
