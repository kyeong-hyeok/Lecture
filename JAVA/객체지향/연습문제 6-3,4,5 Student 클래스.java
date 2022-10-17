package ch6ex345;

class Student {
	
	static int count;
	int studentId;
	String name; 
	int ban; 
	int no;
	int kor; 
	int eng;
	int math;
	
	{
		count++;
		studentId = count;
	}
	
	Student() {}
	
	Student(String name, int ban, int no, int kor, int eng, int math) {
		this.name = name;
		this.ban = ban;
		this.no = no;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
	}
	
	String info() {
		return name+", "+studentId+", "+ban+", "+no
				+", "+kor+", "+eng+", "+math;
	}
	
	int getTotal() {
		return kor+eng+math;
	}
	
	float getAverage() {
		return (int)((float)getTotal()/3*10+0.5f)/10f;
	}
	
}

public class Excercise6_4 {

	public static void main(String[] args) {
		Student s = new Student();
		s.name = "홍길동";
		s.ban = 1;
		s.no = 1;
		s.kor = 100;
		s.eng = 60;
		s.math = 76;
		
		System.out.println("이름:"+s.name);
		System.out.println("총점:"+s.getTotal());
		System.out.println("이름:"+s.getAverage());
		System.out.println(s.info());

	}
	
}
