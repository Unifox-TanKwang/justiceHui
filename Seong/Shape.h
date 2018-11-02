/*
  ==============================================================================

    Shape.h
    Created: 31 Oct 2018 3:37:03pm
    Author:  jhnah
   ==============================================================================
*/

#pragma once
#include <algorithm>
#include "../JuceLibraryCode/JuceHeader.h"

class Shape : public Component {
public:
	static void drawCircle(Graphics& g, float midX, float midY, float r, Colour c) {
		g.setColour(c);
		for (int x = -r; x <= r; x++) {
			for (int y = -r; y <= r; y++) {
				if (x*x + y * y <= r * r) {
					g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
				}
			}
		}
	}

	static void drawRectangle(Graphics& g, float midX, float midY, float x1, float x2, float y1, float y2, Colour c) {
		g.setColour(c);
		for (float x = std::min(x1, x2); x <= std::max(x1, x2); x++) {
			for (float y = std::min(y1, y2); y <= std::max(y1, y2); y++) {
				g.fillRect(x + midX, y + midY, 5.0f, 5.0f);
			}
		}
	}

	static void drawDiagonal(Graphics& g, float midX, float midY, float x1, float x2, float p, Colour c) {
		g.setColour(c);
		for (float x = std::min(x1, x2); x <= std::max(x1, x2); x++) {
			g.fillRect(x + midX, p + x + midY, 10.0f, 10.0f);
			g.fillRect(-x - 2 + midX, p - 2 + x + midY, 10.0f, 10.0f);

		}
	}
};