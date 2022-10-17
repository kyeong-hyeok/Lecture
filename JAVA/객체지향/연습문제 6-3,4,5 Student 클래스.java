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
		return (int)(getTotal()/3f*10+0.5f)/10f;
	}
	
}

public class Excercise6_4 {

	public static void main(String[] args) {
		
		Student s1 = new Student();
		Student s2 = new Student("민경혁", 3, 8, 90, 90, 100);
		s1.name = "홍길동";
		s1.ban = 1;
		s1.no = 1;
		s1.kor = 100;
		s1.eng = 60;
		s1.math = 76;
		
		System.out.println("s1 이름:"+s1.name);
		System.out.println("s1 총점:"+s1.getTotal());
		System.out.println("s1 평균:"+s1.getAverage());
		System.out.println(s1.info());
		
		System.out.println("s2 이름:"+s2.name);
		System.out.println("s2 총점:"+s2.getTotal());
		System.out.println("s2 평균:"+s2.getAverage());
		System.out.println(s2.info());
	}
	
}
