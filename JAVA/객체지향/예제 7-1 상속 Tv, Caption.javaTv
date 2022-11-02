package ch7ex1;


class Tv {
	boolean power;
	int channel;
	void changePower() {power=!power;}
	void channelUp() {++channel;}
	void channelDown() {--channel;}
}

class CaptionTv extends Tv {
	boolean caption;
	void displayCaption(String text) {
		if(caption)
			System.out.println(text);
	}
}

public class CaptionTvTest {
	public static void main(String[] args) {
		CaptionTv ctv = new CaptionTv();
		System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);
		ctv.changePower();
		System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);
		ctv.channel = 10;
		ctv.channelUp();
		System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);
		ctv.displayCaption("Hello, world!");
		ctv.caption=true;
		System.out.println("ctv.power = "+ctv.power
				+", ctv.channel = "+ctv.channel
				+", ctv.caption = "+ctv.caption);
		ctv.displayCaption("Hello, world!");
	}
}
