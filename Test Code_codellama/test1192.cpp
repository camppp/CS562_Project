tOplkError ProcessSyncEvent()
{
    tOplkError oplkRet = kErrorGeneralError;

    oplkRet = oplk_waitSyncEvent(0);
    if (oplkRet != kErrorOk)
    {
        qDebug("Error wait sync event. Err=0x%x", oplkRet);
        return oplkRet;
    }

    return kErrorOk;
}
