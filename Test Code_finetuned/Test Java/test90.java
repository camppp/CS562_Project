public class AudioManager {
    private Boolean captureAudio;
    private Boolean muteAudio;
    private Boolean sliderHasBeenMoved;

    public AudioManager() {
        this.sliderHasBeenMoved = false;
    }

    public void setCaptureAudio(Boolean capture) {
        this.captureAudio = capture;
        if (capture) {
            this.sliderHasBeenMoved = true;
        }
    }

    public void setMuteAudio(Boolean mute) {
        this.muteAudio = mute;
        if (!mute) {
            this.sliderHasBeenMoved = true;
        }
    }

    public Boolean isAudioConnectionOpen() {
        return this.captureAudio || this.muteAudio;
    }
}