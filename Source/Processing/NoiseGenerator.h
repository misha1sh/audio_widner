#pragma once

template<typename T, int size>
class NoiseGenerator {
public:
    NoiseGenerator() : gen(1), distribution(-1, 1) {
        std::fill(values.begin(), values.end(), 0);
    }

    void nextGenerate(float deltaX, float deltaY) {
        float randomWeight = 1 - deltaY - deltaX;
        tmpValues[0] = values[0] * deltaY + distribution(gen) * (1 - deltaY);
        tmpValues[size-1] = values[size-1] * deltaY + distribution(gen) * (1 - deltaY);

        deltaX /= 2;
        float minValue=1, maxValue = -1.f;
        for (int i = 1; i < size - 1; i++) {
            tmpValues[i] = values[i - 1] * deltaX + values[i + 1] * deltaX
                    + values[i] * deltaY +
                    randomWeight * distribution(gen);
            if (tmpValues[i] > 1) {
                tmpValues[i] = 1;
            }
            if (tmpValues[i] < -1) {
                tmpValues[i] = -1;
            }
            minValue = std::fmin(tmpValues[i], minValue);
            maxValue = std::fmax(tmpValues[i], maxValue);
        }

        for (int i = 0; i < size; i++) {
            values[i] = (tmpValues[i] - minValue) / (maxValue - minValue) * 2 - 1;
        }

       /* for (int i = 1; i < size; i++) {
            values[i] = tmpValues[i - 1]  + tmpValues[i] * deltaX;
        }*/
    }


    inline T getValue(const size_t& x) {
        return values[x];
    }

private:
    std::mt19937 gen;
    std::uniform_real_distribution<T> distribution;
    std::array<T, size> values, tmpValues;
};