package ch7polymorphism;

class Ambulance extends Car{
	void siren() {
		System.out.println("siren~~");
	}
}

class Car {
	String color;
	int door;
	public void drive() {
		System.out.println("drive, brrrr~~");
	}
	public void stop() {
		System.out.println("stop!!");
	}
}

class FireEngine extends Car {
	void water() {
		System.out.println("water!!");
	}
}

public class PolymorphismTest {

	public static void main(String[] args) {
		
		//eX7-15
		Car car = null;
		FireEngine fe = new FireEngine();
		FireEngine fe2 = null;
		Ambulance ambulance = new Ambulance();
		
		fe.water();
		car = fe; //upcasting
		//car.water(); //error
		car.drive();
		
		fe2 = (FireEngine)car; //downcasting
		fe2.water();
		
		//ambulance = (Ambulance)fe2; // 상속관계 x
		
		//ex7-16
		Car car1 = new Car();
		//fe2 = (FireEngine)car1; //exception 발생
		//fe2.drive();
		//fe2.water();
		
		//ex7-17
		//instanceof test
		
		if (fe instanceof FireEngine) {
			System.out.println("fe is a FireEngine instance");
		}
		if (fe instanceof Car) {
			System.out.println("fe is a Car instance");
		}
		if (fe instanceof Object) {
			System.out.println("fe is a Object instance");
		}
		method(fe);
	}
	
	static void method(Object obj) {
		if(obj instanceof FireEngine) {
			FireEngine fe = (FireEngine)obj;
			fe.water();
		}
		if (obj instanceof Car) {
			Car c = (Car)obj;
			c.drive();
		}
	}

}
