void ttime::wait(int index) {
    time_t start, end;
    time(&start);
    do {
        time(&end);
    } while(difftime(end, start) < index);
}
