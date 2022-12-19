package javafinal;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob3 {

	public static void main(String[] args) {
		Scanner console = new Scanner(System.in);
		File inputFile = null;
		Scanner in = null;
		int is=0;
		while(is==0) {
			try {
				System.out.print("inputfile name: ");
				String inputFileName = console.next();
				inputFile = new File(inputFileName);
				in = new Scanner(inputFile);
				is=1;
				while(in.hasNext()) {
					String str= in.nextLine();
					System.out.println(str.toUpperCase());
				}
			} catch(FileNotFoundException fe) {
				fe.printStackTrace();
			} finally {
				if(in!=null) {
					in.close();
				}
			}
		}
	}

}
