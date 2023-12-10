java
public Builder ClearPropertyName() {
  PrepareBuilder();
  if (SupportFieldPresence(descriptor_->file())) {
    result.hasPropertyName = false;
  }
  result.propertyName_ = defaultValue();
  return this;
}
