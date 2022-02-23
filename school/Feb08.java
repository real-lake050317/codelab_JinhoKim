public class Feb08 {
    public static void main(String[] args){
        /*
        for (int i = 1; i<=4; i++){
            for (int j = i; j<=4; j++) System.out.print("@");
            for (int j = 1; j<=2*i-1; j++) System.out.print(char('A'+j-1));
            for (int j = i; j<=4; j++) System.out.print("@");
            System.out.println();
        }
        */
        int sum = 0;
        int n = Integer.parseInt(args[0]);
        for (int i = 1; i<=n; i++) sum += double(1/i);
        System.out.println(sum);
    }
}