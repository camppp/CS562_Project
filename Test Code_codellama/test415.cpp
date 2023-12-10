namespace lpc17xx {
    class PwmCompatibility {
    public:
        static Pwm GetPwm(int channel) {
            return lpc40xx::Pwm(channel);
        }
    };
}
