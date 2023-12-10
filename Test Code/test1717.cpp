sharp
using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

[Serializable]
public ref class Pet : public ISerializable {
public:
    String^ Name;
    int Age;
    String^ Type;

    // Constructor for deserialization
    Pet(SerializationInfo^ info, StreamingContext context) {
        Name = info->GetString("Name");
        Age = info->GetInt32("Age");
        Type = info->GetString("Type");
    }

    // Serialization method
    virtual void GetObjectData(SerializationInfo^ info, StreamingContext context) {
        info->AddValue("Name", Name);
        info->AddValue("Age", Age);
        info->AddValue("Type", Type);
    }
};

void SerializePet(Pet^ pet, String^ filename) {
    FileStream^ fileStream = gcnew FileStream(filename, FileMode::Create);
    BinaryFormatter^ formatter = gcnew BinaryFormatter();
    try {
        formatter->Serialize(fileStream, pet);
    } catch (SerializationException^ e) {
        Console::WriteLine("Serialization failed: " + e->Message);
    } finally {
        fileStream->Close();
    }
}

int main() {
    // Example usage
    Pet^ myPet = gcnew Pet();
    myPet->Name = "Buddy";
    myPet->Age = 5;
    myPet->Type = "Dog";
    String^ filename = "pet.dat";
    SerializePet(myPet, filename);
    Console::WriteLine("Pet serialized to " + filename);
    return 0;
}
