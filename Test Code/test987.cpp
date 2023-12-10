#include <memory>
#include <functional>

namespace bnb::oep::interfaces
{
    class offscreen_render_target;
    class effect_player;
}

using offscreen_render_target_sptr = std::shared_ptr<bnb::oep::interfaces::offscreen_render_target>;
using effect_player_sptr = std::shared_ptr<bnb::oep::interfaces::effect_player>;
using image_processing_result_sptr = std::shared_ptr<bnb::oep::interfaces::image_processing_result>;

class OffscreenEffectPlayer
{
public:
    void applyEffect(const offscreen_render_target_sptr& target, const effect_player_sptr& effect, const oep_image_process_cb& callback)
    {
        // Apply the effect to the offscreen render target
        image_processing_result_sptr processedImage = processImage(target, effect);

        // Notify the caller with the processed image
        callback(processedImage);
    }

private:
    image_processing_result_sptr processImage(const offscreen_render_target_sptr& target, const effect_player_sptr& effect)
    {
        // Simulate image processing and return the processed image
        // Replace this with actual image processing logic
        image_processing_result_sptr processedImage = std::make_shared<bnb::oep::interfaces::image_processing_result>();
        // Process the image using the effect and target
        // ...
        return processedImage;
    }
};
