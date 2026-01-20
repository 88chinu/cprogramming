import java.util.Scanner;
class Prime{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x: ");
        int x = sc.nextInt();
        System.out.print("Enter y:");
        int y = sc.nextInt();

        for(int i =x; i<=y; i++){
            if (i>1){
                boolean prime = true;
                for(int j =2;j <=i/2;j++)
                {
                    if(i % j == 0){
                        prime = false;
                        break;
                    }
                }
                if(prime)
                System.out.print(i+" ");
            }
        }
        sc.close();

    }
}