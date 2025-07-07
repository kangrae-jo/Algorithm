import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] arg) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str, bomb;
        str = br.readLine();
        bomb = br.readLine();

        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            answer.append(str.charAt(i));

            if (answer.length() >= bomb.length()) {
                boolean flag = true;
                for (int j = 0; j < bomb.length(); j++) {
                    if (answer.charAt(answer.length() - bomb.length() + j) != bomb.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    answer.setLength(answer.length() - bomb.length());
                }
            }
        }

        if (answer.length() == 0) {
            System.out.println("FRULA");
        }
        System.out.println(answer);
    }

}
