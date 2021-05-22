/*
  ==============================================================================

    SpectrumCanvas.cpp
    Created: 25 Apr 2021 7:37:03pm
    Author:  user

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SpectrumCanvas.h"



//==============================================================================
SpectrumCanvas::SpectrumCanvas(ProcessingParams& _params, ProcessingRendering& _rendering) :
    params(_params),
    rendering(_rendering)
{
    setOpaque(false);
    startTimerHz(24);
  //  renderer.reset(new DynamicTextureOpenGL::DynamicTextureRenderer(*this, 128, 128));
}

SpectrumCanvas::~SpectrumCanvas() {
    stopTimer();
}


void SpectrumCanvas::timerCallback() {
    createMaskPath();
    createSoundPath();
    getParentComponent()->repaint();
}



void SpectrumCanvas::paint (juce::Graphics& g) {
    g.fillAll(Colour::fromRGB(0, 0, 0));

    g.setColour(Colour::fromRGBA(255, 255, 255, 100));
    g.fillPath(soundPath);

    g.setColour(Colour::fromRGB(255, 0, 0));
    g.strokePath(maskPath[0],  juce::PathStrokeType (2.0) );

    g.setColour(Colour::fromRGB(0, 0, 255));
    g.strokePath(maskPath[1],  juce::PathStrokeType (2.0) );


}

void SpectrumCanvas::createMaskPath() {
    if (rendering.lastMask.size() != 0) {
        rendering.lastMask.getValues(mask);
    }

    if (mask.empty()) {
        return;
    }

    for (int maskSide = 0; maskSide < 2; maskSide++) {

        Path& path = maskPath[maskSide];
        path.clear();

        auto width = (float) getWidth();
        auto height = (float) getHeight();
        int realCnt = mask.size();
        int cnt = 20;
        float perSegment = width / (cnt - 1);

        float f = powf(realCnt, 1.f / cnt); //  j ** cnt = realCount111
        float j = 1;


        for (int i = 0; i < cnt; i++) {
            float x = i * perSegment;
            float y;
            if (maskSide == 0) {
                y = mask[j] / 2.f * height;
            } else {
                y = (2 - mask[j]) / 2.f * height;
            }
            if (i == 0) {
                path.startNewSubPath(x, y);
            } else {
                path.lineTo(x, y);
            }
            j *= f;
        }

        path = path.createPathWithRoundedCorners(20.f);
    }
}

void SpectrumCanvas::createSoundPath() {
    if (rendering.lastSound.size() != 0) {
        rendering.lastSound.getValues(sound);
    }

    if (sound.empty()) {
        return;
    }

    Path& path = soundPath;
    path.clear();

    auto width = (float) getWidth();
    auto height = (float) getHeight();
    int realCnt = mask.size();
    int cnt = 20;
    float perSegment = width / (cnt - 1);

    float f = powf(realCnt, 1.f / cnt); //  j ** cnt = realCount111
    float j = 1;

    path.startNewSubPath(-50, height + 50);
    for (int i = 0; i < cnt; i++) {
        float x = i * perSegment;
        float y = juce::Decibels::gainToDecibels(sound[j] / 150.f, -60.f) / -60.f * height
                /** log2f(i)*/;

      //  if (i == 0) {
            path.lineTo(x, y);
     /*   } else {
            float startX = 0, startY = 0, joinX = 0, joinY = 0, endX, endY;
        }*/
        j *= f;
    }
    path.lineTo(width + 50, height + 50);
    path.closeSubPath();

    path = path.createPathWithRoundedCorners(20.f);

}

