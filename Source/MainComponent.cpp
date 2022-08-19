#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

	setSize(800, 300);

	addAndMakeVisible(sliders);

}

MainComponent::~MainComponent()
{


}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	background = juce::ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
	g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);

	


}

void MainComponent::resized()
{
	juce::Rectangle<int> area = getLocalBounds();
	juce::Rectangle<int> sliderComponentArea = area.removeFromLeft(550);

	sliders.setBounds(sliderComponentArea);
}

