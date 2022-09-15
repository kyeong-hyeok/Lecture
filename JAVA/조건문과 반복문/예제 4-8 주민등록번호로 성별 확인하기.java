package ch4ex8;
import java.util.Scanner;

public class ex8 {
	public static void main(String[] args) {
		System.out.print("주민등록번호를 입력하세요(000101-3123456)> ");
		Scanner scanner = new Scanner(System.in);
		String regNo = scanner.next();
		System.out.println("입력값 : "+regNo);
		char gender = regNo.charAt(7);
		switch(gender) {
		case '1': case '3':
			System.out.println("남자");
			break;
		case '2': case '4':
			System.out.println("여자");
			break;
		default:
			System.out.println("잘못된 숫자");
		}
	}
}
