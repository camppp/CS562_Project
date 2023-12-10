#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

class AudioProcessor {
public:
    AudioProcessor(std::shared_ptr<DecoderBase> decoder, std::unique_ptr<Resampler> resampler)
        : m_decoder(decoder), m_resampler(std::move(resampler)), m_run(false) {}

    void start_processing() {
        m_run = true;
        m_thread = std::thread([this] {
            while (m_run) {
                // Fill buffer with float values
                fill_buffer();

                // Process audio data
                process_audio_data();

                // Log messages
                log_messages();
            }
        });
    }

    void stop_processing() {
        m_run = false;
        m_thread.join();
    }

private:
    // Fill buffer with float values
    virtual void fill_buffer() = 0;

    // Process audio data
    void process_audio_data() {
        // Resample audio data if necessary
        if (m_resampler) {
            m_resampler->resample(m_buffer);
        }

        // Decode audio data if necessary
        if (m_decoder) {
            m_decoder->decode(m_buffer);
        }
    }

    // Log messages
    void log_messages() {
        // Log messages using the Logger class
        m_log.log(m_buffer);
    }

    std::shared_ptr<DecoderBase> m_decoder;
    std::unique_ptr<Resampler> m_resampler;
    std::atomic<bool> m_run;
    std::thread m_thread;
    std::vector<float> m_buffer;
};
