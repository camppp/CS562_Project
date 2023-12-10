class ToWahAudioProcessor
{
public:
    // Other class members and methods

    bool producesMidi() const
    {
#if JucePlugin_ProducesMidiOutput
        return true;
#else
        return false;
#endif
    }
};
