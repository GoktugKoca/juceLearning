/*
  ==============================================================================

    Sliders.h
    Created: 19 Aug 2022 3:00:00pm
    Author:  gkoca

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Sliders  : public juce::Component
{
public:
    Sliders();
    ~Sliders() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Sliders)

    juce::Slider rotary1;
    juce::Slider rotary2;
    juce::Slider rotary3;
    juce::Slider rotary4;

};
