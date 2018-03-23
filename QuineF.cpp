/*
 * QuineF.c
 *
 *  Created on: May 16, 2017
 *      Author: kmuhamm1
 */

#include <iostream>
#include <stdio.h>
#include "QuineM.h"
using namespace std;

//unsigned int Quine_SopInput[MAX_SIZE];
struct ColumnElement Quine_SopInput[MAX_SIZE];
MaskElement Quine_Mask[MAX_SIZE];
Result Quine_Result[MAX_SIZE];

//MaskElement Quine_ColumnII[MAX_SIZE];
unsigned int Quine_SopCount;
unsigned int Quine_HighestSOP=0;
unsigned int Quine_SopMaxBits;
unsigned int Quine_MaskLimit=0;
unsigned int Quine_MaskNewLimit=0;
unsigned int Quine_ResultLimit=0;

void Quine_SopStore(){
	unsigned int x;
    for(x=0 ;x<MAX_SIZE ;x++)
    {
    	if (x!= Quine_SopCount){
    		cin>>Quine_SopInput[x].SOP;
    		if(Quine_HighestSOP < Quine_SopInput[x].SOP)
    		   Quine_HighestSOP=Quine_SopInput[x].SOP;
    	}
    	else{
    		break;
    	}
    }
}

void Quine_SopDisplay(){
	unsigned int x;
	cout<<"\n>>> Your SOP : \n";
    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
        	cout<<Quine_SopInput[x].SOP<<"\t";
        }
        else{
        	break;
        }
    }
}
void Quine_SopGroupDisplay(){
	unsigned int x;
	cout<<"\n>>> Your SOP Groups : \n";
    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
        	cout<<Quine_SopInput[x].Group<<"\t";
        }
        else{
        	break;
        }
    }
}

unsigned int Quine_GetHighestSOP(){
	return Quine_HighestSOP;
}

unsigned int Quine_NumberOfBits(unsigned int HighestSop){
	unsigned int x;
	unsigned int temp1 =HighestSop;
	    x=0;
	    while((BIT_MASK1 & temp1) ==0){
	    	temp1=temp1<<1;
	        x++;
	    }
	return (8*(sizeof(x)))-x ;
    }

unsigned int Quine_NumberOfOnes(unsigned int Element){
	unsigned int x,OnesCount=0;
	unsigned int temp1 =Element;
	    x=0;
	    while(x < 32){
	    	if((BIT_MASK2 & temp1) == 1)
	    	OnesCount++;
	    	temp1=temp1>>1;
	    	x++;
	    }
	return OnesCount ;
    }

void Quine_SOPGrouping(){
	unsigned int x;
    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
        	Quine_SopInput[x].Group =Quine_NumberOfOnes(Quine_SopInput[x].SOP);
        }
        else{
        	break;
        }
    }
    }

void Quine_DisplaySopElementExpression(unsigned int temp2){

	unsigned int x=0;
	    temp2=temp2<<SHIFT;
	    while(x < Quine_NumberOfBits(Quine_HighestSOP)){
	    	if((BIT_MASK1 & temp2) == BIT_MASK1){
	    		switch(x){
	    		case 0: cout<<"A "; break;
	    		case 1: cout<<"B "; break;
	    		case 2: cout<<"C "; break;
	    		case 3: cout<<"D "; break;
	    		case 4: cout<<"E "; break;
	    		case 5: cout<<"F "; break;
	    		case 6: cout<<"G "; break;
	    		case 7: cout<<"H "; break;
	    		case 8: cout<<"I "; break;
	    		case 9: cout<<"J "; break;
	    		default: /*! Do NoThing */break;
	    		}
	    		temp2=temp2<<1;
	    		x++;
	    	}
	    	else{
	    		switch(x){

	    		case 0: cout<<"A'"; break;
	    		case 1: cout<<"B'"; break;
	    	    case 2: cout<<"C'"; break;
	    	    case 3: cout<<"D'"; break;
	    		case 4: cout<<"E'"; break;
	    		case 5: cout<<"F'"; break;
	    		case 6: cout<<"G'"; break;
	    		case 7: cout<<"H'"; break;
	    		case 8: cout<<"I'"; break;
	    		case 9: cout<<"J'"; break;
	    		default: /*! Do NoThing */break;
    		 }
	    		temp2=temp2<<1;
	    		x++;
	    	}
}
}


void Quine_DisplaySopElementReducedExpression(unsigned int temp2,unsigned int Mask){

	unsigned int x=0;
//        printf("%x \n",temp2);
//        printf("%x \n",Mask);
	    temp2=temp2<<SHIFT;
	    Mask=Mask << SHIFT;
//	    printf("%x \n",temp2);
//	    printf("%x \n",Mask);
	    while(x < Quine_NumberOfBits(Quine_HighestSOP)){
	    //	cout<<"\n>>> start printing1...";
	 	   if(0 == ( BIT_MASK1 & Mask)) {
	    	if((BIT_MASK1 & temp2) == BIT_MASK1){

	    		switch(x){
	    		case 0: cout<<"A "; break;
	    		case 1: cout<<"B "; break;
	    		case 2: cout<<"C "; break;
	    		case 3: cout<<"D "; break;
	    		case 4: cout<<"E "; break;
	    		case 5: cout<<"F "; break;
	    		case 6: cout<<"G "; break;
	    		case 7: cout<<"H "; break;
	    		case 8: cout<<"I "; break;
	    		case 9: cout<<"J "; break;
	    		default: /*! Do NoThing */break;
	    		}
	    		temp2=temp2<<1;
	    		Mask=Mask<<1;
	    //		printf("\n %x \t",temp2);
	    //		printf("%x \t",Mask);
	    		x++;
	    	}
	    	else{

	    		switch(x){
	    		case 0: cout<<"A'"; break;
	    		case 1: cout<<"B'"; break;
	    	    case 2: cout<<"C'"; break;
	    	    case 3: cout<<"D'"; break;
	    		case 4: cout<<"E'"; break;
	    		case 5: cout<<"F'"; break;
	    		case 6: cout<<"G'"; break;
	    		case 7: cout<<"H'"; break;
	    		case 8: cout<<"I'"; break;
	    		case 9: cout<<"J'"; break;
	    		default: /*! Do NoThing */break;
    		 }
	    		temp2=temp2<<1;
	    		Mask=Mask<<1;
	   // 		printf("\n %x \t",temp2);
	   // 		printf("%x \t",Mask);
	    		x++;
	    	}
	 	   }
	 	   else {/*Do Nothing*/
	    		temp2=temp2<<1;
	    		Mask=Mask<<1;
	    //		printf("\n %x \t",temp2);
	    //		printf("%x \t",Mask);
	    		x++;
	 	   }
	    }

}

void Quine_DisplaySopCompleteExpression(){
	unsigned int x;
    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
        	(Quine_DisplaySopElementExpression(Quine_SopInput[x].SOP));
        	if (x!= Quine_SopCount-1) {cout<<" + ";} else{}
        }
        else{
        	break;
        }
    }
    cout<<"\n";
}

void Quine_DisplayMask(){
	unsigned int x;
	cout<<"\n>>> Generated Masks :\n";
    for(x=0 ;x<Quine_MaskLimit;x++)
        cout<<Quine_Mask[x].GroupElement<<"\t"<<Quine_Mask[x].PreGroupElement<<"\t"<<Quine_Mask[x].Group<<"\t"<<Quine_Mask[x].Mask<<"\t"<<Quine_Mask[x].prime<<"\n";
}

void Quine_DisplayUpdatedMask(){
	unsigned int x;
	cout<<"\n>>> Generated Masks :\n";
    for(x=0 ;x<Quine_MaskLimit;x++)
        	cout<<Quine_Mask[x].GroupElement<<"\t"<<Quine_Mask[x].PreGroupElement<<"\t"<<Quine_Mask[x].Group<<"\t"<<Quine_Mask[x].UpdatedMask<<"\t"<<Quine_Mask[x].prime<<"\n";

}

void Quine_SOPGroupSort(){
	unsigned int x,temp1,temp2,i,j,Swapped;

    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
        	  Swapped = 0;
        	   // loop through all numbers
        	   for(i = 0; i < Quine_SopCount-1; i++) {
        	      Swapped = 0;
        	      // loop through numbers falling ahead
        	      for(j = 0; j < Quine_SopCount-1-i; j++) {
        	         if(Quine_SopInput[j].Group  > Quine_SopInput[j+1].Group ) {
        	            temp1 = Quine_SopInput[j].Group ;
        	            temp2 = Quine_SopInput[j].SOP ;
        	            Quine_SopInput[j].Group  = Quine_SopInput[j+1].Group ;
        	            Quine_SopInput[j].SOP  = Quine_SopInput[j+1].SOP ;
        	            Quine_SopInput[j+1].Group  = temp1;
        	            Quine_SopInput[j+1].SOP  = temp2;
        	            Swapped=1;
        	         }else {}
        	      }
        	      if(!Swapped) {
        	         break;
        	      }
        	   }
        	}
        else{
        	break;
        }
        }
    }



void Quine_ColumnI(){
	unsigned int x,i=0,j=0;
//	unsigned int IsGroupCompFinished;
    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_SopCount){
		Quine_SopInput[x].prime=1;
            for(i=x+1 ;i<Quine_SopCount ;i++){
#ifdef DEBUG_COL1
            	cout<<"\n!!"<<x<<"!!"<<i<<"!!"<<x+i;
#endif
            if(Quine_SopInput[x].Group != Quine_SopInput[i].Group){
        		if (Quine_SopInput[i].Group - Quine_SopInput[x].Group == 1){
        			if(1==Quine_NumberOfOnes(Quine_SopInput[i].SOP ^ Quine_SopInput[x].SOP)){
#ifdef DEBUG_COL1
        			cout<<"\n::"<<Quine_SopInput[x].SOP<<"::"<<Quine_SopInput[i].SOP;
#endif
        			    Quine_SopInput[x].prime=0;
        			    Quine_SopInput[i].prime=0;
        			    Quine_Mask[j].Mask=Quine_SopInput[x].SOP ^ Quine_SopInput[i].SOP;
            			Quine_Mask[j].PreGroupElement = Quine_SopInput[i].SOP;
            			Quine_Mask[j].GroupElement = Quine_SopInput[x].SOP;
            			Quine_Mask[j].Group=Quine_SopInput[x].Group;
            			j++;
            			Quine_MaskLimit=j;

        			}
        			else {/*! Do nothing*/}

        		}
        		else{/*! Do nothing*/}
        	}
            else {/*! Do nothing*/}
            }
        }
        else{
        	break;
        }
    }
}

void Quine_ColumnII(){
	unsigned int x,i=0,j=0;

	for(x=0 ;x<Quine_MaskLimit ;x++)
	Quine_Mask[x].prime=1;

    for(x=0 ;x<MAX_SIZE ;x++)
    {
        if (x!= Quine_MaskLimit){

            for(i=x+1 ;i<Quine_MaskLimit ;i++){
#ifdef DEBUG_COL2
            	cout<<"\n!!"<<x+1<<"!!"<<i+1;
#endif
            if(Quine_Mask[x].Group != Quine_Mask[i].Group){
        		if (Quine_Mask[i].Group - Quine_Mask[x].Group == 1){
        			if (Quine_Mask[i].Mask == Quine_Mask[x].Mask){
        				if(1==Quine_NumberOfOnes(( (Quine_Mask[x].Mask|Quine_Mask[x].PreGroupElement) ^ ( Quine_Mask[x].Mask | Quine_Mask[i].PreGroupElement)))){
#ifdef DEBUG_COL2
        			cout<<"\n>>>>>>>>>>>>>>>>"<<Quine_Mask[x].Group<<"::"<<Quine_Mask[i].Group<<"\t";
        			cout<<"\n>>>>>>>>>>>>>>>>"<<Quine_Mask[x].PreGroupElement<<"::"<<Quine_Mask[i].PreGroupElement<<"\t"<<Quine_Mask[x].Mask<<"\t";
#endif
            		    Quine_Mask[x].prime=0;
            		    Quine_Mask[i].prime=0;
            			Quine_Mask[j].UpdatedMask= ( Quine_Mask[x].Mask | (Quine_Mask[x].PreGroupElement ^ Quine_Mask[i].PreGroupElement));
            			Quine_Mask[j].GroupElement=Quine_Mask[x].PreGroupElement;
#ifdef DEBUG_COL2
            			cout<<Quine_Mask[j].UpdatedMask<<"\t"<<Quine_Mask[j].prime<<"\t";
#endif
            			j++;
            			Quine_MaskNewLimit=j;
        			}
            			else{}
    			}
    			else {/*! Do nothing*/}

    		}
    		else{/*! Do nothing*/}
    	}
        else {/*! Do nothing*/}
        }
    }
    else{
    	break;
    }
}
}

void Quine_ReducedExpression(){
	unsigned int x,y,flag,j=0;
	cout<<"\nTHE OPTIMIZED EXPRESSION = \n";

	for(x=0 ;x<Quine_MaskLimit ;x++){
		if(	Quine_Mask[x].prime==1){
			Quine_Result[j].Mask=Quine_Mask[x].Mask;
			Quine_Result[j].Element=Quine_Mask[x].PreGroupElement;
			j++;
			/*
    		Quine_DisplaySopElementReducedExpression(Quine_Mask[x].PreGroupElement,Quine_Mask[x].Mask);
    		//cout<<Quine_Mask[x].PreGroupElement<<"\t"<<Quine_Mask[x].Mask<<"\t\n";
	    	if (x!= Quine_MaskLimit-1) {cout<<" + ";}
	    	else{}*/
		}
		else{}
	}
#ifdef DEBUG_COL2
	cout<<"\n>>> Generated Masks :\n";
#endif
    for(x=0 ;x<Quine_MaskNewLimit ;x++){
    //	cout<<"\n>>>"<<Quine_Mask[x].PreGroupElement<<"\t"<<Quine_Mask[x].UpdatedMask<<" :\n";
    	flag=0;
    	for(y=x+1 ;y<Quine_MaskNewLimit ; y++){
#ifdef DEBUG_COL2
    		cout<<Quine_Mask[x].UpdatedMask<<"\t"<<Quine_Mask[y].UpdatedMask<<"\t flag=1 \n";
#endif
    		if (Quine_Mask[x].UpdatedMask==Quine_Mask[y].UpdatedMask){
    			flag=1;
                break;
    		}
    		else{
    			/*Do Nothing*/
    		}
    	}
    	if(1==flag){
#ifdef DEBUG_COL2
    		cout<<Quine_Mask[x].PreGroupElement <<"\t"<<Quine_Mask[x].UpdatedMask<<"\n";
#endif

			Quine_Result[j].Mask=Quine_Mask[x].UpdatedMask;
			Quine_Result[j].Element=Quine_Mask[x].GroupElement;
			j++;
			Quine_ResultLimit=j;
			/*
    		Quine_DisplaySopElementReducedExpression(Quine_Mask[x].GroupElement,Quine_Mask[x].UpdatedMask);
	    	if (x!= Quine_MaskNewLimit-2) {cout<<" + ";}
	    	else{}*/
    	}
    	else{
    		/*Do Nothing*/
    	}

    }

}

void Quine_OutputExpression(){
	unsigned int x;
	for (x=0 ;x<Quine_ResultLimit ;x++){
		Quine_DisplaySopElementReducedExpression(Quine_Result[x].Element,Quine_Result[x].Mask);
		if (x!= Quine_ResultLimit-1) {cout<<" + ";}
	}
}


unsigned int  Quine_GetSimilarityCode(unsigned int temp2,unsigned int Mask){

		unsigned int x=0,Shft=BIT_MASK1;
	//	cout<<"\nQuine_GetSimilarityCode running";
	    temp2=temp2<<SHIFT;
	    Mask=Mask << SHIFT;
	    while(x < Quine_NumberOfBits(Quine_HighestSOP)){
	 	   if(Shft == ( Shft & Mask)) {
	 		   temp2= (~Shft) & (temp2);
	 		   Shft=Shft>>1;
	 		   x++;
	 //			cout<<"\nQuine_GetSimilarityCode running while if ";
	    	}
	 	   else {
	 //		  cout<<"\nQuine_GetSimilarityCode running while else ";
	 //		  printf("%x \t",Shft);
	 //		  printf("%x \t",temp2);
	 		  Shft=Shft>>1;
	 		   x++;
	 	   }

}
	    return temp2>>SHIFT;
}


void Quine_RedundencyRemoval(){
	unsigned int x,y,z,count,max1,max2,code;
	cout<<"\n\n\nAfter RedundencyRemoval : \n";
	for(y=0 ;y<Quine_SopCount ;y++)
	{  
//	cout<<"\n"<<Quine_SopInput[y].SOP<<"\n";
	   for(x=0 ;x<Quine_ResultLimit ;x++){
		Quine_Result[x].temp=0;
		code = Quine_GetSimilarityCode(Quine_Result[x].Element,Quine_Result[x].Mask);
//		 printf("%d \t",Quine_Result[x].Element);
//	     printf("%d \t",Quine_Result[x].Mask);
//	     printf("%d \t",code);
	     
		if(Quine_GetSimilarityCode(Quine_SopInput[y].SOP,Quine_Result[x].Mask) == code ){
		Quine_Result[x].temp=1;
//		printf("%d similar code \t",Quine_Result[x].temp);
		}
		else{}
		}
	//cout<<Quine_Result[x].Element <<"\t"<<Quine_Result[x].Mask<<"\n";
		count=0;
		
		for(z=0 ;z<Quine_ResultLimit ;z++){
			if(Quine_Result[z].temp==1) {
			count++;
	//		cout<<"\nQuine_RedundencyRemoval counter++  \n";	
		    }
			
			else{
	//		cout<<"\nQuine_RedundencyRemoval temp != 1 \n";	
			}
			}

	//	cout<<"\nQuine_RedundencyRemoval count = "<<count<<"\n";
		
		if(count==1){
	//		cout<<"\nQuine_RedundencyRemoval count = "<<count<<"\t"<<Quine_Result[z].Element<<"\t"<<y<<"\n";
			for(z=0 ;z<Quine_ResultLimit ;z++){
				if(Quine_Result[z].temp==1) {Quine_Result[z].Essential=1;
	//			cout<<"\nQuine_RedundencyRemoval set essential =>1 "<<Quine_Result[z].Essential<<"\n";
				}
			    else{
	//		    	cout<<"\nQuine_RedundencyRemoval set essential=>0 "<<Quine_Result[z].Essential<<"\n";
			    	Quine_Result[z].Essential=0;
					}
		     }
		}
		else{
	//			cout<<"\nQuine_RedundencyRemoval count != 1 \n";
		}
		
		for(z=0 ;z<Quine_ResultLimit ;z++){
		if(Quine_Result[z].Essential==1 && count==1){
			Quine_DisplaySopElementReducedExpression(Quine_Result[z].Element,Quine_Result[z].Mask);
			cout<<" + ";
	         break;}
		else{}
		}

		}
		/*
		for(z=0 ;z<Quine_ResultLimit ;z++){
		cout<<"\n"<<Quine_Result[z].Element<<"\t"<<Quine_Result[z].Mask<<"\t"<<Quine_Result[z].Essential<<"\n";	
		}
	*/
		
		//		Find the non Essential term
		for(z=0 ;z<Quine_ResultLimit ;z++){
		//	cout<<"\n Essential term loop # "<<z <<"\t"<<Quine_ResultLimit<<"\t";
			if(Quine_Result[z].Essential==1){
		//			cout<<"\n Essential term loop if \n";
		  		for(y=0 ;y<Quine_SopCount ;y++){
		  //				cout<<"\n Essential term loop loop \n";
		  			code = Quine_GetSimilarityCode(Quine_Result[z].Element,Quine_Result[z].Mask);
		  			if(Quine_GetSimilarityCode(Quine_SopInput[y].SOP,Quine_Result[z].Mask) == code ){
		  				Quine_SopInput[y].IsRepresented=1;
		  //					cout<<"\n Essential term Represented \t"<<Quine_SopInput[y].SOP<<"\t"<<Quine_SopInput[y].IsRepresented<<"\n";
		  			}else{}

					}	
	      	}
	      	else{
		
	      	}
		}
	
	            count=0;
	      		max1=0;
	      		max2=0;
		     for(z=0 ;z<Quine_ResultLimit ;z++){
		     	if(Quine_Result[z].Essential==0){
		     	
			//	cout<<"\nnonEssential term Not Represented \t"<<Quine_SopInput[y].SOP<<"\t"<<Quine_SopInput[y].IsRepresented<<"\n";	
	      		
	      	//	cout<<"\nnon Essential term loop else \n"<<Quine_Result[z].Element<<"\t"<<Quine_Result[z].Mask<<"\t counter ="<<count;
	      		
	      		for(y=0 ;y<Quine_SopCount ;y++){
	      		    if(Quine_SopInput[y].IsRepresented==0){
		  			code = Quine_GetSimilarityCode(Quine_Result[z].Element,Quine_Result[z].Mask);
		  			if(Quine_GetSimilarityCode(Quine_SopInput[y].SOP,Quine_Result[z].Mask) == code ){
		  				count++;
		  			}else{}
					}
					else{}
					
		//		cout<<"\nnon Essential term loop after for counter "<<count;
				if (count > max1 && count <4) {
					max1=count;
					max2=z;
			//			cout<<"\nnon Essential term loop if count z "<<max1<<"\t"<<max2;
					}
				else{
				//cout<<"\n count<max1 and count<4";
				}
	     }
		 }
	}
	        //cout<<"\nMAX1 MAX2 "<<max1<<"\t"<<max2;
			Quine_DisplaySopElementReducedExpression(Quine_Result[max2].Element,Quine_Result[max2].Mask);
	
		
		
    }	
	
			
		
		
		
		
		
		


    


