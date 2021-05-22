#include "DataAccumulator.h"
#include "JuceHeader.h"

DataAccumulator::DataAccumulator(): buffer_pos(0), buffer_size(-1), buffer(0) {
}

void DataAccumulator::reset(int maxSamplesPerBlock, int maxRequestLength) {
    buffer_pos = 0;
    buffer_size = 0;
    buffer.resize(std::max(maxSamplesPerBlock *8, maxRequestLength * 8));
}

void DataAccumulator::addDataSamples(const kfr::univector_ref<kfr::f32> &data) {
    jassert(buffer.size() != 0); // not init

    if (buffer_pos + buffer_size + data.size() >= buffer.size()) {
        builtin_memcpy(&buffer[0], &buffer[buffer_pos], buffer_size * sizeof(kfr::f32));
        buffer_pos = 0;
    }
    jassert(buffer_pos + buffer_size + data.size() < buffer.size());
    builtin_memcpy(&buffer[buffer_pos + buffer_size], &data[0], data.size() * sizeof(kfr::f32));
    buffer_size += data.size();
}

kfr::univector_ref<kfr::f32> DataAccumulator::getData(int left, int right) {
    jassert(left + right <= buffer_size);
    kfr::univector_ref<kfr::f32> res(buffer.slice(buffer_pos, left + right));
    buffer_pos += left;
    buffer_size -= left;
    return res;
}


