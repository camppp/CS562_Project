c
#include <stdio.h>
#include <stdbool.h>

void classad_visa_write(FILE *file, void *ad) {
    if (ad == NULL) {
        dprintf(D_ALWAYS | D_FAILURE,
                "classad_visa_write ERROR: Ad is NULL\n");
        return;
    }

    // Write the ClassAd to the file
    fprintf(file, "%s\n", ad->name);
    fprintf(file, "%s\n", ad->description);
    fprintf(file, "%s\n", ad->requirements);
    fprintf(file, "%s\n", ad->attributes);
    fprintf(file, "%s\n", ad->constraints);
}
