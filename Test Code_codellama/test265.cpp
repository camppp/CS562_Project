struct ScoredTabComparator {
    bool operator()(const ScoredTab& tab1, const ScoredTab& tab2) const {
        // Compare the scores of the two tabs
        if (tab1.score > tab2.score) {
            return true;
        } else if (tab1.score < tab2.score) {
            return false;
        }

        // If the scores are equal, compare the other attributes of the tabs
        // to determine their relative scores
        if (tab1.contentType > tab2.contentType) {
            return true;
        } else if (tab1.contentType < tab2.contentType) {
            return false;
        }

        if (tab1.userPreference > tab2.userPreference) {
            return true;
        } else if (tab1.userPreference < tab2.userPreference) {
            return false;
        }

        // If all other attributes are equal, the two tabs have the same score
        return false;
    }
};
