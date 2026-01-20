import java.util.Scanner;
class Greed {
    public void greet (String name){
        System.out.println("Hello "+name+" Welcome to java");
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = sc.nextLine();
        Greed obj = new Greed();
        obj.greet(name);
        sc.close();
    }
    
}
