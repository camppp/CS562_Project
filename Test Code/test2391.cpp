class LinearKnob {
private:
    double start_frame;
    double end_frame;
    double end_val;

public:
    LinearKnob(double start_frame, double end_frame, double end_val) {
        this->start_frame = start_frame;
        this->end_frame = end_frame;
        this->end_val = end_val;
    }

    bool isActive(double frame) {
        return (frame >= start_frame && frame <= end_frame);
    }

    double getValue(double frame) {
        if (!isActive(frame)) {
            return 0.0;
        }

        double t = (frame - start_frame) / (end_frame - start_frame);
        return t * end_val;
    }
};
