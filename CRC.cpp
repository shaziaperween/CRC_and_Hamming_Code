#include <bits/stdc++.h>
#include<vector>

using namespace std;
int main()
{
    vector<int>Dataword;
    int Dataword_length;
    cout<<"Please enter the length of Dataword: ";
    cin>>Dataword_length;
    cout<<"Enter Dataword:";
    for(int i=0;i<Dataword_length;i++)
    {
        int r;
        cin>>r;
        Dataword.push_back(r);
    }
 
    //GENERATING 9-BIT DIVISOR (100000111)
    vector<int>div;
    div.push_back(1);
    for(int i=0;i<5;i++){
     div.push_back(0);
    }
    for(int i=0;i<3;i++){
        div.push_back(1);
    }

    int bits=div.size()-1;
    
    //APPENDING 8 BIT ZEROES TO THE DATAWORD
    for (int i=0;i<bits;i++)
    {
        Dataword.push_back(0);
    }

   vector<int>codeword;
   for(int i=0;i<Dataword.size();i++){
     codeword.push_back(Dataword[i]);
   }

    cout<<"\nGenerated dataword:";
    for(int i=0;i<codeword.size();i++){
     cout<<codeword[i]<<" ";
    }
     int i,j,l;

    
    //PERFORMING DIVISION
    for(int i=0;i<Dataword_length;i++)
    {
        j=0;
        l=i;
        if (codeword[l]>=div[j])
        {
            for(j=0,l=i;j<div.size();j++,l++)
            {
                if((codeword[l]==1 && div[j]==1) || (codeword[l]==0 && div[j]==0))
                {
                    codeword[l]=0;
                }
                else
                {
                    codeword[l]=1;
                }
            }
        }
    }

    int add_bits[20];
    for(int i=0,j=Dataword_length;i<bits;i++,j++)
    {
        add_bits[i]=codeword[j];
    }

    cout<<"\nTrailing bits to be added to codeword: ";
    for(int i=0;i<bits;i++)
    {
        cout<<add_bits[i]<<" ";
    }

    cout<<"\nTransmitted CodeWord(after addition): ";
    vector<int>transmit;
    for(i=0;i<Dataword_length;i++)
    {
        int temp=Dataword[i];
        transmit.push_back(temp);
    }
    for(i=Dataword_length,j=0;i<Dataword_length+bits;i++,j++)
    {
        int temp=add_bits[j];
        transmit.push_back(temp);

    }
    for(i=0;i<Dataword_length+bits;i++)
    {
        cout<<transmit[i]<<" ";
    }
    cout<<endl<<endl;
    
    

    //TRANSMISSION//
    cout<<"\nTransmission"<<endl;
int hops;
double prob ;
cout<<"Number of hops:  ";
cin>>hops ;
cout<<"Crossover probability [between 0 & 1]: ";
cin>>prob ;

int errors=0 ;
if(hops==1)
{
    for(int i =0 ; i<transmit.size() ; i++)
    {
     double x=(((double) rand() +(999*i)) / (RAND_MAX));
      if( x<=prob)
       {
         //cout<<"x="<<x<<endl;
         if(transmit[i]==0)
         {
          transmit[i] = 1;
          errors++;
         }

         else
         {
          transmit[i] = 0;
          errors++ ;
         }

       }
    }
}
else

{

    for(int i =0 ; i<transmit.size() ; i++)
    {
      if(  ((double) rand() / (RAND_MAX)) <= 2*prob*(1-prob))
	     if(transmit[i]==0)
         {
          transmit[i] = 1;
          errors++;
         }
       else
         {
          transmit[i] = 0;
          errors++ ;
         }
    }

}
cout<<endl;
    
    
    
    
 //RECEIVER//
    cout<<"\nReceiver side"<<endl;
    
    cout<<"\nDigital Data stream fed to the system"<<endl;
    for(int i=0;i<Dataword_length;i++){
        cout<<Dataword[i]<<" ";
    }
    
    cout<<"\n\nCodeword formed for dataword\n";
    vector<int>trans;
    for(i=0;i<Dataword_length;i++)
    {
        int p=Dataword[i];
        trans.push_back(p);
    }
    for(i=Dataword_length,j=0;i<Dataword_length+bits;i++,j++)
    {
        int p=add_bits[j];
        trans.push_back(p);

    }
    for(i=0;i<Dataword_length+bits;i++)
    {
        cout<<trans[i]<<" ";
    }
    
    cout<<"\n\nCodeword received at receiver's side: "<<endl;
     for(i=0;i<transmit.size();i++)
    {
        cout<<transmit[i]<<" ";
    }

// FOR CHECK
   for(int i=0;i<Dataword_length;i++)
     {
        j=0;
        l=i;
        if (transmit[l]>=div[j])
        {
            for(j=0,l=i;j<div.size();j++,l++)
            {
                if((transmit[l]==1 && div[j]==1) || (transmit[l]==0 && div[j]==0))
                {
                    transmit[l]=0;
                }
                else
                {
                    transmit[l]=1;
                }
            }
        }
    }
    int r[40];
    for(int i=0,j=Dataword_length;i<bits;i++,j++)
    {
        r[i]=transmit[j];
    }
    cout<<"\n\nThe Remainder is: ";

    for(i=0;i<bits;i++)
    {
        cout<<r[i]<<" ";
    }

    int flag=0;
    for(i=0;i<bits;i++)
    {
        if(r[i]!=0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        cout<<"\n\nTransmission successful with 0 errors"<<endl;
        cout<<"\nExtracted dataword\n";
        for(int i=0;i<Dataword_length;i++){
            cout<<Dataword[i]<<" ";
        }
    }
    else
    {
        cout<<"\n\nDiscard"<<endl;
        cout<<"\n\nWith no. of errors : "<<errors<<endl ;
    }
    return 0;
}


