#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    setSize(600, 300);
    
    addAndMakeVisible(sliders);
    
}

MainComponent::~MainComponent()
{
    
    
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    
    g.fillAll(juce::Colours::lightgrey);
    
    
    if (sliders.rotary1.getValue() == 31) {
        tby = juce::ImageCache::getFromMemory(BinaryData::tby_png, BinaryData::tby_pngSize);
        g.drawImageWithin(tby, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);
        
    }
    else {
        background = juce::ImageCache::getFromMemory(BinaryData::bg_png, BinaryData::bg_pngSize);
        g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::doNotResize);
    }
    
    
    
    
}

void MainComponent::resized()
{
    juce::Rectangle<int> area = getLocalBounds();
    
    
    sliders.setBounds(area);
    
}

