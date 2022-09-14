package ch4ex7;

import java.util.Scanner;

public class ex7 {
	public static void main(String[] args) {
		System.out.println("가위(1), 바위(2), 보(3) 중 하나를 입력하세요.>");
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int com = (int)(Math.random()*3)+1;
		System.out.printf("user : %d, computer : %d\n", num, com);
		switch(num-com) {
		case 0:
			System.out.println("비겼습니다.");
			break;
		case 1: case -2:
			System.out.println("사용자가 이겼습니다.");
			break;
		case -1: case 2:
			System.out.println("사용자가 졌습니다.");
			break;
		}
		scanner.close();
	}
}
