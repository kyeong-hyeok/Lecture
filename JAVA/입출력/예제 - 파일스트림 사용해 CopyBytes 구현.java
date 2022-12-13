package ch15io;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class CopyBytes {
	public static void main(String[] args) throws IOException{
		
		FileInputStream in = null;
		FileOutputStream out = null; 
		// try 안에 들어가면 try 블록 안에서만 유효 -> finally에서 오류 난다
		
		try {
			in = new FileInputStream("xanadu1.txt");
			out = new FileOutputStream("outagain.txt");
			int c;
			
			while((c = in.read()) != -1) {
				out.write(c);;
			}
		} catch (FileNotFoundException fe) {
			System.out.println("xanadu1.txt is not existed.");
			fe.printStackTrace();
		} catch (IOException e) {
			System.out.println("IOException occurred.");
			e.printStackTrace();
		} finally {
			if(in != null) {
				in.close();
			}
			if(out != null) {
				out.close();
			}
		}
	}
}
