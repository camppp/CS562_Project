#include "JuceHeader.h"

class ToWahAudioProcessor : public AudioProcessor
{
public:
    ToWahAudioProcessor() {}

    bool producesMidi()
    {
#if JucePlugin_ProducesMidiOutput
        return true;
#else
        return false;
#endif
    }
};
