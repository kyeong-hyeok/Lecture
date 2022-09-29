package ch6ex14;


class Data{int x;}
public class ReferenceReturnEx {
	public static void main(String[] args) {
		Data d = new Data();
		d.x = 10;
		Data d2 = copy(d);
		
		System.out.println("d.x = " +d.x);
		System.out.println("d2.x = " +d2.x);
		
		d2.x=20;
		System.out.println("d.x = " +d.x);
		System.out.println("d2.x = " +d2.x);
		
		Data d3=d2;
		System.out.println("d2.x = " +d2.x);
		System.out.println("d3.x = " +d3.x);
		
		d2.x=30;
		System.out.println("d2.x = " +d2.x);
		System.out.println("d3.x = " +d3.x);
		
		System.out.println(d);
		System.out.println(d2);
		System.out.println(d3);
	}
	static Data copy(Data d) {
		Data tmp = new Data();
		tmp.x = d.x;
		return tmp;
	}
}
