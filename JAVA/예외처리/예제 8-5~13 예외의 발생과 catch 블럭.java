package ch8exception;

public class ExceptionEx {

	public static void main(String[] args) {
		
		System.out.println(1);
		System.out.println(2);
		try {
			//System.out.println(0/0);
			System.out.println(3);
			System.out.println(4);
			method1();
		} catch(ArithmeticException e) {
			e.printStackTrace();
			//return;
		} catch(Exception e) {
			e.printStackTrace();
			System.out.println("exception message: "+e.getMessage());
			return;
		} finally {
			System.out.println(6);
		}
		
		//throw new Exception();
		throw new RuntimeException(); 
		//unchecked Exception이기 때문에 main에서 throw 안해도 됨
	}
	
	static void method1() throws Exception {
		method2();
	}
	
	static void method2() throws Exception {
		throw new Exception("exception at method2");
	}

}
