#pragma once

#include "kfr/all.hpp"

#include "ProcessingParams.h"
#include "DataAccumulator.h"
#include "ProcessingRendering.h"
#include "NoiseGenerator.h"

#define FFT_SZ 2048
#define FFT_RES_SZ (FFT_SZ / 2 + 1)
#define OVERLAP_COUNT (FFT_SZ / 2)

class MainProcessor {
public:
    explicit MainProcessor(ProcessingParams& params, ProcessingRendering& _rendering);

    void reset();

    void process(kfr::univector<kfr::univector<kfr::f32, 0>, 2> data);
    int getLatencyInSamples();

private:
    ProcessingParams& params;
    ProcessingRendering& rendering;
    DataAccumulator inAccumulators[2];
    DataAccumulator inSumAccumulator;
    DataAccumulator fftOutAccumulators[2];
    DataAccumulator outAccumulators[2];


    kfr::dft_plan_real<kfr::f32> dftPlan;
    kfr::univector<kfr::u8> dftPlanTemp;
    kfr::univector<kfr::f32> dftWindow;

    NoiseGenerator<float, 2048> noiseGenerator;

    typedef kfr::univector<kfr::complex<kfr::f32>, FFT_RES_SZ> vecfft;
    typedef kfr::univector<kfr::complex<kfr::f32>, 0> vecfft_ref;
    void processFFTForAccumulator(DataAccumulator& inAccumulator, DataAccumulator& outAccumulator1,
                                  DataAccumulator& outAccumulator2);
    void performIFFTAndWrite(vecfft& in, DataAccumulator& outAccumulator);
    void applyConversionsToFFT(vecfft& fftData,
                               vecfft& res1,
                               vecfft& res2);
    void processSplit(vecfft& data, vecfft& res1, vecfft& res2);
    void generateMask(vecfft& data,
                      kfr::univector<kfr::f32, 0> mask);
    int freqToFFTIndex(int frequency) const;
    int FFTIndexToFreq(int index) const;

};
