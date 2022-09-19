package ch4ex9;

import java.util.Scanner;

public class ex9 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String str = scanner.nextLine();
		int sum=0;
		for(int i=0; i<str.length(); i++) {
			sum+=str.charAt(i)-'0';
		}
		System.out.println("sum="+sum);
	}
}
