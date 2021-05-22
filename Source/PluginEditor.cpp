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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...



//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (PluginProcessor& processor)
    : juce::AudioProcessorEditor(processor), audioProcessor(processor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    spectrum_canvas.reset (new SpectrumCanvas (processor.params, processor.rendering));
    addAndMakeVisible (spectrum_canvas.get());
    spectrum_canvas->setName ("spectrum_canvas");

    spectrum_canvas->setBounds (144, 32, 272, 192);

    leftCutoffSlider.reset (new juce::Slider ("leftCutoffSlider"));
    addAndMakeVisible (leftCutoffSlider.get());
    leftCutoffSlider->setTooltip (TRANS("Filter begining freq"));
    leftCutoffSlider->setRange (1, 15000, 0);
    leftCutoffSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    leftCutoffSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    leftCutoffSlider->setBounds (216, 232, 128, 88);

    rightCutoffSlider.reset (new juce::Slider ("rightCutoffSlider"));
    addAndMakeVisible (rightCutoffSlider.get());
    rightCutoffSlider->setTooltip (TRANS("Filter ending frequency"));
    rightCutoffSlider->setRange (1, 15000, 0);
    rightCutoffSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rightCutoffSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    rightCutoffSlider->setBounds (320, 232, 128, 88);

    strengthSlider.reset (new juce::Slider ("strengthSlider"));
    addAndMakeVisible (strengthSlider.get());
    strengthSlider->setTooltip (TRANS("Strength of stereo effect"));
    strengthSlider->setRange (0, 2, 0);
    strengthSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    strengthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    strengthSlider->setBounds (0, 8, 128, 88);

    frequencySpreadSlider.reset (new juce::Slider ("frequencySpreadSlider"));
    addAndMakeVisible (frequencySpreadSlider.get());
    frequencySpreadSlider->setTooltip (TRANS("How often frequency changes"));
    frequencySpreadSlider->setRange (0.1, 0.999, 0);
    frequencySpreadSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    frequencySpreadSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    frequencySpreadSlider->setBounds (0, 104, 128, 88);

    dynamicSplitEnabledButton.reset (new juce::ToggleButton ("dynamicSplitEnabledButton"));
    addAndMakeVisible (dynamicSplitEnabledButton.get());
    dynamicSplitEnabledButton->setTooltip (TRANS("Split into frequencies depending on audio volume"));
    dynamicSplitEnabledButton->setButtonText (TRANS("Dynamic split"));
    dynamicSplitEnabledButton->setToggleState (true, juce::dontSendNotification);

    dynamicSplitEnabledButton->setBounds (8, 216, 112, 24);

    attackSlider.reset (new juce::Slider ("attackSlider"));
    addAndMakeVisible (attackSlider.get());
    attackSlider->setTooltip (TRANS("How fast filter reacts to changes in sound"));
    attackSlider->setRange (0, 1, 0);
    attackSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    attackSlider->setBounds (0, 232, 128, 88);

    juce__label.reset (new juce::Label ("Left cutoff",
                                        TRANS("Left cutoff")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centred);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (208, 312, 144, 24);

    juce__label2.reset (new juce::Label ("Right cutoff",
                                         TRANS("Right cutoff")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centred);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (312, 312, 150, 24);

    juce__label3.reset (new juce::Label ("Strength",
                                         TRANS("Strength")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centred);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (0, 80, 128, 32);

    juce__label4.reset (new juce::Label ("Frequency spread",
                                         TRANS("Frequency spread")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centred);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (-8, 184, 152, 24);

    juce__label5.reset (new juce::Label ("Attack",
                                         TRANS("Attack")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centred);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (16, 312, 96, 24);

    noiseSlider.reset (new juce::Slider ("noiseSlider"));
    addAndMakeVisible (noiseSlider.get());
    noiseSlider->setTooltip (TRANS("Adds random noise to filter"));
    noiseSlider->setRange (0, 1, 0);
    noiseSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    noiseSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    noiseSlider->setBounds (112, 232, 128, 88);

    juce__label6.reset (new juce::Label ("Noise",
                                         TRANS("Noise")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centred);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (128, 312, 96, 24);

    bypassButton.reset (new juce::ToggleButton ("bypassButton"));
    addAndMakeVisible (bypassButton.get());
    bypassButton->setTooltip (TRANS("Temporary disables audioplugin"));
    bypassButton->setButtonText (TRANS("bypass"));
    bypassButton->addListener (this);

    bypassButton->setBounds (376, 0, 64, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (444, 348);


    //[Constructor] You can add your own custom stuff here..
    tooltipWindow.reset(new TooltipWindow(this, 700));
  /*  setResizable(true, true);
    setResizeLimits(100, 100, 1000, 1000);
    */
    setResizable(false, false);


    leftCutoffAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "leftCutoff", *leftCutoffSlider);
    rightCutoffAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "rightCutoff", *rightCutoffSlider);
    strengthAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "strength", *strengthSlider);
    frequencySpreadAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "frequencySpread", *frequencySpreadSlider);
    attackAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "attack", *attackSlider);
    noiseAttachment = std::make_unique<SliderAttachment>(*audioProcessor.params.tree, "noise", *noiseSlider);
    dynamicSplitEnabledAttachment = std::make_unique<ButtonAttachment>(*audioProcessor.params.tree, "dynamicSplitEnabled", *dynamicSplitEnabledButton);
    bypassEnabledAttachment = std::make_unique<ButtonAttachment>(*audioProcessor.params.tree, "bypassEnabled", *bypassButton);

    leftCutoffSlider->setSkewFactorFromMidPoint(1024);
    rightCutoffSlider->setSkewFactorFromMidPoint(1024);

    audioProcessor.params.tree->addParameterListener("dynamicSplitEnabled", this);

    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    tooltipWindow = nullptr;

    leftCutoffAttachment = nullptr;
    rightCutoffAttachment = nullptr;
    strengthAttachment = nullptr;
    frequencySpreadAttachment = nullptr;
    attackAttachment = nullptr;
    noiseAttachment = nullptr;
    dynamicSplitEnabledAttachment = nullptr;
    bypassEnabledAttachment = nullptr;
    audioProcessor.params.tree->removeParameterListener("dynamicSplitEnabled", this);

    //[/Destructor_pre]

    spectrum_canvas = nullptr;
    leftCutoffSlider = nullptr;
    rightCutoffSlider = nullptr;
    strengthSlider = nullptr;
    frequencySpreadSlider = nullptr;
    dynamicSplitEnabledButton = nullptr;
    attackSlider = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;
    noiseSlider = nullptr;
    juce__label6 = nullptr;
    bypassButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 0, y = -1, width = 452, height = 348;
        juce::Colour fillColour = juce::Colour (0x21ffffff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton.get())
    {
        //[UserButtonCode_bypassButton] -- add your button handler code here..
        //[/UserButtonCode_bypassButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginEditor::parameterChanged (const String& parameterID, float newValue) {
    if (parameterID == "dynamicSplitEnabled") {
        attackSlider->setEnabled(newValue > 0.5f);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public juce::AudioProcessorEditor, public juce::AudioProcessorValueTreeState::Listener"
                 constructorParams="PluginProcessor&amp; processor" variableInitialisers="juce::AudioProcessorEditor(processor), audioProcessor(processor)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="444" initialHeight="348">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 -1 452 348" fill="solid: 21ffffff" hasStroke="0"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="spectrum_canvas" id="c28ba59d3075a746" memberName="spectrum_canvas"
                    virtualName="" explicitFocusOrder="0" pos="144 32 272 192" class="SpectrumCanvas"
                    params="processor.params, processor.rendering"/>
  <SLIDER name="leftCutoffSlider" id="110eb12e1151856" memberName="leftCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="216 232 128 88" tooltip="Filter begining freq"
          min="1.0" max="15000.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="rightCutoffSlider" id="f5f11eb2404957fc" memberName="rightCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="320 232 128 88" tooltip="Filter ending frequency"
          min="1.0" max="15000.0" int="0.0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="strengthSlider" id="f56ba4a089565a1e" memberName="strengthSlider"
          virtualName="" explicitFocusOrder="0" pos="0 8 128 88" tooltip="Strength of stereo effect"
          min="0.0" max="2.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="frequencySpreadSlider" id="ab103c844f994ea3" memberName="frequencySpreadSlider"
          virtualName="" explicitFocusOrder="0" pos="0 104 128 88" tooltip="How often frequency changes"
          min="0.1" max="0.999" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="dynamicSplitEnabledButton" id="1d2e5d0b4ed829bd" memberName="dynamicSplitEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="8 216 112 24" tooltip="Split into frequencies depending on audio volume"
                buttonText="Dynamic split" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <SLIDER name="attackSlider" id="8781b1d7d0cf8163" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="0 232 128 88" tooltip="How fast filter reacts to changes in sound"
          min="0.0" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="Left cutoff" id="8620c0632c450024" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="208 312 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Left cutoff" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Right cutoff" id="40b2fd643a5430b4" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="312 312 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Right cutoff" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Strength" id="f0af7ab8cc3ea80f" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="0 80 128 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Strength" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Frequency spread" id="692de3b7b1d976e" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="-8 184 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency spread" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Attack" id="2459ebcb1b75d0a3" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="16 312 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="noiseSlider" id="cdc302d03b5071d1" memberName="noiseSlider"
          virtualName="" explicitFocusOrder="0" pos="112 232 128 88" tooltip="Adds random noise to filter"
          min="0.0" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="Noise" id="8052689b5ca1ad00" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="128 312 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Noise" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="bypassButton" id="d736abf09da68e44" memberName="bypassButton"
                virtualName="" explicitFocusOrder="0" pos="376 0 64 16" tooltip="Temporary disables audioplugin"
                buttonText="bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

