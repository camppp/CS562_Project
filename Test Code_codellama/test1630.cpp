JsonValue UiConfig::Jsonize() const
{
    JsonValue json;

    // Add m_uiTemplateS3Uri to the JSON payload if it has been set
    if (m_uiTemplateS3UriHasBeenSet()) {
        json.WithString("uiTemplateS3Uri", m_uiTemplateS3Uri);
    }

    // Add other attributes to the JSON payload
    json.WithString("otherAttribute1", m_otherAttribute1);
    json.WithString("otherAttribute2", m_otherAttribute2);

    return json;
}
