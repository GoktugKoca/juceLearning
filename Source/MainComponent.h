#pragma once

#include <JuceHeader.h>
#include "Sliders.h"





class MainComponent : public juce::Component
{
public:
	//==============================================================================
	MainComponent();
	~MainComponent() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	//==============================================================================
	// Your private member variables go here...

	Sliders sliders;
	juce::Image background;
    juce::Image tby;
    
    


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
