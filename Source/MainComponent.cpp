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


}

void MainComponent::resized()
{
	juce::Rectangle<int> area = getLocalBounds();
	juce::Rectangle<int> sliderComponentArea = area.removeFromLeft(400);

	sliders.setBounds(sliderComponentArea);
}

