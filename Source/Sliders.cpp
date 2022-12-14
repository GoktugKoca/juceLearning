/*
 ==============================================================================
 
 Sliders.cpp
 Created: 19 Aug 2022 3:00:00pm
 Author:  gkoca
 
 Genel olarak dizayn Ableton'ın Convolution Reverb'ünden esinlenerek, Cocteau Twins eşliğinde yapıldı.
 
 ==============================================================================
 */

#include <JuceHeader.h>
#include "Sliders.h"

//==============================================================================

// from https://forum.juce.com/t/best-way-of-rotating-components/17750/4 :
//static void setVerticalRotatedWithBounds (juce::Component& component, bool clockWiseRotation, juce::Rectangle<int> verticalBounds)
//{
//    auto angle = juce::MathConstants<float>::pi / 2.0f;
//
//    if (! clockWiseRotation)
//        angle *= -1.0f;
//
//    component.setTransform ({});
//    component.setSize (verticalBounds.getHeight(), verticalBounds.getWidth());
//    component.setCentrePosition (0, 0);
//    component.setTransform (juce::AffineTransform::rotation (angle).translated (verticalBounds.getCentreX(), verticalBounds.getCentreY()));
//}



Sliders::Sliders()
{
//    getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff4AABE1)); // Blue Jeans
//    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(0xffAE9D7A)); // Grullo
//    getLookAndFeel().setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(0xffb76a5e)); // Copper
//    getLookAndFeel().setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(23.f, 115.f, 57.f, 0.f)); // bunu transparent yapmaya calısıyorum ama olmuyor
//    getLookAndFeel().setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xffAE9D7A));
    getLookAndFeel().setColour(juce::ComboBox::backgroundColourId, juce::Colours::transparentWhite);
    
    
    rotary1.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag); // vertical? horizontal? ya da her ikisi birden mi?
    rotary2.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag); // e.g., ableton vertical kullanıyor
    rotary3.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    rotary4.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    rotary5.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    rotary6.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    rotary1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    rotary2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    rotary3.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    rotary4.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    rotary5.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    rotary6.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 10);
    
    rotary1.setRange(0.0, 200.0, 1);
    rotary1.setValue(100);
    rotary1.setTextValueSuffix(" %");
    //    rotary1.setPopupDisplayEnabled(true, true, &rotary1Label);
    rotary1.setPopupMenuEnabled(true);
    rotary1Label.setText("Decay", juce::dontSendNotification);
    rotary1Label.setFont(labelFont);
    rotary1Label.setJustificationType (juce::Justification::centred);
    rotary1Label.setColour(juce::Label::textColourId, juce::Colour(0xffAE9D7A));
   
    rotary1.setLookAndFeel(&lfM);
    rotary2.setLookAndFeel(&lfM);
    rotary3.setLookAndFeel(&lfM);
    rotary4.setLookAndFeel(&lfM);
    rotary5.setLookAndFeel(&lfM);
    rotary6.setLookAndFeel(&lfM);
    
    rotary2.setRange(0.0, 200.0, 1);
    rotary2.setValue(100);
    rotary2.setTextValueSuffix(" %");
    rotary2.setPopupMenuEnabled(true);
        rotary2Label.setText("Size", juce::dontSendNotification);
        rotary2Label.setFont(labelFont);
        rotary2Label.setJustificationType(juce::Justification::centred);
        rotary2Label.setColour(juce::Label::textColourId, juce::Colour(0xffAE9D7A));
    
    rotary3.setRange(0.00f, 1000.f, 0.01f);
    rotary3.setValue(0.00f);
    rotary3.setTextValueSuffix(" ms");
    
    rotary4.setRange(0, 100, 1);
    rotary4.setValue(100);
    rotary4.setTextValueSuffix(" %");
    
    rotary5.setRange(-10.0f, 10.0f, 0.1f);
    rotary5.setValue(0.0f);
    rotary5.setTextValueSuffix(" dB");
    
    rotary6.setRange(0.0f, 100.0f, 0.1f);
    rotary6.setValue(50.0f);
    rotary6.setTextValueSuffix(" %");
    
    
    addAndMakeVisible(rotary1);
    addAndMakeVisible(rotary2);
    addAndMakeVisible(rotary3);
    addAndMakeVisible(rotary4);
    addAndMakeVisible(rotary5);
    addAndMakeVisible(rotary6);
    
    addAndMakeVisible(menuLabel);
    menuLabel.setFont(textFont);
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("ALH 1",  1);
    styleMenu.addItem ("ALH 2",   2);
    styleMenu.addItem ("Tasoda", 3);
    styleMenu.setSelectedId (1);
    
    menuLabel.attachToComponent(&styleMenu, true);
    
   addAndMakeVisible(rotary1Label);
    addAndMakeVisible(rotary2Label);
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
    /*
     juce::Rectangle<int> SlidersArea = getLocalBounds().reduced(sliderBorder);
     juce::Rectangle<int> upperRow = SlidersArea.removeFromTop(SlidersArea.getHeight() / 2);
     
     rotary1.setBounds(upperRow.removeFromLeft(upperRow.getWidth() / 3));
     rotary1Label.setBounds(rotary1.getX(), rotary1.getY() - 14, rotary1.getWidth(), 20 );
     rotary2.setBounds(upperRow.removeFromLeft(upperRow.getWidth() / 2));
     rotary3.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 3));
     rotary4.setBounds(SlidersArea.removeFromLeft(SlidersArea.getWidth() / 2));
     rotary5.setBounds(upperRow);
     rotary6.setBounds(SlidersArea);
     */
    
    juce::Rectangle<int> SlidersArea = getLocalBounds().reduced(sliderBorder);
    juce::Rectangle<int> SlidersArea2 = getLocalBounds().reduced(sliderBorder);
    juce::Rectangle<int> leftSlidersArea = SlidersArea.removeFromLeft(SlidersArea.getWidth()/3-120);
    juce::Rectangle<int> rightSlidersArea = SlidersArea2.removeFromRight(SlidersArea2.getWidth()/3-120);
    // juce::Rectangle<int> middleArea = getLocalBounds().reduced(rotary1.getX() + rotary1.getWidth(), sliderBorder);
    
    
    // rotary2Label.setBounds(rotary2.getX(), rotary2.getY() + 20	, rotary2.getWidth(), 10);
    
    rotary1.setBounds(leftSlidersArea.removeFromTop(leftSlidersArea.getHeight()/3));
    rotary2.setBounds(leftSlidersArea.removeFromTop(leftSlidersArea.getHeight()/2));
    rotary3.setBounds(leftSlidersArea);
    rotary4.setBounds(rightSlidersArea.removeFromTop(rightSlidersArea.getHeight()/3));
    rotary5.setBounds(rightSlidersArea.removeFromTop(rightSlidersArea.getHeight()/2));
    rotary6.setBounds(rightSlidersArea);
    
    rotary1Label.setBounds(rotary1.getX(), rotary1.getY() - 10, rotary1.getWidth(), 10);
    rotary2Label.setBounds(rotary2.getX(), rotary2.getY() - 10, rotary2.getWidth(), 10);
    
    styleMenu.setBounds(150,240,320,22);
}
