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

class rotaryLookAndFeel : public juce::LookAndFeel_V4
{
public:
    rotaryLookAndFeel ()
    {
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
        
    }
};


class Sliders : public juce::Component
{
public:
    Sliders();
    ~Sliders() override;
    
    void paint(juce::Graphics&) override;
    void resized() override;
    
    juce::Slider rotary1;
    juce::Slider rotary2;
    juce::Slider rotary3;
    juce::Slider rotary4;
    juce::Slider rotary5;
    juce::Slider rotary6;
    
    rotaryLookAndFeel rotaryLookAndFeel;
    
    juce::Label rotary1Label;
    juce::Label rotary2Label;
    juce::Label rotary3Label;
    juce::Rectangle<int> middleRect;
    
    juce::Label menuLabel { {}, "IR:" };
    juce::Font textFont   { 17.0f };
    juce::ComboBox styleMenu;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Sliders)
    
};
