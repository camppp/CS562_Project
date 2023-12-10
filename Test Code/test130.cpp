class XMLImportHandler
{
public:
    XMLImportContext* createImportContext(const Import& import, int nPrefix, const std::string& rLocalName, const AttributeList& xAttrList, const std::string& xBase64Stream)
    {
        // Check if the base64 stream is available
        if (xBase64Stream.empty())
        {
            // Create a default SvXMLImportContext
            return new SvXMLImportContext(import, nPrefix, rLocalName, xAttrList);
        }
        else
        {
            // Create an XMLBase64ImportContext
            return new XMLBase64ImportContext(import, nPrefix, rLocalName, xAttrList, xBase64Stream);
        }
    }
};
