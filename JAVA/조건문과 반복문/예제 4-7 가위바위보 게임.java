package ch4ex7;

import java.util.Scanner;

public class ex7 {
	public static void main(String[] args) {
		System.out.println("가위(1), 바위(2), 보(3) 중 하나를 입력하세요.>");
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int com = (int)(Math.random()*3)+1;
		System.out.printf("user : %d, computer : %d\n", num, com);
		if(com%3==num-1) System.out.println("사용자가 이겼습니다.");
		else if (num%3==com-1) System.out.println("사용자가 졌습니다.");
		else System.out.println("비겼습니다.");
		scanner.close();
	}
}
