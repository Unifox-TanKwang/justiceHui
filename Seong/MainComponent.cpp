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
	g.setColour(Colours::blue);
	midX -= 70.0f; midY += 20.0f;
	for (float x = -r; x <= r; x+=0.1f) {
		for (float y = -r; y <= r; y+=0.1f) {
			if ((x*x + y * y) <= (r * r)) {
				g.fillRect(x+midX, y+midY, 5.0f, 5.0f);
			}
		}
	}


	for (float x = -5.0f; x <= 5.0f; x++) {
		for (float y = -50.0f; y >= -150.f; y--) {
			g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
		}
	}

	for (float x = 0.0f; x <= r; x++) {
		g.fillRect(x + midX, -150.0f + x + midY, 10.0f, 10.0f);
		g.fillRect(-x - 2 + midX, -152.0f + x + midY, 10.0f, 10.0f);
	}

	g.setColour(originalColor);
	for (float x = -r + 20; x <= r - 20; x += 0.1f) {
		for (float y = -r + 20; y <= r - 20; y += 0.1f) {
			if ((x*x + y * y) <= (r - 20)*(r - 20)) {
				g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
			}
		}
	}

	midX += 140.0f; midY -= 40.0f;
	g.setColour(Colours::pink);
	for (float x = -r; x <= r; x += 0.1f) {
		for (float y = -r; y <= r; y += 0.1f) {
			if ((x*x + y * y) <= (r * r)) {
				g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
			}
		}
	}
	for (float x = -5.0f; x <= 5.0f; x++) {
		for (float y = 50.0f; y <= 150.f; y++) {
			g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
		}
	}

	for (float x = -r; x <= r; x++) {
		for (float y = 95.0f; y <= 105.0f; y++) {
			g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
		}
	}

	g.setColour(originalColor);
	for (float x = -r + 20; x <= r - 20; x += 0.1f) {
		for (float y = -r + 20; y <= r - 20; y += 0.1f) {
			if ((x*x + y * y) <= (r - 20)*(r - 20)) {
				g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
			}
		}
	}
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
