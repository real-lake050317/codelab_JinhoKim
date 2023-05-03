public class classcasting {
    public static class Fish {
        public String endoskeleton = "bone";

        public void action() {
            System.out.println("splash splash");
        }
    }

    public static class Shark extends Fish {
        public String endoskeleton = "cartilage";

        public void action() {
            System.out.println("chomp chomp");
        }
    }

    public static void main(String[] args) {
        Shark Bob = new Fish();
        System.out.println(Bob.endoskeleton);
        Bob.action();
    }
}