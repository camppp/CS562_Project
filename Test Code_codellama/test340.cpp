void processCommands(FILE *fp) {
    int case_val;
    while (fscanf(fp, "%d", &case_val) == 1) {
        switch (case_val) {
            case 1:
                fprintf(fp, "*  Blue\n");
                break;
            default:
                fprintf(fp, "*  Unknown\n");
                break;
        }
    }
}
