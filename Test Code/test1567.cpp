for (int i = 0; i < num_conditions; i++) {
    if (conditions[i].overlap == false && conditions[i].offset == true) {
        found = true;
        break;
    }
}
