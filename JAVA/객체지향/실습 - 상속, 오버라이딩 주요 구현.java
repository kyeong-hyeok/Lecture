package javafinalexam;

class Person {
	String name;
	String birthDate;
	
	Person() {
	}
	
	Person(String name, String birthDate) {
		this.name=name;
		this.birthDate=birthDate;
	}
	
	public boolean equals(Object obj) {
		if(obj!=null && obj instanceof Person) {
			return (name==((Person)obj).name) && (birthDate==((Person)obj).birthDate);
		}
		else {
			return false;
		}
	}
	
	public String toString() {
		return "name: "+name+", birthDate: "+birthDate;
	}
}

class Student extends Person{
	static int count=210001;
	int studentId;
	String department;
	double gpa;
	{
		studentId=count;
		count++;
	}
	Student() {
		
	}
	
	Student(String name, String birthDate, String department, double gpa) {
		super(name,birthDate);
		this.department=department;
		this.gpa=gpa;
	}
	
	
	public boolean equals(Object obj) {
		if(obj!=null && obj instanceof Student) {
			return super.equals(obj) && (studentId==((Student)obj).studentId)
					&& (department==((Student)obj).department) && (gpa==((Student)obj).gpa);
		}
		else {
			return false;
		}
	}
	
	public String toString() {
		return super.toString() + ", studentId: "+studentId+", department: "+department+
				", GPA: "+gpa;
	}
	
}
public class InheritanceTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person[] persons = new Person[3];

		persons[0] = new Person("Mozart", "981212");
		persons[1] = new Person("Mozart", "981212");
		persons[2] = new Person("Chopin", "010101");
		
		print(persons);
		equalTest(persons);
		
		Student[] students = new Student[3];
		students[0] = new Student("Brown", "000520", "EE", 3.85);
		students[1] = new Student("Smith", "011212", "EE", 3.45);
		students[2] = new Student("Lincoln", "011212", "EE", 3.45);
		
		print(students);
		equalTest(students);
	}
	
	static void print(Object[] obj) {
		for(int i=0; i<obj.length; i++)
			System.out.println(obj[i].toString());
	}

	static void equalTest(Object[] obj) {
		for(int i=0; i<obj.length; i++) {
			for(int j=i+1; j<obj.length; j++) {
				if(obj[i].equals(obj[j]))
					System.out.println(obj[i].toString()+" and "+obj[j].toString()+" are same.");
				else
					System.out.println(obj[i].toString()+" and "+obj[j].toString()+" are different.");
			}
		}
	}
}
