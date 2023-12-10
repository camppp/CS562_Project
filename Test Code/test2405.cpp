class CDetectorMouseController {
public:
    CDetectorMouseController();
    ~CDetectorMouseController();

    void OnMouseDClick();

private:
    CMotionDetector detector;
    CPoint mousePos;
};

CDetectorMouseController::CDetectorMouseController() {
    detector = CMotionDetector();
}

CDetectorMouseController::~CDetectorMouseController() {
    detector.Release();
}

void CDetectorMouseController::OnMouseDClick() {
    mousePos = MousePixelPos();
    detector.OnMouseAction(mousePos);
}
