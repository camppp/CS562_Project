XmlNamespaceManager^ nsmgr = gcnew XmlNamespaceManager( nt );

// Create the XmlParserContext.
XmlParserContext^ context = gcnew XmlParserContext( nullptr, nsmgr, nullptr, XmlSpace::None );

// Create the reader.
XmlReader^ reader = XmlReader::Create("sample.xml", gcnew XmlReaderSettings(), context);

// Read the XML data and extract specific information.
while (reader->Read()) {
    // Extract the value of the "name" attribute from the current element.
    String^ name = reader->GetAttribute("name");

    // Check if the current element is the "person" element.
    if (reader->IsStartElement("person")) {
        // Extract the value of the "age" attribute from the current element.
        int age = reader->GetAttribute("age");

        // Perform an action based on the extracted data.
        if (age > 30) {
            Console::WriteLine("The person is older than 30 years.");
        } else {
            Console::WriteLine("The person is younger than 30 years.");
        }
    }
}

// Close the reader.
reader->Close();
