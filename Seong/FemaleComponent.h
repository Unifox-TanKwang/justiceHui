/*
  ==============================================================================

    FemaleComponent.h
    Created: 31 Oct 2018 4:59:13pm
    Author:  jhnah

  ==============================================================================
*/

#pragma once
#include "Shape.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FemaleComponent    : public Component
{
public:
	FemaleComponent() {
		midX = midY = r = 0;
	}

	FemaleComponent(float _midX, float _midY, float _r) : midX(_midX), midY(_midY), r(_r) {}

	~FemaleComponent()
	{
	}

	void set(float _midX, float _midY, float _r) {
		midX = _midX, midY = _midY, r = _r;
	}

    void paint (Graphics& g) override
    {
		Colour originalColor(50, 62, 68);
		Shape::drawCircle(g, midX, midY, r, Colours::pink);
		Shape::drawRectangle(g, midX, midY, -5.0f, 5.0f, r, r+100, Colours::pink);
		Shape::drawRectangle(g, midX, midY, -r, r, 95.0f, 105.0f, Colours::pink);
		Shape::drawCircle(g, midX, midY, r - 20, originalColor);
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FemaleComponent)
		float midX, midY, r;
};
