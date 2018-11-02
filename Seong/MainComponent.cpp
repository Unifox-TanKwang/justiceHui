/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "MaleComponent.h"
#include "FemaleComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
	midX = getWidth() / 2;
	midY = getHeight() / 2;
	maleX = midX - 70;
	maleY = midY + 20;
	femaleX = midX + 70;
	femaleY = midY - 20;
	r = 50;
	male.set( maleX, maleY, r );
	female.set(femaleX, femaleY, r);
	addAndMakeVisible(male);
	addAndMakeVisible(female);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    /*g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);*/

	Colour originalColor(50, 62, 68);

	/*midX -= 70.0f; midY += 20.0f;
	Shape::drawCircle(g, midX, midY, r, Colours::blue);
	Shape::drawRectangle(g, midX, midY, -5.0f, 5.0f, -50.0f, -150.0f, Colours::blue);
	Shape::drawDiagonal(g, midX, midY, 0.0f, r, -150.0f, Colours::blue);
	Shape::drawCircle(g, midX, midY, r - 20, originalColor);*/ 
	//male.paint(g);

	/*midX += 140.0f; midY -= 40.0f;
	Shape::drawCircle(g, midX, midY, r, Colours::pink);
	Shape::drawRectangle(g, midX, midY, -5.0f, 5.0f, 50.0f, 150.0f, Colours::pink);
	Shape::drawRectangle(g, midX, midY, -r, r, 95.0f, 105.0f, Colours::pink);
	Shape::drawCircle(g, midX, midY, r - 20, originalColor);*/
	//female.paint(g);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	male.setBounds(getLocalBounds());
	female.setBounds(getLocalBounds());
}
