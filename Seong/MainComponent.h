/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once
#include <algorithm>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Shape.h"
#include "MaleComponent.h"
#include "FemaleComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
	

	
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
	float maleX, maleY, femaleX, femaleY;
	float midX, midY, r;
	MaleComponent male;
	FemaleComponent female;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
