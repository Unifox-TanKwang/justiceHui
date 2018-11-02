/*
  ==============================================================================

    MaleComponent.h
    Created: 31 Oct 2018 3:33:48pm
    Author:  jhnah

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Shape.h"

//==============================================================================
/*
*/
class MaleComponent    : public Component
{
public:
    MaleComponent(){
		midX = midY = r = 0;
    }

	MaleComponent(float _midX, float _midY, float _r) : midX(_midX), midY(_midY), r(_r) {}

    ~MaleComponent()
    {
    }

	void set(float _midX, float _midY, float _r) {
		midX = _midX, midY = _midY, r = _r;
	}

    void paint (Graphics& g) override{
		Colour originalColor(50, 62, 68);
		Shape::drawCircle(g, midX, midY, r, Colours::blue);
		Shape::drawRectangle(g, midX, midY, -5.0f, 5.0f, -r, -(r+100), Colours::blue);
		Shape::drawDiagonal(g, midX, midY, 0.0f, r, -150.0f, Colours::blue);
		Shape::drawCircle(g, midX, midY, r - 20, originalColor);
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MaleComponent)
		float midX, midY, r;
	
};
