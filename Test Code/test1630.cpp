JsonValue UiConfig::Jsonize() const
{
  JsonValue payload;

  if(m_uiTemplateS3UriHasBeenSet())
  {
    payload.WithString("UiTemplateS3Uri", m_uiTemplateS3Uri);
  }

  // Add other attributes to the JSON payload if needed
  // Example:
  // if(m_otherAttributeHasBeenSet)
  // {
  //   payload.WithString("OtherAttribute", m_otherAttribute);
  // }

  return payload;
}
