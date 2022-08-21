/*
  ==============================================================================

	Sliders.cpp
	Created: 19 Aug 2022 3:00:00pm
	Author:  gkoca

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Sliders.h"

//==============================================================================
Sliders::Sliders()
{
    
    
    rotary1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary3.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary4.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary5.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary6.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	rotary1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 40, 20);
	rotary2.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary3.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary4.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary5.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary6.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
    
    rotary1.setRange(0.0, 200.0, 1);
    rotary1.setValue(100);
    rotary1.setTextValueSuffix("%");
    rotary1Label.setText("Decay", juce::dontSendNotification);
    rotary1Label.attachToComponent(&rotary1, false);
    rotary1Label.setJustificationType (juce::Justification::centred);
    rotary1Label.setColour(juce::Label::textColourId, juce::Colour(0xffAE9D7A));
    
    
    getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff4AABE1)); // Blue Jeans
    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(0xffAE9D7A)); // Grullo
    getLookAndFeel().setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(0xffb76a5e)); // Copper 
    getLookAndFeel().setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(23.f, 115.f, 57.f, 0.f)); // bunu transparent yapmaya calısıyorum ama olmuyor
    

	addAndMakeVisible(rotary1);
	addAndMakeVisible(rotary2);
	addAndMakeVisible(rotary3);
	addAndMakeVisible(rotary4);
	addAndMakeVisible(rotary5);
	addAndMakeVisible(rotary6);
    addAndMakeVisible(rotary1Label);
}

Sliders::~Sliders()
{
}

void Sliders::paint(juce::Graphics& g)
{

}

void Sliders::resized()
{
	const int sliderBorder = 20;
	juce::Rectangle<int> SlidersArea = getLocalBounds().reduced(sliderBorder);
    juce::Rectangle<int> upperRow = SlidersArea.removeFromTop(SlidersArea.getHeight() / 2);

	rotary1.setBounds(upperRow.removeFromLeft(upperRow.getWidth() / 3));
    rotary1Label.setBounds(rotary1.getX(), rotary1.getY() - 14, rotary1.getWidth(), 20 );
	rotary2.setBounds(upperRow.removeFromLeft(upperRow.getWidth() / 2));
	rotary3.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 3));
	rotary4.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 2));
	rotary5.setBounds(upperRow);
	rotary6.setBounds(SlidersArea);
    
  
    
    
    
}
