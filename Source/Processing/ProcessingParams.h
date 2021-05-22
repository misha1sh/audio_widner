#pragma once

#include <JuceHeader.h>

class ProcessingParams {
public:
    ProcessingParams(AudioProcessor& processor);


    std::unique_ptr<juce::AudioProcessorValueTreeState> tree;

    std::atomic<float>* leftCutoff;
    std::atomic<float>* rightCutoff;
    std::atomic<float>* strength;
    std::atomic<float>* frequencySpread;
    std::atomic<float>* attack;
    std::atomic<float>* noise;
    std::atomic<float>* dynamicSplitEnabled, * bypassEnabled;


    float sampleRate;
    int maxSamplesPerBlock;

};

