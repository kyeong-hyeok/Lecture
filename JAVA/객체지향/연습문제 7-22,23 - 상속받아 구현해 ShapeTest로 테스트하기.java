package ch7assignment;

class Point {
	int x;
	int y;
	
	Point() {
		this(0,0);
	}
	
	Point(int x, int y) {
		this.x=x;
		this.y=y;
	}
	
	public String toString() {
		return "["+x+","+y+"]";
	}
}

abstract class Shape {
	Point p;
	
	Shape() {
		this(new Point(0,0));
	}
	
	Shape(Point p) {
		this.p = p;
	}
	
	abstract double calcArea(); // 도형의 면적을 계산해서 반환하는 메서드
	
	Point getPosition() {
		return p;
	}
	
	void setPosition(Point p) {
		this.p = p;
	}
}

class Circle extends Shape {
	double r;
	
	Circle(Point p, double r) {
		super(p);
		this.r=r;
	}
	
	Circle(double r) {
		this(new Point(0,0),r);
	}
	
	Circle() {
		this(0.0);
	}
	
	double calcArea() {
		return r*r*Math.PI;
	}
}

class Rectangle extends Shape {
	double width;
	double height;
	
	Rectangle(Point p, double width, double height) {
		super(p);
		this.width = width;
		this.height = height;
	}
	
	Rectangle(double width, double height) {
		this(new Point(0,0), width, height);
	}
	
	Rectangle() {
		this(0.0,0.0);
	}
	
	double calcArea() {
		return width*height;
	}
	
	boolean isSquare() {
		if(width<=0 || height<=0)
			return false;
		return (width==height);
	}
}

public class ShapeTest {

	static double sumArea(Shape[] arr) {
		double result=0;
		for(int i=0; i<arr.length; i++)
			result+=arr[i].calcArea();
		return result;
	}
	
	public static void main(String[] args) {
		Shape[] s = new Shape[2];
		s[0]=new Circle(3.0);
		s[1]=new Rectangle(5.0,4.0);
		
		System.out.println("면적의 합 : " + sumArea(s));
	}

}
