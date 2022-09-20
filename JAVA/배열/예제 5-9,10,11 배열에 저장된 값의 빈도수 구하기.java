package ch5ex91011;

import java.util.Arrays;

public class ex91011 {

	public static void main(String[] args) {
		int[] arr = new int[20];
		for(int i=0; i<arr.length; i++)
			arr[i] = (int)(Math.random()*10)+1;
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		for(int i=0; i<arr.length-1; i++) {
			for(int j=0; j<arr.length-1-i; j++) {
				if(arr[j]>arr[j+1]) {
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
		System.out.println(Arrays.toString(arr));
		int[] frequency = new int[10];
		for(int i=0; i<arr.length; i++)
			frequency[arr[i]-1]++;
		System.out.println(Arrays.toString(frequency));
		for(int i=0; i<frequency.length; i++)
			System.out.println((i+1) + "의 갯수 : "+frequency[i]);
	}
}
