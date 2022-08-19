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
	rotary1.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary2.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary3.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary4.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary5.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);
	rotary6.setTextBoxStyle(juce::Slider::NoTextBox, false, 40, 20);


	addAndMakeVisible(rotary1);
	addAndMakeVisible(rotary2);
	addAndMakeVisible(rotary3);
	addAndMakeVisible(rotary4);
	addAndMakeVisible(rotary5);
	addAndMakeVisible(rotary6);
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
	rotary2.setBounds(upperRow.removeFromLeft(upperRow.getWidth() / 2));
	rotary3.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 3));
	rotary4.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 2));
	rotary5.setBounds(upperRow);
	rotary6.setBounds(SlidersArea);
}
