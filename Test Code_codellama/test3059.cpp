struct AudioInfo {
  int samplingFrequency;
  int extendedSamplingFrequency;
  int numChannels;
  int objectType;
};

AudioInfo parseAudioHeader(const audio_header& header) {
  AudioInfo info;
  info.samplingFrequency = header.sampling_frequency;
  info.extendedSamplingFrequency = header.extended_sampling_frequency;
  info.numChannels = header.num_channels;
  info.objectType = header.object_type;
  return info;
}
