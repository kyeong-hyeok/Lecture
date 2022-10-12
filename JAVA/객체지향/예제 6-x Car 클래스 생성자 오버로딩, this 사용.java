package ch6ex;

class Car {
	String color;
	String gearType;
	int door;
	
	Car() {
		this("white", "auto", 4);
	}
	
	Car(String color, String gearType, int door) {
		this.color = color;
		this.gearType = gearType;
		this.door = door;
	}
	
	Car(Car c) {
		color = c.color;
		gearType = c.gearType;
		door = c.door;
	}
	
}

public class CarTest {

	public static void main(String[] args) {
		Car c1 = new Car();
		Car c2 = new Car(c1);
		Car c3 = new Car("black", "auto", 2);
		System.out.println("c1.color = "+c1.color+", c1.gearType = "
				+c1.gearType+", c1.door = "+c1.door);
		System.out.println("c2.color = "+c2.color+", c2.gearType = "
				+c2.gearType+", c2.door = "+c2.door);
		System.out.println("c3.color = "+c3.color+", c3.gearType = "
				+c3.gearType+", c3.door = "+c3.door);
	}

}
