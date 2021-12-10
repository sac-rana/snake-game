/*
  ==============================================================================

    MainComponent.h
    Created: 10 Dec 2021 11:24:15am
    Author:  Sachin Rana

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GameBoard.h"

//==============================================================================
/*
*/
class MainComponent  : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GameBoard *game = new GameBoard();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
