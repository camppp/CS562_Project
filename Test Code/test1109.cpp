PRStatus
ProcessLock::acquire(Sleeper& sleeper)
{
#ifdef XP_UNIX

    PRStatus status = PR_FAILURE;

    if (lock_ != NULL && lockFD_ != -1)
    {
        // Attempt to acquire the cross-process lock
        if (acquireCrossProcessLock())
        {
            // Attempt to acquire the intra-process lock
            if (acquireIntraProcessLock())
            {
                status = PR_SUCCESS;  // Both locks acquired successfully
            }
            else
            {
                releaseCrossProcessLock();  // Release the cross-process lock
            }
        }

        if (status == PR_FAILURE)
        {
            // If the locks are not immediately available, use the Sleeper to wait
            if (sleeper.sleep())
            {
                // Retry acquiring the locks after waiting
                status = acquire(sleeper);
            }
        }
    }

    return status;
#endif
}
