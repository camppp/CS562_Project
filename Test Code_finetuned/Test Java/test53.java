public class FirstTest {
    private int a;

    public void setA(int a) {
        this.a = a;
    }

    @Override
    public String toString() {
        return "x: " + a;
    }

    public static void main(String[] args) {
        FirstTest test = new FirstTest();
        test.setA(10);
        System.out.println(test);
    }
}