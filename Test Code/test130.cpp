java
public class XMLImportHandler {
    public static XMLImportContext createImportContext(Import importObj, int nPrefix, String rLocalName, List<Attribute> xAttrList, Base64Stream xBase64Stream) {
        XMLImportContext pContext = null;
        if (xBase64Stream.is()) {
            pContext = new XMLBase64ImportContext(importObj, nPrefix, rLocalName, xAttrList, xBase64Stream);
        }
        if (pContext == null) {
            pContext = new SvXMLImportContext(importObj, nPrefix, rLocalName);
        }
        return pContext;
    }
}
