#include <iostream>
#include <thread>
#include <atomic>
#include <memory>
#include "Util/Buffer.h"
#include "Util/Resampler.h"
#include "Dsp/DecoderBase.h"
#include "Logger.h"

class AudioProcessor {
public:
    virtual size_t fill_buffer(Util::Buffer<float>& buffer) = 0;

    void start_processing() {
        m_thread = std::thread([this] {
            while (m_run) {
                Util::Buffer<float> audio_buffer;
                size_t filled_size = fill_buffer(audio_buffer);
                if (filled_size > 0) {
                    // Resample audio data if m_resampler is available
                    if (m_resampler) {
                        m_resampler->resample(audio_buffer);
                    }
                    // Decode audio data if m_decoder is available
                    if (m_decoder) {
                        m_decoder->decode(audio_buffer);
                    }
                    // Log processing messages
                    m_log.log("Processed audio data");
                }
            }
        });
    }

    void stop_processing() {
        m_run = false;
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

private:
    Logger m_log {"Processing thread"};
    std::unique_ptr<Util::Resampler> m_resampler;
    std::shared_ptr<Dsp::DecoderBase> m_decoder;
    std::atomic<bool> m_run { true };
    std::thread m_thread;
};
