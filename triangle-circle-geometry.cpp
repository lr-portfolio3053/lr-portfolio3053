// Date:	20 February 2015
// Name:	[]
// Project:	Project #1, Triangle-Circle Geometry
// Inputs:	sides of a triangle
// Outputs:	angles of triangle, radius of incircle, radius of circumcircle
// Program Description:	Calculates the remaining one side and two angles 
//						for a triangle given two sides and one opposite angle using 
//						the law of sines
//
//*************************************************************

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <string>
#include <iomanip>
using namespace std;

main(){
	double sideA,sideB,sideC,angleA,angleB,angleC,param,s,area,radius,perim;		// Declare necessary variables
	double pi = acos(-1.0);
	int option;
	char cont=0;
	
	do{									// Do-while loop for entering sides
		do{

	cout<<"Are you comfortable?"<<endl;							// The computer cares, promise.
	sleep(1); cout<<"."<<endl; sleep(1); cout<<"."<<endl; sleep(1); cout<<"."<<endl;
	cout<<"Good. Let us begin."<<endl;							// You are ready.
	sleep(1); cout<<"."<<endl; sleep(1); cout<<"."<<endl; sleep(1); cout<<"."<<endl;
	cout<<"Please enter the sides of a triangle, one by one."<<endl;
	cout<<"Enter Side A here: ";								// User inputs sides one by one
	cin>>sideA;
	cout<<"Now, Side B: ";
	cin>>sideB;
	cout<<"And finally, Side C: ";
	cin>>sideC;
	
	cout<<"\nCongratulations, you have successfully followed the directions I provided."<<endl;
	sleep(3);
	
	cout<<"\nI will now check to see if the sides are valid.  One moment, please."<<endl;
	sleep(3);
		
	// If-else statement for when sides are valid - or invalid
	if((sideA>0 && sideB>0 && sideC>0) && (sideA<sideB+sideC && sideB<sideA+sideC && sideC<sideA+sideB)){
		cont=0;
		cout<<"\nGood news. The sides you provided are VALID."<<endl;
		sleep(3);
		cout<<"\n";
		cout<<"         TRIANGLE ABC   "<<endl;
		cout<<"             /\\         "<<endl;
		cout<<"            /  \\        "<<endl;
		cout<<"           /    \\        "<<endl;
		cout<<"       "<<sideB<<" /      \\ "<<sideA<<endl;
		cout<<"         /        \\        "<<endl;
		cout<<"        /          \\        "<<endl;
		cout<<"       /            \\        "<<endl;
		cout<<"      /______________\\        "<<endl;
		cout<<"            "<<sideC<<endl;
	}
		else{
		cout<<"It brings me great sorrow to inform you that the sides you entered are INVALID."<<endl;
		cout<<"Try again?";
		cin>>cont;
		}
	}
	while(cont=='Y'||cont=='y');
		
		do{					// Do-while loop for returning to option menu
		cout<<"\nNow, choose an option from this list by entering a number."<<endl;
		cout<<"\nOption 1: Angles of the Triangle, and the Area of the Triangle."<<endl;
		cout<<"Option 2: Radius of the Triangle's Incircle, and the remaining Interior Area of the Triangle."<<endl;
		cout<<"Option 3: Radius of the Triangle's Circumcircle, and the remaining Interior Area of the Triangle."<<endl;
		cout<<"Enter option number here: ";
		cin>>option;
		
		switch(option){
			
			// Calculate Angles of Triangle ABC via the Law of cosines
			case 1:
				// Angle A
				param=pow(sideB,2)+pow(sideC,2)-pow(sideA,2);
				param/=(2*sideB*sideC);
				angleA=acos(param)*180/pi;
				cout<<"\nAngle A is "<<angleA<<" degrees.";
				sleep(1); cout<<"."; sleep(1); cout<<".";
	
				// Angle B
				param=pow(sideA,2)+pow(sideC,2)-pow(sideB,2);
				param/=(2*sideA*sideC);
				angleB=acos(param)*180/pi;
				cout<<"\nAngle B is "<<angleB<<" degrees.";
				sleep(1); cout<<"."; sleep(1); cout<<".";
			
				//Angle C
				angleC=180-(angleA+angleB);
				cout<<"\nAngle C is "<<angleC<<" degrees.";
				sleep(1); cout<<"."; sleep(1); cout<<".";
			
				// Area of the Triangle ABC via Heron's Formula
				// First, calculate the semi-perimiter, s
				s=0.5*(sideA+sideB+sideC);
				area=sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
				cout<<"\nThe Area of the Triangle ABC is "<<area<<endl;
			
					break;
			
			// Calculate Radius of the Triangle's Incircle & remaining Interior Area
			case 2:
				s=0.5*(sideA+sideB+sideC);						// Calculate Triangle ABC's semi-perimeter
				area=sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));		// Calculate Triangle ABC's Area
				perim=s*2;										// Then, calculate Triangle ABC's Perimeter
				radius=(2*area/perim);							// Now, ready to calculate incircle radius
				cout<<"\nThe radius of Triangle ABC's Incircle is "<<radius;
				sleep(1); cout<<"."; sleep(1); cout<<".";
				// Calculate the remaining Interior Area of Trangle ABC
				area-=(pi*pow(radius,2));
				cout<<"\nThe remaining Interior Area of Triangle ABC is "<<area;
				sleep(1); cout<<"."; sleep(1); cout<<".";
				
					break;
			// Calculate Radius of Triangle ABC's Circumcircle & remaining Interior Area
			case 3:
				radius=sideA*sideB*sideC;						// Calculate radius of circumcircle
				radius/=sqrt((sideA+sideB+sideC)*(sideB+sideC-sideA)*(sideC+sideA-sideB)*(sideA+sideB-sideC));
				cout<<"\nThe Radius of Triangle ABC's Circumcircle is "<<radius;
				sleep(1); cout<<"."; sleep(1); cout<<".";
				s=0.5*(sideA+sideB+sideC);						// Calculate Triangle ABC's semi-perimeter
				area=sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));		// Calculate Triangle ABC's Area
				cout<<"\nThe Area of Triangle ABC is "<<area;
				sleep(1); cout<<"."; sleep(1); cout<<".";
				area=pi*pow(radius,2)-area;
				cout<<"\nThe remaining Interior Area of Triangle ABC's Circumcircle is "<<area;
				sleep(1); cout<<"."; sleep(1); cout<<".";
					break;
				}
				cout<<"\nWould you like to return to the option menu? ";	// Prompt user for returning to option selection menu
				cin>>cont;
		}
			while(cont=='Y' || cont=='y');
			
			cout<<"\nWould you like to enter in new side lengths? ";		// Prompt user for returning to side length input menu
			cin>>cont;
		}
		while(cont=='Y' || cont=='y');
		// GAME OVER
		cout<<"Snake?"<<endl; sleep(3);
		cout<<"Snake!"<<endl; sleep(3);
		cout<<"Snaaaaaaaaaaaaaaake!!!"<<endl; sleep(1);
		cout<<"GAME OVER";
	
	return 0;
}
