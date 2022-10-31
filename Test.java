public class Test {
    public static void main(String[] args) {
        int n = 3, i, sum, f;
        for (i = 1; i <= n; i = i + 1) {
            sum = 0;
            if (n % i == 0)
                sum = sum + 1;
            if (sum % 2 == 1)
                f = 1;
            else
                f = 0;
            if (f == 1)
                sum = sum + i;
            else
                sum = sum - i;
        }
        System.out.println(sum);

    }
}