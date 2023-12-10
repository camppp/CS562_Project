void SerializePet(Pet^ pet, String^ filename)
{
    // Create a new file stream
    FileStream^ fileStream = gcnew FileStream(filename, FileMode::Create);

    // Create a new binary writer
    BinaryWriter^ binaryWriter = gcnew BinaryWriter(fileStream);

    // Write the pet's name
    binaryWriter->Write(pet->Name);

    // Write the pet's age
    binaryWriter->Write(pet->Age);

    // Write the pet's type
    binaryWriter->Write(pet->Type);

    // Close the binary writer
    binaryWriter->Close();

    // Close the file stream
    fileStream->Close();
}
