import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import static java.lang.System.exit;

/*
   submission 1:
    Started to write this task in C++. But I'm a bit of a novice regarding
    C++ so wanted to finish it, just wrote it in java.

    submission 2:
     Tested all combinations possible, don't know where the problem is.
     1. added Scanner.close()... forgot that.
     2. noticed "The representation of the instruction set makes it impossible
        to try to manipulate bits outside this range." So made checks for every
        bit operand
     3.

 */
public class Main {

    public static void main(String[] args) {
        Task task = new Task(32);
        task.invoke();
        exit(0);
    }
}

class Task {
    private final int REG_SIZE;
    private Scanner inpSc;
    private List<Register> registers;
    private String command;
    private int arg1, arg2;
    private int nArgs;
    private int topIndex;

    Task(int regSize) {
        this.REG_SIZE = regSize;
        inpSc = new Scanner(System.in);
        registers = new ArrayList<>();
        topIndex = 0;
    }

    void invoke() {
        while (true) {

            nArgs = inpSc.nextInt();
            inpSc.nextLine(); // consume \n character
            if (nArgs < 1) {
                break;
            }

            registers.add(new Register(32));

            for (int i = 0; i < nArgs; i++) {
                command = inpSc.next();

                if (command.equals("CLEAR")) {
                    arg1 = inpSc.nextInt();
                    registers.get(topIndex).CLEAR(arg1);

                } else if (command.equals("SET")) {
                    arg1 = inpSc.nextInt();
                    registers.get(topIndex).SET(arg1);

                } else if (command.equals("OR")) {
                    arg1 = inpSc.nextInt();
                    arg2 = inpSc.nextInt();
                    registers.get(topIndex).OR(arg1, arg2);

                    // AND
                } else if (command.equals("AND")) {
                    arg1 = inpSc.nextInt();
                    arg2 = inpSc.nextInt();
                    registers.get(topIndex).AND(arg1, arg2);
                }
                // printRegisters();
            }
            topIndex++;
        }
        if (topIndex == 0) {
            registers.add(new Register(32));
        }

        inpSc.close();
        printRegisters();
    }

    private void printRegisters() {
        for (Register r : registers) {
            r.printRegiser();
        }
    }

    /*-----------------------INNER CLASS-----------------------*/

    private class Register {
        int size;
        char[] data;

        Register(int size) {
            data = new char[size];
            this.size = size;
            for (int i = 0; i < size; i++) {
                data[i] = '?';
            }
        }

        void CLEAR(int n) {
            if (isInBounds(n, size - 1)) {
                int i = REG_SIZE - 1 - n;
                data[i] = '0';
            }
        }

        void SET(int n) {
            if (isInBounds(n, size - 1)) {
                int i = REG_SIZE - 1 - n;
                data[i] = '1';
            }

        }

        // unkown has highest presidenc
        void OR(int n, int k) {
            if (isInBounds(n, size - 1) && isInBounds(k, size - 1)) {
                int i = REG_SIZE - 1 - n;
                int j = REG_SIZE - 1 - k;

                if (data[i] == '0' && data[j] == '?'){
                    regis[i] = '?';
                }else if(data[i] == '1' || data[j] == '1'){
                    data[i] = '1';
                }
            }
        }

        // unkown has highest presidence
        void AND(int n, int k) {
            if(isInBounds(n,size-1) && isInBounds(k,size-1)){
                int i = REG_SIZE-1 - n;
                int j = REG_SIZE-1 - k;
            if(data[i] == '0' || data[j] =='0'){
                data[i] = '0';
            }else if(data[i] == '1' && data[j] =='1'){
                data[i] = '1';
            }else { data[i] ='?'
            }
        }

        private boolean isInBounds(int index, int maxIndex) {
            return (index >= 0 && index <= maxIndex);
        }

        void printRegiser() {
            System.out.println(data);
        }

    }

}
