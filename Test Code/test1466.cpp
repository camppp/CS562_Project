++
#ifdef CLASS_TEST
    ci("3: class    : %f", stats[idx++].getMedian());
#elif defined(CLASS_PRECOMP_TEST)
    ci("4: precomp  : %f", stats[idx++].getMedian());
#elif defined(CLASS_COLORPARALLEL_TEST)
    ci("5: colorPara: %f", stats[idx++].getMedian());
#elif defined(FAST_TEST)
    ci("6: fast     : %f", stats[idx++].getMedian());
#endif
