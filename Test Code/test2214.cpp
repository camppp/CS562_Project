OFBool
DU_putShortDOElement(DcmItem *obj, DcmTagKey t, Uint16 us)
{
    OFCondition ec = EC_Normal;
    DcmElement *e = NULL;
    DcmTag tag(t);
    
    // Create a new DICOM element with the given tag
    ec = newDicomElement(e, tag);
    
    // If creating the element was successful, set its value to the given 16-bit unsigned integer
    if (ec == EC_Normal) {
        ec = e->putUint16(us);
    }
    
    // If setting the value was successful, insert the element into the DICOM object
    if (ec == EC_Normal) {
        ec = obj->insert(e, OFTrue);
    }
    
    // Return true if all operations were successful, otherwise return false
    return (ec == EC_Normal) ? OFTrue : OFFalse;
}
