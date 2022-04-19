public class Feb07 {
    public static void main(String[] args){
        char x = 'A';
        System.out.println(x+1); //int가 우선하기 때문에 65 + 1 해서 66이 출력됨
        System.out.println((int)x+1); //char는 int로 변환해서 연산하기 때문에 65 + 1 해서 66이 출력됨
        System.out.println((char)(x+1)); //char는 int로 변환해서 연산하기 때문에 65 + 1 해서 66이 출력됨

    }
}