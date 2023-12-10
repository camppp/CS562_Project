#include <QObject>

enum class SequenceObjectContext {
    TS_DoNotTranslate,
    TS_AnnotationsOrSelection,
    TS_SetUpFramesManually,
    TS_ShowAllFrames
};

class SequenceContextManager : public QObject {
    Q_OBJECT

public:
    QCheckBox* doNotTranslateAction;
    QCheckBox* translateAnnotationsOrSelectionAction;
    QCheckBox* setUpFramesManuallyAction;
    QCheckBox* showAllFramesAction;

    // Constructor to initialize the actions
    SequenceContextManager(QCheckBox* doNotTranslate, QCheckBox* translateAnnotationsOrSelection, QCheckBox* setUpFramesManually, QCheckBox* showAllFrames) 
        : doNotTranslateAction(doNotTranslate), translateAnnotationsOrSelectionAction(translateAnnotationsOrSelection),
          setUpFramesManuallyAction(setUpFramesManually), showAllFramesAction(showAllFrames) {}

    // Method to set the checked state based on the SequenceObjectContext
    void setCheckedState(SequenceObjectContext state) {
        doNotTranslateAction->setChecked(state == SequenceObjectContext::TS_DoNotTranslate);
        translateAnnotationsOrSelectionAction->setChecked(state == SequenceObjectContext::TS_AnnotationsOrSelection);
        setUpFramesManuallyAction->setChecked(state == SequenceObjectContext::TS_SetUpFramesManually);
        showAllFramesAction->setChecked(state == SequenceObjectContext::TS_ShowAllFrames);
    }

    // Method to emit the signal based on the SequenceObjectContext
    void emitSignal(SequenceObjectContext state) {
        switch (state) {
            case SequenceObjectContext::TS_DoNotTranslate:
                emit sl_doNotTranslate();
                break;
            case SequenceObjectContext::TS_AnnotationsOrSelection:
                emit sl_translateAnnotationsOrSelection();
                break;
            case SequenceObjectContext::TS_SetUpFramesManually:
                emit sl_setUpFramesManually();
                break;
            case SequenceObjectContext::TS_ShowAllFrames:
                emit sl_showAllFrames();
                break;
        }
    }

signals:
    void sl_doNotTranslate();
    void sl_translateAnnotationsOrSelection();
    void sl_setUpFramesManually();
    void sl_showAllFrames();
};
