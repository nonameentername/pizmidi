#pragma once


#include "Module.h"
#include "JuceHeader.h"

class MidiMorph;
class ControllerValue;
class Controller;
namespace juce { class MidiBuffer; } 
class Cursor;

class Scene : public Module,
              public Component,
              public ChangeListener,
              public SliderListener,
              public TextEditorListener
{
  public:
    Scene(const Scene & scene);

    Scene(MidiMorph * core);

     ~Scene();

    void sliderValueChanged (Slider* sliderThatWasMoved);
    void textEditorTextChanged(TextEditor&);
    void textEditorReturnKeyPressed(TextEditor&);
    void textEditorEscapeKeyPressed(TextEditor&);
    void textEditorFocusLost(TextEditor&);
    void changeListenerCallback (void* source);

  private:
    //stored for performance reason
    float distanceFromCursor;

    float affectionRatio;

    float affectionValue;

    bool distanceFromCursorChanged_;

    bool affectionRatioChanged;

    bool affectionValueChanged;


    MidiMorph* core;
    
    TextEditor* textEditor;
    ColourSelector* colourSelector;
    Slider* sizeSlider;

  public:
    Array<ControllerValue*> controllerValues;
    float getAffectionRatio();

    //get Precalculated Value
    float getDistanceFromCursor();

    int getValue(const Controller* controller);

    //gets called when the XYItem gets new coordinates
    //in this implementation refresh the distance value
    virtual void moved();

    juce::Colour getColour();

    void setColour(const juce::Colour & colour);

    String getName();

    void setName(String newName);

    void addValue( ControllerValue * value);

    float getAffectionValue();

    void distanceFromCursorChanged();

    void mouseDown(const MouseEvent & e);

    void mouseUp(const MouseEvent & e);

    void getMidiMessages(juce::MidiBuffer & buffer, int pos);

    void mouseDrag(const MouseEvent & e);

    int getId();

  friend class ControllerValue;
    int id;

};

