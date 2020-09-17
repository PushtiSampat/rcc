 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      15-MathClass.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 import java.lang.Math; 


class MathClass
{ 
	public static void main(String[] args) 
	{ 
        int a = -10;
        float b = -20.20f;

		// Use of .abs() method to get the absoluteValue 
		int AbsA = Math.abs(a); 
		float AbsB = Math.abs(b); 

		System.out.println("Absolute value of int: " + AbsA); 
		System.out.println("Absolute value of float: " + AbsB); 
		System.out.println(""); 

		double x = Math.PI; 
        System.out.println("Math.PI: "  + Math.PI);
	} 
} 



/* ===========================================================
Output: 

Absolute value of int: 10
Absolute value of float: 20.2

Math.PI: 3.141592653589793

 =========================================================== */