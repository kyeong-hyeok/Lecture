package ch7ex13;

class Time {
	private int hour;
	private int minute;
	private int second;
	
	public int getHour() {
		return hour;
	}

	public void setHour(int hour) {
		if(hour>=0 && hour<24)
			this.hour = hour;
	}

	public int getMinute() {
		return minute;
	}

	public void setMinute(int minute) {
		if(minute>=0 && minute<60)
			this.minute = minute;
	}

	public int getSecond() {
		return second;
	}

	public void setSecond(int second) {
		if(second>=0 && second<60)
		this.second = second;
	}

	
	Time(int hour, int minute, int second) {
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}
	
	public String toString() {
		return hour + ":" + minute + ":" + second;
	}	
}

public class TimeTest {

	public static void main(String[] args) {
		Time t= new Time(10,30,0);
		System.out.println(t);
		
		//t.hour = 13;
		t.setHour(13);
		System.out.println("현재 " + t.getHour() +"시 입니다.");
		System.out.println(t);
	}

}
