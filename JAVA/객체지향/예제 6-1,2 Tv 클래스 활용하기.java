package ch6exTv;

class Tv {
	String color;
	boolean power;
	int channel;
	void power() {power = !power;}
	void channelUp(){ channel++;}
	void channelDown() { channel--;}
}

public class TvTest {

	public static void main(String[] args) {
		//ex6-1
		Tv t = new Tv();
		System.out.println("After instantiation, color : " +t.color
				+ ", power : " +t.power
				+ ", channel : " +t.channel);
		t.channel = 7;
		t.channelDown();
		System.out.println("t's channel : " + t.channel);
		//ex6-2
		Tv t1 = new Tv();
		Tv t2 = new Tv();
		t1.channel = 5;
		t2.channel = 6;
		System.out.println("t1's channel : " + t1.channel);
		System.out.println("t2's channel : " + t2.channel);
		t2=t1;
		//t1.channel = 7;
		System.out.println("t1's channel : " + t1.channel);
		System.out.println("t2's channel : " + t2.channel);
		//ex6-4
		Tv[] tvArr = new Tv[3];
		for(int i=0; i<tvArr.length; i++) {
			tvArr[i]=new Tv();
			tvArr[i].channel = i+10;
			System.out.println("tvArr["+i+"].channel : " +tvArr[i].channel);
		}
		for(int i=0; i<tvArr.length; i++) {
			tvArr[i].channelUp();
			System.out.println("tvArr["+i+"].channel : " +tvArr[i].channel);	
		}
	}

}
