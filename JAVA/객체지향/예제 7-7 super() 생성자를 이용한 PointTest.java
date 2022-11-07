package ch7ex7;

class Point {
	int x;
	int y;
	
	Point() {}
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	String getLocation() {
		return "x: " + x + ", y: " + y;
	}
}

class Point3D extends Point {
	int z;
	
	Point3D() {
		this(0,0,0);
	}
	Point3D(int x, int y, int z) {
		//super(x,y);
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	String getLocation() {
		return super.getLocation()+", z:"+z;
	}
}
public class PointTest {

	public static void main(String[] args) {
		Point3D p1 = new Point3D();
		System.out.println(p1.getLocation());
		
		Point3D p2 = new Point3D(1,2,3);
		System.out.println(p2.getLocation());
	}

}
