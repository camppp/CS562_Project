public class MultipleEventContainsFilter {
    private String filterName;
    private boolean isAnd;
    private FilterFactory factory;
    private List<String> eventContainsStrings;

    public MultipleEventContainsFilter(String filterName, boolean isAnd, FilterFactory factory) {
        this.filterName = filterName;
        this.isAnd = isAnd;
        this.factory = factory;
        this.eventContainsStrings = new ArrayList<>();
    }

    public void setEventContainsString(String eventContainsString) {
        this.eventContainsStrings.add(eventContainsString);
    }


           