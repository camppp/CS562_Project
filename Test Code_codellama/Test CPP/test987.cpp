#include <optional>
#include <interfaces/effect_player.hpp>
#include <interfaces/offscreen_render_target.hpp>
#include <interfaces/image_processing_result.hpp>

namespace bnb::oep::interfaces
{
    class offscreen_effect_player;
}

using offscreen_effect_player_sptr = std::shared_ptr<bnb::oep::interfaces::offscreen_effect_player>;
using oep_image_process_cb = std::function<void(image_processing_result_sptr)>;

class OffscreenEffectPlayer
{
public:
    OffscreenEffectPlayer(const offscreen_render_target_sptr& target, const effect_player_sptr& effect, const oep_image_process_cb& callback)
    {
        // Apply the effect to the offscreen render target
        effect->apply(target);

        // Get the processed image
        auto processed_image = effect->get_processed_image();

        // Invoke the callback function with the processed image
        callback(processed_image);
    }

    void applyEffect(const offscreen_render_target_sptr& target, const effect_player_sptr& effect, const oep_image_process_cb& callback)
    {
        // Apply the effect to the offscreen render target
        effect->apply(target);

        // Get the processed image
        auto processed_image = effect->get_processed_image();

        // Invoke the callback function with the processed image
        callback(processed_image);
    }
};
