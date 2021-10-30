import java.util.Scanner;
import java.util.Random;
import java.util.InputMismatchException;

public class Main {

    private static String randomOption(String[] options) {
        final int index = new Random().nextInt(options.length);
        return options[index];
    }

    private static int comparator(String a, String b) {
        if (a.equals(b)) {
            return 0;
        }
        if (
            (a.equals("paper") && b.equals("rock")) ||
            (a.equals("scissors") && b.equals("paper")) ||
            (a.equals("rock") && b.equals("scissors"))
        ) {
            return 1;
        }
        return -1;
    }

    public static void main(String[] args) {

        final String[] OPTIONS = new String[] {
            "paper",
            "rock",
            "scissors"
        };

        System.out.println("Welcome to the Rock Paper Scissors");
        System.out.println("----------------------------------");
        boolean isOptionOk = false;
        String userOption = "";
        Scanner reader = new Scanner(System.in);
        while (isOptionOk == false) {
            System.out.println("Choosse an option < 1 | 2 | 3 >: ");
            System.out.println("1) Rock");
            System.out.println("2) Paper");
            System.out.println("3) Scissors");
            try {
                int option = reader.nextInt();
                switch (option) {
                    case 1:
                        userOption = "rock";
                        isOptionOk = true;
                        break;
                    case 2:
                        userOption = "paper";
                        isOptionOk = true;
                        break;
                    case 3:
                        userOption = "scissors";
                        isOptionOk = true;
                        break;
                    default:
                        throw new InputMismatchException();
                }
            } catch (InputMismatchException ex) {
                System.out.println("Invalid option. It should be 1, 2 or 3");
                reader.next();
            }
        }
        reader.close();
        System.out.println("You choose: " + userOption);
        final String computerOption = randomOption(OPTIONS);
        System.out.println("Computer choose: " + computerOption);
        final int result = comparator(userOption, computerOption);
        if (result == 1) {
            System.out.println("YOU WON");
        } else if (result == -1) {
            System.out.println("COMPUTER WON");
        } else {
            System.out.println("DRAW");
        }
    }

}