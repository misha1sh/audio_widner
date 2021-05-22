#pragma once

#include "JuceHeader.h"

template<typename T>
class SyncedArray {
public:
    explicit SyncedArray(float _smoothFactor) :
            valuesLock(),
            values(),
            smoothFactor(_smoothFactor) {

        jassert(0.f <= smoothFactor && smoothFactor < 1);
    }

    void addValues(T* newValues, int valuesCount) {
        juce::CriticalSection::ScopedLockType locker(valuesLock);

        if (values.size() == valuesCount && smoothFactor != 0)  {
            float otherSmoothFactor = 1 - smoothFactor;
            for (int i = 0; i < valuesCount; i++) {
                values[i] = smoothFactor * values[i] + otherSmoothFactor * newValues[i];
            }
        } else {
            values.assign(newValues, newValues + valuesCount);
        }
    }

    void getValues(std::vector<T>& array) {
        juce::CriticalSection::ScopedLockType locker(valuesLock);

        array.assign(values.begin(), values.end());
    }

    void reset() {
        juce::CriticalSection::ScopedLockType locker(valuesLock);

        values.resize(0);
    }

    size_t size() {
        juce::CriticalSection::ScopedLockType locker(valuesLock);
        return values.size();
    }

private:
    juce::CriticalSection valuesLock;
    std::vector<T> values;
    float smoothFactor;
};
