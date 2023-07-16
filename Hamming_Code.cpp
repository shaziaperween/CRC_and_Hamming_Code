//#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    string datastream;
    cout<<"PLEASE ENTER 4-BIT DATA STREAM: ";
    cin>>datastream;
    
    int length=datastream.length();
    cout<<"DIGITAL DATA STREAM: ";
    cout<<datastream<<endl;
    
    int x=0;
    int errors=0;
    int error[10]={0};
    string codeword="";
    string errorword="";
    string correctword="";
    
    //POPULATING DATA WORDS
    for(int i=0;i<length;i+=4){
     string dataword="";
     string temp="";
     for(int j=i;j<i+4;j++){
     temp+=datastream.at(j);
     }
      for(int k=0;k<3;k++){
          dataword+=temp.at(k);
      }
      dataword+=" ";
      dataword+=temp.at(3);
    
        
    //ADDING PARITY BITS
    int p1,p2,p3;
    p1=dataword.at(0)^dataword.at(2)^dataword.at(4);
    p2=dataword.at(0)^dataword.at(1)^dataword.at(4);
    p3=dataword.at(0)^dataword.at(1)^dataword.at(2);
    dataword.at(3)=p3;
    dataword+=p2;
    dataword+=p1;
    cout<<"CODEWORD FORMED FROM INPUT DATA STREAM: "<<dataword<<endl;
    codeword+=dataword;
    cout<<"CODEWORD SENT: ";
    cout<<codeword<<endl<<endl;
        
        
//Calculating no of errors
int index=0;
float prob=0.50;
    
for(int i =0 ; i<dataword.length() ; i++)
    {
      if(  ((float) rand() / (RAND_MAX)) <=prob )
       {
         if(dataword.at(i)=='0')
         {
          dataword.at(i)= '1';
          errors++;
          index=i;
          break;
         }

         else
         {
          dataword.at(i) = '0';
          errors++ ;
          index=i;
          break;
         }

       }
    }
        error[x]=index;
    x++;

    errorword+=dataword;
    }
   
    
    

//RECEIVER//

int len=errorword.length();
int k=0;
for(int i=0;i<len;i+=7){
     string temp="";
     for(int j=i;j<i+7;j++){
          temp+=errorword.at(j);
     }
     cout<<"Error is at position "<<error[k]<<endl;

     if(temp.at(error[k])=='0'){
          temp.at(error[k])='1';
     }
     else{
          temp.at(error[k])='0';
     }
correctword+=temp;
 k++;
}
cout<<endl;
cout<<"DIGITAL DATA STREAM FED TO THE SYSTEM"<<endl;
cout<<datastream<<endl<<endl;
    
cout<<"CODEWORD FORMED FOR DATAWORD: "<<endl;
cout<<codeword<<endl<<endl;
    
cout<<"RECEIVED CODEWORD:"<<endl;
cout<<errorword<<endl<<endl;
    
cout<<"NO. OF ERRORS: "<<errors<<endl<<endl;
    
cout<<"DATAWORD AFTER CORRECTING ALL THE ERRORS:"<<endl;
cout<<correctword<<endl;
return 0;
}


