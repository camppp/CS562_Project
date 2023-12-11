OFBool DU_putShortDOElement(DcmItem *obj, DcmTagKey t, Uint16 us)
{
    OFCondition ec = EC_Normal;
    DcmElement *e = NULL;
    DcmTag tag(t);
    
    ec = newDicomElement(e, tag);
    if (ec == EC_Normal) {
        ec = e->putUint16(us);
    }
    if (ec == EC_Normal) {
        ec = obj->insert(e, OFTrue);
    }
    if (ec == EC_Normal) {
        return OFTrue;
    } else {
        return OFFalse;
    }
}
