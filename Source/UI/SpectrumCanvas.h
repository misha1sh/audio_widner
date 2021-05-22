#pragma once

#include <JuceHeader.h>

#include "../Processing/ProcessingRendering.h"
#include "../Processing/ProcessingParams.h"
class SpectrumCanvas : public juce::Component, private juce::Timer
{
public:
    SpectrumCanvas(ProcessingParams& _params, ProcessingRendering& _rendering);
    ~SpectrumCanvas() override;

    void timerCallback() override;
	
    void paint (juce::Graphics&) override;

private:
    ProcessingParams& params;
    ProcessingRendering& rendering;

    Path maskPath[2];
    Path soundPath;
    std::vector<float> mask;
    std::vector<float> sound;

    void createMaskPath();
    void createSoundPath();


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectrumCanvas)
};
