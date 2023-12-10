#include <QRadioButton>
#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QDebug>

template <typename T>
class radio_btn : public base_widget<QRadioButton, T, detail::radio_btn_to_model>
{
public:
    radio_btn(QWidget* parent = nullptr) : base_widget<QRadioButton, T, detail::radio_btn_to_model>(parent) {}

    // Member functions
    void setText(const QString& text) { this->widget()->setText(text); }
    void setChecked(bool checked) { this->widget()->setChecked(checked); }
    void setEnabled(bool enabled) { this->widget()->setEnabled(enabled); }
    void setFocusPolicy(Qt::FocusPolicy policy) { this->widget()->setFocusPolicy(policy); }
    void setFont(const QFont& font) { this->widget()->setFont(font); }
    void setStyleSheet(const QString& styleSheet) { this->widget()->setStyleSheet(styleSheet); }

    // Template specialization
    template <typename U>
    void bind(U& observableObject)
    {
        // Bind the radio button to the observable object
        // ...
    }
};
