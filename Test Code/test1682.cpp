#include <QObject>
#include <QAction>
#include <QSignal>

class SequenceContextManager : public QObject
{
    Q_OBJECT

public:
    explicit SequenceContextManager(QObject *parent = nullptr);

    void setCheckedState(SequenceObjectContext context);
    void emitSignal(SequenceObjectContext context);

private:
    QAction *doNotTranslateAction;
    QAction *translateAnnotationsOrSelectionAction;
    QAction *setUpFramesManuallyAction;
    QAction *showAllFramesAction;

    QSignal *sl_doNotTranslate;
    QSignal *sl_translateAnnotationsOrSelection;
    QSignal *sl_setUpFramesManually;
    QSignal *sl_showAllFrames;
};

SequenceContextManager::SequenceContextManager(QObject *parent) : QObject(parent)
{
    doNotTranslateAction = new QAction(this);
    translateAnnotationsOrSelectionAction = new QAction(this);
    setUpFramesManuallyAction = new QAction(this);
    showAllFramesAction = new QAction(this);

    sl_doNotTranslate = new QSignal(this);
    sl_translateAnnotationsOrSelection = new QSignal(this);
    sl_setUpFramesManually = new QSignal(this);
    sl_showAllFrames = new QSignal(this);
}

void SequenceContextManager::setCheckedState(SequenceObjectContext context)
{
    switch (context) {
        case SequenceObjectContext::DoNotTranslate:
            doNotTranslateAction->setChecked(true);
            break;
        case SequenceObjectContext::TranslateAnnotationsOrSelection:
            translateAnnotationsOrSelectionAction->setChecked(true);
            break;
        case SequenceObjectContext::SetUpFramesManually:
            setUpFramesManuallyAction->setChecked(true);
            break;
        case SequenceObjectContext::ShowAllFrames:
            showAllFramesAction->setChecked(true);
            break;
    }
}

void SequenceContextManager::emitSignal(SequenceObjectContext context)
{
    switch (context) {
        case SequenceObjectContext::DoNotTranslate:
            sl_doNotTranslate->emit();
            break;
        case SequenceObjectContext::TranslateAnnotationsOrSelection:
            sl_translateAnnotationsOrSelection->emit();
            break;
        case SequenceObjectContext::SetUpFramesManually:
            sl_setUpFramesManually->emit();
            break;
        case SequenceObjectContext::ShowAllFrames:
            sl_showAllFrames->emit();
            break;
    }
}
