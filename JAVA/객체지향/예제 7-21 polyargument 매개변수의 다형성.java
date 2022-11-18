package ch7polyargument;

import java.util.Vector;

//ex7-21
class Product {
	int price;
	int bonuspoint;
	
	public Product(int price) {
		this.price = price;
		this.bonuspoint = (int)(price/10.0);
	}
	
}

class Tv extends Product {
	
	public Tv() {
		super(100);
	}
	
	public String toString() {
		return "Tv";
	}
	
}

class Computer extends Product {
	Computer() {
		super(200);
	}
	public String toString() {
		return "Computer";
	}
}

class Buyer {
	int money;
	int bonusPoint;
	
	Buyer(int money) {
		this.money = money;
	}
	
	//Product[] item = new Product[10]; //10개 넘어가면 오류
	//int i=0;
	Vector item = new Vector(); //배열 -> Vector 사용하기
	
	void buy(Product p) {
		if(money<p.price) {
			System.out.println("imsufficient balance");
			return;
		}
		money -= p.price;
		bonusPoint += p.bonuspoint;
		
		//item[i++] = p;
		item.add(p);
		System.out.println("Bought " + p + ".");
	}
	
	void summary() {
		int sum=0;
		String itemList = "";
		
		if(item.isEmpty()) {
			System.out.println("No purchased product.");
			return;
		}
		
		for(int i=0; i<item.size(); i++) {	// item.length() -> item.size()
			Product p = (Product)item.get(i);
			//if(item[i]==null) break;
			//sum += item[i].price;
			//itemList = itemList + item[i] + ", ";
			sum += p.price;
			itemList = itemList + p + ", ";
		}
		
		System.out.println("Sum of total price of purchased items: "+sum);
		System.out.println("List of purchased items: "+ itemList);
	}
}

public class PolyArgumentTest {

	public static void main(String[] args) {

		Buyer b = new Buyer(450);
		b.buy(new Tv());
		b.buy(new Computer());
		
		b.summary();
		
		System.out.println("Current balance : " + b.money);
		System.out.println("Current bonus point : " + b.bonusPoint);
	}

}
