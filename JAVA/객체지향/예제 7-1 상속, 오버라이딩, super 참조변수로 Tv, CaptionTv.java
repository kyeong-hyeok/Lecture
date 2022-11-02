package ch7ex1;

class Tv {
	boolean power;
	int channel;
	void changePower() {power=!power;}
	void channelUp() {
		if(power)
			++channel;
	}
	void channelDown() {
		if(power)
			--channel;
	}
	public String toString() {
		return "power = "+power+", channel = "+channel;
	}
}

class CaptionTv extends Tv {
	boolean caption;
	void displayCaption(String text) {
		if(power && caption)
			System.out.println(text);
	}
	public String toString() {
		return super.toString()+", caption = "+ caption;
	}
}

public class CaptionTvTest {
	public static void main(String[] args) {
		Tv tv = new Tv();
		System.out.println(tv);
		System.out.println(tv.toString());
		
		CaptionTv ctv = new CaptionTv();
		System.out.println(ctv);
		/*System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);*/
		ctv.changePower();
		System.out.println(ctv);
		/*System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);*/
		ctv.channel = 10;
		ctv.channelUp();
		System.out.println(ctv);
		/*System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);*/
		ctv.displayCaption("Hello, world!");
		ctv.caption=true;
		System.out.println(ctv);
		/*System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);*/
		ctv.displayCaption("Hello, world!");
	}
}
