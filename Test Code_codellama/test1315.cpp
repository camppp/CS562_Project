c
void updateInputWidth(Schema *schema, const Schema *lastSchema) {
    schema->inputWidth = lastSchema->outputWidth;
}
