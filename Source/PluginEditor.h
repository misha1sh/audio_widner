/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>


#include "UI/SpectrumCanvas.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public juce::AudioProcessorEditor,
                      public juce::AudioProcessorValueTreeState::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    PluginEditor (PluginProcessor& processor);
    ~PluginEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void parameterChanged (const String& parameterID, float newValue) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PluginProcessor& audioProcessor;

    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

        std::unique_ptr<SliderAttachment> leftCutoffAttachment, rightCutoffAttachment,
            strengthAttachment, frequencySpreadAttachment, attackAttachment, noiseAttachment;
    std::unique_ptr<ButtonAttachment> dynamicSplitEnabledAttachment, bypassEnabledAttachment;
    std::unique_ptr<TooltipWindow> tooltipWindow;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<SpectrumCanvas> spectrum_canvas;
    std::unique_ptr<juce::Slider> leftCutoffSlider;
    std::unique_ptr<juce::Slider> rightCutoffSlider;
    std::unique_ptr<juce::Slider> strengthSlider;
    std::unique_ptr<juce::Slider> frequencySpreadSlider;
    std::unique_ptr<juce::ToggleButton> dynamicSplitEnabledButton;
    std::unique_ptr<juce::Slider> attackSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Slider> noiseSlider;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::ToggleButton> bypassButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

