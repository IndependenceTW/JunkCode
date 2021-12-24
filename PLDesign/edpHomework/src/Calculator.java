import java.awt.*;
import java.awt.event.*;

public class Calculator extends KeyAdapter{

    Frame frame;
    Panel panel;
    Label text;
    boolean errorLock = false;
    boolean inOperation = false;
    // add variables...
    
    public static void main(String[] args) {
        new Calculator();
    }

    public Calculator() {
        frame = new Frame("108502515"); // your student ID
        frame.addWindowListener(
            new WindowAdapter() {
                public void windowClosing(WindowEvent event) {
                    System.exit(0);
                }
            }
        );
        frame.setSize(400, 200);
        frame.addKeyListener(this);
        panel = new Panel();
        text = new Label("0");
        panel.add(text);
        frame.add(panel);
        frame.setVisible(true);
    }
    
    public void keyPressed(KeyEvent e) {
        // implement here...
        int key = e.getKeyCode();
        if(errorLock == false){
            if(key >= KeyEvent.VK_NUMPAD0 && key <= KeyEvent.VK_NUMPAD9) {
                inOperation = false;
                String show = text.getText();
                if(show != "0") {
                    show = show + Integer.toString(key-KeyEvent.VK_NUMPAD0);
                }
                else {
                    show = Integer.toString(key-KeyEvent.VK_NUMPAD0);
                }
                text = new Label(show);
                updateFrame(text);
            }
            if(key == KeyEvent.VK_ADD) {
                doOperation("+");
            }
            if(key == KeyEvent.VK_SUBTRACT){
                doOperation("-");
            }
            if(key == KeyEvent.VK_MULTIPLY) {
                doOperation("*");
            }
            if(key == KeyEvent.VK_DIVIDE) {
                doOperation("/");
            }
            if(key == KeyEvent.VK_ENTER) {
                doOperation("");
            }
        }
        if(key == KeyEvent.VK_ESCAPE) {
            errorLock = false;
            text = new Label("0");
            updateFrame(text);
        }
    }

    private void doOperation(String op) {
        String show = text.getText();
        if(inOperation) {
            show = show.substring(0, show.length() - 1);
        }
        else {
            show = calculate(show);
        }
        if(show != "Invalid Operation") {
            show = show + op;
        }
        text = new Label(show);
        updateFrame(text);
        inOperation = true;
    }

    private String calculate(String count) {
        int sign = -1;
        for(int i = 1; i < count.length(); i++) {
            if(count.charAt(i) == '-' || count.charAt(i) == '+' || count.charAt(i) == '*' || count.charAt(i) == '/') {
                sign = i;
                break;
            }
        }

        if(sign == -1) {
            return count;
        }

        char op = count.charAt(sign);
        int num1 = Integer.parseInt(count.substring(0, sign));
        int num2 = Integer.parseInt(count.substring(sign + 1, count.length()));
        int result = 0;
        try {
            switch(op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }
        } 
        catch (ArithmeticException ex){
            errorLock = true;
            return "Invalid Operation";
        }
        return Integer.toString(result);
    }

    private void updateFrame(Label l) {
        panel.setVisible(false);
        panel = new Panel();
        panel.add(l);
        frame.add(panel);
        panel.setVisible(true);
        frame.setVisible(true);
    }
}