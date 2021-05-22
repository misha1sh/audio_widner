#pragma once

#include "SyncedArray.h"

class ProcessingRendering {
public:
    SyncedArray<float> lastMask;
    SyncedArray<float> lastSound;

    ProcessingRendering() : lastMask(0.7f), lastSound(0.9f) {

    }
};
