#pragma once

#include "kfr/all.hpp"

class DataAccumulator {
public:
    DataAccumulator();
    void addDataSamples(const kfr::univector_ref<kfr::f32>& data) ;

    void reset(int maxSamplesPerBlock, int maxRequestLength);

    // returns [pos-left, pos+right]
    // left samples will be dropped
    kfr::univector_ref<kfr::f32> getData(int left, int right);

    int size() { return buffer_size; }

private:
    kfr::univector<kfr::f32> buffer;
    int buffer_pos, buffer_size;
};
