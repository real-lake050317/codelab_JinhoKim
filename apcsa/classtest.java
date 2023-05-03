public class classtest {
    public static class Person {
        public String name;
        public int age;

        public Person(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public void action() {
            System.out.println("I am a person");
        }
    }
    public static class Children extends Person {
        public String name;
        public int age;

        public Children(String name, int age) {
            super(name, age);
        }

        public void action() {
            System.out.println("I am a child");
        }

        public void cry() {
            System.out.println("Wahhh");
        }
    }

    public static class Elderly extends Person {
        public String name;
        public int age;

        public Elderly(String name, int age) {
            super(name, age);
        }

        public void action() {
            System.out.println("I am an elderly");
        }

        public void complain() {
            System.out.println("My back hurts");
        }
    }

    public static void main(String[] args) {
        Children Bob = new Children("Bob", 10);
        Elderly Alice = new Elderly("Alice", 80);
        Person k = new Children("Bob", 10);
        Person[] a = new Person[10];
        a[0] = Bob;
        a[1] = Alice;

    } 
}
