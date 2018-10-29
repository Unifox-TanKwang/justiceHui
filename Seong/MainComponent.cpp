/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
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

	float midX = getWidth() / 2, midY = getHeight() / 2;
	float r = 50.0f;
	Colour originalColor(50, 62, 68);

	midX -= 70.0f; midY += 20.0f;
	drawCircle(g, midX, midY, r, Colours::blue);
	drawRectangle(g, midX, midY, -5.0f, 5.0f, -50.0f, -150.0f, Colours::blue);
	drawDiagonal(g, midX, midY, 0.0f, r, -150.0f, Colours::blue);
	drawCircle(g, midX, midY, r - 20, originalColor);

	midX += 140.0f; midY -= 40.0f;
	drawCircle(g, midX, midY, r, Colours::pink);
	drawRectangle(g, midX, midY, -5.0f, 5.0f, 50.0f, 150.0f, Colours::pink);
	drawRectangle(g, midX, midY, -r, r, 95.0f, 105.0f, Colours::pink);
	drawCircle(g, midX, midY, r - 20, originalColor);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
