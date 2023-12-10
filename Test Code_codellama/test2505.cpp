tCIDLib::TCard4 c4UpdateObject(const TString& strKey, const tCIDLib::TCard4 c4DataBytes)
{
    // Check if the key exists in the object
    if (obj.bKeyExists(strKey))
    {
        // Update the object with the new data bytes
        obj.objUpdate(strKey, c4DataBytes);
        return 1;
    }
    else
    {
        // Add a new entry to the object with the provided key and data bytes
        obj.objAdd(strKey, c4DataBytes);
        return 2;
    }
}
