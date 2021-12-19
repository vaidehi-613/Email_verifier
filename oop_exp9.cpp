#include<iostream>
#include<string.h>

using namespace std;

class Email
{
  char id[100];
  char *Email_Id;
  int size;
  public:
   Email()
   {
     cout<<"\n\t Enter Email Id :";
     cin>>id;
     Email_Id = new char[sizeof(id)+1];
     strcpy(Email_Id, id);
     size = strlen(Email_Id);
     cout<<"\n\n----------"<<Email_Id;
   }
   ~Email()
   {
     delete[] Email_Id;
   }

   bool HasSpecialSymbols()
   {
     int k=0, temp;
     for(int i=size-1; i>=0 ; i--)
       {

           if(!isalpha(Email_Id[i]))
             {
                if(Email_Id[i]!='.')
                  return 0;
             }

             k++;
 	  if(Email_Id[i]=='.')
           {
             k--;
             if(k>3 || k<2)
                return 0;

             temp = i+1;
             for(i=temp;i>=0;i--)
             {
                if(Email_Id[i]=='@')
                 {
                    if(temp==i)
                      return 0;
                    else
                      return 1;
                 }
             }
           }
       }
       return 0 ;
   }

   bool First_char()
   {
     if(isalpha(Email_Id[0]))
        return 1;
     return 0;
   }

   void check_id(void)
   {
     if( First_char() && HasSpecialSymbols() )
       {}
      else
       throw 0;
   }
};

int main()
{
  Email E;
   try
  {
    E.check_id();
    cout<<"\n\t Entered Email id is valid.";
   }
  catch (int)
  {
    cout<<"\n\t Entered Email id is invalid.";
  }

  cout<<endl<<endl;
  return 0;
}
