void BackdropWidget::SetContentWidth(qreal width)
{
    internal_widget_->setMinimumWidth(width);
    internal_widget_->setMaximumWidth(width);
}
