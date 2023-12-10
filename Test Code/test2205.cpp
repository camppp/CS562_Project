java
public class LayoutConverter {
    public static String convertLayoutToAbbreviation(String type) {
        if (type.equals("LayoutTOCI")) {
            return "TOCI";
        } else if (type.equals("LayoutIndex")) {
            return "Index";
        } else if (type.equals("LayoutNonStruct")) {
            return "NonStruct";
        } else if (type.equals("LayoutPrivate")) {
            return "Private";
        } else if (type.equals("LayoutParagraph")) {
            return "P";
        } else if (type.equals("LayoutHeading")) {
            return "H";
        } else {
            return "Unknown";
        }
    }

    public static void main(String[] args) {
        System.out.println(convertLayoutToAbbreviation("LayoutTOCI"));  // Output: TOCI
        System.out.println(convertLayoutToAbbreviation("LayoutIndex"));  // Output: Index
        System.out.println(convertLayoutToAbbreviation("LayoutNonStruct"));  // Output: NonStruct
        System.out.println(convertLayoutToAbbreviation("LayoutPrivate"));  // Output: Private
        System.out.println(convertLayoutToAbbreviation("LayoutParagraph"));  // Output: P
        System.out.println(convertLayoutToAbbreviation("LayoutHeading"));  // Output: H
        System.out.println(convertLayoutToAbbreviation("UnknownLayout"));  // Output: Unknown
    }
}
