import greycat.Interceptor;
import greycat.Node;

public class CustomNodeInterceptor implements Interceptor {

    @Override
    public void beforeAdd(Node node) {
        // Add a new attribute to the node
        node.addAttribute("newAttribute", "newValue");
    }

    @Override
    public void afterAdd(Node node) {
        // This method is not used in this interceptor
    }

    @Override
    public void beforeRemove(Node node) {
        // This method is not used in this interceptor
    }

    @Override
    public void afterRemove(Node node) {
        // This method is not used in this interceptor
    }
}