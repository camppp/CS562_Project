XmlNamespaceManager^ nsmgr = gcnew XmlNamespaceManager( nt );

// Create the XmlParserContext.
XmlParserContext^ context = gcnew XmlParserContext( nullptr, nsmgr, nullptr, XmlSpace::None );

// Create the reader.
XmlReader^ reader = XmlReader::Create("sample.xml", gcnew XmlReaderSettings(), context);

// Read the XML data and extract specific information.
while (reader->Read()) {
    if (reader->NodeType == XmlNodeType::Element) {
        if (reader->Name == "item") {
            // Extract specific information from the "item" element.
            String^ itemName = reader->GetAttribute("name");
            int itemQuantity = Convert::ToInt32(reader->GetAttribute("quantity"));

            // Perform a particular action based on the extracted data.
            // Your action code here
            Console::WriteLine("Item: " + itemName + ", Quantity: " + itemQuantity);
        }
    }
}

// Close the reader.
reader->Close();
