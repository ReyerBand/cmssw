#include "DataFormats/EcalDigi/interface/EcalTimeDigi.h"

namespace {
  constexpr unsigned int maxSamples = 10;
}  // namespace

EcalTimeDigi::EcalTimeDigi() : id_(0), size_(0), sampleOfInterest_(-1), waveform_(waveFormSamples), data_(maxSamples) {}

EcalTimeDigi::EcalTimeDigi(const DetId& id)
    : id_(id), size_(0), sampleOfInterest_(-1), waveform_(waveFormSamples), data_(maxSamples) {}

void EcalTimeDigi::setSize(unsigned int size) {
  size_ = size;
  if (size > maxSamples)
    data_.resize(size_);
}

void EcalTimeDigi::setWaveform(float* waveform) {
  waveform_.resize(waveFormSamples);
  for (uint i(0); i != waveFormSamples; ++i) {
    waveform_[i] = waveform[i];
  }
}
